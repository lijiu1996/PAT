#include<iostream>
#include<queue>
#include<iomanip>
#include<fstream>
using namespace std;

int N,M, K, Q;
int out[1000];
int tsac[1000];
int query[1000];
queue<int> q[20];

int main()
{
  // ifstream cin("data.txt");
  cin >> N >> M >> K >> Q;
  int yellow = N * M;

  for (int i = 0; i < K; i++){
    cin >> tsac[i];
    if(i<yellow)
    {
      if(i<N)
        out[i] = tsac[i];
      else
        out[i] = out[q[i % N].back()] + tsac[i];
      q[i % N].push(i);
    }
    else
    { //find a queue to out
      int minN = 0;
      for (int i = 0; i < N; i++)
      {
        if(out[q[i].front()]<out[q[minN].front()])
          minN = i;
      }
      out[i] = out[q[minN].back()] + tsac[i];
      q[minN].pop();
      q[minN].push(i);
    }
  }
  for (int i = 0; i < Q;i++)
    {
      cin >> query[i];
      query[i] -= 1;
    }
    for (int i = 0; i < Q; i++)
    {
      int outtime = out[query[i]];
      if (outtime-tsac[i] >= 540)
        cout << "Sorry" << endl;
      else
      {
        int h = 8 + outtime / 60;
        int m = outtime % 60;
        cout << setw(2) << setfill('0') << h << ":";
        cout << setw(2) << setfill('0') << m << endl;
      }
  }

  return 0;
}

/*
本题技巧 
1.常用实现方法
maxN = ...
struct Customer[maxN]
bool operator<(const A&)const

2.queue使用
empty size front back push pop
适用于数据先入先出的情况 但有一个问题是无法遍历
而priorty_queue的话是有一个top和cmp


3.cout和printf输出格式 空格和自动填充
printf("02d");
cout<<setw(2)<<setfill('0')<<
*/