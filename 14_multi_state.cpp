//
// Created by xuejun on 23-5-20.
//
//父类指针指向子类
//通过c++多态实现函数功能封装，外部只能调用父类暴露的接口，无法对子类方法进行访问
#include <iostream>
#include <memory>

using namespace std;
//region multi-state abstract class
class Infer
{
public:
    virtual void forward()=0;
};
class InferImp:public Infer
{
public:
    void forward() override
    {
        cout<<"InferImp forward func has been called"<<endl;
    }
    void new_func()
    {
        cout<<"A func belong to InferImp"<<endl;
    }
};
shared_ptr<Infer> Test_func()
{
    shared_ptr<InferImp> p1(new InferImp());
    return p1;
}
//endregion
class Desk
{
public:
    virtual void print(){}

};
class Desk2:public Desk
{
public:
    void print(){cout<<"Desk2 print"<<endl;}
    void get(){cout<<"Call get fun"<<endl;}

};
int main()
{
    Desk* p2 = new Desk;
    p2 = new Desk2;
    p2->print();
//    auto p = Test_func();
//    p->forward();



}