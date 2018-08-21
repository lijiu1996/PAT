#include <iostream> 
#include <vector>
#include <map>
using namespace std;

int sid = 0;
map<string, int> strtoi;
map<int, string> itostr;

struct node 
{
  int dest;
  int value;
  bool visit;
  node(int d, int v) : dest(d), value(v),visit(false) {}
};

const int maxN = 2000;
vector<node> e[maxN];
bool visited[maxN] = {0};
int weight[maxN] = {0};
int N, K;
map<string,int> result;

int maxweight= maxN;

void DFS(int v,int depth,int& sum,int& total)
{
  if(!visited[v])
    total++;
  visited[v] = true;
  if(weight[v]>weight[maxweight])
    maxweight = v;
  for (int i = 0; i < e[v].size(); ++i)
  {
    if(!e[v][i].visit)
    {
      // cout << itostr[v] << "-->" << itostr[e[v][i].dest] << endl;
      e[v][i].visit = true;
      int d = e[v][i].dest;
      int l = e[v][i].value;
      sum += l;
      DFS(d, depth + 1, sum, total);
    }
  }
}

int main()
{

  cin >> N >> K;
  for (int i = 0; i < N;++i)
  {
    string a, b;
    int ai, bi, t;
    cin >> a >> b >> t;

    strtoi.insert(make_pair(a, sid));
    itostr.insert(make_pair(sid, a));
    sid++;
    strtoi.insert(make_pair(b, sid));
    itostr.insert(make_pair(sid, b));
    sid++;
    ai = strtoi[a];
    bi = strtoi[b];
    e[ai].push_back(node(bi, t));
    weight[ai] += t;
    weight[bi] += t;
  }
  for (int i = 0; i < maxN;++i)
  {
    if(!visited[i])
    {
      maxweight = maxN;
      int sum = 0;
      int total = 0;
      DFS(i, 1, sum, total);
      if(total>2 && sum > K)
        result.insert(make_pair(itostr[maxweight],total));
    }
  }
  cout << result.size() << endl;
  for (auto e = result.begin(); e != result.end(); e++)
    cout << e->first <<" "<< e->second << endl;

  return 0;
}

/** 图的深度优先搜索
 *  1.如何记录一个所有边权值之和
 *    DFS中添加一个变量
 *  2.如何记录一个
 *  3.如何判断visit情况(图是有向图)
 *    在每条边里边添加一个变量visit
 *  4.找最大的情况可以在读入的时候就把每个点的weight算好
 * 
 * 5.错误点:
 *  只遍历一遍的无向图与遍历n遍的有向图还是不同的
 *  但是无向图遍历的时候要注意环路的问题
 *  -- 1.无向图遍历的时候会忽略掉环路的那条边
 *  -- 2.这题却要加上所有的边权之和
 *  -- 3.所以加和的问题放到外面去做
 * 
 * */