#include <iostream>
using namespace std;
#include "game_engine.h"
bool intersect(int*,int*);
int main()
{
//	int line1[4] = {1,0,1,1};
//	int line2[4] = {2,0,0,1};
//	if(intersect(line1,line2))
//		cout << "intersect";
	Sprite obj1,obj2;
	int collider1[8] = { 0,0,1,0,1,1,0,1};
	int collider2[6] = { 2,0,0,1,2,1};
	obj1.set_collider(collider1);
	obj1.set_collider_size(8);
	obj2.set_collider(collider2);
	obj2.set_collider_size(6);
	obj2.move(1,0);
	for(int i = 0; i < 2; i++)
	{
		if(obj1.collides_with(obj2))
			cout << "collides";
		else
			cout << "|\n";
		obj2.move(-1,0);
	}
}
