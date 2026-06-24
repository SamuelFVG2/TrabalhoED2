#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "classes/department/department.h"

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
  std::vector<Department> departments;
  std::ifstream file("./arquivo.txt");
  std::string line;
  if (!file.is_open()) {
    std::cout << "Error opening file!" << std::endl;
    return 1;
}
  while (std::getline(file, line)) {
    Department department = getDepartmentFromLine(line);
    departments.push_back(department);
  }

  file.close();

  for (int i = 0; i < departments.size(); i++) {
    std::cout << departments[i].getDepartment() << std::endl << std::endl;
  }

  return 0;
}