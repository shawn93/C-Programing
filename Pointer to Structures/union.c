#include <stdio.h>
#include <math.h>
// #define M_PI 3.14159265358979323846

struct point { 
    int x, y; 
};

struct shape {
    enum {RECTANGLE, CIRCLE} shape_type;
    struct point center; //coordinates of center
    union {
        struct {int height, width;} rectangle;
        struct {int radius; } circle;
        } u;
};

void display(const struct shape s) {
    if(s.shape_type == RECTANGLE) {
        printf("[rectangle] center point: (%d,%d)  ", s.center.x, s.center.y);
        printf("height: %d  width: %d\n",s.u.rectangle.height, s.u.rectangle.width);
    }
    if(s.shape_type == CIRCLE) {
        printf("[cirlcle] center point: (%d,%d)  ", s.center.x, s.center.y);
        printf("radius: %d\n", s.u.circle.radius);
    }
} 
//this function displays the contents of s based onits shape type. 
//If it is a RECTANGLE, display x, y center point and the height and width.
//If it is a CIRCLE, display x, y center point and the radius.

double area(struct shape* s) {
    double area = 0.0;
    if(s->shape_type == RECTANGLE) {
        area = ((s->u).rectangle.height) * ((s->u).rectangle.width);
    }
    if(s->shape_type == CIRCLE) {
        area = M_PI * (s->u).circle.radius * (s->u).circle.radius;
    }
    return area;
} 
//this function returns the area of s.

struct shape move(const struct shape* s, int addx, int addy) {
    struct shape tmp;
    tmp.shape_type = s->shape_type;
    tmp.u = s->u;
    tmp.center.x = (s->center).x + addx;
    tmp.center.y = (s->center).y + addy;
    return tmp;
};
// //this function moves by addx units in the x direction and addy units in the y direction, 
// //returning the modified version of s.

struct shape scale(const struct shape* s, double c) {
    struct shape tmp;
    tmp.shape_type = s->shape_type;
    tmp.u = s->u;
    tmp.center = s->center;
    if(tmp.shape_type == RECTANGLE) {
        tmp.u.rectangle.height *= c;
        tmp.u.rectangle.width *= c; 
    }
    if(tmp.shape_type == CIRCLE) {
        tmp.u.circle.radius *= c;
    }
    return tmp;
}; 

//this function returns the modified version of s which is scaled by the factor c.

int main() {
    struct shape a={RECTANGLE, {0,0}, {3,4}};
    struct shape b={CIRCLE, {0,0}, {5}};
    display(a);
    display(b);
    printf("a area is %f\n", area(&a));
    printf("b area is %f\n", area(&b));
    display(move(&a, -5, -2));
    display(move(&b, -5, -2));
    display(scale(&a,1.5));
    display(scale(&b,0.8));
}