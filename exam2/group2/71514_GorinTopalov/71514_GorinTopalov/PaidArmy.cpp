#include "PaidArmy.h"


PaidArmy::PaidArmy()
{
	countSold = 0;
}
PaidArmy::PaidArmy(const PaidArmy &other){
	for (size_t i = 0; i < other.countSold; i++)
	{
		sold[i] = other.sold[i];
	}
	setAll(other);
}

void PaidArmy::setAll(const PaidArmy &other){
	countSold = other.countSold;
	salary = other.salary;
	armyGrade = other.armyGrade;
	budge = other.budge;
	leaderSalary = other.leaderSalary;
	grade = other.grade;
	armyPower = other.armyPower;
}

double PaidArmy::getArmyPower(){
	armyPower = 0;
	for (int i = 0; i < countSold; i++){
		armyPower += sold[i].getPower();
	}
	armyPower += Leader.getPower();
}
double PaidArmy::getArmyGrade(){
	armyGrade = Leader.getLoyalty()*(budge - getLeaderSalary()) + getArmyPower();
}

bool PaidArmy::operator>(const PaidArmy& other){
	return armyGrade > other.armyGrade;
}

double PaidArmy::getSalary(){
	salary=(budge-getLeaderSalary())/countSold;
}
double PaidArmy::getLeaderSalary(){
	leaderSalary = budge*0.2;
}
PaidArmy::~PaidArmy()
{
}
