#include<iostream>

using namespace std;

class Human {
public:
	Human();
	Human(char* name, int strong, int loyalty);
	~Human();
	void set_name(char* name){
		this->name = name;
	}
	char* get_name(){
		return name;
	}
	void set_strong(int strong){
		this->strong = strong;
	}
	int get_strong(){
		return strong;
	}
	void set_loyalty(int loyalty){
		this->loyalty = loyalty;
	}
	int get_loyalty(){
		return loyalty;
	}

protected:
	char* name;
	int strong;
	int loyalty;

};
Human::Human(char* name, int strong, int loyalty){
	this->name = name;
	this->strong = strong;
	this->loyalty = loyalty;
}
class Normal_human : public Human{
public:
	Normal_human();
	~Normal_human();

};

class Army{
public:
	Army();
	Army(Human* s[100], int number, Human* lider);
	~Army();
	void set_number(int number){
		this->number = number;
	}
	int get_number(){
		return number;
	}

protected:
	Human* s[100];
	int number;
	Human* lider;
};
Army::Army(Human* s[100], int number, Human* lider){
	this->s[100] = s[100];
	this->number = number;
	this->lider = lider;
}
class Paid_army : public Army{
public:
	Paid_army();
	Paid_army(int budjet, int salaryN, Human* s[100], int number, Human* lider);
	~Paid_army();
	void set_bidjet(int budjet){
		this->budjet = budjet;
	}
	int get_budjet(){
		return budjet;
	}
	void set_salaryN(int salaryN){
		this->salaryN = salaryN;
	}
	int get_salaryN(){
		return salaryN;
	}
protected:
	int budjet;
	int salaryN;
};
Paid_army::Paid_army(int budjet, int salaryN, Human* s[100], int number, Human* liderr){
	this->budjet = budjet;
	this->salaryN = salaryN;
}
Paid_army::Paid_army(int budjet, int salaryN, Human* s[100], int number, Human* liderr) : public Army(Human* s[100], int number, Human* lider){
	this->s[100] = s[100];
	this->number = number;
	this->lider = lider;

}
class Conscript_army : public Army{
public:
	Conscript_army();
	~Conscript_army();

	void set_mark(int mark){
		this->mark = mark;
	}
	int get_mark(){
		return mark;
	}

	int operator >(Conscript_army x){
		if (this->mark > x.mark){
			return this->mark;
		}
		else
		{
			return x.mark;
		}
	}

protected:
	int mark;
};
int main(){
	
	Army z;
	Paid_army a;
	Conscript_army b;
	Conscript_army b1;

	b.set_mark(5);
	b1.set_mark(6);
	cout << b.get_mark() << b1.get_mark() << endl;

	cout << (b > b1) << endl;

	system("pause");
	return 0;
}