#include <stdio.h>
#include "SDB.h"
void SDB_APP() {
    int choice;
    do {
        printf("\n1. To add entry, enter 1\n"
               "2. To get used size in database, enter 2\n"
               "3. To read student data, enter 3\n"
               "4. To get the list of all student IDs, enter 4\n"
               "5. To check if ID exists, enter 5\n"
               "6. To delete student data, enter 6\n"
               "7. To check if database is full, enter 7\n"
               "8. To exit, enter 0\n");

        scanf("%d", &choice);

        switch (choice) {
            case 0:
    printf("*************************************************************************************************\n");
    printf("***                                                                                           ***\n");
    printf("***---------------------------------->THANKS FOR USING MY PROGRAMME<--------------------------***\n");
    printf("***                                     HAVE A NICE DAY                                       ***\n");
    printf("***                                                                                           ***\n");
    printf("*************************************************************************************************\n");
                printf("Exiting program.\n");
                break;
            case 1: {
                uint32 id, year, c1_id, c1_grade, c2_id, c2_grade, c3_id, c3_grade;
                printf("Enter student ID: ");
                scanf("%u", &id);
                printf("Enter student year: ");
                scanf("%u", &year);
                printf("Enter course 1 ID: ");
                scanf("%u", &c1_id);
                printf("Enter course 1 grade: ");
                scanf("%u", &c1_grade);
                printf("Enter course 2 ID: ");
                scanf("%u", &c2_id);
                printf("Enter course 2 grade: ");
                scanf("%u", &c2_grade);
                printf("Enter course 3 ID: ");
                scanf("%u", &c3_id);
                printf("Enter course 3 grade: ");
                scanf("%u", &c3_grade);

                if (SDB_AddEntry(id, year, c1_id, c1_grade, c2_id, c2_grade, c3_id, c3_grade)) {
                    printf("Entry added successfully.\n");
                } else {
                    printf("Failed to add entry.\n");
                }
                break;
            }
            case 2:
                printf("Number of students in the database: %u\n", SDB_GetUsedSize());
                break;
            case 3: {
                uint32 id;
                printf("Enter student ID: ");
                scanf("%u", &id);
                SDB_ReadEntry(id);
                break;
            }
            case 4: {
                uint8 count;
                uint32 list[MAX_STUDENTS];
                SDB_GetList(&count, list);
                printf("List of student IDs:\n");
                for (int i = 0; i < count; i++) {
                    printf("%u\n", list[i]);
                }
                break;
            }
            case 5: {
                uint32 id;
                printf("Enter student ID: ");
                scanf("%u", &id);
                if (SDB_IsIdExist(id)) {
                    printf("Student ID %u exists in the database.\n", id);
                } else {
                    printf("Student ID %u does not exist in the database.\n", id);
                }
                break;
            }
            case 6: {
                uint32 id;
                printf("Enter student ID to delete: ");
                scanf("%u", &id);
                SDB_DeleteEntry(id);
                break;
            }
            case 7:
                if (SDB_IsFull()) {
                    printf("Database is full.\n");
                } else {
                    printf("Database is not full.\n");
                }
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);
}
