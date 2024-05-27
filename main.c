/*
* Title: Assignment #1 - Student Registration System
* Course: CST8234 C Language
* @Author: Jeffin Tom 041094535
* Lab Section: 011
* Professor: Veda Vasavi Erukulla
* Due date: 06/11/2023
* Submission date: 06/11/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "registration.h"


 #define MAX_STUDENTS 100
 #define MAX_COURSES 100
 #define COURSE_CODE_LENGTH 8

int main() {
    int studentIDs[MAX_STUDENTS];
    char courseCodes[MAX_COURSES][COURSE_CODE_LENGTH]; 
    char registrationTable[MAX_STUDENTS][MAX_COURSES];
    int numStudents, numCourses;

    printf("Welcome to the Student Registration System\n");

    // Prompt the user for the number of students and courses
    printf("Enter the number of students to register: ");
    scanf("%d", &numStudents);

    if (numStudents < 1 || numStudents > MAX_STUDENTS) {
        printf("Invalid number of students. Please enter a value between 1 and %d.\n", MAX_STUDENTS);
        return 1; // Exit the program with an error code
    }

    // Prompt the user to enter student IDs
    printf("Enter student IDs (5-digit integers):\n");
    for (int i = 0; i < numStudents; i++) {
    int studentID;
    int validInput = 0;

    while (!validInput) {
        printf("Enter the student index[%d] student id [5-digits]: ", i);

        if (scanf("%d", &studentID) != 1 || studentID < 10000 || studentID > 99999) {
            printf("Student ID must be a 5-digit integer. Please try again.\n");
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            studentIDs[i] = studentID;
            validInput = 1;
        }
    }
}


    // Prompt the user for the number of courses
    printf("Enter the number of courses offered: ");
    scanf("%d", &numCourses);

     if (numCourses < 1 || numCourses > MAX_COURSES) {
        printf("Invalid number of courses. Please enter a value between 1 and %d.\n", MAX_COURSES);
        return 1; // Exit the program with an error code
    }

printf("Enter course codes (3 alphabetic characters followed by 4 digits):\n");
for (int i = 0; i < numCourses; i++) {
    char inputCourseCode[COURSE_CODE_LENGTH];
    int validInput = 0;

    while (!validInput) {
        printf("Enter the course index[%d] course id [3-Alphas] [4-digits]: ", i);

        if (scanf("%7s", inputCourseCode) != 1 || strlen(inputCourseCode) != 7 ||
            !isalpha(inputCourseCode[0]) || !isalpha(inputCourseCode[1]) || !isalpha(inputCourseCode[2]) ||
            !isdigit(inputCourseCode[3]) || !isdigit(inputCourseCode[4]) || !isdigit(inputCourseCode[5]) || !isdigit(inputCourseCode[6])) {
            printf("Incorrect Course Id input [3-Alphas] [4-digits]. Please try again.\n");
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            strcpy(courseCodes[i], inputCourseCode);
            validInput = 1;
        }
    }
}

    int choice, studentID;
    int courseIndex;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Register a student into a course\n");
        printf("2. Drop a student from a course\n");
        printf("3. Display Registration table\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
              case 1:
                registerStudent(registrationTable, studentIDs, courseCodes, numStudents, numCourses, courseIndex);
                break;
            case 2:
                  dropStudent(registrationTable, studentIDs, courseCodes, numStudents, numCourses);
                break;
            case 3:
                // Display the registration table
                displayRegistrationTable(registrationTable, studentIDs, courseCodes, numStudents, numCourses);
                break;
            case 4:
                return 0;
                 printf("Exiting\n");
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}