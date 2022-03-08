#include<iostream>
#include"Student.h"

void PrintInfo()
{
	std::cout << "1. 학생 추가\n";
	std::cout << "2. 학생 제거(번호)\n";
	std::cout << "3. 전체 학생 출력\n";
	std::cout << "4. 평균, 총점 출력\n";
	std::cout << "5. 평균 이상 학생 출력\n";
	std::cout << "6. 종료\n";
	std::cout << ">>";
}



int main()
{
	std::vector<Student> student = { 
		{1,"Kim",80},
		{2,"Lee",20},
		{3,"Park",50},
		{4,"choi",30} };

	bool Exit{ false };

	while (!Exit)
	{
		PrintInfo();

		int command;
		std::cin >> command;

		switch (command)
		{
			case 1:
				AddStudent(student);
				break;
			case 2:
				RemoveStudent(student);
				break; 
			case 3:
				PrintStudent(student);
				break;
			case 4:
				PrintScoreInfo(student);
				break;
			case 5:
				PrintOverAverage(student);
				break;
			case 6:
				Exit = true;
				break;
		}
			
	}
}