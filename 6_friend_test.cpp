//
// Created by xuejun on 23-4-24.
//

//定义类的友元类，可以通过友元类对类的私有成员进行访问
#include<iostream>
#define Pi 3.14
using namespace std;
class Verify;
//region 友元类example
//class Rectangle
//{
//    friend Verify;
//public:
//    void Area(int length,int wdith)
//    {
//        printf("Area is %d",length*wdith);
//    }
//private:
//    int length;
//    int width;
//};
//class Circle
//{
//
//public:
//    friend Verify;
//    void Area(int radius)
//    {
//        printf("Area is %f",Pi*radius*radius);
//    }
//private:
//    int radius;
//};
//class Verify
//{
//public:
//    void print()
//    {
//        Rectangle r1;
//        r1.Area(10,5);
//    }
//
//
//private:
//};
//endregion

//region 加入模板
template<typename T>
class Rectangle
{
    friend T;
public:
    Rectangle(int length,int width):length(length),width(width){};

private:
    int length;
    int width;
};
template<typename T>
class Circle
{

public:
    friend T;
    Circle(int radius):radius(radius){};
private:
    int radius;
};
class Verify
{
public:
    void VerifyCircle(int radius, Circle<Verify> &c)
    {
        cout<<c.radius<<endl;
    }
    void VerifyRectangle(int l ,int w,Rectangle<Verify> &r)
    {
        cout<<r.length<<"  "<<r.width<<endl;
    }


private:
};
//endregion

int main()
{
    Rectangle<Verify> r1(10,5);
    Circle<Verify> c1(10);
    Verify v1;
    v1.VerifyCircle(55,c1);
    v1.VerifyRectangle(22,22,r1);
}