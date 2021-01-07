#include "Input.h"

istream& operator >> (istream& is, Mark& m) {
    cout << "Enter Student ID: "; getline(is, m._studentid);
    cout << "Enter Subject ID: "; getline(is, m._subjectid);
    cout << "Enter Mark: "; is >> m._mark;
    return is;
}
istream& operator >> (istream& is, Subject& s) {
    cout << "Enter Subject ID: "; getline(is, s._subjectid);
    cout << "Enter Subject Name: "; getline(is, s._subjectname);
    cout << "Enter Number: "; is >> s._number;
    return is;
}
istream& operator >> (istream& is, Student& s) {
    cout << "Enter Student ID: "; getline(is, s._sid);
    cout << "Enter Student Name: "; getline(is, s._sname);
    cout << "Enter BirthDate: "; getline(is, s._bdate);
    cout << "Enter Sex: "; getline(is, s._sex);
    return is;
}