#include "Mark.h"

Mark::Mark() {

}

Mark::Mark(string studentid, string subjectid, int mark) {
    _studentid = studentid;
    _subjectid = subjectid;
    _mark = mark;
}

int Mark::IncreaseID() {
    return ID = ++sIDMax;
}

int& Mark::GetIDMax() {
    return sIDMax;
}

string Mark::PrintElement() {
    string s;
    s += "StudentID: " + _studentid + ", ";
    s += "SubjectID: " + _subjectid + ", ";
    s += "Mark: " + to_string(_mark);
    return s;
}

string Mark::GetStudentID() {
    return _studentid;
}

string Mark::GetSubjectID() {
    return _subjectid;
}

int Mark::GetMark() {
    return _mark;
}

int Mark::sIDMax = 0;

