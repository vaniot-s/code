//
// Created by vaniot on 2020/2/3.
//

#ifndef INTRODUCTION_TO_ALGORITHMS_STUDENT_H
#define INTRODUCTION_TO_ALGORITHMS_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int score;

    bool operator<(const Student &otherStudent) {
        return scope < otherStudent.score;
    }

    //友元函数
    friend ostream &operator<<(ostream &os, const Student &student) {
        os << "Student:" << student.name << " " << student.score << endl;
        return os;
    }
};

#endif //INTRODUCTION_TO_ALGORITHMS_STUDENT_H
