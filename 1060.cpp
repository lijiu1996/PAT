#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;


string ex(string s,int len)
{
  int expont = 0;
  string head="0.";
  auto e = s.begin();
  
  while(s[0]=='0')
  {
    if(s.size()==1 || s[1]=='.')
      break;
    s.erase(s.begin());
  }

  if (s.size() > 1 && s[0] == '0' && s[1] == '.')
  {
    e = s.begin() + 2;
    while(*e=='0')
    {
      ++e;
      expont--;
    }
    if(atof(s.c_str())==0)
      expont = 0;
  }
  else
  {
    auto i = s.find('.');
    expont = i == string::npos ? s.size() : i;
    if(i!=string::npos)
      s.erase(s.begin()+i);
    if(atof(s.c_str())==0)
      expont = 0;
  }
  for (int i = 0; i < len;++i)
  {
    head += e==s.end()?'0':*e;
    if(e!=s.end())
      e++;
  }
  
  head = head + "*10^" + to_string(expont);
  return head;
}

int main()
{
  // ifstream cin("data.txt");
  int N;
  string s1, s2,r1,r2;
  cin >> N >> s1 >> s2;

  r1 = ex(s1,N);
  r2 = ex(s2,N);
  if (r1 == r2)
    cout << "YES " << r1;
  else
    cout << "NO " << r1 << " " << r2;
  return 0;
}

/** 字符串String类的一些成员函数
 *        连接 append(迭代器,num ch,)
 *        长度 size
 *        根据位置删除 erase(pos,pos end,index n) 
 *            注意erase输入一个迭代器和输入一个整数是不同的
 *            输入一个迭代器是删除这个迭代器位置的内容
 *            输入一个整数是删除这个index开始的n个元素的内容 必须要输入int int才能使用
 *        根据元素值删除 只能用全局函数remove
 *        注意remove函数有一个很恐怖的性质 并不是真的删除 而是把元素放在所有数据的尾部 然后返回一个迭代器
 *        所以使用的时候请结合string.erase s.erase(std.remove(),s.end())完成删除
 *        查找 find string.find与其他find不同 返回的是一个整数表示的int
 *        计数 count 只能用全局函数了
 * 
 * 0.algorithm 算法总结
 * remove removeif
 * find   findif
 * 
 * 1060 题解 
 * 1.数字与字符串相互转化问题
 *   数字转化成字符串 
 *    - 输入时直接用string读 非常适用于高位小数
 * 
 *    - to_string() 默认6位
 *    - sprintf   最为方便
 *    - stringstream 默认6位
 *    - atoi itoa等等
 * 
 * 2.输入数字问题
 *  - 大体上分为两类 0.xxxxxx xxx.xxxxx
 *  - 首先写一个函数把一开始的0000都过滤掉
 *  - 然后统计整数和起始点(注意0的时候整数要设为0)
 * */



