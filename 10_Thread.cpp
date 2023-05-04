//
// Created by xuejun on 23-4-25.
//

//(1)线程的创建和使用
//(2)thread 不能拷贝构造，可以移动构造
//(3)join(),detach(),joinable(),thread::hardware_concurrency()
//(4)类成员函数作为线程入口：静态成员函数，非静态成员函数
//(5)call_once(flag,f,args),应用场景：单例模式，懒汉模式
#include<thread>
#include <iostream>
#include <mutex>
#include <functional>
#include <chrono>
#include <mutex>
using namespace std;

mutex mtx;
class Test
{
public:
    static void s_print(){cout<<"this is a static func call"<<endl;}
    void print(){cout<<"this is a non-static func call"<<endl;}
};
//region 基于callonce实现懒汉模式——>单例模式
once_flag flag;   //创建once_flag作为记录调用的标志
class SingleTest
{
public:
//    using foo = void(SingleTest);
//    function<SingleTest*()> f =[](){return new SingleTest;}

    static SingleTest* GetInstance()
    {
        call_once(flag,[&]()
        {
            obj = new SingleTest;
            cout<<"Instance has been created"<<endl;
        }
        );
        return obj;
    }
    void Setname(string name)
    {
        lock_guard<mutex> lk(mtx);  //不加锁线程之间访问同一变量引起冲突
        this->name = name;
        cout<<"This is "<<this->name<<endl;
    }
private:

    string name;
    static SingleTest* obj;
    SingleTest(){};    //构造函数必须写出来，否则无法类内创建对象
    SingleTest(const SingleTest&)=delete;
    SingleTest & operator=(const SingleTest&)=delete;
};
SingleTest* SingleTest::obj = nullptr;  //static变量类内声明，类外定义
void myFunc(string name)
{
    SingleTest::GetInstance()->Setname(name);
}
//endregion

int main()
{
//    thread t1(&Test::s_print);
//    Test tt;
//    thread t2(&Test::print,&tt);
//    t1.join();
//    t2.join();
//    cout<<thread::hardware_concurrency()<<endl;
    thread t1(myFunc,"Tommy");
    thread t2(myFunc,"Auther");
    thread t3(myFunc,"John");
    t1.join();
    t2.join();
    t3.join();


}