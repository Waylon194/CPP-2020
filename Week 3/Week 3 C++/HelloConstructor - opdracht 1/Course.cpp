#include <iostream>
#include "Course.h"

Course::Course(const std::string& courseName, int capacity) {
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new std::string[capacity];
}

Course::Course(const Course& course) {
	numberOfStudents = course.getNumberOfStudents();
	this->courseName = course.courseName;
	this->capacity = course.capacity;
	//this->students = course.students;
	this->students = new std::string[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->students[i] = course.students[i];
	}
}

Course::~Course() {
	delete[] students;
}

std::string Course::getCourseName() const {
	return courseName;
}

void Course::addStudent(const std::string& name) {
	if (numberOfStudents == capacity)
	{
		capacity *= 2;
		std::string* newArray = new std::string[capacity];
		
		for (size_t i = 0; i < numberOfStudents; i++)
		{
			newArray[i] = this->students[i];
		}

		this->students = newArray;
	}

	students[numberOfStudents] = name;
	numberOfStudents++;
}

void Course::dropStudent(const std::string& name) {
	
	for (size_t i = 0; i < numberOfStudents; i++)
	{
		if (this->students[i].compare(name) == 0)
		{
			this->numberOfStudents--;
			this->students[i] = this->students[numberOfStudents];
			break;
		}
	}
}

std::string* Course::getStudents() const {
	return students;
}

int Course::getNumberOfStudents() const {
	return numberOfStudents;
}

void Course::clear()
{
	for (size_t i = 0; i < numberOfStudents; i++)
	{
		this->students[i].clear();
	}
	this->numberOfStudents = 0;
}