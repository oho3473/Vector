#include "Student.h"

void Student::Print()
{
	std::cout << "(" << mNumber << ")" << mName << " : " << mScore << std::endl;
}

void AddStudent(std::vector<Student>& vector)
{
	std::cout << "��ȣ, �̸�, ���� : ";

	Student newStudent;

	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)
	{
		auto itr = std::find_if(vector.begin(), vector.end(),
			[&](auto& elem)->bool
			{
				return elem.mNumber == newStudent.mNumber; 
			});

		if (itr != vector.end())
		{
			std::cout << "�ߺ��� ��ȣ�Դϴ�\n";
			return;
		}


		/*for (auto& elem : vector)
		{
			if (elem.mNumber == newStudent.mNumber)
			{
				std::cout << "�ߺ��� ��ȣ�Դϴ�" << std::endl;
				return;
			}
		}*/
		vector.push_back(newStudent);
	}
	else
	{
		std::cout << "�߸��� �Է��Դϴ�" << std::endl;
	}
}

void RemoveStudent(std::vector<Student>& vector)
{
	std::cout << "������ ��ȣ �Է� : ";

	int num;
	if (std::cin >> num)
	{
		for (auto itr = vector.begin(); itr != vector.end(); itr++)
		{
			if (itr->mNumber == num)
			{
				vector.erase(itr);
				break;
			}
		}
	}
	else
	{
		std::cout << "�߸��� �Է��Դϴ�" << std::endl;
	}
}

void PrintStudent(std::vector<Student>& vector)
{
	for (auto& itr : vector)
	{
		itr.Print();
	}
}

void PrintScoreInfo(std::vector<Student>& vector)
{
	int total{ 0 };
	for (auto& elem : vector)
	{
		total += elem.mScore;
	}
	std::cout << "���� : " << total << ", ��� : " << total / vector.size() << std::endl;
}

void PrintOverAverage(std::vector<Student>& vector)
{
	int average{ 0 };
	for (auto& elem : vector)
	{
		average += elem.mScore;
	}

	average /= vector.size();

	for (auto& elem : vector)
	{
		if (elem.mScore >= average)
		{
			elem.Print();
		}
	}
}
