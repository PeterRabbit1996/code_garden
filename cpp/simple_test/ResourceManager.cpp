#include <iostream>
#include <memory>
#include <map>
#include <tuple>
#include <mutex>

template <typename ResType, typename IdType>
class ResourceManager
{
public:
    template <typename... Args>
    std::shared_ptr<ResType> createResource(IdType id, Args &&...args)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        auto iter = resource_map_.find(id);
        if (iter != resource_map_.end())
        {
            const auto res = iter->second.lock();
            if (res)
                return res;
        }

        std::shared_ptr<ResType> new_resource = std::make_shared<ResType>(std::forward<Args>(args)...);
        resource_map_[id] = new_resource;
        return new_resource;
    }

private:
    std::map<IdType, std::weak_ptr<ResType>> resource_map_;
    std::mutex mutex_;
};

class ExampleResource
{
public:
    ExampleResource(int x, int y)
    {
        std::cout << "ExampleResource created with (" << x << ", " << y << ")." << std::endl;
    }

    ~ExampleResource()
    {
        std::cout << "ExampleResource destroyed." << std::endl;
    }
};

int main()
{
    ResourceManager<ExampleResource, int> manager;

    {
        std::shared_ptr<ExampleResource> resource1 = manager.createResource(1, 10, 20);
        std::shared_ptr<ExampleResource> resource2 = manager.createResource(1, 10, 20);
        std::shared_ptr<ExampleResource> resource3 = manager.createResource(2, 30, 40);
    }


    std::cout << "=== end ===" << std::endl;

    return 0;
}
