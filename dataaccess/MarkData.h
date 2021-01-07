#ifndef dataaccess_MarkData_H_
#define dataaccess_MarkData_H_
#include "../businessobject/Mark.h"
#include "DataAccess.h"
#include <vector>
#include <fstream>

class MarkData : public DataAccess {
private:
    vector<Mark> _arrMark;
public:
    MarkData();
    BusinessObject* GetPointer(int);
    Mark Get(int);
    int GetSize();
    void ReadFile(string);
    void CreateData(Mark&);
    void UpdateData(Mark&, int);
    void DeleteData(int);
    void ExportToFile(string);
    void Swap(int&, int&);
};
#endif