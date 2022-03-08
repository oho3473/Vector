#include "Student.h"

void Student::Print()
{
	std::cout << "(" << mNumber << ")" << mName << " : " << mScore << std::endl;
}

void AddStudent(std::vector<Student>& vector)
{
	std::cout << "번호, 이름, 점수 : ";

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
			std::cout << "중복된 번호입니다\n";
			return;
		}


		/*for (auto& elem : vector)
		{
			if (elem.mNumber == newStudent.mNumber)
			{
				std::cout << "중복된 번호입니다" << std::endl;
				return;
			}
		}*/
		vector.push_back(newStudent);
	}
	else
	{
		std::cout << "잘못된 입력입니다" << std::endl;
	}
}

void RemoveStudent(std::vector<Student>& vector)
{
	std::cout << "삭제할 번호 입력 : ";

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
		std::cout << "잘못된 입력입니다" << std::endl;
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
	std::cout << "총점 : " << total << ", 평균 : " << total / vector.size() << std::endl;
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
