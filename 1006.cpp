#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class mytime
{
  public:
    int h;
    int m;
    int s;
    void print() { cout << h << ":" << m << ":" << s; }
    mytime(int, int, int);
    mytime():h(0),m(0),s(0){}
    bool operator<(const mytime &b);
    bool operator>(const mytime &b);
};

mytime::mytime(int h_,int m_,int s_):h(h_),m(m_),s(s_){}
bool mytime::operator<(const mytime &b){
  bool check;
  if(h==b.h){
    if(m==b.m){
      check = s < b.s;
    }
    else
      check = m < b.m;
  }
  else
    check = (h < b.h);
  return check;
}
bool mytime::operator>(const mytime &b){
   bool check;
  if(h==b.h){
    if(m==b.m){
      check = s > b.s;
    }
    else
      check = m > b.m;
  }
  else
    check = (h > b.h);
  return check;
}

int main(){
  int N;
  cin >> N;
  int first=0;
  int last=0;
  mytime t_begin(24, 24, 24);
  mytime t_end(0, 0, 0);
  vector<string> ids;
  int a, b, c, d, e, f;
  for (int i = 0; i < N; i++)
  {
    string tmp;
    cin >> tmp;
    ids.push_back(tmp);
    scanf("%d:%d:%d %d:%d:%d", &a, &b, &c, &d, &e, &f);
    mytime begin(a, b, c);
    mytime end(d, e, f);
    if(begin<t_begin){
      t_begin = begin;
      first = i;
    }
    if(end > t_end){
      t_end = end;
      last = i;
    }
  }
  cout << ids[first] << " " << ids[last];
  return 0;
}

/*
  标准stdio执行格式化输出
  1.如果%d会自动忽略前面的空格
  2.但如果把一个字符赋给%d 会输出一个不正常的数


*/