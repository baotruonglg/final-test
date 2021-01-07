#ifndef dataaccess_SubjectData_H_
#define dataaccess_SubjectData_H_
#include "../businessobject/Subject.h"
#include "DataAccess.h"
#include <vector>
#include <fstream>

class SubjectData : public DataAccess {
private:
    vector<Subject> _arrSubject;
public:
    SubjectData();
    BusinessObject* GetPointer(int);
    Subject Get(int);
    int GetSize();
    void ReadFile(string);
    void CreateData(Subject&);
    void UpdateData(Subject&, int);
    void DeleteData(int);
    void ExportToFile(string);
};
#endif