#include <stdio.h>
struct Employee 
{
    int empId;
    char name[50];
    char designation[50];
    float basicSalary;
    float hraPercentage;
    float daPercentage;
};
float calculateGrossSalary(struct Employee emp) {
    float hra = (emp.hraPercentage / 100) * emp.basicSalary;
    float da = (emp.daPercentage / 100) * emp.basicSalary;
    return emp.basicSalary + hra + da;
}
int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
struct Employee employees[n];
for (int i = 0; i < n; i++) 
{
        printf("\nEnter details for Employee %d:\n", i + 1);        
        printf("Employee ID: ");
        scanf("%d", &employees[i].empId);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Designation: ");
        scanf("%s", employees[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basicSalary);
        printf("HRA Percentage: ");
        scanf("%f", &employees[i].hraPercentage);
        printf("DA Percentage: ");
        scanf("%f", &employees[i].daPercentage);
    }
    printf("\nEmployee Information with Gross Salary:\n");
    for (int i = 0; i < n; i++) {
        float grossSalary = calculateGrossSalary(employees[i]);
        printf("\nEmployee %d:\n", i + 1);
        printf("Emp ID: %d\n", employees[i].empId);
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2f\n", employees[i].basicSalary);
        printf("HRA Percentage: %.2f%%\n", employees[i].hraPercentage);
        printf("DA Percentage: %.2f%%\n", employees[i].daPercentage);
        printf("Gross Salary: %.2f\n", grossSalary);
    }
    return 0;
}
