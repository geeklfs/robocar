#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <limits>
#include <complex>
#include <fstream>
#include <unistd.h>

using namespace std;

class signal
{
public:

  static const double two_pi;

private:

  const double amplitude;
  const double frequency;

public:

  signal(const double a = 1.0, const double f = 1.0) : amplitude(a), frequency(f)
  {
  }

  const double value(const double x)
  {
    if(x < 0 )
    {
      return 0;
    }
    else
    {
      return amplitude * ::sin((two_pi * frequency) * x);
    }
  }
  //input:last_time--total time that the sin wave last
  void getsinvalue(const float last_time)
  {
      const int point = 100; //show 100 point in every period
      ofstream file("out_sin.cvs");
      if (!file.is_open())
      {
          std:cout<<"open file error."<<endl;
      }
      for(int i = 0; i < last_time * point - 1; i++)
      {
          const double x = static_cast<double>(i) / point;
          usleep(int(1000000/point));  //delay ms
          std::cout << x << "," << signal::value(x) << endl;
          file << std::setprecision(4) << x << "," << signal::value(x) << endl;
      }
  }

  void getsquarewave(const float last_time)
  {
      const int point = 100;
      unsigned char up = 1;
      float out_value = signal::amplitude;
      ofstream file("out_square.cvs");
      if (!file.is_open())
      {
          std:cout<<"open file error."<<endl;
      }
      for(int i = 0; i < last_time * point - 1; i++)
      {
          const double x = static_cast<double>(i) / point;
          usleep(int(1000000/point));
          if(int(2.0*signal::frequency*i/point)%2==0)
          {
              out_value = signal::amplitude;
          }
          else
          {
              out_value = -signal::amplitude;
          }
          std::cout << x << "," << out_value << endl;
          file << std::setprecision(4) << x << "," << out_value << endl;
      }
  }
};

const double signal::two_pi = ::atan(1) * 8.0;

int main(int argc, char* argv[])
{
     signal sinwave(8.0,2);
     sinwave.getsinvalue(4.3);
     signal squarewave(7.0,1.5);
     squarewave.getsquarewave(4);
    return 0;
}
