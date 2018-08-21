#include <iostream>
#include <vector>
using namespace std;
struct node
{
  int data;
  node *left;
  node *right;
} nodes[1010];

int N;
vector<int> pre;
vector<int> prem;
vector<int> org;

void insert(node* & r,int n)
{
  if(r==NULL)
  {
    r = new node;
    r->data = n;
    r->left = NULL;
    r->right = NULL;
    return;
  }
  else if(n<r->data)
    insert(r->left, n);
  else
    insert(r->right, n);
}

void preorder(node* r)
{
  if(r==NULL)
    return;
  pre.push_back(r->data);
  preorder(r->left);
  preorder(r->right);
}

void preorderm(node* r)
{
  if(r==NULL)
    return;
  prem.push_back(r->data);
  preorderm(r->right);
  preorderm(r->left);
}

bool flag=false;

void post(node* r)
{
  if(r==NULL)
    return;
  post(r->left);
  post(r->right);
  if(!flag)
  {
    cout<<r->data;
    flag = true;
  }
  else
    cout<<" "<<r->data;
}

void postm(node* r)
{
  if(r==NULL)
    return;
  postm(r->right);
  postm(r->left);
  if(!flag)
  {
    cout<<r->data;
    flag = true;
  }
  else
    cout<<" "<<r->data;
}

int main()
{
  cin >> N;
  node *tree = NULL;
  for (int i = 0; i < N; ++i)
  {
    int t;
    cin >> t;
    insert(tree, t);
    org.push_back(t);
  }
  preorder(tree);
  preorderm(tree);
  if(org==pre )
  {
    cout<<"YES"<<endl;
    post(tree);
  }
  else if(org==prem)
  {
    cout<<"YES"<<endl;
    postm(tree);
  }
  else
    cout<<"NO"<<endl;
  
  return 0;
}
/** 二叉查找树的性质
 * 1. 二叉查找树给出一个序列就能建立 建立完在比较顺序即可
 * 2.二叉查找树的删除
 *  如果删除的是根 则找前驱替换等方法
 *  如果删除的不是根 则在子树里递归删除
 * 3.经验心得 
 *   镜像树-->写两个函数然后判断
 *   node* 与node* &
 *
 *
 *
 * */
