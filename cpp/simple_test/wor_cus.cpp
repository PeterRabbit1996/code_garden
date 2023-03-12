

/*
3 生产者
1 消费者

10 商品队列
*/

// product

#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <memory>
#include <mutex>

class Product
{
};

class TE
{
public:
	TE(int wor, int cus, int pro) : cnt_wor_(wor), cnt_cus_(cus), cnt_pro_(pro) {}

	void start()
	{
		isStart = true;

		// wor td
		for (int i = 0; i < cnt_wor_; i++)
		{
			td_wor_.emplace_back(new std::thread(&TE::thread_worker, this));
		}

		// cus td
		for (int i = 0; i < cnt_cus_; i++)
		{
			td_cus_.emplace_back(new std::thread(&TE::thread_customer, this));
		}

		return;
	}

	void stop()
	{
		isStart = false;
		for (int i = 0; i < cnt_wor_; i++)
		{
			// td_wor_.emplace_back(new std::thread(thread_worker));
			td_wor_[i]->join();
			delete td_wor_[i];
		}

		return;
	}

private:
	void thread_worker()
	{
		while (true)
		{
			// std::sleep(1);
			// sleep 1ms
			if (!isStart)
				break;
			std::lock_guard<std::mutex> lck(mtx_);
			if (que_pro_.size() >= cnt_pro_)
				continue;
			que_pro_.emplace(new Product());
		}
		return;
	}

	void thread_customer()
	{
		while (true)
		{
			if (!isStart)
				break;
		}
		return;
	}

	std::vector<std::thread *> td_wor_;
	std::vector<std::thread *> td_cus_;

	std::mutex mtx_;
	std::queue<std::shared_ptr<Product>> que_pro_;

	int cnt_wor_;
	int cnt_cus_;
	int cnt_pro_;

	bool isStart = false;
};

int main()
{

	return 0;
}
