#include <iostream>
using namespace std;
int seq[10000] = {0};
int main(void)
{
  int n;
  cin >> n;
  bool allneg = true;
  int maxsum = -1, m_first = 0, m_last = 0;
  int t_sum = 0, t_first = 0, t_last = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> seq[i];
    if (seq[i] >= 0)
      allneg = false;
    t_sum += seq[i];
    t_last = i;
    if (t_sum < 0)
    {
      t_first = t_last = i + 1;
      t_sum = 0;
    }
    else if (t_sum > maxsum)
    {
      maxsum = t_sum;
      m_first = t_first;
      m_last = t_last;
    }
    
  }
  if (allneg)
  {
    maxsum = 0;
    m_first = 0;
    m_last = n - 1;
  }
  cout << maxsum << " " << seq[m_first] << " " << seq[m_last];
  return 0;
}

/*
  1.这道题用普通的dp会挂 因为这题可以直接一次循环 
  顺序扫描所有元素 保留一个max和temp
  所以dp的时候尽量判断是否可以一次循环
  2.第六个测试点没过是因为忽略了最开始的0 第一次temp等与0时也要加入到sub里
*/