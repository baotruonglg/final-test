#include "DiemData.h"

DiemData::DiemData() {
    arrDiemData.resize(0);
}

int DiemData::GetSize() {
    return arrDiemData.size();
}

BusinessObject* DiemData::GetPointer(int i) {
    return &arrDiemData[i];
}

Diem DiemData::Get(int i) {
    return arrDiemData[i];
}

void DiemData::ReadFile(string filename) {
    if (arrDiemData.back().GetIDMax() != 0) {
        arrDiemData.back().GetIDMax() = 0;
    }
    arrDiemData.resize(0);
    ifstream fileIn(filename);
    int numberelement;
    fileIn >> numberelement;
    string mahp, masv;
    int diem;
    for (int i = 0; i < numberelement; i++) {
        fileIn >> masv; 
        fileIn >> mahp;
        fileIn >> diem;
        Diem d(ReplaceAll::replaceAll(masv, "_", " "), ReplaceAll::replaceAll(mahp, "_", " "), diem);
        d.IncreaseID();
        arrDiemData.push_back(d);
    }
    fileIn.close();
}

void DiemData::AddElement(Diem& d) {
    d.IncreaseID();
    arrDiemData.push_back(d);
}

void DiemData::EditElement(Diem& d, int& i) {
    d.GetId() = arrDiemData[i - 1].GetId();
    arrDiemData[i - 1] = d;
}

void DiemData::DeleteElement(int i) {
    arrDiemData.erase(arrDiemData.begin() + i - 1);
    for (int j = i - 1; j < arrDiemData.size(); j++) {
        arrDiemData[j].GetId() = j + 1;
    }
    arrDiemData.back().GetIDMax() = arrDiemData.size();
}
