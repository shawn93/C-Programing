#include <stdio.h>
#include <stdlib.h>

struct point {
    int x, y; 
};

struct rectangle { 
    struct point upper_left, lower_right; 
};

int area(const struct rectangle* r) {
    int w,l;
    w = (r->lower_right).x - (r->upper_left).x;
    l = (r->lower_right).y - (r->upper_left).y;
    return abs(w*l);
}       
//this function returns the area of r.

struct point center(const struct rectangle* r) {
    int x,y;
    x = ((r->lower_right).x + (r->upper_left).x)/2;
    y = ((r->lower_right).y + (r->upper_left).y)/2;
    struct point pt = {x, y};
    return pt;
}; 
//this function returns the center point of r. If either the x or y coordinate 
//of the center is not an integer, store its truncated value in the point structure.

struct rectangle move(const struct rectangle* r, int addx, int addy) {
    int x1,x2,y1,y2;
    x1 = (r->upper_left).x + addx;
    x2 = (r->lower_right).x + addx;
    y1 = (r->upper_left).y + addy;
    y2 = (r->lower_right).y + addy;
    struct rectangle box = {{x1, y1}, {x2, y2}};
    return box;
}; 
//this function moves r by addx units in the x direction and addy units 
//in the y direction, returning the modified version of r.

int inside(const struct rectangle* r, const struct point* p) {
    if(((p->x)>(r->upper_left).x) && ((p->x)<(r->lower_right).x) && ((p->y)>(r->lower_right).y) && ((p->y)<(r->upper_left).y)) {
        return 1;
    }
    return 0;
} 
//this function returns 1 if point p lies within rectangle r and 0 otherwise.

int main() {
    struct rectangle box = {{2,8},{10,3}};
    struct point p = {3,6};
    printf("area is %d\n", area(&box));
    struct point c = center(&box);
    printf("center is (%d,%d)\n", c.x, c.y);
    struct rectangle box2 = move(&box, 3, 6);
    printf("moved to (%d,%d) and (%d,%d)\n", box2.upper_left.x, box2.upper_left.y, box2.lower_right.x, box2.lower_right.y);
    printf("inside function test result is %d\n", inside(&box,&p));
}
