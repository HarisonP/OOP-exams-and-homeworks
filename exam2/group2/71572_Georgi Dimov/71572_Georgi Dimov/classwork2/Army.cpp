#include "Army.h"
#include <iostream>
using namespace std; 

void  Army::addMember(Human& other)
{
	army[size] = &other;
	size++; 
}
void Army :: delMember(const char* name)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(army[i]->getName(), name) == 0)
		{
			delete army[i];
		}
	}
}
void Army ::  addLider(Human& other)
{
	lider = &other;
}

Army ::~Army()
{
	for (int i = 0; i <size; i++)
	{
		 delete army[i];
	}
	delete[] lider; 
	delete[] army; 
}

 Army ::Army()
{
	
	this->size = 0; 
	lider = NULL;
	for (int i = 0; i < 100; i++)
	{
		army[i] = NULL;
	}

}

 bool Army:: operator>(Army& other)
 {
	 if (this->getGrade() >= other.getGrade())
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }
 }