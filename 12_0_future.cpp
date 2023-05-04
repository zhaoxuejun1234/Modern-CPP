//
// Created by xuejun on 23-4-26.
//
//在主线程中创建 std::promise 对象
//将这个 std::promise 对象通过引用的方式传递给子线程的任务函数
//在子线程任务函数中给 std::promise 对象赋值
//在主线程中通过 std::promise 对象取出绑定的 future 实例对象
//通过得到的 future 对象取出子线程任务函数中返回的值。

#include <iostream>
#include <future>
#include <thread>

using namespace std;
using f = void(*)();
void Future_test()
{
    promise<int> pro;
    thread t1([](promise<int> &p){p.set_value(100);this_thread::sleep_for(chrono::seconds(3));cout<<"线程休眠结束"<<endl;},ref(pro));

    future<int> f = pro.get_future();
    auto value = f.get();
    cout<<"value is "<<value<<endl;
    t1.join();
}
int main()
{
    Future_test();
}