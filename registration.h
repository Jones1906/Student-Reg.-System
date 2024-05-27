/*
* Title: Assignment #1 - Student Registration System
* Course: CST8234 C Language
* @Author: Jeffin Tom 041094535
* Lab Section: 011
* Professor: Veda Vasavi Erukulla
* Due date: 06/11/2023
* Submission date: 06/11/2023
*/


#ifndef REGISTRATION_H
#define REGISTRATION_H

#define MAX_STUDENTS 100
#define MAX_COURSES 100
#define COURSE_CODE_LENGTH 8

#include <stdbool.h>

// Functions related to students
void registerStudent(char registrationTable[][MAX_COURSES], int studentIDs[], char courseCodes[][COURSE_CODE_LENGTH], int numStudents, int numCourses, int courseIndex);
void dropStudent(char registrationTable[][MAX_COURSES], int studentIDs[], char courseCodes[][COURSE_CODE_LENGTH], int numStudents, int numCourses);
void displayRegistrationTable(char registrationTable[][MAX_COURSES], int studentIDs[], char courseCodes[][COURSE_CODE_LENGTH], int numStudents, int numCourses);

#endif
