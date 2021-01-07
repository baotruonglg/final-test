#include "MarkData.h"

MarkData::MarkData() {

}

BusinessObject* MarkData::GetPointer(int i) {
    return &_arrMark[i];
}

Mark MarkData::Get(int i) {
    return _arrMark[i];
}

int MarkData::GetSize() {
    return _arrMark.size();
}

void MarkData::ReadFile(string filename) {
    if (_arrMark.size() != 0) {
        _arrMark.back().GetIDMax() = 0;
    }
    _arrMark.resize(0);
    ifstream fileIn(filename);
    int numberelement;
    fileIn >> numberelement;
    fileIn.ignore();
    string _studentid;
    string _subjectid;
    int _mark;
    for (int i = 0; i < numberelement; i++) {
        getline(fileIn, _studentid);
        getline(fileIn, _subjectid);
        fileIn >> _mark;
        fileIn.ignore();
        Mark s(_studentid, _subjectid, _mark);
        s.IncreaseID();
        _arrMark.push_back(s);
    }
    fileIn.close();

}

void MarkData::CreateData(Mark& s) {
    s.IncreaseID();
    _arrMark.push_back(s);
}

void MarkData::UpdateData(Mark& s, int i) {
    s.GetID() = _arrMark[i - 1].GetID();
    _arrMark[i - 1] = s;
}

void MarkData::DeleteData(int j) {
    for (int i = 0; i < _arrMark.size(); i++) {
        if (_arrMark[i].GetID() == j) {
            _arrMark.erase(_arrMark.begin() + i);
        }
    }
}

void MarkData::ExportToFile(string filename) {
    ofstream fileOut(filename);
    fileOut << _arrMark.size() << endl;
    for (int i = 0; i < _arrMark.size(); i++) {
        fileOut << _arrMark[i].GetStudentID() << endl;
        fileOut << _arrMark[i].GetSubjectID() << endl;
        fileOut << _arrMark[i].GetMark() << endl;
    }
    fileOut.close();
}

void MarkData::Swap(int& x , int& y) {
    Mark temp;
    temp = _arrMark[x];
    _arrMark[x] = _arrMark[y];
    _arrMark[y] = temp;
}

