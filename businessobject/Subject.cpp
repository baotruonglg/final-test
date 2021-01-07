#include "Subject.h"

Subject::Subject() {

}

Subject::Subject(string sid, string sname, int number) {
    _subjectid = sid;
    _subjectname = sname;
    _number = number;
}

int Subject::IncreaseID() {
    return ID = ++sIDMax;
}

int& Subject::GetIDMax() {
    return sIDMax;
}

string Subject::PrintElement() {
    string s;
    s += "SubjectID: " + _subjectid + ", ";
    s += "SubjectName: " + _subjectname + ", ";
    s += "Number: " + to_string(_number);
    return s;
}

string Subject::GetSubjectID() {
    return _subjectid;
}

string Subject::GetSubjectName() {
    return _subjectname;
}

int Subject::GetNumber() {
    return _number;
}

int Subject::sIDMax = 0;