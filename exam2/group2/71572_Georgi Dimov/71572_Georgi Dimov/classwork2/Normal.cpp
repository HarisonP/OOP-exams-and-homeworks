#include "Normal_human.h"

void Normal::addFriend(Normal& other)
{
		friends[friendnum] = new Normal;
		friends[friendnum] = &other;
		friendnum++;

}
