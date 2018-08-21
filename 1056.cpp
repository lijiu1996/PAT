#include <iostream> 
#include <queue>

using namespace std;
int main()
{
  queue<int> q;
  int weight[1010];
  int order[1010];
  int NP, NG;
  cin >> NP >> NG;
  for (int i = 0; i < NP;++i)
    cin >> weight[i];
  for (int i = 0; i < NP;++i)
    {
      int t;
      cin >> t;
      q.push(t);
    }

  int thisturn = NP;
  int thisorder = (NP + 2) / NG + 1;

  int counttotal = 0;
  int countout = 0;
  int weigh = -1;
  int weighindex = -1;
  while (q.size()>0)
  {
    int a = q.front();
    q.pop();
    ++countout;
    ++counttotal;
    order[a] = thisorder;
    if(weight[a]>weigh)
    {
      weigh = weight[a];
      weighindex = a;
    }
    if(counttotal==thisturn)
    {
      q.push(weighindex);
      thisturn = (thisturn+2) / NG;
      thisorder = (thisturn+2)/NG +1 ;
      counttotal = 0;
      countout = 0;
      weigh = -1;
      if(thisturn==1)
        break;
    }
    else if(countout==NG)
    {
      q.push(weighindex);
      countout = 0;
      weigh = -1;
    }
  }
  order[q.front()] = 1;
  cout << order[0];
  for (int i = 1; i < NP; ++i)
    cout << " " << order[i];
  return 0;
}
/** queue常见用法 类似stack 
 * 十分限制
 *  只能用front和back来访问 无法迭代
 *  
 * 
 * 
 * 
 * */