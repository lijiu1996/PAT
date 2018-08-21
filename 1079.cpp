#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;


struct node
{
  int layer;
  vector<int> childs;
  int nproduct;
} Nodes[100010];

int N;
double org_price, up_percentage;

double power(double org_price,int N)
{
  double p = up_percentage*0.01 + 1;
  double r = org_price;
  while (N--)
  {
    r *= p;
  }
  return r;
}

void travel()
{
  int minlayer=0;
  int numberofmin = 0;

  queue<int> q;
  q.push(0);
  Nodes[0].layer = 0;
  while(!q.empty())
  {
    int n = q.front();
    q.pop();
    if(minlayer && Nodes[n].layer>minlayer)
      break;
    if (Nodes[n].childs.size() == 0)
    {
      minlayer = Nodes[n].layer;
      numberofmin++;
    }
    else 
    {
      for(auto v:Nodes[n].childs)
      {
        q.push(v);
        Nodes[v].layer = Nodes[n].layer + 1;
      }
    }
  }
  double t = power(org_price, minlayer);
  printf("%.4f %d", t, numberofmin);
}

int main()
{
  
  cin >> N >> org_price >> up_percentage;
  for (int i = 0; i < N;++i)
  {
    int nchild;
    // cin >> nchild;
    scanf("%d",&nchild);
    if(nchild)
    {
      for (int j = 0; j < nchild;++j)
      {
        int t;
        // cin >> t;
        scanf("%d",&t);
        Nodes[i].childs.push_back(t);
      }
    }
  }
  travel();
  return 0;
}