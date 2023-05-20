//
// Created by xuejun on 23-5-20.
//
//子类指针指向父类
//通过c++多态实现函数功能封装，外部只能调用父类暴露的接口，无法对子类方法进行访问
#include <iostream>
#include <memory>
using namespace std;
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
int main()
{
    auto p = Test_func();
    p->forward();
}