#ifndef STAMPBUF_H
#define STAMPBUF_H
#include <streambuf>
#include <iostream>
//#include <cstdlib>
//#include <cmath>
using namespace std;
#include "stamp.h"

class stampbuf : public streambuf
{
    private:
        char* buffer;
        int current_row;
        int current_col;
        int buffer_size;  //to change buffer size 
    public:
        stampbuf(int,int);
        ~stampbuf();
        void increase_row_by_one();
        int sync();
        void change_row_to(int);
        void change_col_to(int);
        int overflow(int);
};
#endif