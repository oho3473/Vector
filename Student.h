#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

class Student
{
public:
	int mNumber;
	std::string mName;
	int mScore;

	void Print();
};

void AddStudent(std::vector<Student>& vector);
void RemoveStudent(std::vector<Student>& vector);
void PrintStudent(std::vector<Student>& vector);
void PrintScoreInfo(std::vector<Student>& vector);
void PrintOverAverage(std::vector<Student>& vector);