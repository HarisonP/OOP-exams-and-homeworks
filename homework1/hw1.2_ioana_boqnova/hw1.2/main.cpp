#include <cstdlib>
#include "list.h"

using namespace std;

int main()
{
	Date d1;
	d1.setDate(1, 2, 1990);

	Person pesho;
	pesho.setDate(d1);
	pesho.setName("Petrov");
	pesho.print();

	Date d2;

	Person ivan;
	ivan.setName("Ivanov");
	ivan.setDate(d2);
	pesho = ivan;
	pesho.print();

	ListPerson l1;
	ListPerson l2;

	l1.addPerson(ivan);
	l1.print();
	l2.addPerson(pesho);
	l2.print();

	l1.addPerson(pesho);
	l1.print();  
	l1.deletePerson("Ivanov");
	l1.print();

	l1.getPerson("Petrov");
	l1.unionList(l2);
	l1.sectionList(l2);
	l1.differenceList(l2);

	l1.getZodia("Petrov");

	system("pause");
	return 0;
}
