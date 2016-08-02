#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <limits>
#include <complex>
#include <fstream>

using namespace std;
class c_sinewave
{
public:

  static const double two_pi;

private:

  const double amplitude;
  const unsigned int frequency;

public:

  c_sinewave(const double a = 1.0, const unsigned int f = 1) : amplitude(a), frequency(f)
  {
  }

  const double value(const double x)
  {
    if(x < 0 || x > 1)
    {
      return 0;
    }
    else
    {
      return amplitude * ::sin((two_pi * frequency) * x);
    }
  }

};

const double c_sinewave::two_pi = ::atan(1) * 8.0;

int main(int argc, char* argv[])
{
  // Test it.
  ofstream file("out.cvs");
  if (!file.is_open())
  {
      std:cout<<"open file error."<<endl;
  }
  c_sinewave sinewave(10.0, 1);

  const int n_point = 1000;

  for(int i = 0; i < n_point + 1; i++)
  {
    const double x = static_cast<double>(i) / n_point;

    std::cout << std::fixed
              << std::showpos
              << std::setprecision(4)
              << x
              << ", "
              << std::setprecision(std::numeric_limits<double>::digits10 - 1)
              << sinewave.value(x)
              << std::endl;
    file << std::setprecision(4) << x << "," << sinewave.value(x) << endl;
  }
  file.close();

  return 0;
}

//#include <fstream>

//using namespace std;

//int main()
//{
//        //定义文件输出流
//    ofstream oFile;

//        //打开要输出的文件
//    oFile.open("scoresheet.csv", ios::out | ios::trunc);
//    oFile << "姓名" << "," << "年龄" << "," << "班级" << "," << "班主任" << endl;
//    oFile << "张三" << "," << "22" << "," << "1" << "," << "JIM" << endl;
//    oFile << "李四" << "," << "23" << "," << "3" << "," << "TOM" << endl;

//    oFile.close();
//}
