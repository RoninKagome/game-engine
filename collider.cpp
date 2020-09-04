#include "collider.h"
Collider& Collider::add(int x,int y)
{
	int *tmp = new int[size+2];
	for(int i = 0; i < size; i++)
		tmp[i] = collider[i];
	delete [] collider;
	tmp[size] = x;
	tmp[size+1] = y;
	collider = tmp;
	size+=2;
	return *this;
}
Collider::Collider()
{
	collider = NULL;
	size = 0;
}
void Collider::squere(int width, int height)
{
	if(collider) delete [] collider;
	if(size) size = 0;
	add(0,0).add(width,0).add(width,height).add(0,height);
}
void Collider::elipse(int width, int height)
{
	if(collider) delete [] collider;
	if(size) size = 0;
	for(int i = 0; i < width; i++)
	{
		double w = width, x = i, h = height;
		double y = (w*w+(x-h/2)*(x-h/2)-(w-x-h/2)*(w-x-h/2))/2/w;
		double visota = sqrt(y*y-(x-h/2)*(x-h/2));
		add(x,h/2-visota);
	}
	for(int i = size-1; i > 0; i--)
		add(collider[i*2],height-collider[i*2+1]);
}
