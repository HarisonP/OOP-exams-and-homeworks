#ifndef PAIDARMY_H
#define PAIDARMY_H
#include "Army.h"

class PaidArmy :public Army{
private:
	int budget;
	int singleSalary;
	int leaderSalary;
public:
	PaidArmy(int budget = 0) :Army(){
		this->budget = budget;
		singleSalary = (budget * (8 / 10)) / size;
		leaderSalary = budget * (2 / 10);
	}

	virtual void makeLeader(const Human& newLeader){
	if (!strcmp(newLeader.getSpecialSkill, "None") || !strcmp(newLeader.getSpecialSkill, "Fire"))
		this->leader = newLeader.clone();
	}
	virtual int getGrade(){
		int result = 0;
		int sum1 = singleSalary * (size - 1) + leaderSalary;
		int sum2 = 0;
		for (size_t i = 0; i < size; i++){
			sum2 += this->arr[i]->getStrenght;
		}
		return leader->getLoyalty() * sum1 + sum2;
	}

};

#endif