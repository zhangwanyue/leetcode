//
// Created by vera on 19-3-19.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
bool cmp(int a, int b){
    return a>b; //从大到小（如果cmp的返回值是false，就交换a、b的位置）
}
int main(){
    vector<int> vec = {0, 1, 2, 3};
    sort(vec.begin(), vec.end(), cmp);
    for(int i: vec){
        cout<<i<<endl;
    }
}
*/

struct Student{
    int id;
    string name;
    Student(int id, string name){
        this->id = id;
        this->name = name;
    }
};

bool cmp(Student* stu1, Student* stu2){
    return stu1->id>stu2->id; //从大到小（如果cmp的返回值是false，就交换a、b的位置）
}

int main(){
    vector<Student*> stuVec;
    stuVec.push_back(new Student(3, "Alice"));
    stuVec.push_back(new Student(1, "Bob"));
    stuVec.push_back(new Student(2, "Lily"));
    sort(stuVec.begin(), stuVec.end(), cmp);
    for(Student* stu : stuVec){
        cout<<stu->id<<" "<<stu->name<<endl;
    }
    for(Student* stu : stuVec){
        delete stu;
    }
}
