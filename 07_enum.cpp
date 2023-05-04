//
// Created by xuejun on 23-4-24.
//

//强作用域，强类型枚举成员的名称不会被输出到其父作用域空间。
//强类型枚举只能是有名枚举，如果是匿名枚举会导致枚举值无法使用（因为没有作用域名称）。
//转换限制，强类型枚举成员的值不可以与整型隐式地相互转换
#include<iostream>
using namespace std;
enum class Color :char{Red,Blue,Black};

int main()
{
    Color c1 = Color::Red;
    cout<<sizeof(c1)<<endl;
    cout<<sizeof(int(c1))<<endl;  //显式的类型转换

}