#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*******************************************************************************
 * List preprocessing directives - you may define your own.
*******************************************************************************/
#define MAX_COMPANY_SIZE 5
#define MAX_NAME_SIZE 11
/*******************************************************************************
 * List structs - you may define struct date_time and struct flight only. Each
 * struct definition should have only the fields mentioned in the assignment
 * description.
*******************************************************************************/
struct date{
    unsigned int day;
    unsigned int month;
    unsigned int year;
};
typedef struct date date_t;

struct employee{
    char name[MAX_NAME_SIZE];
    date_t birthday;
    float fte;
    unsigned int level;
};
typedef struct employee employee_t;
employee_t list[MAX_COMPANY_SIZE];
/*******************************************************************************
 * Function prototypes - do NOT change the given prototypes. However you may
 * define your own functions if required.
*******************************************************************************/
int main(void);
void printMenu(void);
void addEmployee(void);
void deleteLast(void);
void displayEmployee(void);
char dbFileName[] = "database";
void saveDatabase(char dbFileName[]);
int readDatabase(char dbFileName[]);
unsigned int companySize = 0;

int main(void){
    int choice = 0;
    while (choice != 6){
        printMenu();
        scanf("%d", &choice);
        switch (choice){
            case 1:
                addEmployee();
                break;
            case 2:
                deleteLast();
                break;
            case 3:
                displayEmployee();
                break;
            case 4:
                saveDatabase(dbFileName);
                break;
            case 5:
                readDatabase(dbFileName);
                break;
            default:
            if (choice != 6){
                printf("Invalid choice.");
            }
            break;
        }
    }
    return 0;
}

void printMenu(void){
    printf("\n\n"
     "1. add employee\n"
     "2. delete last employee\n"
     "3. display employee list\n"
     "4. save the employee list to the database\n"
     "5. read the employee list from the database\n"
     "6. exit the program\n"
     "Enter your choice>\n");
}

void addEmployee(void){
    while (companySize < MAX_COMPANY_SIZE) {
    printf("Enter name>");
    scanf("%s", list[companySize].name);
    int nameSize = strlen(list[companySize].name);
    while (nameSize < MAX_NAME_SIZE) {
        printf("Enter birthday: day>");
        scanf("%u", &list[companySize].birthday.day);
        while (list[companySize].birthday.day >= 1 && list[companySize].birthday.day <= 31){
            printf("Enter birthday: month>");
            scanf("%u", &list[companySize].birthday.month);
            while (list[companySize].birthday.month >= 1 && list[companySize].birthday.month <= 12){
                printf("Enter birthday: year>");
                scanf("%u", &list[companySize].birthday.year);
                while (list[companySize].birthday.year >= 1800 && list[companySize].birthday.year <= 2017){
                    printf("Enter FTE>");
                    scanf("%f", &list[companySize].fte);
                    while (list[companySize].fte >=  0.0 && list[companySize].fte <= 1.0){
                        printf("Enter level>");
                        scanf("%u", &list[companySize].level);
                        while (list[companySize].level >= 7 && list[companySize].level <= 18){
                            companySize++;
                            break; // 현재 while 루프를 탈출하고 상위 루프로 돌아간다.
                        }
                        printf("Invalid level.\n");
                    }
                    printf("Invalid FTE.\n");
                    break; // 현재 while 루프를 탈출하고 상위 루프로 돌아간다.
                }
                printf("Invalid year.\n");
                break; // 현재 while 루프를 탈출하고 상위 루프로 돌아간다.
            }
            printf("Invalid month.\n");
            break; // 현재 while 루프를 탈출하고 상위 루프로 돌아간다.
        }
        printf("Invalid day.\n");
        break; // 현재 while 루프를 탈출하고 상위 루프로 돌아간다.
    }
    printf("Name is too long.\n");
    break; // 현재 while 루프를 탈출하고 상위 루프로 돌아간다.
}
printf("Maximum company size.\n");
}

void deleteLast(void){
    if (companySize > 0){
        companySize--;
    } else {
        printf("List is empty");
    }
}

void displayEmployee(void){
    if(companySize == 0){
            printf("List is empty");
        } else {
            printf("%-10s %-10s %-5s %-2s\n", "Name", "Birthday", "FTE", "Level");
            printf("%-10s %-10s %-5s %-2s\n", "----------", "----------", "-----", "-----");
            int i = 0;
            for(i = 0; i < companySize; i++){
            printf("%-10s %02u-%02u-%04u %0.3f %02u\n", list[i].name, list[i].birthday.day, list[i].birthday.month, list[i].birthday.year, list[i].fte, list[i].level);
        }
    }
}

void saveDatabase(char dbFileName[]){
    FILE *data = fopen(dbFileName, "w");

    if(companySize < 1) {
        printf("No employee to save.\n");
    } else {
        int j = 0;
        for (j = 0; j < companySize; j++) {
            fprintf(data, "%-10s %u %u %u %f %u\n", list[j].name, list[j].birthday.day, list[j].birthday.month, list[j].birthday.year,list[j].fte, list[j].level);
        }
    }
    fclose(data);
}

int readDatabase(char dbFileName[]){
    FILE *data = fopen(dbFileName, "r");

    if (data == NULL) {
        printf("No data to read.\n");
    } else {
        int count = 0;
        while (!feof(data) && (count <= MAX_COMPANY_SIZE)) {
            fscanf(data, "%s %u-%u-%u %f %u\n", list[count].name, &list[count].birthday.day, &list[count].birthday.month, &list[count].birthday.year,&list[count].fte, &list[count].level);
            count++;
        }
        count--;
    }
    fclose(data);
    return 0;
}
