#include<iostream>

using namespace std;

// 1. Encapsulation 
 // 2. Inheritance
// 3. Abstraction
// 4. Polymorphism

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
};
class Normal_human : public Human{
public:
	Normal_human();
	~Normal_human();
};

int main(){
	Human x;
	Human y;

	x.set_name("No Name");
	x.set_strong(10);
	x.set_loyalty(10);

	y.set_name("No Name1");
	y.set_strong(14);
	y.set_loyalty(14);


	system("pause");
	return 0;
}