#include "stampbuf.h"

stampbuf::stampbuf(int num_cols, int num_rows) //change buf size below
  :buffer_size(num_cols/3),current_row(0),current_col(0)
{
  buffer=new char[buffer_size];
  stamping_press::insert_plate(num_cols,num_rows);
  setp(buffer,buffer+buffer_size);
}

void stampbuf::increase_row_by_one()
{
  current_row++;
}

void stampbuf::change_row_to(int row)
{
  current_row=row;
}

void stampbuf::change_col_to(int col)
{
  current_col=col;
}

int stampbuf::sync()
{
  for(char* i=pbase(); i<pptr(); ++i)
  {
    try{
      stamping_press::set_die(*i);
      stamping_press::stamp(current_col,current_row);
      ++current_col;
    }
    catch(invalid_argument){
      if(stamping_press::get_die()==*i)
      {
        try{
          stamping_press::stamp(current_col,current_row);
          ++current_col;
        }
        catch(...){}
      }
      else
      {
        ++current_col;
      }
    }
    catch(...)
    {

    }
  }
  setp(pbase(),epptr());
  return 0;
}

int stampbuf::overflow(int character)
{
  sync();
  char mych=character;
  sputc(mych);
  return mych;
}

stampbuf::~stampbuf()
{
  sync();
  delete [] buffer;
  stamping_press::eject_plate();
}