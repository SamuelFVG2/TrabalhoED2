#include <iostream>

#include "./classes/department/department.h"

int main() {

    Department department("001", "FINANCEIRO");

    department.addWord("INVESTIMENTO");
    department.addWord("RENDA");
    department.addWord("GASTOS");
    department.addWord("DESPESAS");
    department.addWord("LUCRO");

    std::cout << department.getDepartment() << std::endl;

    return 0;
}