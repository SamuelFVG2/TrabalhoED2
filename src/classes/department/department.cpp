#include "department.h"

Department::Department(std::string code, std::string name) {
    this->code = code;
    this->name = name;
}

std::string Department::getCode() {
    return code;
}

std::string Department::getName() {
    return name;
}

std::vector<std::string> Department::getWords() {
    return words;
}

void Department::setCode(std::string code) {
    this->code = code;
}

void Department::setName(std::string name) {
    this->name = name;
}

void Department::addWord(std::string keyword) {
    words.push_back(keyword);
}

std::string Department::getDepartment() {
    std::string result = code + " - " + name + " ";

    for (int i = 0; i < words.size(); i++) {
        result += words[i] + " ";
    }

    return result;
}