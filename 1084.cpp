#include <iostream>
#include <cctype>
#include <set>
#include <vector>

using namespace std;

int main()
{
  string org, worn;
  cin >> org >> worn;

  vector<char> v;

  int op = 0, wp = 0;
  while(op<org.size() && wp< worn.size())
  {
    while(org[op]!=worn[wp])
    {
      char c = org[op];
      if (islower(c))
        c = c - 'a' + 'A';
      auto e = find(v.begin(),v.end(),c);
      if(e==v.end())
        v.push_back(c);
      ++op;
    }
    ++op;
    ++wp;
  }
  while(op!=org.size())
  {
     char c = org[op];
     if (islower(c))
        c = c - 'a' + 'A';
     auto e = find(v.begin(),v.end(),c);
     if(e==v.end())
        v.push_back(c);
      ++op;
  }


  for (auto e :v)
    cout << e;
  return 0;
}

/** 1084 遍历两个字符串 找到第一个字符串比第二个字符串多的东西
 * 1.判断字符函数 
 * include cctype
 * islower isupper isalpha isalbum
 * toupper tolower
 * 
 * 
 * 2. stl 两种find
 * 一种在al里面 find(begin,end,&&);
 * 一种在ADT里面
 * vector容器没有实现find所以需要使用第一种find
 * 不建议每次都find这种实现方式 应该使用hash char到bool的方式
 * 
 * 3.string find
 * 如果没找到 返回string::npos (-1)
 * 
 * */
