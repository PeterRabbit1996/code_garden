#include <iostream>

#define BUFF_SIZE	64

class Person
{
public:
	Person()
	{
		m_size = BUFF_SIZE;
		m_name = (char *)malloc(m_size);
	}
	~Person()
	{
		free(m_name);
	}
	Person& operator=(const Person &other)
	{
		memcpy((*this).m_name, other.m_name, m_size);
		return *this;
	};

	int getName(char *name, int *size)
	{
		if (*size < BUFF_SIZE)
			return -1;
		*size = m_size;
		memcpy(name, m_name, m_size);

		return 0;
	}
	int setName(char *name, int size)
	{
		if (size > BUFF_SIZE)
			return -1;
		memcpy(m_name, name, m_size);
		
		return 0;
	}

private:
	char *m_name;
	size_t m_size;
};

int main()
{
	char name[BUFF_SIZE] = "Jay";
	Person Jay;
	Jay.setName(name, BUFF_SIZE);

	Person Peter;
	Peter = Jay;
	memset(name, 0, BUFF_SIZE);
	int size = BUFF_SIZE;
	Peter.getName(name, &size);
	std::cout << "name = " << name << std::endl;

	return 0;
}