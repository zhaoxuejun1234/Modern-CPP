//
// Created by xuejun on 23-4-22.
//
#include<iostream>
#include<initializer_list>
using namespace std;

//可以通过初始化列表对聚合类进行初始化
//1.普通数组
//2.类：(1)无基类,无虚函数;(2)无私有或者保护成员(3)无自定义构造函数
//非聚合类型初始化化需要自定义构造函数

void func(initializer_list<int> ls)
{
    for(const auto &n:ls)  //基于范围的for循环，采用引用的方式省去了拷贝，效率更高
    {
        cout<<n<<endl;
    }
}

int main()
{
    int array1[]={1,2,3,45};
    int a{10};
//    cout<<a<<endl;
    func({1,2,3,4,5,5,5,5,5});
}

