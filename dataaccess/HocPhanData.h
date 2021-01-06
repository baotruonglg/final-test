#ifndef _dataaccess_HocPhanData_H_
#define _dataaccess_HocPhanData_H_
#include "../businessobject/HocPhan.h"
#include "DataBusinessObject.h"
#include <vector>
#include <fstream>
#include "../libs/ReplaceAll.h"

class HocPhanData : public DataBusinessObject {
private:
    vector<HocPhan> arrHocPhanData;
public:
    HocPhanData();
    int GetSize();
    BusinessObject* GetPointer(int);
    HocPhan Get(int);
    void ReadFile(string);
    void AddElement(HocPhan&);
    void EditElement(HocPhan&, int&);
    void DeleteElement(int);
};
#endif