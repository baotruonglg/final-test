#ifndef _dataaccess_DiemData_H_
#define _dataaccess_DiemData_H_
#include "../businessobject/Diem.h"
#include "DataBusinessObject.h"
#include <vector>
#include <fstream>
#include "../libs/ReplaceAll.h"

class DiemData : public DataBusinessObject {
private:
    vector<Diem> arrDiemData;
public:
    DiemData();
    int GetSize();
    BusinessObject* GetPointer(int);
    Diem Get(int);
    void ReadFile(string);
    void AddElement(Diem&);
    void EditElement(Diem&, int&);
    void DeleteElement(int);
    void Swap(int&, int&);
};
#endif