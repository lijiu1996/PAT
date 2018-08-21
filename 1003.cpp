#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const int inf = 99999999;
int n_v, n_dis, src_v, dis_v;
int dis[500][500];
int weight_v[500];

int dij_dis[500];
int dij_wei[500];
int dij_num[500];
bool visit[500];


int find_min(){
  int min_v = -1;
  int min_dis = inf;
  for (int i = 0; i < n_v; i++)
  {
    if(visit[i]==false && dij_dis[i] < min_dis)
    {
      min_v = i;
      min_dis = dij_dis[i];
    }
  }
  if(min_v!=-1)
    visit[min_v] = true;
  return min_v;
}

int dijkstra(int src, int to)
{
  fill(dij_dis, dij_dis + 500, inf);
  fill(visit, visit + 500, false);
  fill(dij_wei, dij_wei + 500, 0);

  dij_dis[src] = 0;
  dij_num[src] = 1;
  dij_wei[src] = weight_v[src];
  int min_v = find_min();
  while(min_v!=-1){
    for (int i = 0; i < n_v;i++){
      if(visit[i]==false  && dis[min_v][i] != inf){
        if(dij_dis[min_v] + dis[min_v][i] <dij_dis[i]){
          dij_dis[i] = dij_dis[min_v] + dis[min_v][i];
          dij_wei[i] = dij_wei[min_v] + weight_v[i];
          dij_num[i] = dij_num[min_v];
        }
        else if(dij_dis[min_v]+dis[min_v][i]== dij_dis[i]){
          if(dij_wei[i] < dij_wei[min_v] +weight_v[i])
            dij_wei[i] = dij_wei[min_v] + weight_v[i];
            dij_num[i] =dij_num[min_v] + dij_num[i];
        }
      }
    }
    min_v = find_min();
  }
  cout << dij_num[to] <<" "<< dij_wei[to] << endl;
}

int main(){

  fill(dis[0], dis[0] + 500 * 500, inf);
  ifstream fin("data.txt");
  fin >> n_v >> n_dis >> src_v >> dis_v;
  for (int i = 0; i < n_v; i++)
    fin >> weight_v[i];
  for (int i = 0; i < n_dis; i++)
  {
    int from_v, to_v, dtmp;
    fin >> from_v >> to_v >> dtmp;
    dis[from_v][to_v] = dtmp;
    dis[to_v][from_v] = dtmp;
  }
  dijkstra(src_v, dis_v);
  return 0;
}

/*
1.dis数组赋初值
  2）memset 缺点是只能赋值char,如果是int等比较麻烦
  4）{0} 缺点是只适用于全都赋值为0的情况
  5 algorithm fill(v.begin,v.end,value);
    需要注意的是如果初始化2维数组 不能直接用数组指针 而是应该用v[0]

2.2维数组传参数
  pat里直接用全局数组更为方便

3.dijkstra简单实现
  1 维护一个visit数组 以及dij_dis数组
    此题目中需要额外维护一个dij_wei数组
  2 每次找到一个最近的点没有visit的点
    然后更新距离dij_dis(dij_wei)
  3 本题目需要给出的是最短路径条数

*/