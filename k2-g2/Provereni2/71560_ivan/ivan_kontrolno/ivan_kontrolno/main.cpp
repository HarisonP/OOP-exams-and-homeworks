#include<iostream>
using namespace std;

class Human
{
public:
	virtual double getSalary() = 0;
	Human(char* name = "", int power = 0, int loyalty = 0)
	{
		init(name, power, loyalty);
		this->arrSize = loyalty;

	}
	Human(const Human& other)
	{
		init(other.name, other.power, other.loyalty);
		this->arrSize = other.loyalty;
	}
	~Human()
	{
		delete[]this->name;
	}

	void setName(char* name)
	{
		delete[]this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name), name);
	}

	char* getName() const
	{
		return this->name;
	}

	void setPower(int power)
	{
		this->power = power;
	}

	int getPower() const
	{
		return this->power;
	}

	void setLoyalty(int loyalty)
	{
		this->loyalty = loyalty;
		this->arrSize = loyalty;
	}
	int getLoyalty() const
	{
		return this->loyalty;
	}

	bool reducePower(int n)
	{
		if (this->power == 0 || ((this->power - n) < 0))
		{
			return false;
		}
		this->power = this->power - n;
		return true;
	}

	bool addFriend(Human& human)
	{
		if (arrSize < loyalty)
		{
			this->friends[this->arrSize] = &human;
			this->arrSize++;
			return true;
		}
		return false;
	}
	int getPower() const
	{
		return this->power;
	}
	
	int getSumOfFriendsPower()
	{
		int sum = 0;
		for (int i = 0; i < arrSize; i++)
		{
			sum = sum + friends[i]->getPower();
		}
		return sum;
	}

	virtual double revengePoint() = 0;
	virtual char* getSpecialSkill() = 0;
	virtual char* getType() = 0;
protected:
	char* name;
	int power;
	int loyalty;
	int arrSize;
	Human** friends;

	void init(char* name, int power, const int loyalty, Human* friends = NULL)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name), name);
		this->power = power;
		this->loyalty = loyalty;
	}
};

class Normal_human :public Human
{
public:
	Normal_human(char* name = "", int power = 0, int loyalty = 0) :Human(name, power, loyalty)
	{

	}

	char* getSpecialSkill()
	{
		return "none";
	}
	char* getType()
	{
		return "normal human";
	}

	bool addFriend(Human &f)
	{
		if ((strcmp(f.getType(), "normal human") == 0))
		{
			Human::addFriend(f);
			return true;
		}
		return false;
	}

	bool removeFriends(char* name)
	{
		int index = 0;
		for (int i = 0; i < this->arrSize; i++)
		{
			if ((strcmp(this->getName, name) == 0))
			{
				index = i;
				break;
			}
		}
		if (index == 0)
		{
			return false;
		}
		for (int i = index; i < arrSize; i++)
		{
			this->friends[i] = this->friends[i + 1];
		}
		this->arrSize--;
		return true;
	}

	double revengePoint()
	{
		return this->getSumOfFriendsPower();
	}

};


class Army
{
public:
	Army(int numberOfSoldiars, Human** soldiar, Human* leader)
	{
		this->numberOfSoldiars = numberOfSoldiars;
		for (int i = 0; i < numberOfSoldiars; i++)
		{
			this->soldiar[i] = soldiar[i];
		}
		this->leader = leader;
		
	}
	Army(const Army& other)
	{
		this->numberOfSoldiars = other.numberOfSoldiars;
		for (int i = 0; i < numberOfSoldiars; i++)
		{
			this->soldiar[i] = other.soldiar[i];
		}
	}
	Army& operator=(const Army& other)
	{
		if (this != &other)
		{
			this->numberOfSoldiars = other.numberOfSoldiars;
			for (int i = 0; i < numberOfSoldiars; i++)
			{
				this->soldiar[i] = other.soldiar[i];
			}
		}
		return *this;
	}
	Army& operator>(const Army &other)
	{

	}

	virtual bool addSoldiar() = 0;
	virtual bool removeSoldiar() = 0;
	virtual bool addLeader() = 0;
	virtual double getValue() = 0;
	

protected:
	Human* soldiar[100];
	int numberOfSoldiars;
	Human* leader;
};

class Paid_Army : public Army
{
public:
	Paid_Army(int numberOfSoldiars, Human** soldiar, Human* leader) : Army(numberOfSoldiars, soldiar, leader)
	{

	}
	bool addLeader(Human& leader)
	{
		if ((strcmp(leader.getType(), "normal_human")) == 0)
		{
			this->leader = &leader;
			return true;
		}
		return false;
	}

	double getSalary()
	{
		double leader_salary = 20 / 100 * budjet;
		return (budjet - leader_salary) / numberOfSoldiars;
	}
	double getValue()
	{
		int sum = 0;
		int powerSum = 0;
		for (int i = 0; i < numberOfSoldiars; i++)
		{
			sum = sum + soldiar[i]->getSalary();
			powerSum = powerSum + soldiar[i]->getPower();
		}
		return leader->getLoyalty() * sum + powerSum;
	}



private:
	int budjet;
	double salary;
};

class Conscript_army :public Army
{
public:
	Conscript_army(int numberOfSoldiars, Human** soldiar, Human* leader) :Army(numberOfSoldiars, soldiar, leader)
	{

	}
	void addLeader(Human& leader)
	{
		this->leader = &leader;
	}

	double getValue()
	{
		int sum = 0;
		int powerSum = 0;
		for (int i = 0; i < numberOfSoldiars; i++)
		{
			sum = sum + soldiar[i]->getLoyalty();
			powerSum = powerSum + soldiar[i]->getPower();

		}
		return leader->getLoyalty() * sum + powerSum;
	}
};


