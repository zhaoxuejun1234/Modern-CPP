//
// Created by xuejun on 23-4-25.
//

//(1)什么是原子操作；不可拆分的操作(磁盘读取数据-->CPU计算-->磁盘存取数据，文件IO时会失去对CPU的控制，导致新的数据还没更新，旧的数据被其他线程取出)
//(2)atomic 支持的类型及特化类型
//(3)atomic 成员函数：store/load/exchange
//(4)基于原子变量多线程数值加法


#include <iostream>
#include <atomic>
#include <thread>
using namespace std;
//region 基本atomic变量测试
void atom()
{
    atomic<bool> flag;
    flag=true;
    flag.load();
    printf("flag value is %d \n",flag.load());
    flag.store(false);
    printf("flag value is %d \n",flag.load());
    atomic_int num;
    atomic_init(&num,9);
    cout<<num<<endl;
}
//endregion

//region 采用原子变量实现一个多线程加法操作
class Counter
{
public:
    void increment1()
    {
        for(int i =0;i<10000;i++)
        {
            num++;
        }
    }
    void increment2()
    {
        for(int i =0;i<10000;i++)
        {
            num++;
        }
    }

    void init()
    {
        atomic_init(&(this->num),0);
    }

    void getNum()
    {
        cout<<"value is "<<num<<endl;
    }
private:
    atomic_int num;
//    int num = 0;   //普通int类型不是线程安全的

};
//endregion

int main()
{
//    atom();
    Counter c;
    c.init();
    thread t1(&Counter::increment1,&c);
    thread t2(&Counter::increment2,&c);
    t1.join();
    t2.join();
    c.getNum();
    return 0;

}

