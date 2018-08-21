#include<iostream> 
#include<cctype>
#include<map>
#include<cstdio>
#include<vector> 
#include<algorithm>
using namespace std;

typedef pair<string, int> PAIR;
bool cmpbypair(const PAIR& a,const PAIR& b)
{
  if(a.second==b.second)
    return strcmp(a.first.c_str(), b.first.c_str()) < 0;
  else
    return a.second > b.second;
}

int main()
{

  map<string, int> counter;
  char c;
  // cin >> c;
  scanf("%c", &c);
  string temps;
  while (c != '\n')
  {
    if(isalnum(c))
    {
      temps += tolower(c);
    }
    else
    {
      if(temps!="")
      {
        auto e = counter.find(temps);
        if(e!=counter.end())
          e->second++;
        else
          counter[temps] = 1;
        temps = "";
      }
    }
    scanf("%c", &c);
  }
  vector<PAIR> v(counter.begin(), counter.end());
  sort(v.begin(), v.end(), cmpbypair);
  cout << v[0].first << " " << v[0].second << endl;
  return 0;
}

/** 1071 
 * 
 * --map排序
 * 1.map<string,int,Cmp> 
 * 排序的话通过传入一个Cmp类可以实现自定义排序
 * 
 * 2.按值排序
 * 转存到vector中 传入一个比较函数
 * 
 * 3.直接遍历 然后自己定制操作 这题目里只是找到一个最大值
 * 
 * 
 * --自己定制化cin
 * 
 * 
 * --补充 cin字符时的几种形式
 * 
 * 0.注意可以直接读到char[]中
 * 比如 char z[10];
 * 可以直接cin>>z
 * 
 * 0.1 常见ascii码 空格--10
 * 
 * 1.cin>>
 * 忽略空白符(在缓冲区中直接丢弃掉)
 * 可以设置cin>>noskipws取消这一点
 *  
 * 2.cin.get三种形式 无参 一参数 二参数
 * 遇到\n停止 但不会再缓冲区中丢弃\n
 * 二参数长度是5 但只会读进去4个 !!!最后一个自动为\0
 * 
 * 3.cin.getline 直接丢弃换行符 其他和cin.get一致
 * 所以后面两种适用于读取定长且不忽略空白的情况
 * 且如果不需要保留\n的话getline不错
 * 
 * 4.getline cin
 * 处理string类的 第二个参数为string
 * 
 * 5.c函数 不用
 * gets()
 * getchar()
 * 
 * 解决实际问题 
 * 1.读取一行
 * 2.读取不定个数字 while(cin>>)
 * 3.读取不定个数字 分隔符不是' ':
 *  思路是先读成string 再转化
*/

