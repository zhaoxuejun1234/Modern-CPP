//
// Created by xuejun on 23-4-23.
//

//1 .可调用对象分以下几种:
//(1)函数指针
//(2)具有operator()成员函数的类对象
//(3)可被转为函数指针的类对象
//(4)类的函数指针、类的成员指针
#include <iostream>
#include <functional>
#include <string>


using namespace  std;
void print(string str,int b)
{
    printf("%s value is %d",str.c_str(),b);
}
class Test
{
public:

    Test() = default;
    ~Test() = default;
    void operator() (){cout<<" operator() "<<endl;}
private:
};
using funcptr = void(*)(string, int);
int main()
{
    Test t;
    t();  //(2)具有operator()成员函数的类对象


}

