#include <iostream>
#include <sstream>

#include "./classes/department/department.h"

Department getDepartmentFromLine(std::string line) {
  std::stringstream ss(line);
  std::string code;
  std::string name;
  std::string keyword;

  ss >> code;
  ss >> name;
  Department department(code, name);
  while (ss >> keyword) {
    department.addWord(keyword);
  }

  return department;
}

int main() {
  std::string line = "001 JURÍDICO INVESTIMENTO RENDA GASTOS DESPESAS LUCRO";

  Department department = getDepartmentFromLine(line);

  std::cout << department.getDepartment() << std::endl;
  return 0;
}