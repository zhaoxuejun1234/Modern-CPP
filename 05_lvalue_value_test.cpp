//
// Created by xuejun on 23-4-23.
//
//左值locator value 存储在内存中、有明确地址的数据
//右值read value   可以提供数据值的数据  纯右值(数字)，将亡值(move();临时对象)
//右值分为纯右值、将亡值
//左值引用&
//右值引用&&   应用于临时对象
//类型推导左右值引用 T&& auto&&
// move (1)所有权转移 (2)左值变为右值
//forward 类型转发 std::forward<T>();
#include<iostream>
using namespace std;
class Test
{
public:
    Test():num(new int(100))
    {cout<<"Build"<<endl;}

    Test(const Test& obj):num(new int(*obj.num))
    {
        cout<<"Copy Build"<<endl;
    }
    Test(Test&& obj):num(obj.num)
    {
        obj.num= nullptr;
        cout<<"Move Build"<<endl;
    }
    ~Test()
    {
        delete num;
        cout<<"Destroy"<<endl;
    }

//private:
    int* num;
};
Test getobj()
{
//        return Test();
    Test t;
    printf("Test obj address is %p\n",&t);
    printf("this is division \n");
    return t;
}
int main()
{
//    int num = 9;
//    int& a= num;
//    int&& b = 10;  //延长变量生存周期
//    cout<<a<<"   "<<b<<endl;
//    Test t1;
//    Test&& t2 = move(t1); //move
    Test t3 = getobj(); //move   //    &getobj();
    printf("t3 obj address is %p \n",&t3);
    cout<<*t3.num<<endl;
//    Test t4 = t1; //copy build
//    printf("address is %p",&Test()); error 临时对象是右值，无法取地址

}