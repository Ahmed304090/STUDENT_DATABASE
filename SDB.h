#ifndef SDB_H
#define SDB_H

#include "STD.h"

#define MAX_STUDENTS 10  //define max number of students

// Define structure for a student
typedef struct Student {
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
    struct Student* next;
} student;

// Function prototypes
bool SDB_IsFull();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry(uint32 id, uint32 year, uint32 c1_id, uint32 c1_grade, uint32 c2_id, uint32 c2_grade, uint32 c3_id, uint32 c3_grade);
void SDB_DeleteEntry(uint32 id);
bool SDB_ReadEntry(uint32 id);
void SDB_GetList(uint8 *count, uint32 *list);
bool SDB_IsIdExist(uint32 id);

#endif /* SDB_H */
