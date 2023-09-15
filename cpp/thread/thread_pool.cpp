#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

class ThreadPool
{
public:
    // the constructor just launches some amount of workers
    ThreadPool(size_t threads) : stop(false)
    {
        for (size_t i = 0; i < threads; ++i)
            workers.emplace_back(std::thread(&ThreadPool::singleTask, this));
    }

    // add new work item to the pool
    template <class F, class... Args>
    auto enqueue(F &&f, Args &&...args)
        -> std::future<typename std::result_of<F(Args...)>::type>
    {
        using return_type = typename std::result_of<F(Args...)>::type;

        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...));

        std::future<return_type> res = task->get_future();
        {
            std::unique_lock<std::mutex> lock(queue_mutex);

            // don't allow enqueueing after stopping the pool
            if (stop)
                throw std::runtime_error("enqueue on stopped ThreadPool");

            tasks.emplace([task]()
                          { (*task)(); });
        }
        condition.notify_one();
        return res;
    }

    // the destructor joins all threads
    ~ThreadPool()
    {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        for (std::thread &worker : workers)
            worker.join();
    }

private:
    void singleTask()
    {
        for (;;)
        {
            std::unique_lock<std::mutex> lock(this->queue_mutex);
            this->condition.wait(lock, [this]
                                 { return this->stop || !this->tasks.empty(); });
            if (this->stop && this->tasks.empty())
                return;
            const auto task = std::move(this->tasks.front());
            this->tasks.pop();
            lock.unlock();

            task();
        }
    }

    // need to keep track of threads so we can join them
    std::vector<std::thread> workers;
    // the task queue
    std::queue<std::function<void()>> tasks;

    // synchronization
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

int main()
{
    // ThreadPool pool = ThreadPool::ThreadPool(4); // not allowed
    ThreadPool pool(4);
    std::vector<std::future<int>> results;

    for (int i = 0; i < 8; ++i)
    {
        results.emplace_back(
            pool.enqueue([](int i)
                         {
                std::cout << "before " << i << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "after " << i << std::endl;
                return i*i; },
                         i));
    }

    for (auto &&result : results)
        std::cout << result.get() << ' ';
    std::cout << std::endl;

    return 0;
}