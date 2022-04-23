//
// Created by Виктория Веселкова on 21.04.2022.
//

#ifndef KR1_POINT_H
#define KR1_POINT_H

#include <iostream>
using namespace std;

class Point{
private:
    int x;
    int y;
public:
    void set_x(int new_x){x = new_x;};
    void set_y(int new_y){y = new_y;};

    int get_x(){return x;};
    int get_y(){return y;};

    Point()
    {
        x = 1;
        y = 1;
    };

};

#endif //KR1_POINT_H
