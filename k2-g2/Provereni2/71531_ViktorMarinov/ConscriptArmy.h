#ifndef ConscriptArmy_H
#define ConscriptArmy_H
#include "Army.h"
class ConscriptArmy :	public Army{
public:
	ConscriptArmy() :Army(){}
	
	virtual void makeLeader(const Human& newLeader){
		this->leader = newLeader.clone();
	}
	virtual int getGrade(){
		int result = 0;
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < size; i++){
			sum1 += this->arr[i]->getLoyalty();
		}
		for (int i = 0; i < size; i++){
			sum2 += this->arr[i]->getStrenght;
		}
		return leader->getLoyalty() * sum1 + sum2;
	}
};

#endif