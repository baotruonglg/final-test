#include "Diem.h"

Diem::Diem() {
}

Diem::Diem(string masv, string mahp, int diem) {
    this->masv = masv;
    this->mahp = mahp;
    this->diem = diem;
}

Diem::Diem(const Diem& d) {
    ID = d.ID;
    masv = d.masv;
    mahp = d.mahp;
    diem = d.diem;
}

int Diem::IncreaseID() {
    return ID = ++sIDMax;
}

int& Diem::GetIDMax() {
    return sIDMax;
}

string Diem::GetMaSV() {
    return masv;
}

string Diem::GetMaHP() {
    return mahp;
}

int Diem::GetDiem() {
    return diem;
}

string Diem::PrintElement() {
    string s;
    s += "Ma sinh vien: " + masv + ", ";
    s += "Ma hoc phan: " + mahp + ", ";
    s += "Diem: " + to_string(diem);
    return s;
}

int Diem::sIDMax = 0;
