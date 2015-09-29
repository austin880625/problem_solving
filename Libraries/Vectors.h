#include<math.h>
struct Vector;
double cross(Vector a,Vector b);
double dot(Vector a,Vector b);
struct Vector
{
    double x,y;
    bool operator < (const Vector &rhs)const{return cross((Vector){x,y},rhs)>0;}
    bool operator == (const Vector &rhs)const{return fabs(x-rhs.x) <= 1e-10 && fabs(y-rhs.y) <= 1e-10;}
    Vector operator + (const Vector &rhs)const{return (Vector){x+rhs.x,y+rhs.y};}
    Vector operator - (const Vector &rhs)const{return (Vector){x-rhs.x,y-rhs.y};}
};

double cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}

double dot(Vector a,Vector b)
{
    return a.x*b.x+a.y*b.y;
}