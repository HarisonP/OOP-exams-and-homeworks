#include "Paid_army.h"
int  Paid_army ::getGrade()
{
	for (int i = 0; i < size; i++)
	{
		sum += army[i]->getPower();
	}
	return lider->getLoql()*getSalary()+sum;
}
int Paid_army :: getSalary()
{
	int sum1 = sum / 5; 
	sum -= sum1; 
	return sum / size; 
}



