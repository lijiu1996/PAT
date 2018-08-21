#include <iostream> 
#include <map>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int cost[24];

class Record{
public:
  Record():month(-1){}
  Record(int, int, int, int, string);
  int month;
  int day;
  int h;
  int m;
  bool online;
  friend ostream &operator<<(ostream &out,const Record &tmp);
  friend bool operator<(const Record &a, const Record &b);
};

Record::Record(int month_,int day_,int h_,int m_,string line):
    month(month_),day(day_),h(h_),m(m_),online(false)
{
  if(line == string("on-line")){
    online = true;
  }
  else if(line!=string("off-line")){
    cout << "Invaile input line" << endl;
    exit(1);
  }
}

bool operator<(const Record& a,const Record& b)
{
  if(a.month!=b.month){
    cout << "Error: different month" << endl;
  }
  if(a.day<b.day)
    return true;
  else if(a.day==b.day){
    if(a.h<b.h)
      return true;
    else if(a.h==b.h){
      if(a.m<b.m)
        return true;
    }
  }
  return false;
}

ostream& operator<<(ostream& out,const Record& tmp)
{
  out.fill('0');
  out <<setw(2) << tmp.day << ":" <<setw(2)<< tmp.h << ":" <<setw(2)<<tmp.m;
  out.fill(' ');
  return out;
}

class Member{
  public:
    int month;
    vector<Record> records;
    double total;
    Member():total(0.0){}
    void outputDis(const Record &begin, const Record &end);
};

void Member::outputDis(const Record& begin,const Record& end)
{
  double amount = 0;
  int mins = 0;
  cout <<begin <<" "<<end<<" ";
  Record tbegin = begin;
  mins -= tbegin.m;
  amount -= tbegin.m * cost[tbegin.h] / 100.0;
  while (!(tbegin.day == end.day && tbegin.h == end.h))
  {
    mins += 60;
    amount += 60.0 * cost[tbegin.h] / 100;
    tbegin.h++;
    if (tbegin.h == 24)
    {
      tbegin.day++;
      tbegin.h = 0;
    }
  }
  mins += end.m;
  amount += end.m * cost[end.h] / 100.0;
  cout << mins << " $" <<fixed<<setprecision(2)<<amount<<endl;
  total += amount;
}

int main()
{
  ifstream cin("data.txt");
  for (int i = 0; i < 24; i++)
    cin >> cost[i];
  int N;
  cin >> N;

  map<string, Member> members;
  for (int i = 0; i < N; i++)
  {
    int mo, dd, hh, mm;
    string name, line;
    char c;
    cin >> name;
    cin >> mo >> c >> dd >> c >> hh >> c >> mm;
    cin >> line;
    Record t(mo, dd, hh, mm, line);
    auto it = members.find(name);
    if(it==members.end())
    {
      members[name] = Member();
      members[name].month = mo;
    }
    members[name].records.push_back(t);
  }

  for(auto i = members.begin(); i != members.end(); i++)
  {
    bool firstflag = false;
    Member tm = i->second;
    sort(tm.records.begin(), tm.records.end());
    Record recent_on;
    for (auto e = tm.records.begin(); e != tm.records.end(); e++)
    {
      if (e->online)
      {
        recent_on.month = e->month;
        recent_on.day = e->day;
        recent_on.h = e->h;
        recent_on.m = e->m;
      }
      else{
        if(recent_on.month!=-1) //output
        {
          if(!firstflag){
            cout << i->first << " " <<setfill('0')<<setw(2)<<tm.month<< endl;
            firstflag = true;
          } 
          tm.outputDis(recent_on, *e);
          recent_on.month = -1;
        }
      }
    }
    if(firstflag)
      cout << "Total amount: $" <<tm.total<<endl;
  }
  return 0;
}

/** 本题笔记
 * 这个问题可以由两个类实现转化为 双排序问题
 * 问题1 如何实现结果的输出的时候 避免非0
 * 问题2 如何实现阶段性计算cost 直接求总数然后相减 !!
 * 问题3 sort函数 传入cmp
 * 
 * 
 * *
 * 
 */