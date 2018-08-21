#include <iostream>
#include <queue>
using namespace std;

struct node
{
  int x;
  int y;
  int z;
  node(){}
  node(int x_,int y_,int z_):x(x_),y(y_),z(z_){}
};

int M,
    N, L, T;
int nodes[62][1290][130];
bool visited[62][1290][130] = {false};

int mx[] = {1, -1, 0, 0, 0, 0};
int my[] = {0, 0, -1, 1, 0, 0};
int mz[] = {0, 0, 0, 0, 1, -1};

bool check(node t)
{
  
  if(t.x>=L || t.x<0)
    return false;
  if(t.y>=M || t.y<0)
    return false;
  if(t.z>=N || t.z<0)
    return false;
  if(visited[t.x][t.y][t.z] || nodes[t.x][t.y][t.z]==0)
    return false;
  return true;
}

int BFS(int x,int y,int z)
{
  int result = 0;
  queue<node> q;
  q.push(node(x, y, z));
  visited[x][y][z] = true;
  while(!q.empty())
  {
    node t = q.front();
    q.pop();
    ++result;
    for (int i = 0; i < 6;++i){
      node mt = node(t.x + mx[i], t.y + my[i], t.z + mz[i]);
      if (check(mt))
      {
        q.push(mt);
        visited[mt.x][mt.y][mt.z] = true;
      }
    }
  }
  return result;
}

int main()
{
  cin >> M >> N >> L >> T;
  for (int i = 0; i < L;++i)
  {
    for (int x = 0; x < M;++x)
      for (int y = 0; y < N;++y)
        cin >> nodes[i][x][y];
  }
  int core = 0;
  for (int x = 0; x < L;++x)
    for (int y = 0; y < M;++y)
      for (int z = 0; z < N;++z)
      {
        if(!visited[x][y][z] && nodes[x][y][z]==1)
        {
        int r = BFS(x, y, z);
        core += r >= T ? r : 0;
        }
      }
  cout << core;
  return 0;
}