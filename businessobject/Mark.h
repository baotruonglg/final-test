#ifndef businessobject_Mark_H_
#define businessobject_Mark_H_
#include "BusinessObject.h"
class Mark : public BusinessObject {
private:
    string _studentid;
    string _subjectid;
    int _mark;
    static int sIDMax;
public:
    Mark();
    Mark(string, string, int);
    int IncreaseID();
    int& GetIDMax();
    string PrintElement();
    string GetStudentID();
    string GetSubjectID();
    int GetMark();
    friend istream& operator >> (istream&, Mark&);
};
#endif