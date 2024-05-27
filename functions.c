

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
#include <string.h>
#include "registration.h"


// Function to register a student into a course
/****************************************************************************
* Function Name: registerStudent
* Purpose: Registers a student into a course based on user input.
* Function in parameters:
*   - registrationTable: 2D array representing student registrations
*   - numStudents: Total number of students
*   - numCourses: Total number of courses
* Function out parameter: none
* Version: 1.0
* Author: Jeffin Tom
****************************************************************************/
void registerStudent(char registrationTable[][MAX_COURSES], int studentIDs[], char courseCodes[][COURSE_CODE_LENGTH], int numStudents, int numCourses, int courseIndex) {
    int studentID; // Declare studentID variable here

    // Validate course index

    // Print the list of student IDs
    printf("List of Student IDs:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Index %d\t%d\n", i, studentIDs[i]);
    }

    // Prompt for student index
    printf("Enter the Student's Id to register a course: ");
    scanf("%d", &studentID);

    // Check if the entered student ID exists in the studentIDs array
    int studentIndex = -1; // Initialize to an invalid index
    for (int i = 0; i < numStudents; i++) {
        if (studentIDs[i] == studentID) {
            studentIndex = i;
            break; // Student found
        }
    }

    if (studentIndex == -1) {
       printf("Student with ID %d not found. Please enter a valid student ID: %d\n", studentID, studentID);

    } else {
        // List available course IDs
        printf("List of Available Course IDs:\n");
        for (int i = 0; i < numCourses; i++) {
            printf("Index %d\t%s\n", i, courseCodes[i]);
        }
        // Prompt for course code
        printf("Enter the course id [3-Alphas] [4-digits]: ");
        char inputCourseCode[COURSE_CODE_LENGTH];
        scanf("%s", inputCourseCode);
        int courseIndex = -1;

        // Validate course code
        for (int i = 0; i < numCourses; i++) {
            if (strcmp(courseCodes[i], inputCourseCode) == 0) {
                courseIndex = i;
                break; // Course found
            }
        }

      if (courseIndex == -1) {
            printf("Course with code %s not found. Please enter a valid course code.\n", inputCourseCode);
        } else {
            if (registrationTable[studentIndex][courseIndex]) {
                printf("Student with ID %d is already registered in course %s.\n", studentID, inputCourseCode);
            } else {
                registrationTable[studentIndex][courseIndex] = true;
                printf("Registration Successful\n");
            }
        }
    }
}


// Function to display the registration table
/****************************************************************************
* Function Name: displayRegistrationTable
* Purpose: Displays the registration table showing student-course registrations.
* Function in parameters:
*   - registrationTable: 2D array representing student registrations
*   - numStudents: Total number of students
*   - numCourses: Total number of courses
* Function out parameter: None
* Version: 1.0
* Author: Jeffin Tom
****************************************************************************/
void displayRegistrationTable(char registrationTable[MAX_STUDENTS][MAX_COURSES], int studentIDs[MAX_STUDENTS], char courseCodes[MAX_COURSES][COURSE_CODE_LENGTH], int numStudents, int numCourses) {
    printf("Registration Table\n");
    printf("Registration Index\tStudent Id\tCourseId\tRegistrationStatus\n");

    int registrationIndex = 0; // Counter for registered students

    for (int studentIndex = 0; studentIndex < numStudents; studentIndex++) {
        int studentID = studentIDs[studentIndex];
        int registered = 0; // Flag to check if the student is registered in any course

        for (int courseIndex = 0; courseIndex < numCourses; courseIndex++) {
            char registrationStatus = ' '; // Initialize registrationStatus with a default value

          if (registrationTable[studentIndex][courseIndex] == 1) {
    registrationStatus = 'R';
    printf("%-25d%-18d%-21s%c\n", registrationIndex, studentID, courseCodes[courseIndex], registrationStatus);
    registered = 1;
    registrationIndex++; // Increment the index for registered students
} else if (registrationTable[studentIndex][courseIndex] == 'D') {
    registrationStatus = 'D';
    printf("%-25d%-18d%-21s%c\n", registrationIndex, studentID, courseCodes[courseIndex], registrationStatus);
    registered = -1;
    registrationIndex++;
}


        }
    }
}


// Function to drop a course for a student
/****************************************************************************
* Function Name: dropStudent
* Purpose: Drops a student from a course based on user input.
* Function in parameters:
*   - registrationTable: 2D array representing student registrations
*   - numStudents: Total number of students
*   - numCourses: Total number of courses
* Function out parameter: None
* Version: 1.0
* Author: Jeffin Tom
****************************************************************************/
void dropStudent(char registrationTable[][MAX_COURSES], int studentIDs[], char courseCodes[][COURSE_CODE_LENGTH], int numStudents, int numCourses) {
    displayRegistrationTable(registrationTable, studentIDs, courseCodes, numStudents, numCourses);

    printf("Please select the registration index to drop student registration: ");
    int dropIndex;
    scanf("%d", &dropIndex);

    if (dropIndex >= 0 && dropIndex < numStudents) {
        for (int courseIndex = 0; courseIndex < numCourses; courseIndex++) {
            if (registrationTable[dropIndex][courseIndex] == 1) {
                registrationTable[dropIndex][courseIndex] = 'D';
                break; // Exit the loop after the first 'R' course is dropped
            }
        }
        printf("Drop course successful\n");
    } else {
        printf("Invalid registration index. Please enter a valid index.\n");
    }

    // Display the updated registration table after dropping
    displayRegistrationTable(registrationTable, studentIDs, courseCodes, numStudents, numCourses);
}


   









    