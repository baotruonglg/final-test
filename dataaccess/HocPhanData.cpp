#include "HocPhanData.h"

HocPhanData::HocPhanData() {
    arrHocPhanData.resize(0);
}

int HocPhanData::GetSize() {
    return arrHocPhanData.size();
}

BusinessObject* HocPhanData::GetPointer(int i) {
    return &arrHocPhanData[i];
}

HocPhan HocPhanData::Get(int i) {
    return arrHocPhanData[i];
}

void HocPhanData::ReadFile(string filename) {
    if (arrHocPhanData.back().GetIDMax() != 0) {
        arrHocPhanData.back().GetIDMax() = 0;
    }
    arrHocPhanData.resize(0);
    ifstream fileIn(filename);
    int numberelement;
    fileIn >> numberelement;
    string mahp, tenhp;
    int sotinchi;
    for (int i = 0; i < numberelement; i++) {
        fileIn >> mahp;
        fileIn >> tenhp;
        fileIn >> sotinchi;
        HocPhan hocphan(ReplaceAll::replaceAll(mahp, "_", " "), ReplaceAll::replaceAll(tenhp, "_", " "), sotinchi);
        hocphan.IncreaseID();
        arrHocPhanData.push_back(hocphan);
    }
    fileIn.close();
}

void HocPhanData::AddElement(HocPhan& hp) {
    hp.IncreaseID();
    arrHocPhanData.push_back(hp);
}

void HocPhanData::EditElement(HocPhan& hp, int& i) {
    hp.GetId() = arrHocPhanData[i - 1].GetId();
    arrHocPhanData[i - 1] = hp;
}

void HocPhanData::DeleteElement(int i) {
    arrHocPhanData.erase(arrHocPhanData.begin() + i - 1);
    for (int j = i - 1; j < arrHocPhanData.size(); j++) {
        arrHocPhanData[j].GetId() = j + 1;
    }
    arrHocPhanData.back().GetIDMax() = arrHocPhanData.size();
}
