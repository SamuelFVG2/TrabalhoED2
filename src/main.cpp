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

Department searchDepartmentData(std::vector<Department> departments, std::string name) {
  for (int i = 0; i < departments.size(); i++) {
    if (departments[i].getName() == name) {
      return departments[i];
    }
  }

  return Department("", "");
}

Department searchWord(std::vector<Department> departments, std::string keyword) {
  for (int i = 0; i < departments.size(); i++) {
    for (int j = 0; j < departments[i].getWords().size(); j++) {
      if (departments[i].getWords()[j] == keyword) {
        return departments[i];
      }
    }
  }
  return Department("", "");
}

int main() {
  std::vector<Department> departments;
  std::ifstream file("./arquivo.txt");
  std::string line;
  
  while (std::getline(file, line)) {
    Department department = getDepartmentFromLine(line);
    departments.push_back(department);
  }

  file.close();

  Department department = searchWord(departments, "LUCRO");

  std::cout << department.getDepartment() << std::endl;

  return 0;
}