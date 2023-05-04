//
// Created by xuejun on 23-4-23.
//lambda
//[capture](params){};
//mutable关键字，修改[=]的值，但无法修改外部变量
//定义与调用()
//lambda函数本质
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

using funptr = int(*)();//指针类型 返回值为int

int main()
{
    int a=20;
    string str = "hello world";
    auto funcptr = [=]() mutable {printf("capture %d,  %s \n",++a,str.c_str());return 100;};
//    auto funcptr = [=]() mutable {printf("capture %d,  %s \n",++a,str.c_str());return 100;}(); //error
    funcptr();
    cout<<a<<endl;
}