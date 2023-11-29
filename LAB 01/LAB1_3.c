#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct employee
{
    int Empid;
    char name[20];
    char desig[20];
    int salary;
    int da;
    int hra;
};
int main()
{
    int n;
    printf("Enter no.of employees: ");
    scanf("%d", &n);
    struct employee e[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d Employee  information:\n", i + 1);
        fflush(stdin);
        printf("Enter the Employee ID: ");
        scanf("%d", &e[i].Empid);
        fflush(stdin);
        printf("Enter the Name: ");
        gets(e[i].name);
        fflush(stdin);
        printf("Enter the Designation: ");
        gets(e[i].desig);
        printf("Enter the Salary: ");
        scanf("%d", &e[i].salary);
        printf("Enter HRA: ");
        scanf("%d", &e[i].hra);
        printf("Enter DA : ");
        scanf("%d", &e[i].da);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Employee Information: \n");
        printf("Name: ");
        puts(e[i].name);
        printf("Designation: ");
        puts(e[i].desig);
        printf("Basic Salary : %d\n", e[i].salary);
        printf("HRA : %d\n", e[i].hra);
        printf("DA : %d\n", e[i].da);
        float gross = e[i].salary * e[i].da;
        gross = gross / 100;
        float sal = (e[i].hra * e[i].salary);
        sal = sal / 100;
        gross = gross + sal;
        printf("Gross Salary : %.2f\n", gross + e[i].salary);
    }

    return 0;
}