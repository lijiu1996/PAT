#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct node
{
  int data;
  node *right;
  node *left;
};


int N;
int total = 0;
stack<int> s;
vector<int> pushv;//pre
vector<int> popv;//in

node* create(int preL,int preR,int inL,int inR)
{
  if(preL>preR || inL>inR)
    return NULL;
  node *n = new node;
  n->data = pushv[preL];
  auto e = find(popv.begin(), popv.end(), n->data);
  int pos = e - popv.begin();
  int l = pos-inL;
  int r = inR -pos;
  n->left = create(preL + 1, preL + l, inL, inL + l - 1);
  n->right = create(preL + l + 1, preR, inL + l + 1, inR);
  return n;
}

void travel(node * root)
{
  if(!root)
    return;
  travel(root->left);
  travel(root->right);
  ++total;
  if(total==N)
    cout << root->data;
  else
    cout << root->data << " ";
}

int main()
{
  
  cin >> N;
 

  for (int i = 0; i < 2 * N; ++i)
  {
    string op;
    cin >> op;
    if(op=="Push")
    {
      int t;
      cin >> t;
      s.push(t);
      pushv.push_back(t);
    }
    else if(op =="Pop")
    {
      int t = s.top();
      s.pop();
      popv.push_back(t);
    }
  }
  node *tree = create(0, N - 1, 0, N - 1);
  travel(tree);
  return 0;
}

/** 来自礼拜天的复习 
 * 
 * 注意比较不同容器的不同迭代方式 有可以随机访问的 有可以迭代的 还有不能迭代的
 * --vector使用
 * insert(it,x) 
 * erase(it)
 * erase(first,last)
 * 
 * --set使用
 * insert()
 * 有成员函数find() vector没有 需要使用全局函数
 * 
 * --string使用
 * insert有很多种重载方式
 * 1.insert(pos,string)
 * 2.insert(it,it2,it3)
 * 3.replace
 * 
 * --map使用
 * 1.同set一样拥有 find count lowerbound upperbound
 * 2.
 * 
 * 第六章 剩余部分(未能学习)
 * priority queue 使用
 * algorithm 使用
 * 
 * 树的学习
 * 1.二叉树的递归定义
 * 2.完全二叉树
 * 3.先序遍历性质 第一个一定是根节点
 * 4.中序遍历 只要知道根节点 就可以根据中序遍历区分左右子树
 * 5.后序遍历 最后一个是根节点
 * 如果要获得一棵树 必须知道中序遍历和其他一种遍历方法
 * 6.层序遍历
 * */