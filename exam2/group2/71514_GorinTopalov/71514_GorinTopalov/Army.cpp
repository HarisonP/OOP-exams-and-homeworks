#include "Army.h"


Army::Army(){
	this->countSold = 0;
}
Army::Army(const Army &other){
	for (int i = 0; i < other.countSold; i++){
		sold[i] = other.sold[i];
	}
	countSold = other.countSold;
	Leader = other.Leader;
}
Army& Army::operator= (const Army&other){
	if (this != &other){
		delete[]sold;
		for (int i = 0; i < other.countSold; i++){
			sold[i] = other.sold[i];
		}
		countSold = other.countSold;
		Leader = other.Leader;
	}
}
void Army::addSoldier(Human other){
	if (countSold >= 100)
		std::cout << "can't add";
	else{
		countSold++;
		sold[countSold] = other;
	}
}

void Army::removeSoldier(char *name){
	Army *temp = new Army[countSold - 1];
	for (int i = 0; i < countSold; i++){
		if (strcmp(sold[i].getName(), name) == 0){
			for (size_t k = i+1,z=i; k < countSold; k++,z++)
			{
				temp[z] = sold[k];
			}
		}
		temp[i] = sold[i];
	}
}
void Army::addLeader(Human &other){
	Leader = other;
}
double Army::getArmyGrade(){

}

Army::~Army()
{
	delete[]sold;
}
