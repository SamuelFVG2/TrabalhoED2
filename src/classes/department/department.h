#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>

class Department {
private:
    std::string code;
    std::string name;
    std::vector<std::string> words;

public:
    Department(std::string code, std::string name);

    std::string getCode();
    std::string getName();
    std::vector<std::string> getWords();

    void setCode(std::string code);
    void setName(std::string name);

    void addWord(std::string word);

    std::string getDepartment();
};

#endif