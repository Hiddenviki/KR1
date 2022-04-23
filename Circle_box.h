
#ifndef KR1_CIRCLE_BOX_H
#define KR1_CIRCLE_BOX_H
#include "Circle.h"
#include "StreamTable.h"
using namespace std;

class Circle_box{
public:
    Circle* Array;
    Circle_box(){Array = new Circle[0];}

    void addElement()
    {
        Circle* tmp;
        tmp = (Circle*)std::realloc(Array, (Circle::count + 1) * sizeof(Circle));
        if (tmp != nullptr)
        {
            Array = tmp;
            setData(Array,Circle::count);
            Circle::count++;
        }
        else
        {
            cout<<"Бывают в жизни взлёты и падения, но в основном падения\n";
        }
    }
    void showData()
    {

        StreamTable st(std::cout);
        st.AddCol(10);
        st.AddCol(10);
        st.AddCol(10);

        st.MakeBorderExt(true);
        st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
        st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк

        st << "RADIUS" << "X" << "Y";
        for (int i = 0; i < Circle::count; i++)
        {
            st << Array[i].get_radius() << Array[i].get_center_x() << Array[i].get_center_y();
        }
    }

    ~Circle_box(){cout<<"Память почистилас"<<endl;}
};


#endif //KR1_CIRCLE_BOX_H
