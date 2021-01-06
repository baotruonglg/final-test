#include "MyUI.h"
#include "../libs/ReplaceAll.h"
void MyUI::Display(DataBusinessObject* databusinessobject) {
    for (int i = 0; i < databusinessobject->GetSize(); i++) {
        BusinessObject* businessobject = databusinessobject->GetPointer(i);
        cout << "ID: " << businessobject->GetId() << ", " << businessobject->PrintElement() << endl;
    }
    cout << endl;
}

void MyUI::ListStudentHighestPoint(int n) {
    vector<int> sortDiem;
    sortDiem.resize(diemdata.GetSize());
    for (int i = 0; i < diemdata.GetSize(); i++) {
        sortDiem[i] = diemdata.Get(i).GetDiem();
    }
    for (int i = 0; i < sortDiem.size() - 1; i++) {
        for (int j = i + 1; j < sortDiem.size(); j++) {
            if (sortDiem[j] > sortDiem[i]) {
                swap(sortDiem[j], sortDiem[i]);
            }
        }
    }
    int count = 0;
    for (int j = 0; j < sortDiem.size(); j++) {
        for (int i = 0; i < diemdata.GetSize(); i++) {
            if (diemdata.Get(i).GetDiem() == sortDiem[j]) {
                cout << "ID: " << diemdata.Get(i).PrintElement() << endl;
                count++;
            }
            if (count == n) {
                break;
            }
        }
        if (count == n) {
            break;
        }
    }
}

void MyUI::ListStudentHighestPoint1(int n) {
    DiemData diemdata1 = diemdata;
    for (int i = 0; i < diemdata.GetSize(); i++) {
        diemdata1.Get(i) = diemdata.Get(i);
    }
    
}

void MyUI::ListStudentOldest(int n) {
    vector<int> sortAge;
    sortAge.resize(studentdata.GetSize());
    string Bdate;
    for (int i = 0; i < studentdata.GetSize(); i++) {
        Bdate = ReplaceAll::replaceAll(studentdata.Get(i).GetNgaySinh(), "-", "");
        sortAge[i] = stoi(Bdate);
    }
    for (int i = 0; i < sortAge.size() - 1; i++) {
        for (int j = i + 1; j < sortAge.size(); j++) {
            if (sortAge[j] < sortAge[i]) {
                swap(sortAge[j], sortAge[i]);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < sortAge.size(); i++) {
        Bdate = to_string(sortAge[i]);
        for (int j = 0; j < studentdata.GetSize(); j++) {
            if (Bdate == ReplaceAll::replaceAll(studentdata.Get(j).GetNgaySinh(), "-", "")) {
                cout << "ID: " << studentdata.Get(j).PrintElement() << endl;
                count++;
            }
            if (count == n) {
                break;
            }
        }
        if (count == n) {
            break;
        }
    }
}

void MyUI::ChooseSentence() {
    system("cls");
    cout << endl << endl;
    int yourchoice;
    bool k = true;
    do {
        cout << "                CHOOSE SENTENCE              " << endl;
        cout << "**********************************************" << endl;
        cout << "** 1. Add, Edit, Delete, Read.               *" << endl;
        cout << "** 2. List student has highest point.        *" << endl;
        cout << "** 3. Student's oldest.                      *" << endl;
        cout << "** 4. Exit.                                  *" << endl;
        cout << "**********************************************" << endl;
        cout << endl;
        cout << "** Your choice: ";
        cin >> yourchoice;
        switch (yourchoice)
        {
            case 1:
                ChooseObject();
                break;
            case 2:
                int n;
                cout << "Nhap so sinh vien co diem thi cao nhat: ";
                cin >> n;
                ListStudentHighestPoint1(n);
                break;
            case 3:
                int x;
                cout << "Nhap so sinh vien co tuoi cao nhat: ";
                cin >> x;
                ListStudentOldest(x);
                break;
            case 4:
                exit('0');
                break;
            default:
                k = false;
                break;
        }
    } while (k);
}

void MyUI::ChooseObject() {
    int yourchoice;
    bool k = true;
    do {
        system("cls");
        cout << endl << endl;
        cout << "                  CHOOSE OBJECT               " << endl;
        cout << "**********************************************" << endl;
        cout << "** 1. Student.                               *" << endl;
        cout << "** 2. Hoc phan.                              *" << endl;
        cout << "** 3. Diem.                                  *" << endl;
        cout << "** 4. Return to back.                        *" << endl;
        cout << "**********************************************" << endl;
        cout << endl;
        cout << "** Your choice: ";
        cin >> yourchoice;
        switch (yourchoice)
        {
            case 1:
                ChooseOption(yourchoice);
                break;
            case 2:
                ChooseOption(yourchoice);
                break;
            case 3:
                ChooseOption(yourchoice);
                break;
            case 4:
                k = false;
                break;
            default:
                exit('0');
                break;
        }
    } while (k);
}

void MyUI::ChooseOption(int n) {
    system("cls");
    cout << endl << endl;
    int yourchoice;
    bool k = true;
    do {
        cout << "                  CHOOSE OPTION               " << endl;
        cout << "**********************************************" << endl;
        cout << "** 1. Add.                                   *" << endl;
        cout << "** 2. Eddit.                                 *" << endl;
        cout << "** 3. Delete.                                *" << endl;
        cout << "** 4. Read.                                  *" << endl;
        cout << "** 5. Return to back.                        *" << endl;
        cout << "**********************************************" << endl;
        cout << endl;
        cout << "** Your choice: ";
        cin >> yourchoice;
        cin.ignore();
        switch (yourchoice)
        {
            case 1:
                if (n == 1) {
                    Student s;
                    cin >> s;
                    studentdata.AddElement(s);
                    Display(&studentdata);
                }
                else if (n == 2) {
                    HocPhan hp;
                    cin >> hp;
                    hocphandata.AddElement(hp);
                    Display(&hocphandata);
                }
                else {
                    Diem d;
                    cin >> d;
                    diemdata.AddElement(d);
                    Display(&diemdata);
                }
                break;
            case 2:
                if (n == 1) {
                    
                    int n;
                    cout << "Enter the number who want to eddit: ";
                    cin >> n;
                    cin.ignore();
                    Student s;
                    cin >> s;
                    studentdata.EditElement(s, n);
                    Display(&studentdata);
                }
                else if (n == 2) {
                    
                    int n;
                    cout << "Enter the number who want to eddit: ";
                    cin >> n;
                    cin.ignore();
                    HocPhan hp;
                    cin >> hp;
                    hocphandata.EditElement(hp, n);
                    Display(&hocphandata);
                }
                else {
                    
                    int n;
                    cout << "Enter the number who want to eddit: ";
                    cin >> n;
                    cin.ignore();
                    Diem d;
                    cin >> d;
                    diemdata.EditElement(d, n);
                    Display(&diemdata);
                }
                break;
            case 3:
                if (n == 1) {
                    
                    int n;
                    cout << "Enter the number who want to delete: ";
                    cin >> n;
                    studentdata.DeleteElement(n);
                    Display(&studentdata);
                }
                else if (n == 2) {
                    
                    int n;
                    cout << "Enter the number who want to delete: ";
                    cin >> n;
                    hocphandata.DeleteElement(n);
                    Display(&hocphandata);
                }
                else {
                    
                    int n;
                    cout << "Enter the number who want to delete: ";
                    cin >> n;
                    diemdata.DeleteElement(n);
                    Display(&diemdata);
                }
                break;
            case 4:
                if (n == 1) {
                    studentdata.ReadFile("data/DataStudent.txt");
                    Display(&studentdata);
                }
                else if (n == 2) {
                    hocphandata.ReadFile("data/DataHocPhan.txt");
                    Display(&hocphandata);
                }
                else {
                    diemdata.ReadFile("data/DataDiem.txt");
                    Display(&diemdata);
                }
                break;
            case 5:
                k = false;
                break;
            default:
                exit('0');
                break;
        }
    } while (k);
}