#include "Conscript_army.h"

int Conscript_army::getGrade()
{
	int sum = 0; 
	for (int i = 0; i < size; i++)
	{
		sum += army[i]->getLoql();
	}
	int sumOfPower = 0; 
	for (int i = 0; i < size; i++)
	{
		sum += army[i]->getPower();
	}
	return lider->getLoql()*sum + sumOfPower + lider->getPower();
}