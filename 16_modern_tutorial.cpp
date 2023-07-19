//Using C++14 compiler
#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <memory>
using namespace std;
//region STL
void STL_test()
{
    vector<int> v1;
    cout<<v1.size()<<"\t"<<v1.capacity()<<endl;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    cout<<v1.size()<<"\t"<<v1.capacity()<<endl;
    v1.clear();
    cout<<v1.size()<<"\t"<<v1.capacity()<<endl;
    v1.shrink_to_fit();
    cout<<v1.size()<<"\t"<<v1.capacity()<<endl;
    array<int,4> arr1={1,3,2,4};
    for(auto n:arr1)
    {
        cout<<n<<" ";
        cout<<endl;
    }
    sort(arr1.begin(),arr1.end());
    for(auto n:arr1)
    {
        cout<<n<<" ";
        cout<<endl;
    }
    unordered_map<int,int> map1 = {{1,1}};
    map1.insert({2,2});
    map1.insert({3,3});
    for (auto n:map1)
    {
        cout<<n.first<<" "<<n.second<<endl;
    }
}
//endregion
//regionSmartptr
void Smart_ptr()
{
    int* p = new int{1};
    auto sp1 = make_shared<int>(10);
    shared_ptr<int> sp2(p);
    auto sp3=sp2;
    cout<<"sp3 use_count"<<sp3.use_count()<<endl;
    cout<<"sp2 use_count"<<sp2.use_count()<<endl;
//    cout<<*sp1<<endl;
//    cout<<*sp2<<" "<<sp2.use_count()<<endl;
}
//endregion
//region 内存对齐
void Alignment()
{
#include <iostream>

    struct Storage {
        char      a;
        int       b;
        double    c;
        long long d;
    };

    struct alignas(std::max_align_t) AlignasStorage {
        char      a;
        int       b;
        double    c;
        long long d;
    };

        std::cout << alignof(Storage) << std::endl;
        std::cout << sizeof(Storage) << std::endl;
        std::cout << alignof(AlignasStorage) << std::endl;
        std::cout << sizeof(AlignasStorage) << std::endl;
}
//endregion
//regionLambda
void Lambda()
{
    int x =10;
    int y =20;
    cout<<"before lambda y is<< "<<y<<endl;
    auto lambda = [y]() mutable {y=30;};
    lambda();
    cout<<"after lambda y is<< "<<y<<endl;
}
//endregion
//regionnullptr
void test(const char*){cout<<"null ptr called"<<endl;}
void test(int){cout<<"null int called"<<endl;}
void null_test()
{
    test(nullptr);

}
//endregion
//region constexptr
class OBJ
{
public:
    template<class T>
    auto Test(const T& t)-> decltype(t) //const T&具有右值引用特性
    {
       if constexpr (is_integral<T>::value) {return t+1;}
       else{return t+0.1;}

    }
};
constexpr int fibnaci(int n)
{
    if(n==1 || n==2) {return 1;}
    return fibnaci(n-1)+fibnaci(n-2);
//    return n==1 || n==2? 1: fibnaci(n-1)+fibnaci(n-2);
}
//endregion
//region InitializerList
class Obj
{
public:
    vector<int> v1;
    Obj(initializer_list<int> list)
    {
        for(auto n:list)
        {
            v1.push_back(n);
        }
    }
    void print()
    {
        for(vector<int>::iterator iter = v1.begin();iter!=v1.end();++iter)
        {
            cout<<*iter<<"\t";
        }
        cout<<endl;
    }
//    vector<int>::iterator iter = v1.begin();

};


//endregion
//region Template
void Template()
{
    vector<int> v1{1,2,3,4,5,6};
    using iter = vector<int>::iterator;
    for(iter i=v1.begin();i!=v1.end();++i)
    {
        cout<<*i<<"\t";
    }
    cout<<endl;
}


//endregion
//region delegate construct
class OBJ2
{
public:
    OBJ2()=default;
    OBJ2(int i){cout<<"single int"<<endl;};
    OBJ2(int i,float j){cout<<"int and float"<<endl;};
    OBJ2(double d): OBJ2(){cout<<"int float and double"<<endl;};
};
//region enum
enum class animal:char {Sheep,Bat,Lion};
void enum_test(animal Animal)
{
    switch(Animal)
    {
        case animal::Sheep:
            cout<<"Sheep"<<endl;
            break;
        case animal::Bat:
            cout<<"Bat"<<endl;
            break;
        case animal::Lion:
            cout<<"Lion"<<endl;
            break;
    }

}
//endregion
//region function/bind/placeholders
void function_test(double y,int x=1)
{
    auto f =[](int x){return x>5? x:5;};

    auto f2 = function(f);

    function<int(int)> f3 = f;


    cout<<f2(8)<<endl;
    cout<<f3(4)<<endl;
    cout<<"x is "<<x<<'\t'<<"y is "<<y<<endl;
}
void bind_test()
{
    auto func = bind(function_test,placeholders::_1,placeholders::_2);
    func(3.5,10);
}


void lr_value()
{
    int i=10;
    int && l = 10;
    cout<< is_same<decltype(l),int&&>::value<<endl;
}
//endregion
int main()
{
//    STL_test();
//    Smart_ptr();
//    Alignment();
//    Lambda();
//    null_test();
//    cout<<fibnaci(9)<<endl;
//    Obj obj{1,2,3,4,5};
//    obj.print();
//    OBJ obj2;
//    const int i=10;
//    cout<<obj2.Test(10)<<endl;
//    OBJ2 obj;
//    OBJ2 obj2(3);
//    OBJ2 obj3(3,1.2);
//    OBJ2 obj4(3.88);
//    Template();
//    enum class animal:char {Sheep,Bat,Lion};
//    enum_test(animal::Bat);
//    function_test();
//    bind_test();
    lr_value();
    return 0;



}
