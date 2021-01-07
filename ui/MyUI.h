#ifndef ui_MyUI_H_
#define ui_MyUI_H_

#include "../dataaccess/MarkData.h"
#include "../dataaccess/StudentData.h"
#include "../dataaccess/SubjectData.h"
#include <direct.h>
#include <iostream>

using namespace std;

class MyUI {
private:
    MarkData markdata;
    StudentData studentdata;
    SubjectData subjectdata;
public:
    void Display(DataAccess*);
    void ChooseSentence();
    void ChooseClass();
    void ChooseOption(int);
    void StoreData(string&);
    void RestoreData();
    void ListStudentHighestMark(int);
    void ListStudentOldestAge(int);
};
#endif