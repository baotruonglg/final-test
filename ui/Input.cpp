#include "Input.h"

istream& operator >> (istream& is, Diem& d) {
    cout << "Nhap ma sinh vien: "; getline(is, d.masv);
    cout << "Nhap ma hoc phan: "; getline(is, d.mahp);
    cout << "nhap diem: "; is >> d.diem;
    return is;
}

istream& operator >> (istream& is, HocPhan& hp) {
    cout << "Nhap ma hoc phan: "; getline(is, hp.mahp);
    cout << "Nhap ten hoc phan: "; getline(is, hp.tenhp);
    cout << "nhap so tin chi: "; is >> hp.sotinchi;
    return is;
}

istream& operator >> (istream& is, Student& st) {
    cout << "Nhap ma sinh vien: "; getline(is, st.masv);
    cout << "Nhap ho ten: "; getline(is, st.hoten);
    cout << "Nhap ngay sinh: "; getline(is, st.ngaysinh);
    cout << "nhap gioi tinh: "; is >> st.gioitinh;
    return is;

}