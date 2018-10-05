#ifndef __CLASS_H__
#define __CLASS_H__
#include "typeof.h"

class BaseA
{
public:
	void Func(){}
	const char* operator()() { return "BaseA\n"; }
};
REGISTER_TYPE(BaseA);
REGISTER_TYPE(BaseA*);

class DerivedA :public BaseA
{
public:
	const char* operator()() { return "DerivedA\n"; }
};
REGISTER_TYPE(DerivedA);
REGISTER_TYPE(DerivedA*);


class BaseB
{
public:
	virtual void Func(){}
	const char* operator()() { return "BaseB\n"; }
};
REGISTER_TYPE(BaseB);
REGISTER_TYPE(BaseB*);


class DerivedB :public BaseB
{
public:
	const char* operator()() { return "DerivedB\n"; }
};
REGISTER_TYPE(DerivedB);
REGISTER_TYPE(DerivedB*);

#endif 
