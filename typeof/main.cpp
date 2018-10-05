#include <iostream>
#include <iomanip>
#include "Class.h"

#define OutputSplite(class_name) \
	std::cout <<"=========================="#class_name"============================="<< std::endl;
#define OutputType(type_name, var) \
	std::cout << std::setw(10) << #type_name << " Type type_info:" << &(typeid(var))  << "  ->  type name:" << typeid(var).name() << std::endl;
#define OutputObj(type_name, var) \
	std::cout << std::setw(10) << #type_name << " Obj  type_info:" << &(typeid(var))  << "  ->  type name:" << typeid(var).name() << std::endl;
#define OutputRef(type_name, var) \
	std::cout << std::setw(10) << #type_name << " Ref  type_info:" << &(typeid(var))  << "  ->  type name:" << typeid(var).name() << std::endl;
#define OutputPtr(type_name, var) \
	std::cout << std::setw(10) << #type_name << " Ptr  type_info:" << &(typeid(var))  << "  ->  type name:" << typeid(var).name() << std::endl;
#define OutputRPtr(type_name, var) \
	std::cout << std::setw(10) << #type_name << " RPtr type_info:" << &(typeid(var))  << "  ->  type name:" << typeid(var).name() << std::endl;
#define OutputPPtr(type_name, var) \
	std::cout << std::setw(10) << #type_name << " PPtr type_info:" << &(typeid(var))  << "  ->  type name:" << typeid(var).name() << std::endl;

#define _OutputNewObj(oldObj,newObj) \
	std::cout << std::setw(20) << "type_of("#oldObj") " <<  std::setw(10) << #newObj << ":   "<< #oldObj << " -> " << std::setw(16) << typeid(oldObj).name() << " | "<< #newObj<< " -> "<< typeid(newObj).name() << std::endl;
#define OutputNewObj(oldObj, newObj) _OutputNewObj(oldObj, newObj)
	

#define VarName(prefix, suffix)\
	prefix##suffix
#define ClassVal(class_name)\
	VarName(v,class_name)
#define ClassRef(class_name)\
	VarName(r,class_name)
#define ClassPtr(class_name)\
	VarName(p,class_name)
#define TypeOfVal(class_name)\
	VarName(tv,class_name)
#define TypeOfRef(class_name)\
	VarName(tr,class_name)
#define TypeOfPtr(class_name)\
	VarName(tp,class_name)

#define TestClass(class_name)\
	class_name  ClassVal(class_name);	\
	class_name& ClassRef(class_name) =  ClassVal(class_name);	\
	class_name* ClassPtr(class_name) =  &ClassVal(class_name);	\
	type_of(ClassVal(class_name)) TypeOfVal(class_name); \
	type_of(ClassRef(class_name)) TypeOfRef(class_name); \
	type_of(ClassPtr(class_name)) TypeOfPtr(class_name); \
	OutputSplite(class_name);\
	OutputType(class_name, class_name);\
	OutputType(class_name*, class_name*);\
	OutputObj(class_name, ClassVal(class_name));\
	OutputRef(class_name, ClassRef(class_name));\
	OutputPtr(class_name, ClassPtr(class_name));\
	std::cout <<std::endl;\
	OutputNewObj(ClassVal(class_name), TypeOfVal(class_name));\
	OutputNewObj(ClassRef(class_name), TypeOfRef(class_name));\
	OutputNewObj(ClassPtr(class_name), TypeOfPtr(class_name));

int main()
{
	std::cout << "this is" " a test!" << std::endl;
	std::cout << std::setw(10) << "Test" << "---" << "Test" << std::endl;
	std::cout.flags(std::ios::left);
	/*BaseA vBaseA;
	BaseA &rBaseA = vBaseA;
	BaseA *pBaseA = &vBaseA;
	type_of(vBaseA) tvBaseA;
	type_of(rBaseA) trBaseA;
	type_of(pBaseA) tpBaseA;

	OutputSplite(BaseA);
	OutputType(BaseA, BaseA);
	OutputType(BaseA*, BaseA*);
	OutputObj(BaseA, vBaseA);
	OutputRef(BaseA, rBaseA);
	OutputPtr(BaseA, pBaseA);

	OutputNewObj(vBaseA, tvBaseA);
	OutputNewObj(rBaseA, trBaseA);
	OutputNewObj(pBaseA, tpBaseA);*/

	TestClass(BaseA);
	TestClass(DerivedA);
	TestClass(BaseB);
	TestClass(DerivedB);

	OutputSplite(OtherTest);
	BaseA    vOBaseA;
	DerivedA vODerivedA;
	BaseA    *pOBaseA = &vODerivedA;
	type_of(pOBaseA) tpOBaseA = pOBaseA;
	OutputPtr(BaseA, pOBaseA);
	OutputNewObj(pOBaseA, tpOBaseA);

	BaseB    vOBaseB;
	DerivedB vODerivedB;
	BaseB    *pOBaseB = &vODerivedB;
	type_of(pOBaseB) tpOBaseB = pOBaseB;
	OutputPtr(BaseB, pOBaseB);
	OutputNewObj(pOBaseB, pOBaseB);

	std::system("pause");
	return 0;
}