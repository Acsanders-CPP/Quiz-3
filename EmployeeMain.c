#include <string.h> 
#include <stdlib.h> 
#include "Employee.h"

int main(void){
  //defined in employeeSearchOne.c
  PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
  PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
  PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);
  PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char *phoneToFind);
  
  //defined in employeeTable.c
  extern Employee EmployeeTable[];
  extern const int EmployeeTableEntries;
  
  PtrToEmployee matchPtr; //Declaration
  
  matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);
  
  //Example not found
  if (matchPtr != NULL){
    printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
  }
  else{
    printf("Employee ID is NOT found in the record\n");
  }
  
  //Example found
  matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
  
  if (matchPtr != NULL){
    printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
  }
  else{
    printf("Employee Tony Bobcat is NOT found in the record\n");
  }

  //Example found
  matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.34);
  
  if (matchPtr != NULL){
    printf("Employee Dorris Perl is in record %d\n", matchPtr - EmployeeTable);
  }
  else{
    printf("Employee Dorris Perl is NOT found in the record\n");
  }

  //Example found
  matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-555-2749");
  
  if (matchPtr != NULL){
    printf("Employee Brain Height is in record %d\n", matchPtr - EmployeeTable);
  }
  else{
    printf("Employee Brian Height is NOT found in the record\n");
  }
  
  return EXIT_SUCCESS;
} 