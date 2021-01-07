#include "SubjectData.h"

SubjectData::SubjectData() {

}

BusinessObject* SubjectData::GetPointer(int i) {
    return &_arrSubject[i];
}

Subject SubjectData::Get(int i) {
    return _arrSubject[i];
}

int SubjectData::GetSize() {
    return _arrSubject.size();
}

void SubjectData::ReadFile(string filename) {
    if (_arrSubject.size() != 0) {
        _arrSubject.back().GetIDMax() = 0;
    }
    _arrSubject.resize(0);
    ifstream fileIn(filename);
    int numberelement;
    fileIn >> numberelement;
    fileIn.ignore();
    string _subjectid;
    string _subjectname;
    int _number;
    for (int i = 0; i < numberelement; i++) {
        getline(fileIn, _subjectid);
        getline(fileIn, _subjectname);
        fileIn >> _number;
        fileIn.ignore();
        Subject s(_subjectid, _subjectname, _number);
        s.IncreaseID();
        _arrSubject.push_back(s);
    }
    fileIn.close();

}

void SubjectData::CreateData(Subject& s) {
    s.IncreaseID();
    _arrSubject.push_back(s);
}

void SubjectData::UpdateData(Subject& s, int i) {
    s.GetID() = _arrSubject[i - 1].GetID();
    _arrSubject[i - 1] = s;
}

void SubjectData::DeleteData(int j) {
    for (int i = 0; i < _arrSubject.size(); i++) {
        if (_arrSubject[i].GetID() == j) {
            _arrSubject.erase(_arrSubject.begin() + i);
        }
    }
}

void SubjectData::ExportToFile(string filename) {
    ofstream fileOut(filename);
    fileOut << _arrSubject.size() << endl;
    for (int i = 0; i < _arrSubject.size(); i++) {
        fileOut << _arrSubject[i].GetSubjectID() << endl;
        fileOut << _arrSubject[i].GetSubjectName() << endl;
        fileOut << _arrSubject[i].GetNumber() << endl;
    }
    fileOut.close();
}




