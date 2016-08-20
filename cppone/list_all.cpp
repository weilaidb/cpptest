#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>
#include <array>
#include <string>
#include "list_all.h"
#include "sales_data.h"

using namespace std;

list_all::list_all()
{

}

template <typename A>
void print_list(list<A> &con)
{
    typename list<A>::const_iterator it;
    for (it = con.begin(); it != con.end(); ++it)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

template <typename A>
void print_list_rervese(list<A> &con)
{
    typename list<A>::const_reverse_iterator it;
    for (it = con.rbegin(); it != con.rend(); ++it)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

template <typename A>
void print_forward_list(forward_list<A> &con)
{
    typename forward_list<A>::const_iterator it;
    for (it = con.begin(); it != con.end(); ++it)
    {
        cout << *it << "  ";
    }
    cout << endl;
}


template <typename A>
void print_vector(vector<A> &con)
{
    typename vector<A>::const_iterator it;
    for (it = con.begin(); it != con.end(); ++it)
    {
        cout << *it << "  ";
    }
    cout << endl;
}


void list_all::insert()
{
    list<string> lst;
    string word;
    auto iter = lst.begin();
    cout << "please enter a word:" << endl;
    while (cin >> word)
    {
        iter = lst.insert(iter, word);
        if ("q" == word)
        {
            break;
        }
    }

    cout << "list size is " << lst.size() << endl;
    print_list(lst);
    print_list_rervese(lst);
}

void list_all::emplace()
{
    list<Sales_data> c;
    c.emplace_back("987-0590353403", 25, 15.99); //对应于push_back
    c.emplace_front("987-0590353403", 25, 15.99); //对应于push_front
    list<Sales_data>::const_iterator it = c.cbegin();
    c.emplace(it, Sales_data("987-0590353403", 25, 15.99)); //类似insert
//    c.push_back("987-0590353403", 25, 15.99); //err
//    Sales_data a("987-0590353403", 25, 15.99);
    c.push_back(Sales_data("987-0590353403", 25, 15.99)); //push_back创建临时内存对象

    cout << "list size is " << c.size() << endl;

    //在解引用一个迭代器或调用front或back之前检查是否有元素
    if (!c.empty())
    {
        //val 和val2是第一个元素值的拷贝
        auto val  = *c.begin(), val2 = c.front();
        //val3 和val4是c中最后一个元素值的拷贝
        auto last = c.end();
        auto val3 = *(--last); //不能递减forward_list迭代器
        auto val4 = c.back(); // forward_list不支持
    }

    list<int> lsti;
    lsti.push_back(10);
    lsti.push_back(29);
    if (!lsti.empty())
    {
        lsti.front() = 42;
        auto &v = lsti.back(); //获取指向最后一个元素的引用
        v = 1024; //改变lsti中的元素
        auto v2 = lsti.back(); //获取拷贝
        v2 = 23233; //未改变lsti中的元素
    }

    print_list(lsti);
}

void list_all::delete_lst()
{
    list<int> lst = {0,1,2,3,4,5,6,7,8,9};
    print_list(lst);
    auto it = lst.begin();
    while ( it != lst.end())
    {
        if (*it % 2) //若元素为奇数，删除此元素
        {
            it = lst.erase(it);
        }
        else
        {
            ++it;
        }
    }

    print_list(lst);

//    elem1 = slist.erase(elem1, elem2); //调用后，elem1 == elem2
    lst.clear(); //删除容器中元素
    lst.erase(lst.begin(), lst.end());//等价调用


}

void list_all::forward_list_t2()
{
    forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
    auto prev = flst.before_begin();
    auto curr = flst.begin();

    while (curr != flst.end())
    {
        if (*curr % 2)
        {
            curr = flst.erase_after(prev);
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }

    print_forward_list(flst);
    
}


void list_all::resize()
{
    list<int> ilist(10,42);
    ilist.resize(15);
    ilist.resize(25, -1);
    ilist.resize(5);
}

void list_all::erase_update_iterator()
{
    cout << "testing erase_update_iterator" << endl;
    std::vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter); //复制当前元素
            iter += 2; //向前移动迭代器，跳过当前元素以及插入到它之前的元素
        }
        else
        {
            //删除偶数元素
            //不应向前移动迭代器，iter指向我们删除的元素之后的元素
            iter = vi.erase(iter);
        }
    }

    print_vector(vi);


    //不保存end()
    //更安全的方法：在每个循环步添加/删除元素后都重新计算end
    auto begin = vi.begin();
    while (begin != vi.end())
    {
        //
        ++begin;
        begin = vi.insert(begin, 32);
        ++begin;
    }

    print_vector(vi);


/*
testing erase_update_iterator
1  1  3  3  5  5  7  7  9  9
*/
}

