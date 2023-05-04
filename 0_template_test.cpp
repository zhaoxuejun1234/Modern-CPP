//
// Created by xuejun on 23-4-22.
//
#include<iostream>
#include <map>

using namespace std;
// region0函数返回值类型推倒
template<typename T,typename R>
auto add(T a,R b) -> decltype(a+b)
{
    auto m=a+b;
    return m;
}
//endregionm
//region1 templat+map
template <typename T>
struct My_map
{
    typedef map<int,T> Mymap;
};
template <typename T>
using MMmap = map<int,T>;
template <typename T1>
class Container
{
public:
    void tp(T1& t)
    {
        auto it = t.begin();
        for(;it!=t.end();++it)
        {
            cout<<it->first<<"  "<<it->second<<endl;
        }
    }
};
//endregion
int main()
{
    //    cout<<add(3, 4.0)<<endl;
    My_map<int>::Mymap map1;
    map1.insert(make_pair(1,1));
    map1.insert(make_pair(2,2));
    map1.insert(make_pair(3,3));
    My_map<double>::Mymap map2;
    My_map<string>::Mymap map3;
    Container<My_map<int>::Mymap> C1;
    C1.tp(map1);


}


