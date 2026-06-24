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

  int option = -1;

  while (option != 0) {
    std::cout << "\n===== MENU =====" << std::endl;
    std::cout << "1 - Buscar departamento" << std::endl;
    std::cout << "2 - Buscar palavra-chave" << std::endl;
    std::cout << "0 - Sair" << std::endl;
    std::cout << "Opcao: ";
    std::cin >> option;

    if (option == 1) {
      std::string name;
      std::cout << "Nome do departamento: ";
      std::cin >> name;

      Department department = searchDepartmentData(departments, name);
      std::cout << std::endl;
      if (department.getCode() == "") std::cout << "Departamento chave nao encontrado." << std::endl;
      else std::cout << department.getDepartment() << std::endl;
    }

    else if (option == 2) {
      std::string word;
      std::cout << "Palavra-chave: ";
      std::cin >> word;

      Department department = searchWord(departments, word);

      std::cout << std::endl;

      if (department.getCode() == "") std::cout << "Palavra chave nao encontrada." << std::endl;
      else std::cout << department.getDepartment() << std::endl;
    }

    else if (option != 0) {
      std::cout << "Opcao invalida." << std::endl;
    }
  }

  return 0;
}