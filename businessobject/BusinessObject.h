#ifndef _businessobject_BusinessObject_H_
#define _businessobject_BusinessObject_H_
#include <string>
using namespace std;
class BusinessObject {
protected:
    int ID;
public:
    int& GetId();
    virtual string PrintElement() = 0;
};
#endif