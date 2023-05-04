//
// Created by xuejun on 23-4-27.
//在future的基础上进行扩展
//两个线程异步调用方法，packaged_task类和async函数
//(1)async
//线程的异步调用，async函数，注意是函数
//不需要thread启动线程，通过async启动线程，返回future对象，而后实现异步调用
//async两种调用方法；async和deferred


#include <iostream>
#include <future>
#include <functional>
using namespace std;
//region Async
void TestAsync()
{
//    using f = void(int);
    auto f = [](int num){cout<<"Sub thread ID is "<<this_thread::get_id()<<endl;printf("num value is %d \n",num);return num;};
    future<int> ff = async(launch::deferred,f,100);
    this_thread::sleep_for(chrono::seconds(2));  //通过休眠查看线程的唤起顺序，async表示同步启动，deferred表示延时启动（当调用get方法时启动）
    cout<<"Main thread ID is "<<this_thread::get_id()<<endl;
//    this_thread::sleep_for(chrono::seconds(2));
    cout<<ff.get()<<endl;
}
//endregion


//region packaged_task
//(2)packaged_task
//本质是一个函数包装器,但std::function与之不同的是内部没有封装future对象，无法实现异步操作

//将可调用对象包装为package_task类，作为线程入口函数进行调用
//packaged_task类模板定义时需要提供返回值参数和函数参数
void Test_Package()
{
    packaged_task<int(int)> task([](int num){return num+100;});
    function<int(int)> task2 = ([](int num){cout<<"std::function has been called";return num+200;});
    thread t1(ref(task),100);
    thread t2(task2,100);
    auto f = task.get_future();
    cout<<f.get()<<endl;
    t1.join();
    t2.join();

}
//endregion
int main()
{
//    TestAsync();
    Test_Package();
    return 0;
}