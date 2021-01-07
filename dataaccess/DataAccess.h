#ifndef dataaccess_DataAccess_H_
#define dataaccess_DataAccess_H_

#include "../businessobject/BusinessObject.h"

class DataAccess {
public:
    virtual BusinessObject* GetPointer(int) = 0;
    virtual int GetSize() = 0;
};
#endif