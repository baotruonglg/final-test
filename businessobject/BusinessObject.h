#ifndef businessobject_BusinessObject_H_
#define businessobject_BusinessObject_H_

#include <string>
using namespace std;

class BusinessObject {
protected:
    int ID;
public:
    int& GetID();
    virtual string PrintElement() = 0;
};
#endif