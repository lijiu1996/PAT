#include<iostream>
#include<algorithm>
#include<fstream>
#include<cstring>
using namespace std;

int N, M, K;
int e[1000][1000]={0};
int t[1000][1000]={0};

int visit[1000] = {0};

void dfs(int pos,int con[1000][1000]){
  visit[pos] = 1;
  for (int i = 0; i < N;i++){
    if(con[pos][i]&&!visit[i])
      dfs(i,con);
  }
}

int getCon(int con[1000][1000]){
  fill(visit, visit + 1000, 0);
  int result = 0;
  for (int i = 0; i < N; i++)
  {
    if(!visit[i])
      {
        dfs(i, con);
        result++;
        // cout << i << endl;
      }
  }
  return result;
}

int getCon(int con[1000][1000],int target)
{
  fill(visit, visit + 1000, 0);
  int result = 0;
  visit[target] = 1;
  for (int i = 0; i < N; i++)
  {
    if(!visit[i])
    {
      dfs(i, con);
      ++result;
    // cout << i << endl;
    }
  }
  return result;
}

void del(int target){
  memcpy(t, e, 1000);
  /*for (int i = 0; i < N;i++)
    for (int j = 0; j < N;j++)
      t[i][j] = e[i][j];*/
  for (int i = 0; i < N;i++)
    if(t[i][target]&&t[target][i]){
      t[i][target] = t[target][i] = 0;
    }
}

void print(int a[1000][1000]){
  for (int i = 0; i < N;i++){
    for (int j = 0; j < N;j++){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}


int main()
{
  /*
  ifstream cin("data.txt");
  cin >> N >> M >> K;
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    e[a][b] = e[b][a] = 1;
  }
  
  for (int i = 0; i < K; i++)
  {
  int target,postn;
  cin >> target; 
  --target;
  // postn = getCon(e);
  del(target);
  postn = getCon(t);
  // postn = getCon(e, target);
  int cut = postn - 2;
  cout << max(cut,0) << endl;
  }*/
  cout << sizeof(e) << endl;

  return 0;
}
/** 问题1 如何深度优先搜索一个图
 *  问题2 memcpy一个图的时候要用sizeof
 * 
 * 
 * 
 * 
 * 
*/