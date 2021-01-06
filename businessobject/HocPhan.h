#ifndef _businessobject_HocPhan_H_
#define _businessobject_HocPhan_H_

#include <string>
#include <iostream>
#include "BusinessObject.h"
using namespace std;

class HocPhan : public BusinessObject {
private:
    string mahp, tenhp;
    int sotinchi;
    static int sIDMax;
public:
    HocPhan();
    HocPhan(string, string, int);
    int IncreaseID();
    int& GetIDMax();
    string GetMaHP();
    string GetTenHP();
    int GetSoTinChi();
    string PrintElement();
    friend istream& operator >> (istream& , HocPhan& );
};
#endif
