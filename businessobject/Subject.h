#ifndef businessobject_Subject_H_
#define businessobject_Subject_H_
#include "BusinessObject.h"
class Subject : public BusinessObject {
private:
    string _subjectid;
    string _subjectname;
    int _number;
    static int sIDMax;
public:
    Subject();
    Subject(string, string, int);
    int IncreaseID();
    int& GetIDMax();
    string PrintElement();
    string GetSubjectID();
    string GetSubjectName();
    int GetNumber();
    friend istream& operator >> (istream&, Subject&);
};
#endif