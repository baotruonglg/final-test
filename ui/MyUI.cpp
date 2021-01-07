#include "MyUI.h"

void MyUI::Display(DataAccess* dataaccess) {
    for (int i = 0; i < dataaccess->GetSize(); i++) {
        BusinessObject* businessobject = dataaccess->GetPointer(i);
        cout << "ID: " << businessobject->GetID() << " " << businessobject->PrintElement() << endl;
    }
    cout << endl << endl;
}

void MyUI::StoreData(string& foldername) {
    mkdir(("backupdata/" + foldername).c_str());
    studentdata.ExportToFile("backupdata/" + foldername + "/StudentData.txt");
    subjectdata.ExportToFile("backupdata/" + foldername + "/SubjectData.txt");
    markdata.ExportToFile("backupdata/" + foldername + "/MarkData.txt");
    ofstream fileOut("backupdata/storenamefile.txt", ios::app);
    fileOut << foldername << endl;
    fileOut.close();
}

void MyUI::RestoreData() {
    ifstream fileIn("backupdata/storenamefile.txt");
    vector<string> storenamefile;
    string temp;
    while (getline(fileIn, temp)) {
        storenamefile.push_back(temp);
    }
    int choice;
    for (int i = 0; i < storenamefile.size(); i++) {
        cout << "** " << i + 1 << " . " << storenamefile[i] << endl;
    }
    cout << endl << "** Your choice: ";
    cin >> choice;
    studentdata.ReadFile("backupdata/" + storenamefile[choice - 1] + "/StudentData.txt");
    subjectdata.ReadFile("backupdata/" + storenamefile[choice - 1] + "/SubjectData.txt");
    markdata.ReadFile("backupdata/" + storenamefile[choice - 1] + "/MarkData.txt");
    Display(&studentdata);
    Display(&subjectdata);
    Display(&markdata);
} 

void MyUI::ListStudentHighestMark(int N) {
    MarkData mark = markdata;
    for (int i = 0; i < mark.GetSize() - 1; i++) {
        for (int j = i + 1; j < mark.GetSize(); j++) {
            Mark marki = mark.Get(i);
            Mark markj = mark.Get(j);
            if (markj.GetMark() > marki.GetMark()) {
                mark.Swap(j, i);            
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << "ID: " << mark.Get(i).GetID() << ", StudentID: " << mark.Get(i).GetStudentID() << ", SubjectID: " << mark.Get(i).GetSubjectID() << ", Mark: " << mark.Get(i).GetMark();
        cout << endl;
    }
}

void MyUI::ListStudentOldestAge(int N) {
    StudentData student = studentdata;
    for (int i = 0; i < student.GetSize() - 1; i++) {
        for (int j = i + 1; j < student.GetSize(); j++) {
            Student studenti = student.Get(i);
            Student studentj = student.Get(j);
            if (studentj.GetBirthDate() < studenti.GetBirthDate()) {
                student.Swap(j, i);            
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << "ID: " << student.Get(i).GetID() << ", StudentID: " + student.Get(i).GetStudentID() << ", StudentName: " << student.Get(i).GetStudentName() << ", Birthday: " << student.Get(i).GetBirthDate() << ", Sex: " << student.Get(i).GetSex();
        cout << endl;
    }
}

void MyUI::ChooseSentence() {
    int choice;
    do {
        system("cls");
        cout << endl << endl << endl;
        cout << "******************************MENU*******************************" << endl;
        cout << "** 1. Read all file.                                            *" << endl;
        cout << "** 2. Create, Update, Delete.                                   *" << endl;
        cout << "** 3. Store date to file.                                       *" << endl;
        cout << "** 4. Restore date from file.                                   *" << endl;
        cout << "** 5. Display list students have highest mark.                  *" << endl;
        cout << "** 6. Display list students have oldest age.                    *" << endl;
        cout << "** 0. Exit.                                                     *" << endl;
        cout << "**                                                              *" << endl;
        cout << "*****************************************************************" << endl;
        cout << endl;
        cout << "** Your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
            case 1:
                studentdata.ReadFile("data/StudentData.txt");
                subjectdata.ReadFile("data/SubjectData.txt");
                markdata.ReadFile("data/MarkData.txt");
                Display(&studentdata);
                Display(&subjectdata);
                Display(&markdata);
                break;
            case 2:
                ChooseClass();
                break;
            case 3:
                {string foldername;
                cout << "Enter the folder name which you want to store: ";
                getline(cin, foldername);
                StoreData(foldername);}
                break;
            case 4:
                RestoreData();
                break;
            case 5:
                int number;
                cout << "Enter number student have highest mark you want to type: ";
                cin >> number;
                cout << endl;
                ListStudentHighestMark(number);
                break;
            case 6:
                int list;
                cout << "Enter list student have oldest age you want to type: ";
                cin >> list;
                cout << endl;
                ListStudentOldestAge(list);
                break;
            case 0:
                exit('0');
                break;
            default:
                exit('0');
                break;
        }
        if (choice != 0) {
            system("pause");
            system("cls");
        }
    } while(true);
}

void MyUI::ChooseClass() {
    int choice;
    bool k = true;
    do {
        system("cls");
        cout << endl << endl << endl;
        cout << "******************************MENU*******************************" << endl;
        cout << "** 1. Student class.                                            *" << endl;
        cout << "** 2. Subject class.                                            *" << endl;
        cout << "** 3. Mark class.                                               *" << endl;
        cout << "** 4. Return.                                                   *" << endl;
        cout << "** 0. Exit.                                                     *" << endl;
        cout << "**                                                              *" << endl;
        cout << "*****************************************************************" << endl;
        cout << endl;
        cout << "** Your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                ChooseOption(choice);
                break;
            case 2:
                ChooseOption(choice);
                break;
            case 3:
                ChooseOption(choice);
                break;
            case 4:
                k = false;
                ChooseSentence();
                break;
            case 0:
                exit('0');
                break;
            default:
                exit('0');
                break;
        }
    } while(k);
}

void MyUI::ChooseOption(int n) {
    int choice;
    bool k = true;
    do {
        system("cls");
        cout << endl << endl << endl;
        cout << "******************************MENU*******************************" << endl;
        cout << "** 1. Create data.                                              *" << endl;
        cout << "** 2. Update data.                                              *" << endl;
        cout << "** 3. Delete data.                                              *" << endl;
        cout << "** 4. Return.                                                   *" << endl;
        cout << "** 0. Exit.                                                     *" << endl;
        cout << "**                                                              *" << endl;
        cout << "*****************************************************************" << endl;
        cout << endl;
        cout << "** Your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
            case 1:
                if (n == 1) {
                    Student s;
                    cin >> s;
                    studentdata.CreateData(s);
                    Display(&studentdata);
                }
                else if (n == 2) {
                    Subject s;
                    cin >> s;
                    subjectdata.CreateData(s);
                    Display(&subjectdata);
                }
                else {
                    Mark m;
                    cin >> m;
                    markdata.CreateData(m);
                    Display(&markdata);
                }
                break;
            case 2:
                int idupdate;
                cout << "Enter the student who you to update: ";
                cin >> idupdate;
                cin.ignore();
                if (n == 1) {
                    Student s;
                    cin >> s;
                    studentdata.UpdateData(s, idupdate);
                    Display(&studentdata);
                }
                else if (n == 2) {
                    Subject s;
                    cin >> s;
                    subjectdata.UpdateData(s, idupdate);
                    Display(&subjectdata);
                }
                else {
                    Mark m;
                    cin >> m;
                    markdata.UpdateData(m, idupdate);
                    Display(&markdata);
                }
                break;
            case 3:
                int iddelete;
                cout << "Enter the student who you to delete: ";
                cin >> iddelete;
                if (n == 1) {
                    studentdata.DeleteData(iddelete);
                    Display(&studentdata);
                }
                else if (n == 2) {
                    subjectdata.DeleteData(iddelete);
                    Display(&subjectdata);
                }
                else {
                    markdata.DeleteData(iddelete);
                    Display(&markdata);
                }
                break;
            case 4:
                k = false;
                break;
            case 0:
                exit('0');
                break;
            default:
                exit('0');
                break;
        }
        if (choice != 0 && choice != 4) {
            system("pause");
            system("cls");
        }
    } while(k);
}
