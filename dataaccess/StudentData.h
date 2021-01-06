#ifndef _dataaccess_StudentData_H_
#define _dataaccess_StudentData_H_
#include "../businessobject/Student.h"
#include "DataBusinessObject.h"
#include <vector>
#include <fstream>
#include "../libs/ReplaceAll.h"

class StudentData : public DataBusinessObject {
private:
    vector<Student> arrStudentData;
public:
    StudentData();
    int GetSize();
    BusinessObject* GetPointer(int);
    Student Get(int);
    void ReadFile(string);
    void AddElement(Student&);
    void EditElement(Student&, int&);
    void DeleteElement(int);
};
#endif