#include <iostream>
#include <vector>
#include "vector_all.h"

using namespace std;

vector_all::vector_all()
{
}

void vector_all::size()
{
    vector<int> ivec;
    cout << "ivec:size: " << ivec.size()
         << "capacity: " << ivec.capacity() << endl;

	//添加24个元素
	for (vector<int>::size_type ix = 0; ix != 24; ++ix)
	{
		ivec.push_back(ix);
	}

	cout << "ivec: size:  " << ivec.size()
		<< "capacity: " << ivec.capacity() << endl;

	ivec.reserve(50);
	while (ivec.size() != ivec.capacity())
	{
		ivec.push_back(0);
	}

	cout << "ivec: size:  " << ivec.size()
		<< "capacity: " << ivec.capacity() << endl;


	ivec.push_back(50);

	cout << "ivec: size:  " << ivec.size()
		<< "capacity: " << ivec.capacity() << endl;
	//容量分配是翻倍操作

    ivec.shrink_to_fit(); //要求归还内存
    //size 未改变，capacity的值依赖于具体实现 
	cout << "ivec: size:  " << ivec.size()
		<< "capacity: " << ivec.capacity() << endl;	
}


