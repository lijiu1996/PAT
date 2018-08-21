#include <iostream> 
#include <vector>
#include <cmath>
using namespace std;

int N, K, P;
vector<int> factor;
vector<int> current;
vector<int> result;
int maxfacnum = 0;

void DFS(int index,int n,int sum,int vsum)
{
  if(n==K && sum==N)
  {
    if(vsum>maxfacnum)
    {
      result = current;
      maxfacnum = vsum;
      return;
    }
  }
  if(index<1 || sum>N || n>K)
    return;
  current.push_back(index);
  DFS(index, n + 1, sum + factor[index], vsum + index);
  current.pop_back();
  DFS(index - 1, n, sum, vsum);
}

int main()
{
  
  cin >> N >> K >> P;

  //init
  int n = 0;
  int c = pow(n, P);
  while (c<= N)
  {
    factor.push_back(c);
    ++n;
    c = pow(n, P);
  }
  //begin dfs
  DFS(factor.size()-1, 0, 0, 0);
  cout << N << " = " << result[0] << "^" << P;
  for (int i = 1; i < result.size();++i)
    cout << " + " << result[i] << "^" << P;
  return 0;
}

/** 枚举类问题 深度优先搜索
 * 
 * 1.遍历时可以根据点的加入与否来进行两次递归
 * 2.适当剪枝 加快递归速度
 * 3.非常适用于从N个数里选出K个数的问题 限制条件总和为sum 最优条件sumSqu最大
 *  递归函数设计
 *  int index,int nowk,int sum,int sumSqu
 *  函数里保存 当前考虑的数的index,现在的总个数nowK,现在的总和为sum 现在的目标输出为sumSqu
 * 
 * */