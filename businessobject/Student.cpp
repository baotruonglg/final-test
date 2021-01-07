#include "Student.h"

Student::Student() {

}

Student::Student(string sid, string sname, string bdate, string sex) {
    _sid = sid;
    _sname = sname;
    _bdate = bdate;
    _sex = sex;
}

int Student::IncreaseID() {
    return ID = ++sIDMax;
}

int& Student::GetIDMax() {
    return sIDMax;
}

string Student::PrintElement() {
    string s;
    s += "StudentID: " + _sid + ", ";
    s += "StudentName: " + _sname + ", ";
    s += "BirthDay: " + _bdate + ", ";
    s += "Sex: " + _sex;
    return s;
}

string Student::GetStudentID() {
    return _sid;
}

string Student::GetStudentName() {
    return _sname;
}

string Student::GetBirthDate() {
    return _bdate;
}

string Student::GetSex() {
    return _sex;
}

int Student::sIDMax = 0;