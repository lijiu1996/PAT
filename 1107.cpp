#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
const int maxN = 1010;
int hobby[maxN] = {0}; //记录一个喜欢hobby[x]的某个人的id
int father[maxN];

int findfather(int a)
{
  while(father[a]!=a)
    a = father[a];
  return a;
}

void unio(int a,int b)
{
  int fa = findfather(a);
  int fb = findfather(b);
  if(fa!=fb)
  {
    father[fb] = fa;
  }
}

bool cmp(int a,int b)
{
  return a > b;
}

int main()
{
  cin >> N;
  int out[maxN] = {0};
  for (int i = 1; i <= N; ++i)
  {
    father[i] = i;
  }
  for (int i = 1; i <=N;++i)
  {
    int s;
    cin >> s;
    cin.get();
    for (int j = 0; j < s; ++j)
    {
      int t;
      cin >> t;
      if (!hobby[t])
        hobby[t]=i;
      unio(hobby[t], i);
    }
  }
  for (int i = 1; i <=N;++i)
  {
    out[findfather(i)]++;
  }
  sort(out, out + maxN,cmp);
  int total = 0;
  for (int i = 0; i < N; ++i)
  {
    if(out[i])
      total++;
  }
  cout << total << endl;
  for (int i = 0; i < total;i++)
  {
    cout << out[i];
    if(i!=total-1)
      cout << " ";
  }
  return 0;
}

/** 并查集 每一次合并合并的是人!
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * */