#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxN = 105;

struct node{
  vector<int> childs;
} Nodes[maxN];

int weight[maxN];
int N, M, S;

vector<int> current;

void output(vector<int>& v)
{
  if(v.size()==0)
    return;
  int n = v.size();
  cout << weight[v[0]];
  for (int i = 1; i < n;++i)
    cout << " " << weight[v[i]];
  cout << "\n";
}

bool cmp(int a,int b)
{
  return weight[a] > weight[b];
}

void DFS(int r, int sum)
{
  if(sum==S && Nodes[r].childs.size()==0)
  {
    output(current);
    return;
  }
  if(sum>=S)
    return;
  for(auto e:Nodes[r].childs)
  {
    current.push_back(e);
    DFS(e, sum + weight[e]);
    current.pop_back();
  }
}

int main()
{
  cin >> N >> M >> S;
  for (int i = 0; i < N;++i)
    cin >> weight[i];
  for (int i = 0; i < M;++i)
  {
    int id,nchild;
    cin >> id>>nchild;
    for (int j = 0; j < nchild;++j)
    {
      int t;
      cin >> t;
      Nodes[id].childs.push_back(t);
    }
    sort(Nodes[id].childs.begin(), Nodes[id].childs.end(), cmp);
  }
  current.push_back(0);
  DFS(0, weight[0]);
  return 0;
}