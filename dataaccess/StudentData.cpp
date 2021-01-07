#include "StudentData.h"

StudentData::StudentData() {

}

BusinessObject* StudentData::GetPointer(int i) {
    return &_arrStudent[i];
}

Student StudentData::Get(int i) {
    return _arrStudent[i];
}

int StudentData::GetSize() {
    return _arrStudent.size();
}

void StudentData::ReadFile(string filename) {
    if (_arrStudent.size() != 0) {
        _arrStudent.back().GetIDMax() = 0;
    }
    _arrStudent.resize(0);
    ifstream fileIn(filename);
    int numberelement;
    fileIn >> numberelement;
    fileIn.ignore();
    string _sid;
    string _sname;
    string _bdate;
    string _sex;
    for (int i = 0; i < numberelement; i++) {
        getline(fileIn, _sid);
        getline(fileIn, _sname);
        getline(fileIn, _bdate);
        getline(fileIn, _sex);
        Student s(_sid, _sname, _bdate, _sex);
        s.IncreaseID();
        _arrStudent.push_back(s);
    }
    fileIn.close();
}

void StudentData::CreateData(Student& s) {
    s.IncreaseID();
    _arrStudent.push_back(s);
}

void StudentData::UpdateData(Student& s, int i) {
    s.GetID() = _arrStudent[i - 1].GetID();
    _arrStudent[i - 1] = s;
}

void StudentData::DeleteData(int j) {
    for (int i = 0; i < _arrStudent.size(); i++) {
        if (_arrStudent[i].GetID() == j) {
            _arrStudent.erase(_arrStudent.begin() + i);
        }
    }
}

void StudentData::ExportToFile(string filename) {
    ofstream fileOut(filename);
    fileOut << _arrStudent.size() << endl;
    for (int i = 0; i < _arrStudent.size(); i++) {
        fileOut << _arrStudent[i].GetStudentID() << endl;
        fileOut << _arrStudent[i].GetStudentName() << endl;
        fileOut << _arrStudent[i].GetBirthDate() << endl;
        fileOut << _arrStudent[i].GetSex() << endl;
    }
    fileOut.close();
}


void StudentData::Swap(int& x , int& y) {
    Student temp;
    temp = _arrStudent[x];
    _arrStudent[x] = _arrStudent[y];
    _arrStudent[y] = temp;
}


