#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
  int data;
  int left;
  int right;
} nodes[1010];

int N;
vector<int> all;

int in = 0;
void inorder(int r)
{
  if(r<0)
    return;
  nodes[r].left = 2 * r >N?-1:2*r;
  nodes[r].right = 2 * r + 1 >N?-1:2*r+1;

  inorder(nodes[r].left);
  nodes[r].data = all[in++];
  inorder(nodes[r].right);
}

bool firstout = false;
void order(int r)
{
  queue<int> q;
  if(N==0)
    return ;
  q.push(r);
  while(!q.empty())
  {
    int t= q.front();
    q.pop();
    if(nodes[t].left>=0)
      q.push(nodes[t].left);
    if(nodes[t].right>=0)
      q.push(nodes[t].right);
    if(!firstout)
    {
      cout << nodes[t].data;
      firstout = true;
    }
    else
      cout << " " << nodes[t].data;
  }
}

int main()
{
  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    int t;
    cin >> t;
    all.push_back(t);
  }
  sort(all.begin(), all.end());
  inorder(1);
  order(1);
  return 0;
}

/** 题目总结 树构建的几种类型
 * 
 * 
 *  1. 给出先序遍历 建二叉查找树(只限先序遍历可以使用插入法)
 *  2. 给出中序遍历两种 建基本二叉树树(递归法,注意的一个问题是不能有重复值)
 *  3. 栈模拟 建基本二叉树(栈模拟实际上就是两个遍历)
 *  4. 给出序列 建完全树(利用性质中序遍历递增)
 * 
 * 
 * 
 * */