#include "NormalHuman.h"

NormalHuman::NormalHuman(char * name, int power, int loyalty, int sizeOfFriends)
{
	setName(name);
	setPower(power);
	this->sizeOfFriends = sizeOfFriends;
	setLoyalty(loyalty);
	friends = new Human[getLoyalty()];
}
NormalHuman::NormalHuman(const NormalHuman &other){
	setName(other.getName());
	setPower(other.getPower());
	setLoyalty(other.getLoyalty());
	friends = other.friends;
}
NormalHuman& NormalHuman::operator=(const NormalHuman &other){
	if (this != &other){
		delete[]name;
		setName(other.getName());
		setPower(other.getPower());
		setLoyalty(other.getLoyalty());
		friends = other.friends;
	}
	return *this;
}
void NormalHuman::setPower(int power){
	if (power >= 0)
		this->power = power;
	else
		this->power = 2;
}
int NormalHuman::getPower()const{
	return power;
}
void NormalHuman::addFriend(NormalHuman other){
	NormalHuman *temp = new NormalHuman[getLoyalty() + 1];
	for (int i = 0; i < getLoyalty(); i++){
		temp[i] = friends[i];
	}
	temp[getLoyalty() + 1] = other;
	for (int i = 0; i < getLoyalty(); i++){
		delete[i]friends;
	}
	friends = new NormalHuman[getLoyalty() + 1];
	for (int i = 0; i < getLoyalty() + 1; i++){
		friends[i] = temp[i];
	}
	setLoyalty(getLoyalty() + 1);
	for (int i = 0; i < getLoyalty(); i++){
		delete[i]temp;
	}
}

void NormalHuman::reducePower(int morePower){
	if (getPower() - morePower >= 0)
		setPower(getPower() - morePower);
	else
		setPower(0);

}

void NormalHuman::setLoyalty(int loyalty){
	if (loyalty >= 0){
		this->loyalty = loyalty;
	}
	else{
		this->loyalty = 2;
	}
}

int NormalHuman::getLoyalty()const{
	return loyalty;
}
void NormalHuman::removeFriend(char *name){
	for (size_t i = 0; i < getLoyalty(); i++){
		if (strcmp(friends[i].getName(), name) == 0){
			for (size_t j = i + 1; j < getLoyalty(); j++)
			{
				friends[j - 1] = friends[j];
			}
			NormalHuman *temp = new NormalHuman[getLoyalty() - 1];
			for (int i = 0; i < getLoyalty() - 1; i++){
				temp[i] = friends[i];
			}
			for (int i = 0; i < getLoyalty() - 1; i++){
				delete[i]friends;
			}
			friends = new NormalHuman[getLoyalty() - 1];
			for (int i = 0; i < getLoyalty() - 1; i++){
				friends[i] = temp[i];
			}
			setLoyalty(getLoyalty() - 1);
			for (int i = 0; i < getLoyalty(); i++){
				delete[i]temp;
			}
			break;
		}
	}
}
void NormalHuman::setName(char *name){
	delete[]this->name;
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy_s(this->name, strlen(name) + 1, name);
}

char* NormalHuman::getName()const{
	return name;
}

NormalHuman::~NormalHuman()
{
}
