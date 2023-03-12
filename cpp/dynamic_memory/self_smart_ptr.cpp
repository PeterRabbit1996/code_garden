#include <iostream>
#include <memory>

// namespace self_smart_ptr
// {
// 	template <typename T>
// 	class smart_ptr
// 	{
// 		using value_type = T;
// 		friend void swap(smart_ptr<T> &sp1, smart_ptr<T> &sp2);

// 	public:
// 		smart_ptr()
// 		{
// 			t_ = new T;
// 			std::shared_ptr<int> t;
// 			ref_count = new size_t;
// 			*ref_count = 1;
// 		}

// 		smart_ptr(const smart_ptr &sp)
// 		{
// 			ref_count = sp.ref_count;
// 			t_ = sp.t_;
// 			++(*ref_count);
// 		}

// 		smart_ptr &operator=(const smart_ptr &sp)
// 		{

// 			++*sp.ref_count;
// 			if (--*ref_count == 0)
// 			{
// 				lock.unlock();
// 				delete ref_count;
// 			}

// 			ref_count = sp.ref_count;
// 			t_ = sp.t_;

// 			return *this;
// 		}

// 		~smart_ptr()
// 		{
// 			if (--*ref_count == 0)
// 			{
// 				lock.unlock();
// 				delete ref_count;
// 			}
// 		}

// 	private:
// 		T *t_;
// 		size_t *ref_count;
// 	};

// 	template <typename T>
// 	inline void swap(smart_ptr<T> &sp1, smart_ptr<T> &sp2)
// 	{
// 		using std::swap;
// 		swap(sp1.t_, sp2.t_);
// 		swap(sp1.ref_count, sp2.ref_count);
// 		return;
// 	}

// } // namespace self_smart_ptr

int main()
{

	return 0;
}
