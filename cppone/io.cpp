#include <iostream>
#include <fstream>
#include <sstream>
#include "io.h"
#include "sales_data.h"

using namespace std;

/*
istream(输入流)
ostream(输出流)
cin,标准输入
cout,标准输出
cerr,标准输出错误
>> 从istream对象读取输入数据
<< 从ostream对象写入输出数据
getline,从istream对象读取一行数据，存入string对象

*/

/*
iostream
 istream, wistream    ---w表示宽字符处理
 ostream, wostrream
 iostream, wiostream

fstream
 ifstream,wifstream
 ofstream,wofstream
 fstream, wfstream

sstream
 istringstream,wistringstream
 ostringstream,wostringstream
 stringstream,wstringstream

宽字符
wchar_t
wcin
wcout
wcerr

*/


/*
io库条件状态
strm::iostate  strm是一种IO状态，iostate是一种机器相关的类型
strm::badbit 指示流已崩溃
strm:failbit IO操作失败
strm::eofbit 流达到文件结束
strm::goodbit  流未处于错误状态，此值保证为零
s.eof()
s.fail()
s.bad()
s.good()
s.clear()
s.clear(flags)
s.setstate(flags_
s.rdstate()



*/
io::io()
{
}

void io::obj_copy()
{
    ofstream out1, out2;
//    out1  = out2;  //err
    ofstream print(ofstream);
//    out2 = print(out2); //err



//-----记住cin的当前状态
    auto old_state = cin.rdstate();
    cin.clear();
//    process_input(cin);
    cin.setstate(old_state);

    //--复位failbit和badbit,保持其它位不变
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);


    //管理输出缓冲区
    cout << "please enter a value: " ;
    //end 显示刷新缓冲区
    cout << "please enter a value: "  << endl;
    // cerr是设置无缓冲，unitbuf
    //
    cout << "hi!" << endl; //内容 + 换行  + 刷新缓冲区
    cout << "hi!" << flush; //内容 + 刷新缓冲区
    cout << "hi!" << ends;   //内容 +一个空字符 + 刷新缓冲区

    cout << unitbuf; //所有输出操作后都立即刷新

    cout << nounitbuf;//回到正常的缓冲模式


//    //警告：当程序崩溃时，输出缓冲区不会被刷新
//    int ival;
//    cin >> ival; //cout缓冲区被刷新
    







//可以将一个istream对象关联到另一个ostream,也可以将一个ostream关联到另一个ostream
    cin.tie(&cout); //演示，标准库将cin和cout关联在一起
    //old_tie指向当前关联到cin的流(如果存在)
    ostream *old_tie = cin.tie(nullptr); //cin不再与其它关联
    //
    cin.tie(&cerr); //读取cin会刷新cerr而不是cout
    cin.tie(old_tie); //重建cin和cout间的正常关联




}


void io::file_ops()
{

	fstream fstrm;
	string s("filename");
	fstream fstrm2(s);

//    int mode = ios_base::in | ios_base::out;
//	fstream fstrm3(s,mode);
    fstream fstrm3(s,ios_base::in);
	fstrm.open(s);
	fstrm.close();
    fstrm.is_open();


    cout << unitbuf;
    string ifname = "i.txt";
    string ofname = "o.txt";
    ifstream input(ifname);
    ofstream output(ofname);
    Sales_data total;
    if (read(input, total))
    {
    	Sales_data trans;
        while (read(input, trans)) //input一直往前走的数据
    	{
            if (total.isbn() == trans.isbn())
    		{
                cout << "here!";
    			total.combine(trans);
    		}
    		else
    		{
                cout << "else!";
    			print(output, total) << endl;
    			total = trans;
    		}
    	}
        cout << "end";
    	print(output, total) << endl;
    }
    else
    {
    	cerr << "No Data ?!" << endl;
    }

	
}




//int main()
//{
//    Sales_data total;
//    if (read(cin, total))  // 读取对象数据， 存入total中， 并返回cin
//    {
//        Sales_data trans;
//        while(read(cin, trans))  // 读取对象数据， 存入trans中， 并返回cin
//        {
//            if (total.isbn() == trans.isbn()) // 判断当前isbn和前一个isbn是否相等
//            {
//                total.combine(trans);  // 加到当前对象total中
//            }
//            else
//            {
//                print(cout, total) << endl; // 输出当前对象
//                total = trans;  // 更新当前对象
//            }
//        }

//        print(cout, total) << endl; // 输出当前对象(最后的对象)
//    }
//    else
//    {
//        cerr << "No data?!" << endl; // 最开始就读取失败
//    }

//    return 0;
//}


