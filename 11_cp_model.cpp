//
// Created by xuejun on 23-4-26.
//
//建立一个生产者-消费者模型，构建一个任务队列
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <future>
using namespace std;
class TaskQueue
{
public:
    void Taskpush()
    {
        while (true)
        {
            {
                unique_lock<mutex> lock(mtx);
                cv1.wait(lock,[this](){return Tasks.size()<10;});
                Tasks.push(count);
                cout<<this_thread::get_id()<<" Push Task "<<count<<endl;
                cv2.notify_one();

            }
            this_thread::sleep_for(chrono::seconds(1));
            count++;
        }
    }

    void TaskGet()
    {
        while (true)
        {

            {
                unique_lock<mutex> lock(mtx);
                cv2.wait(lock,[this](){return !Tasks.empty();});
                cout<<this_thread::get_id()<<" get Task "<<Tasks.front()<<endl;
                Tasks.pop();
                cv1.notify_one();
            }

            this_thread::sleep_for(chrono::seconds(2));
        }
    }
private:
    queue<int> Tasks;
    mutex mtx;
    condition_variable cv1;
    condition_variable cv2;
    int count =0;
    promise<int> pro;
};



int main()
{
    TaskQueue t;
    thread t1(&TaskQueue::Taskpush,&t);
    thread t2(&TaskQueue::TaskGet,&t);
    t1.join();
    t2.join();
    return 0;
}