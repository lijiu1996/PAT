#include <iostream>
#include <queue>
using namespace std;

int N;
int postorder[31];
int inorder[31];

struct node{
  int data;
  node *left;
  node *right;
};


node* create(int postL,int postR,int inL,int inR)
{
  if(postL>postR || inL >inR)
    return NULL;
  node *n = new node;
  n->data = postorder[postR];
  int loc;
  for (int i = inL; i <= inR; ++i)
  {
    if(inorder[i]==n->data)
    {
      loc = i;
      break;
    }
  }
  int l = loc - inL;
  int r = inR - loc;
  n->left = create(postL, postL + l - 1, inL, inL + l - 1);
  n->right = create(postL+l, postR - 1, loc + 1, inR);
  return n;
}

void travel(node* root)
{
  queue<node *> q;
  if(root!=NULL){
    q.push(root);
    cout << root->data;
  }
  while(!q.empty())
  {
    node *n = q.front();
    q.pop();
    if(n->left){
      q.push(n->left);
      cout << " " << n->left->data;
    }
    if(n->right){
      q.push(n->right);
      cout << " " << n->right->data;
    }
  }
}

int main()
{
  cin >> N;
  for (int i = 0; i < N;++i)
    cin >> postorder[i];
  for (int i = 0; i < N;++i)
    cin >> inorder[i];
  node *tree = create(0, N - 1, 0, N - 1);
  travel(tree);
  return 0;
}

/** 树的实现要点
 * 1.struct 尽量定义的简单
 * 2.通过遍历序列递归建树
 * 
 * 
 * 
 * 
 * */