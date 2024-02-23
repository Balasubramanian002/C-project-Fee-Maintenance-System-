#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50
int estimated_reven = 0;

// Structure to represent a student
struct Student {
    char name[50];
    int rollNumber;
    float tuitionFee;
    float examFee;
    float totalfee;
    int paymentstate;
};

struct Student students[MAX_STUDENTS];
int numStudents = 0;

// Function to add a new student
void addStudent() {
    if (numStudents < MAX_STUDENTS) {
        printf("Enter the name of the new student: ");
        scanf("%s", students[numStudents].name);

        printf("Enter the roll number of the student: ");
        scanf("%d", &students[numStudents].rollNumber);

        printf("Enter the tuition fee for the student: ");
        scanf("%f", &students[numStudents].tuitionFee);

        printf("Enter the exam fee for the student: ");
        scanf("%f", &students[numStudents].examFee);
        estimated_reven = students[numStudents].examFee + students[numStudents].tuitionFee;
        numStudents++;
        printf("Student added successfully.\n");
    } else {
        printf("Maximum number of students reached.\n");
    }
}

// Function to delete a student based on roll number
void deleteStudent(int rollNumber) {
    int i, found = 0;

    for (i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            found = 1;
            break;
        }
    }

    if (found) {
        // Shift remaining elements to fill the gap
        for (int j = i; j < numStudents - 1; j++) {
            students[j] = students[j + 1];
        }
        numStudents--;

        printf("Student with Roll Number %d deleted successfully.\n", rollNumber);
    } else {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}

// Function to display billing information for all students
void displayStudentData(int rollNumber) {
    int i, found = 0;

    for (i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            found = 1;
            break;
        }
    }

    if (found) {
        float totalFee = students[i].tuitionFee + students[i].examFee;
        printf("\nStudent Data for Roll Number %d:\n", rollNumber);
        printf("Student Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Tuition Fee: Rs.%.2f\n", students[i].tuitionFee);
        printf("Exam Fee: Rs.%.2f\n", students[i].examFee);
        students[i].totalfee=students[i].examFee+students[i].tuitionFee;
        printf("Fee to be paid: Rs.%.2f\n", students[i].totalfee);
        printf("---------------------------\n");
    } else {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}



void expenditure() {
    int celeb=10000,maintenance=50000,Sfortech=120000,sfornontech=60000;
    int total=celeb+maintenance+Sfortech+sfornontech;
    printf("\n-------------------EXPENDITURE-----------------------");
    printf("\nYearly maintenance Costs:%d",maintenance);
    printf("\nYearly celebration Activities spends:%d",celeb);
    printf("\nSalary for teaching staffs:%d",Sfortech);
    printf("\nSalary for Non teaching staffs:%d",sfornontech);
    printf("\nRevenue Generated:%d",estimated_reven);
    if(estimated_reven==0)
    {
        printf("\nRaise Announcement for fee collection");
    }
    if(estimated_reven>0 && estimated_reven<total)
    {
        printf("\nStill fees collection lags");
    }
    if(estimated_reven==total)
    {
        printf("\nFees collection is over");
    }
}
void Feepayment(int rollNumber,int amount)
{
    int i, found = 0;
    int temp;
    for (i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            found = 1;
            
            break;
        }
    }
    temp=(students[i].totalfee)-amount;
    students[i].totalfee=temp;
    if (found) {
        
        printf("\nFee of %d is successfully paid",amount);

    } else {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}

int main() {
    int choice;

    do {
        printf("\nSchool Billing System Menu:\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Billing Information\n");
        printf("4. Expenditure\n");
        printf("5. Fee payment\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        int rollNumber,amount;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                 printf("Enter the roll number to delete: ");
                    scanf("%d", &rollNumber);
                    deleteStudent(rollNumber);
                 break;
            case 3:
                printf("Enter the roll number to display data: ");
                scanf("%d", &rollNumber);
                displayStudentData(rollNumber);
                break;
            case 4:
                expenditure();
                break;

            case 5:
                printf("Enter the roll number: ");
                scanf("%d", &rollNumber);
                printf("\nEnter the amount to be paid:");
                scanf("%d",&amount);
                Feepayment(rollNumber,amount);
                break;

            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 6);

    return 0;
}
