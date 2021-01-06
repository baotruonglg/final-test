#ifndef _businessobject_Student_H_
#define _businessobject_Student_H_

#include <string>
#include <iostream>
#include "BusinessObject.h"
using namespace std;

class Student : public BusinessObject {
private:
    string masv, hoten, ngaysinh;
    string gioitinh;
    static int sIDMax;
public:
    Student();
    Student(string, string, string, string);
    int IncreaseID();
    int& GetIDMax();
    string GetMaSV();
    string GetHoTen();
    string GetNgaySinh();
    string GetGioiTinh();
    string PrintElement();
    friend istream& operator >> (istream& , Student& );
};
#endif
