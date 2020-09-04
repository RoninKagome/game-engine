#include "game_engine.h"
int Sprite::get_x()
{
	return x;
}
int Sprite::get_y()
{
	return y;
}
void Sprite::set_x(int x)
{
	this->x = x;
}
void Sprite::set_y(int y)
{
	this->y = y;
}
bool intersect(int* line1,int* line2)
{
	if(line1[0]!=line1[2]&&line1[1]!=line1[3])
	{
			double k = ((double)line1[3]-line1[1])/(line1[2]-line1[0]);
			double b = (double)line1[1]-(double)line1[0]*k;
			double f1 = k*line2[0]+b-line2[1];
			double f2 = k*line2[2]+b-line2[3];
			if(f1*f2<0) 
				return true;
			else
				return false;
	}
	if(line2[0]!=line2[2]&&line2[1]!=line2[3])
	{
			double k = ((double)line2[3]-line2[1])/(line2[2]-line2[0]);
			double b = (double)line2[1]-(double)line2[0]*k;
			double f1 = k*line1[0]+b-line1[1];
			double f2 = k*line1[2]+b-line1[3];
			if(f1*f2<0) 
				return true;
			else
				return false;
	}
	if(line1[0]==line1[2]&&line2[0]==line2[2]||line1[1]==line1[3]&&line2[1]==line2[3])
		return false;
	if(line1[0]==line1[3]&&(line2[0]-line1[0])*(line2[3]-line1[0])<0&&(line1[1]-line2[1])*(line1[3]-line2[1])<0)
		return true;
	return false;
}
bool Sprite::collides_with(Sprite& obj)
{
	for(int i = 0; i+3 < collider_size; i+=2)
		for(int j = 0; j+3 < obj.get_collider_size(); j+=2)
		{
			int line1[4] = {x+collider[i],y+collider[i+1],x+collider[i+2],y+collider[i+3]};
			int line2[4] = {obj.get_x()+obj.get_collider()[j],obj.get_y()+obj.get_collider()[j+1],obj.get_x()+obj.get_collider()[j+2],obj.get_y()+obj.get_collider()[j+3]};
			if(intersect(line1,line2)) return true;
		}
	return false;
}
int* Sprite::get_collider()
{
	return collider;
}
void Sprite::set_collider(int* collider)
{
	this->collider = collider;
}
int Sprite::get_collider_size()
{
	return collider_size;
}
void Sprite::set_collider_size(int collider_size)
{
	this->collider_size = collider_size;
}
Sprite::Sprite()
{
	x=y=0;
}
void Sprite::move(int x, int y)
{
	this->x+=x;
	this->y+=y;
}
