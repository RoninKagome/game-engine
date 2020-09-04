class Sprite {
private:
	int x,y,*collider,collider_size;
public:
	int get_x();
	void set_x(int x);
	int get_y();
	void set_y(int y);
	int* get_collider();
	void set_collider(int*);
	int get_collider_size();
	void set_collider_size(int);
	bool collides_with(Sprite&);
	Sprite();
	void move(int,int);
};
