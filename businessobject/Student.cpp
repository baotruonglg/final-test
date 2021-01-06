#include "Student.h"

Student::Student() {
}

Student::Student(string masv, string hoten, string ngaysinh, string gioitinh) {
    this->masv = masv;
    this->hoten = hoten;
    this->ngaysinh = ngaysinh;
    this->gioitinh = gioitinh;
}

int Student::IncreaseID() {
    return ID = ++sIDMax;
}

int& Student::GetIDMax() {
    return sIDMax;
}

string Student::GetMaSV() {
    return masv;
}

string Student::GetHoTen() {
    return hoten;
}

string Student::GetNgaySinh() {
    return ngaysinh;
}

string Student::GetGioiTinh() {
    return gioitinh;
}

string Student::PrintElement() {
    string s;
    s += "Ma sinh vien: " + masv + ", ";
    s += "Ho ten: " + hoten + ", ";
    s += "Ngay sinh: " + ngaysinh + ", ";
    s += "Gioi tinh: " + gioitinh;
    return s;
}

int Student::sIDMax = 0;
