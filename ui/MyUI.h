#ifndef _ui_MyUI_H_
#define _ui_MyUI_H_

#include "../dataaccess/StudentData.h"
#include "../dataaccess/DiemData.h"
#include "../dataaccess/HocPhanData.h"

class MyUI {
private:
    StudentData studentdata;
    DiemData diemdata;
    HocPhanData hocphandata;
public:
    void Display(DataBusinessObject* );
    void ChooseSentence();
    void ChooseObject();
    void ChooseOption(int );
    void ListStudentHighestPoint(int);
    void ListStudentOldest(int);
};
#endif