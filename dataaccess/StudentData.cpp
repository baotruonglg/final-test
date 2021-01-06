#include "StudentData.h"

StudentData::StudentData() {
    arrStudentData.resize(0);
}

int StudentData::GetSize() {
    return arrStudentData.size();
}

BusinessObject* StudentData::GetPointer(int i) {
    return &arrStudentData[i];
}

Student StudentData::Get(int i) {
    return arrStudentData[i];
}

void StudentData::ReadFile(string filename) {
    if (arrStudentData.back().GetIDMax() != 0) {
        arrStudentData.back().GetIDMax() = 0;
    }
    arrStudentData.resize(0);
    ifstream fileIn(filename);
    int numberelement;
    fileIn >> numberelement;
    string masv, hoten, ngaysinh;
    string gioitinh;
    for (int i = 0; i < numberelement; i++) {
        fileIn >> masv;
        fileIn >> hoten;
        fileIn >> ngaysinh;
        fileIn >> gioitinh;
        Student student(ReplaceAll::replaceAll(masv, "_", " "), ReplaceAll::replaceAll(hoten, "_", " "), ReplaceAll::replaceAll(ngaysinh, "_", " "), ReplaceAll::replaceAll(gioitinh, "_", " "));
        student.IncreaseID();
        arrStudentData.push_back(student);
    }
    fileIn.close();
}

void StudentData::AddElement(Student& st) {
    st.IncreaseID();
    arrStudentData.push_back(st);
}

void StudentData::EditElement(Student& st, int& i) {
    st.GetId() = arrStudentData[i - 1].GetId();
    arrStudentData[i - 1] = st;
}

void StudentData::DeleteElement(int i) {
    arrStudentData.erase(arrStudentData.begin() + i - 1);
    for (int j = i - 1; j < arrStudentData.size(); j++) {
        arrStudentData[j].GetId() = j + 1;
    }
    arrStudentData.back().GetIDMax() = arrStudentData.size();
}
