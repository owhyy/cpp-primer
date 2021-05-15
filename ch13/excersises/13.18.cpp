
// The class will need to define its own versions of the copy-control members,
// because there can't be 2 different people with the same ID -> there has to be
// generated a new ID every time a new Employee is created, but the
// synthesized versions of the copy-control members do not increment the
// static member variable -> 2 people will have the same ID

#include <iostream>
#include <string>

class Employee {
  std::string employee_name_;
  static int ID_increment_;
  int employee_ID_;

public:
  Employee() { employee_ID_++; }
  Employee(const std::string &name) : employee_name_(name) {
    ID_increment_++;
    employee_ID_ = ID_increment_;
  }

  Employee(const Employee &);
  Employee &operator=(const Employee &);
  ~Employee() {}

  friend std::ostream &operator<<(std::ostream &stream, const Employee &e) {
    stream << e.employee_name_ << ' ' << e.employee_ID_ << '\n';
    return stream;
  }
};

int Employee::ID_increment_ = 0;

Employee::Employee(const Employee &orig) {
  employee_name_ = orig.employee_name_;
  ID_increment_++;
  employee_ID_ = ID_increment_;
}

Employee &Employee::operator=(const Employee &orig) {
  employee_name_ = orig.employee_name_;
  ID_increment_++;
  return *this;
  employee_ID_ = ID_increment_;
}

int main() {
  Employee e1("Joanne");
  Employee e2("Mike");
  Employee e3("Bob");
  Employee e5(e2);
  e5 = e3;
  std::cout << e1;
  std::cout << e2;
  std::cout << e3;
  std::cout << e5;
}
