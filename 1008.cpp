#include <iostream>
using namespace std;
int req[100];
int main()
{
  int N, sum=0;
  cin >> N;
  if(N>0)
  {
    cin >> req[0];
    sum += 6 * (req[0]);
  }
  for (int i = 1; i < N;i++)
  {
    cin >> req[i];
    if(req[i]>req[i-1])
      sum += (req[i] - req[i - 1]) * 6;
    else if(req[i]<req[i-1])
      sum += (req[i - 1] - req[i]) * 4;
  }
  sum += N * 5;
  cout << sum;
  return 0;
}

/*1.哨兵技巧
第一次输入没有前一项 所以要割裂开来
避免割裂的话可以用一个last变量保存前面一个seq的值
然后last初始化的时候初始化成最开始要比较的值
*/