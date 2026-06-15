# Employee Payroll Management System

A console-based Employee Payroll Management System written in C++ that demonstrates object-oriented programming principles, data management using vectors, operator overloading, and payroll calculations.

## Overview

This application allows a company to manage employee payroll records, including:

* Adding new employees
* Recording bonuses and deductions
* Calculating net salaries
* Generating individual payslips
* Viewing all employee records
* Identifying the highest-paid employee
* Calculating total company payroll

The project was developed as a practical implementation of C++ classes, encapsulation, vectors, loops, and formatted output.

---

## Features

### Employee Management

* Create employee records with:

  * Name
  * Employee ID
  * Base salary

### Payroll Processing

* Add multiple bonuses to an employee
* Add multiple deductions to an employee
* Automatically calculate net salary

### Reporting

* Display individual employee payslips
* View all employees in the payroll system
* Generate a complete payroll report
* Show total company payroll expenses
* Find the highest-earning employee

### Data Validation

* Prevents negative bonus values
* Prevents negative deduction values
* Handles searches for non-existent employee IDs

---

## Technologies Used

* C++
* Standard Template Library (STL)

  * `vector`
  * `string`
  * `iomanip`
* Object-Oriented Programming (OOP)

---

## Class Structure

### Employee Class

Represents an individual employee.

#### Attributes

* `name`
* `id`
* `baseSalary`
* `bonuses`
* `deductions`

#### Methods

* `addBonus()`
* `addDeduction()`
* `netSalary()`
* `displayPaySlip()`

### Payroll Class

Manages a collection of employees.

#### Methods

* `addEmployee()`
* `findById()`
* `displayAll()`
* `totalPayroll()`
* `highestEarner()`

---

## Menu Options

When the program starts, users can choose from the following options:

1. Add New Employee
2. Add Bonus or Deduction
3. Display Individual Pay Slip
4. Display All Employees
5. Show Highest Earner
6. Show Total Company Payroll
7. Exit

---

## Example Workflow

1. Add an employee:

   * Name: John Smith
   * ID: 101
   * Salary: 5000

2. Add a bonus:

   * Employee ID: 101
   * Bonus: 500

3. Add a deduction:

   * Employee ID: 101
   * Deduction: 200

4. Net salary calculation:

Net Salary = Base Salary + Bonuses − Deductions

Net Salary = 5000 + 500 − 200 = 5300

---

## Learning Objectives

This project demonstrates:

* Object-Oriented Programming
* Class design and encapsulation
* Constructor initialization lists
* Friend functions
* Operator overloading (`<<`)
* Dynamic data storage using vectors
* Input validation
* Formatted console output
* Searching and aggregation algorithms

---

## Future Improvements

Potential enhancements include:

* File storage and data persistence
* Employee removal and editing
* Monthly payroll history
* Department management
* Tax calculations
* GUI implementation
* Database integration

---

## Author
Muravyeva Aida
Developed as a C++ payroll management project for Computer Science course at Warsaw University of Technology.
