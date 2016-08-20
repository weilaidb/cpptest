#include <iostream>
#include "vector_all.h"
//#include "io.h"
#include "list_all.h"
#include <string_all.h>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
//    io iot;
//    iot.obj_copy();
//    iot.file_ops();
//    iot.string_phones();

    list_all lstall;
//    lstall.insert();
    lstall.emplace();
    lstall.delete_lst();
    lstall.forward_list_t2();
    lstall.resize();
    lstall.erase_update_iterator();


    vector_all vecall;
    vecall.size();


    string_all strall;
    strall.other_method();
    strall.substr();
    strall.append_replace();
    strall.search();

    return 0;
}


