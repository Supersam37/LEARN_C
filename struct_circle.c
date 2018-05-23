struct circle{
	struct pt_2d *center;
	int radius;
}; 

struct pt_2d {
	int x,y;
}pt1 = {100,200};

struct circle_t c1 = {&pt1,100};
c1.center->x ==200; 
