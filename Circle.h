
#ifndef KR1_CIRCLE_H
#define KR1_CIRCLE_H
#include "Point.h"
//class Point;

class Circle{

private:
    int radius;
    Point Center;

public:
    static int count;
    void set_radius(double new_radius){radius = new_radius;}

    int get_radius(){return radius;};
    int get_center_x(){return Center.get_x();};
    int get_center_y(){return Center.get_y();};

    void set_center_x(double new_x){Center.set_x(new_x);};
    void set_center_y(double new_y){Center.set_y(new_y);};

    Circle()
    {
        radius = 2;
    };

    friend void setData(Circle* Obj, int amount);
    friend void Search_OX(Circle* Obj, int amount);
    friend void Search_OY(Circle* Obj, int amount);
    friend void double_massiv(Circle* Obj);
    friend void for_random(Circle* Obj);
};


#endif //KR1_CIRCLE_H
