#ifndef ui_Input_H_
#define ui_Input_H_
#include "../businessobject/Mark.h"
#include "../businessobject/Student.h"
#include "../businessobject/Subject.h"
#include <iostream>
using namespace std;

istream& operator >> (istream&, Mark&);
istream& operator >> (istream&, Subject&);
istream& operator >> (istream&, Student&);
#endif