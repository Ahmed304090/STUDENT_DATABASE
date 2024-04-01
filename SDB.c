#include "SDB.h"
#include <stdio.h>
#include <stdlib.h>

//  we write Global variables to be readable in whole project
static student* head = NULL;
static uint8 usedSize = 0;

// Function to check if the database is full   max = 10
bool SDB_IsFull() {
    return usedSize >= MAX_STUDENTS;
}

// Function to get the number of students in the database
uint8 SDB_GetUsedSize() {
    return usedSize;
}

// Function to add a new student entry to the database
bool SDB_AddEntry(uint32 id, uint32 year, uint32 c1_id, uint32 c1_grade, uint32 c2_id, uint32 c2_grade, uint32 c3_id, uint32 c3_grade) {
    if (SDB_IsFull()) {
        printf("Database is full. Cannot add new entry.\n");
        return 0;
    }

    // Create a new student node
    student* new_student = (student*)malloc(sizeof(student));
    if (new_student == NULL) {
        printf("  your data is not complete you Cannot add new entry.\n");
        return 0;
    }

    // Fill data for the new student
    new_student->Student_ID = id;
    new_student->Student_year = year;
    new_student->Course1_ID = c1_id;
    new_student->Course1_grade = c1_grade;
    new_student->Course2_ID = c2_id;
    new_student->Course2_grade = c2_grade;
    new_student->Course3_ID = c3_id;
    new_student->Course3_grade = c3_grade;
    new_student->next = NULL;

    // Add the new student to the end of the linked list
    if (head == NULL) {
        head = new_student;
    } else {
        student* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_student;
    }

    // Increment usedSize
    usedSize++;

    printf("Student with ID %d added successfully.\n", id);
    return 1;
}

// Function to delete a student entry from the database
void SDB_DeleteEntry(uint32 id) {
    if (head == NULL) {
        printf("Database is empty. Cannot delete entry.\n");
        return;
    }

    student* current = head;
    student* prev = NULL;

    // Traverse the linked list to find the student with the given ID
    while (current != NULL && current->Student_ID != id) {
        prev = current;
        current = current->next;
    }

    // If student with given ID is found, delete it
    if (current != NULL) {
        if (prev == NULL) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        printf("Student with ID %d deleted successfully.\n", id);
        usedSize--;
    } else {
        printf("Student with ID %d not found. Cannot delete.\n", id);
    }
}

// Function to read a student entry from the database
bool SDB_ReadEntry(uint32 id) {
    if (head == NULL) {
        printf("Database is empty. Cannot read entry.\n");
        return 0;
    }

    student* current = head;

    // Traverse the linked list to find the student with the given ID
    while (current != NULL && current->Student_ID != id) {
        current = current->next;
    }

    // If student with given ID is found, print its data
    if (current != NULL) {
        printf("Student ID: %d\n", current->Student_ID);
        printf("Student Year: %d\n", current->Student_year);
        printf("Course 1 ID: %d, Grade: %d\n", current->Course1_ID, current->Course1_grade);
        printf("Course 2 ID: %d, Grade: %d\n", current->Course2_ID, current->Course2_grade);
        printf("Course 3 ID: %d, Grade: %d\n", current->Course3_ID, current->Course3_grade);
        return 1;
    } else {
        printf("Student with ID %d not found.\n", id);
        return 0;
    }
}

// Function to get the list of all student IDs in the database
void SDB_GetList(uint8 *count, uint32 *list) {
    *count = 0;
    student* current = head;
    while (current != NULL) {
        list[(*count)++] = current->Student_ID;
        current = current->next;
    }
}

// Function to check if a student ID exists in the database
bool SDB_IsIdExist(uint32 id) {
    student* current = head;
    while (current != NULL) {
        if (current->Student_ID == id) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
