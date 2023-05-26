//
// Created by xuejun on 23-5-26.
//
/*开始本文件的测试之前，确定自己的系统安装了jsoncpp库，github地址如下 https://github.com/open-source-parsers/jsoncpp
 *Json文件是C++面向对象编程更常见的文件格式，借助json开源库能够快速的实现json文件的解析
 * Json主要有两种数据格式，分别为Json数组和Json对象
 */
#include <json/json.h>
#include <fstream>
#include <iostream>
using namespace std;
using namespace Json;
//采用Json提供的Value：：toStyledString方法进行序列化，该方法序列化的字段带换行
void WriteJson()
{
    Value root;
    root.append("Naruto");
    root.append("Village of Fire");

    Value dict1;
    dict1["Sex"]="man";
    dict1["Class"]="Level Master";
    Value dict2;
    dict2["Ability"]="Wind";
    dict2["Tasks"]="Level S";
    Value dict3;
    dict3["Magic"]= "Multi-Person";
    dict3["Body"]= "Bullet-proof";
    dict3["Field"] = dict2; //字典的嵌套
    root.append(dict1);
    root.append(dict3);
    string str = root.toStyledString();
    ofstream of("Naruto.json");
    of<<str;
    of.close();

}
//采用Json提供的Reader方法进行解析
void ReadJson()
{
    ifstream file("../cmake-build-debug/Naruto.json");
    Value root;
    Reader reader;
    if(reader.parse(file,root))
    {
            for(auto &item:root)
        {
            if (item.isObject())
            {
                cout<<"Object has benn detected"<<endl;
                Value::Members keys = item.getMemberNames();
                for (auto &key: keys)
                {
                    cout << key << ": " << item[key] << endl;
                }
            }
        }
    }
    else
        cout<<"Parse file failed"<<endl;
}
int main()
{
//    WriteJson();
    ReadJson();
};