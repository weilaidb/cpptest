#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <array>
#include <map>
#include "string_all.h"

using namespace std;

string_all::string_all()
{

}

void print_string(const string &s)
{
    cout << s << endl;
}

void print_int(const int &i)
{
    cout << "i: " << i <<  endl;
}

void string_all::other_method()
{
    const char *cp = "Hello World!!!";
    char noNull[] = {'H', 'i'};
    string s1(cp); print_string(s1);
    string s2(noNull,2); print_string(s2);
    string s3(noNull);   print_string(s3); //未定义:noNull不是以空字符结束
    string s4(cp + 6, 6); print_string(s4);
    string s5(s1, 6, 5); print_string(s5);
    string s6(s1,6);print_string(s6);
    string s7(s1, 6, 20);print_string(s7);
//    string s8(s1, 16); //out of range

    //insert
    s1.insert(s1.size(), 5,'!'); print_string(s1);
    s1.erase(s1.size() - 3, 3); print_string(s1);

    s1.assign(cp, 7); print_string(s1);
    s1.insert(s1.size(), cp + 7); print_string(s1);


    string s = "some string", st = "some other string",
    st2 = "test for string";
    print_string(s);
    print_string(st);
    s.insert(0, st); print_string(s);
    s.insert(0,st2,0,st2.size()); print_string(s);
    s.insert(0,st2,0,st2.size()-11); print_string(s);
}

void string_all::substr()
{
    string s("Hello World"); print_string(s);
    string s2 = s.substr(0, 5);  print_string(s2);
    string s3 = s.substr(5);  print_string(s3);
    string s4 = s.substr(6, 11); print_string(s4);
//    string s5 = s.substr(12); //out of range
}

void string_all::append_replace()
{
    string s("C++ Primer"), s2 = s; print_string(s);print_string(s2);
    s.insert(s.size(), " 4th Ed.");print_string(s);
    s2.append(" 4th Ed.");print_string(s2);
    s.erase(11,3);print_string(s);
    s.insert(11, "5th"); print_string(s);
    s2.replace(11,3, "5th");print_string(s2);
    s.replace(11, 3, "Fifth"); print_string(s);
}

void string_all::search()
{
    string name("AnnaBeall");
    auto pos1 = name.find("Anna");  print_int(pos1); // pos1 == 0 
    pos1 = name.rfind("Anna");  print_int(pos1); // pos1 == 0 
    string lowercase("annabeall");
    pos1 = lowercase.find("Anna"); print_int(pos1); //pos1 == npos

    string numbers("0123456789"), name2("r2d2");
    //查找与给定字符串中任何一个字符匹配的位置
    auto pos = name2.find_first_of(numbers); print_int(pos);
    //搜索第一个不在参数中的字符，用find_first_not_of,为了搜索一个string中第一个非数字字符，可以如此
    string dept("03714p4");
    pos = dept.find_first_not_of(numbers); print_int(pos);
    pos = dept.rfind(numbers); print_int(pos);
}
