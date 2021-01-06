#ifndef _ui_Input_H_
#define ui_Input_H_
#include "../businessobject/Student.h"
#include "../businessobject/HocPhan.h"
#include "../businessobject/Diem.h"

istream& operator >> (istream& , Diem& );
istream& operator >> (istream& , HocPhan& );
istream& operator >> (istream& , Student& );
#endif