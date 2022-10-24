#include <iostream>

using namespace std;

struct Student
{
	Student(string name, int age, float score);
	void show();
	string m_name;
	int m_age;
	float m_score;
};

Student::Student(string name, int age, float score): m_name(name), m_age(age), m_score(score){ }

void Student::show()
{
	cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}

int main(){
	Student stu("小明", 15, 92.5f);
	stu.show();

	Student *pstu = new Student("李华", 16, 96);
	pstu -> show();

	return 0;
}
