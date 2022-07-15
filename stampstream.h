#ifndef STAMPSTREAM_H
#define STAMPSTREAM_H
#include "stampbuf.h"

class stampstream : public ostream
{
    public:
        stampstream(int,int);
        ~stampstream();
};

ostream& endrow(ostream&);

class row
{
    public:
        row(int);
    private:
        int desired_row;
        friend ostream& operator<<(ostream& os, const row& row_obj);
};
#endif