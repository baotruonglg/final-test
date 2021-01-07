#ifndef dataaccess_StudentData_H_
#define dataaccess_StudentData_H_
#include "../businessobject/Student.h"
#include "DataAccess.h"
#include <vector>
#include <fstream>

class StudentData : public DataAccess {
private:
    vector<Student> _arrStudent;
public:
    StudentData();
    BusinessObject* GetPointer(int);
    Student Get(int);
    int GetSize();
    void ReadFile(string);
    void CreateData(Student&);
    void UpdateData(Student&, int);
    void DeleteData(int);
    void ExportToFile(string);
    void Swap(int&, int&);
};
#endif