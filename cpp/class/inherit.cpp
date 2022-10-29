#include <iostream>

namespace inherit
{
	class Player
	{
	public:
		Player(std::string name = "", unsigned short age = 0) : name_(name), age_(age)
		{
			std::cout << typeid(*this).name() << "constructor" << std::endl;
		}
		virtual void self_induc() { std::cout << "this is a Player\n"; }
		virtual void display() { std::cout << "name = " << name_ << ", age = " << age_ << std::endl; }
		virtual void display(const std::string &msg) { std::cout << "name = " << name_ << ", age = " << age_ << ", msg = " << msg << std::endl; }

	private:
		std::string name_;
		unsigned short age_;
	};

	class SoccorPlayer : public Player
	{
		using Player::display;
		using Player::Player;

	public:
		// SoccorPlayer(std::string name = "", unsigned short age = 0) : name_(name), age_(age)
		// {
		// 	std::cout << typeid(*this).name() << "constructor" << std::endl;
		// }
		virtual void self_induc() { std::cout << "this is a soccor Player\n"; }
		virtual void display()
		{
			std::cout << "name = " << name_ << ", age = " << age_ << std::endl;
		}

	private:
		std::string name_;
		unsigned short age_;
	};

	class basketballPlayer : public Player
	{
	public:
		basketballPlayer(std::string name = "", unsigned short age = 0) : name_(name), age_(age)
		{
			std::cout << typeid(*this).name() << "constructor" << std::endl;
		}
		virtual void self_induc() { std::cout << "this is a basketball Player\n"; }

	private:
		std::string name_;
		unsigned short age_;
	};

	void test()
	{
		Player *p = new SoccorPlayer("Messi", 35);
		p->self_induc();

		return;
	}

} // namespace inherit

int main()
{
	inherit::test();

	return 0;
}