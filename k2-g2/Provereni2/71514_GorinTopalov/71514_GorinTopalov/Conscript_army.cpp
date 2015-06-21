#include "Conscript_army.h"


Conscript_army::Conscript_army()
{
}


double Conscript_army::getArmyGrade(){
	double temp1=0, temp2=0;
	for (int i = 0; i < countSold; i++){
		temp1 = sold[i].getLoyalty();
		temp2 = sold[i].getPower();
	}
	return Leader.getLoyalty()*temp1 + temp2;
}


Conscript_army::~Conscript_army()
{
}
