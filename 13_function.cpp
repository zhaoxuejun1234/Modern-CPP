//
// Created by xuejun on 23-4-27.
//
#include <functional>
#include <iostream>


using namespace std;

//什么是可调用对象，什么是包装器，什么是绑定器
//可调用对象：类似于函数可以直接调用的对象
// (1)函数指针;(2)具有operator()的成员函数;(3)类对象转换的函数指针;(4)类成员指针或者函数指针
//region 一、可调用对象
void print_func()
{
    cout<<"This is a func pointer test"<<endl;
}
void Call_test() //函数指针
{
    void(*func)() = print_func;
    func();
}


//endregion



//region二、绑定器

//std::function支持了四种函数的封装
// 1. 普通函数
// 2. 匿名函数
// 3. 类的成员函数
// 4. 仿函数（重载了() 运算符的函数）

//endregion

//region 1.普通函数
string Test_func()
{
//    cout<<"This is normal func test"<<endl;
    return "this is a normal func test";
}
//endregion
//region2.匿名函数
//function<int(int)> task2 = ([](int num){cout<<"std::function has been called";return num+200;});
//endregion
//region3.类的成员函数
class FuncTest
{
public:
    FuncTest(int a, int b):a(a),b(b){};
    void operator()(int num){cout<<"operator() test "<<num<<endl;}
    static int decrease()
    {
        return 100;
    }
    int add(int m)
    {
        printf("para test %d \n",m);
        return a+b;
    }

private:
    int a;
    int b;

};

void Test_class()
{
    FuncTest F(10,90);
    function<int(FuncTest*,int)> f3 = &FuncTest::add; //function模板那参数定义大同小异，function<返回值类型(参数类型)>,不同的是类的指针需要作为参数传入
    cout<<f3(&F,6)<<endl;
    function<int(void)> f5 = &FuncTest::decrease;//包装静态成员函数
    cout<<"Decrease return value is "<<f5()<<endl;

}
//endregion

//region 4.包装仿函数
void Operator_test()
{
    FuncTest T1(10,10);
    function<void(int)> f4 =T1;
    f4(10);
}

//endregion

//region三、bind 函数绑定器，绑定函数和变量，使函数以固定的格式进行调用
void bind_test()
{
    FuncTest A(20,20);
    auto f = bind(&FuncTest::add,&A,placeholders::_1); // 类成员函数bind
    cout<<"bind_function reuslt is "<<f(31)<<endl;
    auto f2 = bind(&FuncTest::decrease);
    cout<<"bind_function result of static function is "<<f2()<<endl;
}


//endregion

int main()
{
//    function<string(void)> f1 = Test_func;   //绑定器绑定普通函数
//    cout<<f1()<<endl;
//    Test_class();
//    Operator_test();
//
//    FuncTest T1(10,10);
//    T1(8);
//    Call_test();
    bind_test();
}
