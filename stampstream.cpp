#include "stampstream.h"

stampstream::stampstream(int cols,int rows)
{
  rdbuf(new stampbuf(cols,rows));
}

stampstream::~stampstream()
{
  delete rdbuf();
}

ostream& endrow(ostream& os)
{
  stampbuf* sbp=(stampbuf*)os.rdbuf();
  sbp->pubsync();
  sbp->increase_row_by_one();
  sbp->change_col_to(0);
  return os;
}

row::row(int row):desired_row(row){}

ostream& operator<<(ostream& os, const row& row_obj)
{
  stampbuf* sbp = (stampbuf*)os.rdbuf();
  sbp->pubsync();
  sbp->change_col_to(0);
  sbp->change_row_to(row_obj.desired_row);
  return os;
}