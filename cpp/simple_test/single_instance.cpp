#include <iostream>
#include <cstdio>
#include <memory>
#include <mutex>

#define NOT_ALLOW_COPY_AND_ASSIGN(class_name) \
    class_name(const class_name &) = delete;  \
    class_name &operator=(const class_name &) = delete;

namespace singinst
{
    class SingleInstance
    {
    public:
        NOT_ALLOW_COPY_AND_ASSIGN(SingleInstance)
        ~SingleInstance()
        {
            std::cout << "destructor called!" << std::endl;
        }

        static SingleInstance &get_instance()
        {
            static SingleInstance instance;
            return instance;
        }

    private:
        SingleInstance()
        {
            std::cout << "constructor called!" << std::endl;
        }
    };

    void test_1()
    {
        SingleInstance &instance_1 = SingleInstance::get_instance();
        SingleInstance &instance_2 = SingleInstance::get_instance();
    }
} // namespace singinst

// namespace sing_inhe
// {

//     class SingletonBase
//     {
//     public:
//         // Disable copy constructor and assignment operator
//         SingletonBase(const SingletonBase &) = delete;
//         SingletonBase &operator=(const SingletonBase &) = delete;

//     protected:
//         // Make constructor and destructor protected to allow inheritance
//         SingletonBase() = default;
//         virtual ~SingletonBase() = default;

//         // Method to check and handle instance creation for derived classes
//         template <typename T>
//         static T &getInstance()
//         {
//             static std::once_flag initFlag;
//             std::call_once(initFlag, []
//                            { T::s_instance.reset(new T()); });

//             return *T::s_instance;
//         }
//         static std::unique_ptr<int> s_instance;

//     private:
//         // Static member to hold the single instance of a derived class
//         template <typename T>
//         struct SingletonHolder
//         {
//             static std::unique_ptr<T> s_instance;
//         };
//     };

//     std::unique_ptr<int> SingletonBase::s_instance = nullptr;

//     template <typename T>
//     std::unique_ptr<T> SingletonBase::SingletonHolder<T>::s_instance = nullptr;

//     class DerivedSingleton : public SingletonBase
//     {
//     public:
//         static DerivedSingleton &getInstance()
//         {
//             return SingletonBase::getInstance<DerivedSingleton>();
//         }

//         void doSomething()
//         {
//             std::cout << "DerivedSingleton instance doing something" << std::endl;
//         }

//     private:
//         // Private constructor to avoid creating multiple instances
//         DerivedSingleton() = default;
//         friend SingletonBase; // Grant access to SingletonBase to call the private constructor
//     };

//     void test_1()
//     {
//         // Get the instance and call the 'doSomething' function
//         DerivedSingleton::getInstance().doSomething();
//     }

// } // namespace sing_inhe

namespace temp_sing
{
    template <typename T>
    class Singleton final
    {
    public:
        static T &getInstance()
        {
            static T instance;
            return instance;
        }

        Singleton(const Singleton &) = delete;
        Singleton &operator=(const Singleton &) = delete;

    private:
        Singleton() = default;
        virtual ~Singleton() = default;
    };
} // namespace temp_sing

int main(int argc, char *argv[])
{
    singinst::test_1();

    return 0;
}