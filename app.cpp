#include <iostream>   // для cout и cin
#include <string>     // чтобы использовать string для имени сотрудника
#include <vector>     // vector нужен, потому что бонусов и вычетов может быть несколько
#include <iomanip>    // для setw, setprecision и красивого вывода
#include <limits>
#include <fstream>

//s\first try of gitpush
// trying git clone

using namespace std;

enum Commands {
    EXIT = 0,
    ADD_EMPLOYEE = 1,
    ADD_BONUS,
    ADD_DEDUCTION,
    DISPLAY_ALL,
    HIGHEST_EARNER,
    TOTAL_PAYROLL,
    DISPLAY_PAYSLIP
}; 
class Employee {
private:
    string name;
    int id;
    double baseSalary;
    vector<double> bonuses;
    vector<double> deductions;

public:
    Employee(string n, int i, double s) : name(n), id(i), baseSalary(s) {} // FIXED stray 60

    string getName() const { return name; }
    int getId() const { return id; }

    void addBonus(double b) {
        // бонус должен быть положительным, иначе зарплата будет считаться неправильно
        if (b > 0) bonuses.push_back(b);
        else cout << "Warning: Bonus amount must be positive!\n";
    }

    void addDeduction(double d) {
        if (d > 0) deductions.push_back(d);
        else cout << "Warning: Deduction amount must be positive!\n";
    }

    double netSalary() const {
        double totalBonuses = 0;
        double totalDeductions = 0;

        // считаем сумму всех бонусов
        for (double b : bonuses) totalBonuses += b;

        // считаем сумму всех вычетов
        for (double d : deductions) totalDeductions += d;

        return baseSalary + totalBonuses - totalDeductions;
    }

    void displayPaySlip() const {
        cout << "\n" << setfill('=') << setw(40) << "=" << setfill(' ') << endl;
        cout << left << setw(25) << "Employee Name:" << right << setw(15) << name << endl;
        cout << left << setw(25) << "Employee ID:" << right << setw(15) << id << endl;

        cout << fixed << setprecision(2);

        cout << left << setw(25) << "Base Salary:" << right << setw(15) << baseSalary << endl;
        cout << left << setw(25) << "Net Monthly Salary:" << right << setw(15) << netSalary() << endl;

        cout << setfill('=') << setw(40) << "=" << setfill(' ') << endl;
    }

    friend ostream& operator<<(ostream& os, const Employee& e) {
        // перегрузка << нужна, чтобы удобно выводить сотрудника через cout
        os << "ID: " << e.id
           << "  Name: " << left << setw(15) << e.name
           << right << "  Net: $" << fixed << setprecision(2) << e.netSalary();
        return os;
    }
};

class Payroll {
private:
    vector<Employee> employees;
    int nextId = 1; // auto ID

    void saveToFile() {
        ofstream file("employees.txt");
        for (auto &e : employees) {
            file << e.getId() << " " << e.getName() << " " << e.netSalary() << "\n";
        }
    }

public:
    bool addEmployee(string name, double salary) {
        if (name.empty()) {
            cout << "Name cannot be empty!\n";
            return false;
        }

        Employee e(name, nextId++, salary);
        employees.push_back(e);
        saveToFile();
        return true;
    }

    Employee* findById(int id) {
        for (auto& employee : employees) {
            if (employee.getId() == id) {
                return &employee;
            }
        }
        cout << "Employee with this ID does not exist.\n";
        return nullptr;
    }

    const Employee* highestEarner() const {
        if (employees.empty()) return nullptr;

        int highestIdx = 0;

        for (size_t i = 1; i < employees.size(); i++) {
            if (employees[i].netSalary() > employees[highestIdx].netSalary()) {
                highestIdx = i;
            }
        }

        return &employees[highestIdx];
    }

    void displayAll() const {
        if (employees.empty()) {
            cout << "The payroll system is currently empty.\n";
            return;
        }

        for (const auto& e : employees) {
            cout << e << endl;
        }
    }

    double totalPayroll() const {
        double total = 0;
        for (const auto& e : employees) total += e.netSalary();
        return total;
    }
};

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Payroll companyPayroll;
    int choice;

    do {
        cout << "\n===== Payroll Menu =====\n";
        cout << "1. Add employee\n";
        cout << "2. Add bonus\n";
        cout << "3. Add deduction\n";
        cout << "4. Display all employees\n";
        cout << "5. Display highest earner\n";
        cout << "6. Display total payroll\n";
        cout << "7. Display employee payslip\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            clearInput();
            continue;
        }

        switch (choice) {

        case ADD_EMPLOYEE: {
            string name;
            double salary;

            cout << "Enter employee name: ";
            cin >> ws;
            getline(cin, name);

            cout << "Enter base salary: ";
            cin >> salary;

            companyPayroll.addEmployee(name, salary);
            break;
        }

        case ADD_BONUS: {
            int id;
            double bonus;

            cout << "Enter ID: ";
            cin >> id;

            Employee* e = companyPayroll.findById(id);
            if (e) {
                cout << "Bonus: ";
                cin >> bonus;
                e->addBonus(bonus);
            }
            break;
        }

        case ADD_DEDUCTION: {
            int id;
            double d;

            cout << "Enter ID: ";
            cin >> id;

            Employee* e = companyPayroll.findById(id);
            if (e) {
                cout << "Deduction: ";
                cin >> d;
                e->addDeduction(d);
            }
            break;
        }

        case DISPLAY_ALL:
            companyPayroll.displayAll();
            break;

        case HIGHEST_EARNER: {
            const Employee* e = companyPayroll.highestEarner();
            if (e) cout << *e << endl;
            else cout << "No employees.\n";
            break;
        }

        case TOTAL_PAYROLL:
            cout << "Total: " << companyPayroll.totalPayroll() << endl;
            break;

        case DISPLAY_PAYSLIP: {
            int id;
            cout << "Enter ID: ";
            cin >> id;

            Employee* e = companyPayroll.findById(id);
            if (e) e->displayPaySlip();
            break;
        }

        case EXIT:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != EXIT);

    return 0;
}