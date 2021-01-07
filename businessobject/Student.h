#ifndef businessobject_Student_H_
#define businessobject_Student_H_
#include "BusinessObject.h"
class Student : public BusinessObject {
private:
    string _sid;
    string _sname;
    string _bdate;
    string _sex;
    static int sIDMax;
public:
    Student();
    Student(string, string, string, string);
    int IncreaseID();
    int& GetIDMax();
    string PrintElement();
    string GetStudentID();
    string GetStudentName();
    string GetBirthDate();
    string GetSex();
    friend istream& operator >> (istream&, Student&);
};
#endif