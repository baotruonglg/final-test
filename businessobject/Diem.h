#ifndef _businessobject_Diem_H_
#define _businessobject_Diem_H_

#include <string>
#include <iostream>
#include "BusinessObject.h"
using namespace std;

class Diem : public BusinessObject {
private:
    string masv, mahp;
    int diem;
    static int sIDMax;
public:
    Diem();
    Diem(string, string, int);
    Diem(const Diem&);
    int IncreaseID();
    int& GetIDMax();
    string GetMaHP();
    string GetMaSV();
    int GetDiem();
    string PrintElement();
    friend istream& operator >> (istream& , Diem& );
};
#endif
