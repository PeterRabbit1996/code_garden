#include <iostream>
#include <string>

namespace constructor
{
	class TE
	{
		friend std::ostream &operator<<(std::ostream &os, const TE &te);

	public:
		TE(std::string name = std::string(""), unsigned short age = 0, char *pet_phrase = "") : name_(name), age_(age)
		{
			auto size = strlen(pet_phrase) + 1;
			pet_phrase_ = new char[size];
			strncpy(pet_phrase_, pet_phrase, size);
		}
		TE(const TE &te) : name_(te.name_), age_(te.age_)
		{
			auto size = strlen(te.pet_phrase_) + 1;
			pet_phrase_ = new char[size];
			strncpy(pet_phrase_, te.pet_phrase_, size);
		}

		TE &operator=(const TE &te)
		{
			name_ = te.name_;
			age_ = te.age_;

			// copy to temp
			auto size = strlen(te.pet_phrase_) + 1;
			auto pet_phrase__ = new char[size];
			strncpy(pet_phrase__, te.pet_phrase_, size);

			// copy to self
			delete pet_phrase_;
			pet_phrase_ = new char[size];
			strncpy(pet_phrase_, pet_phrase__, size);

			// delete temp
			delete pet_phrase__;

			return *this;
		}

		TE(TE &&te)
		noexcept : name_(te.name_), age_(te.age_)
		{
			auto size = strlen(te.pet_phrase_) + 1;
			pet_phrase_ = new char[size];
			strncpy(pet_phrase_, te.pet_phrase_, size);

			te.pet_phrase_ = nullptr;
		}

		TE &operator=(TE &&te) noexcept
		{
			if (this != &te)
			{
				delete pet_phrase_;
				pet_phrase_ = nullptr;

				name_ = te.name_;
				age_ = te.age_;

				auto size = strlen(te.pet_phrase_) + 1;
				pet_phrase_ = new char[size];
				strncpy(pet_phrase_, te.pet_phrase_, size);

				te.pet_phrase_ = nullptr;
			}

			return *this;
		}

		~TE()
		{
			delete pet_phrase_;
			pet_phrase_ = nullptr;
		}

	private:
		std::string name_;
		unsigned short age_;
		char *pet_phrase_;
	};

	std::ostream &operator<<(std::ostream &os, const TE &te)
	{
		os << "name = " << te.name_ << ", age = " << te.age_ << ", pet phrase = " << te.pet_phrase_ << std::endl;
		return os;
	}

	void test1()
	{
		TE t1("a", 10, "the best");
		std::cout << t1;

		t1.operator=(TE("b", 100, "the better")); // equal to te = TE("b", 100)
		std::cout << t1;

		TE t2 = t1;
		std::cout << t2;

		TE t3;
		std::cout << t3;

		return;
	}

} // namespace constructor

int main()
{
	constructor::test1();

	return 0;
}