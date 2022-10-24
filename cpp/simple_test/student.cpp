#include <iostream>

using namespace std;

class Student
{
	private:
		string name;
		unsigned short age;
		unsigned short score;

	public:
		static int stu_cnt;
		Student(string name, unsigned short age, unsigned short score);
		void intro();

};

Student::Student(string name, unsigned short age, unsigned short score)
{
	this->name = name;
	this->age = age;
	this->score = score;
}

void Student::intro()
{
	cout << "name: " << name << ", age: " << age << ", score: " << score << endl;
}

int main()
{
	Student stu = Student("Lisa", 15, 88);
	//Student stu("Lisa", 15, 88);
	stu.intro();

	return 0;
}
