#include "HocPhan.h"

HocPhan::HocPhan() {
}

HocPhan::HocPhan(string mahp, string tenhp, int sotinchi) {
    this->mahp = mahp;
    this->tenhp = tenhp;
    this->sotinchi = sotinchi;
}

int HocPhan::IncreaseID() {
    return ID = ++sIDMax;
}

int& HocPhan::GetIDMax() {
    return sIDMax;
}

string HocPhan::GetMaHP() {
    return mahp;
}

string HocPhan::GetTenHP() {
    return tenhp;
}

int HocPhan::GetSoTinChi() {
    return sotinchi;
}

string HocPhan::PrintElement() {
    string s;
    s += "Ma hoc phan: " + mahp + ", ";
    s += "Ten hoc phan: " + tenhp + ", ";
    s += "So tin chi: " + to_string(sotinchi);
    return s;
}

int HocPhan::sIDMax = 0;
