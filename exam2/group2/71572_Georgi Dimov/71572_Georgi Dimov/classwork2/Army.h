#include "Human.h"
#ifndef Army_h
#define Army_h
class Army
{
private:
protected:
	Human* army[100];
	int size;
	Human* lider;
public:
	void addMember(Human&);
	void delMember(const char* );

	virtual void addLider(Human&);
	virtual  int getGrade() = 0;
	virtual ~Army();
	bool operator>(Army& );
	Army();

};
#endif Army_h
