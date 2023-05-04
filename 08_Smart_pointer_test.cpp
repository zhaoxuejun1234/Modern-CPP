//
// Created by xuejun on 23-4-24.
//
//shared_ptr unique_ptr weak_ptr
// 成员函数 use_count() rest()
//指定删除器 数组元素无法采用默认的删除器删除
//
#include<iostream>
#include<memory>
using namespace std;

//region shared_ptr
template<typename T>  //采用模板函数定义智能指针，支持数组格式
shared_ptr<T> make_ptr(int size)
{
    return shared_ptr<T>(new T[size],[](T* p ){delete[] p;});
}

void Test()
{
    int* p = new int[4]{1,2,3,4};
    shared_ptr<int> p1(p);
//    shared_ptr<int> p2(p);  //禁止对一个变量进行两次初始化
    shared_ptr<int> p2(p1);
    auto p3 = make_shared<int>();
    auto p4 = p3;
    cout<<"p4 use_count is "<<p4.use_count()<<endl;
//    getchar();
    auto p5 = new int;
    p4.reset(p5);
//    auto p3 = make_shared<int[]>(1,2,3,4); //C++20特性
//    std::shared_ptr<double[]> sp7 = std::make_shared<double[]>(256, 2.0);//C++20特性
    cout<<p1.use_count()<<endl;
    auto p6 = move(p1);
    cout<<p1.use_count()<<endl;
    cout<<p2.use_count()<<endl;


    shared_ptr<int> ptr(new int[10],[](int* p){delete[] p;});
    shared_ptr<int> ptr4(new int[10], default_delete<int[]>());
//    unique_ptr<int> ptr2(new int[4],default_delete<int[]>());//unique_ptr则没有该属性
    auto ptr6 = make_ptr<int>(10);


}
//endregion
//region unique_ptr
//定义方法
void Test2()
{
    int* p10 = new int[10]{0,12,3,3,4,5,6,7,12,1};
    for(int i =0;i<10;i++)
    {
        cout<<*p10++<<endl;
    }
    unique_ptr<int> up1(p10) ;
    unique_ptr<int> up2 = move(up1);
    up2.reset();


    //定义删除器,unique_ptr需要指定删除器类型
    using func_delete = void(*)(int*);
    unique_ptr<int,func_delete> p11(new int[10],[](int* p){delete[] p;});
}


//endregion
int main()
{
//    Test();
    Test2();
}