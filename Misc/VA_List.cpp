// VA LIST

#include <cstdarg>
#include <iostream>

using namespace std;

// this function will take the number of values to average
// followed by all of the numbers to average

double avg(int num, ...)
{
 va_list arg;
 double sum = 0;
 va_start (arg, num);
 for(int i=0; i<num;i++)
   sum += va_arg(arg, double);
 va_end(arg);

 return sum/num;
 }
int main()
{
    // this computes the average of 13.2, 22.3 and 4.5 (3 indicates the number of values to average)
  cout<< avg ( 3, 12.2, 22.3, 4.5 ) <<endl;
    // here it computes the average of the 5 values 3.3, 2.2, 1.1, 5.5 and 3.3
  cout<< avg ( 5, 3.3, 2.2, 1.1, 5.5, 3.3 ) <<endl;
}