//
// Created by xuejun on 23-4-23.
//
//不推荐使用的auto场景
//1.auto推导不作为函数参数
//2.auto不作为类内静态成员变量定义
//3.auto不作为模板参数推导
//4.auto不作为数组定义
#include<map>
#include<iostream>
using namespace std;
int main()
{
    map<int,string> Map1;
    Map1.insert(make_pair(1,"zhangsan"));
    Map1.insert(make_pair(2,"wangwu"));
    Map1.insert(make_pair(3,"zhaosi"));
    for(auto n:Map1)
    {
        cout<<n.first<<"  "<<n.second<<endl;
    }
}
