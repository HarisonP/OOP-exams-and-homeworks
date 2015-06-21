#include "Human.h"


Human::Human(char * name,int power, int loyalty, int sizeOfFriends)
{
	setName(name);
	setPower(power);
	this->sizeOfFriends = sizeOfFriends;
	setLoyalty(loyalty);
	friends = new Human[getLoyalty()];
}
Human::Human(const Human &other){
	setName(other.getName());
	setPower(other.getPower());
	setLoyalty(other.getLoyalty());
	friends = other.friends;
}
Human& Human::operator=(const Human &other){
	if (this != &other){
		setName(other.getName());
		setPower(other.getPower());
		setLoyalty(other.getLoyalty());
		friends = other.friends;
	}
	return *this;
}
void Human::setPower(int power){
	if (power >= 0)
		this->power = power;
	else
		this->power = 2;
}
int Human::getPower()const{
	return power;
}
void Human::addFriend(Human other){
	Human *temp = new Human[getLoyalty() + 1];
	for (int i = 0; i < getLoyalty(); i++){
		temp[i] = friends[i];
	}
	temp[getLoyalty() + 1]=other;
	for (int i = 0; i < getLoyalty(); i++){
		delete[i]friends;
	}
	friends = new Human[getLoyalty() + 1];
	for (int i = 0; i < getLoyalty() + 1; i++){
		friends[i] = temp[i];
	}
	setLoyalty(getLoyalty() + 1);
	for (int i = 0; i < getLoyalty(); i++){
		delete[i]temp;
	}
}

void Human::reducePower(int morePower){
	if (getPower() - morePower >= 0)
		setPower(getPower() - morePower);
	else
		setPower(0);

}

void Human::setLoyalty(int loyalty){
	if (loyalty >= 0){
		this->loyalty = loyalty;
	}
	else{
		this->loyalty = 2;
	}
}

int Human::getLoyalty()const{
	return loyalty;
}
void Human::removeFriend(char *name){
	for (size_t i = 0; i < getLoyalty(); i++){
		if (strcmp(friends[i].getName(), name) == 0){
			for (size_t j = i+1; j < getLoyalty(); j++)
			{
				friends[j - 1] = friends[j];
			}
			Human *temp = new Human[getLoyalty() -1];
			for (int i = 0; i < getLoyalty()-1; i++){
				temp[i] = friends[i];
			}
			for (int i = 0; i < getLoyalty()-1; i++){
				delete[i]friends;
			}
			friends = new Human[getLoyalty() -1];
			for (int i = 0; i < getLoyalty() -1; i++){
				friends[i] = temp[i];
			}
			setLoyalty(getLoyalty() -1);
			for (int i = 0; i < getLoyalty(); i++){
				delete[i]temp;
			}
			break;
		}
	}
}
void Human::setName(char *name){
	delete[]this->name;
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy_s(this->name, strlen(name) + 1, name);
}

char* Human::getName()const{
	return name;
}
Human::~Human()
{
	delete[]name;
	for (int i = 0; i < getLoyalty(); i++){
		delete[i] friends;
	}
}
