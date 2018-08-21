#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <fstream>
using namespace std;

class Node{
public:
  Node() 
  { 
    height = 0;
    parent = -1;
  }
  vector<int> childs;
  int height;
  int parent;
  bool hasNochild();
  bool isRoot();
};

bool Node::hasNochild(){
  return childs.empty();
}

bool Node::isRoot(){
  bool check = (parent == -1 && childs.size() != 0);
  return check;
}

int main(){
  Node nodes[100];
  int n_node, n_nonleaf;
  ifstream fin("data.txt");
  fin >> n_node >> n_nonleaf;
  for (int i = 0; i < n_nonleaf;i++)
    {
      int ID, K;
      int childt;
      fin >> ID >> K;
      for (int i = 0; i < K;i++){
        fin >> childt;
        nodes[ID].childs.push_back(childt);
      }
    }

  queue<int> cengxu;
  int root;
  for (int i = 0; i < 100; i++)
    if(nodes[i].isRoot()){
      root = i;
      break;
    }
  cengxu.push(root);
  nodes[root].height = 0;

  map<int, int> result;

  while (!cengxu.empty())
  {
    int top = cengxu.front();
    Node parent = nodes[top];
    int p_height = parent.height;
    cengxu.pop();
    for (auto e = parent.childs.begin(); e != parent.childs.end();e++){
      nodes[*e].height = p_height + 1;
      cengxu.push(*e);
    }
    auto it = result.find(p_height);
    if(it == result.end()){
        result[p_height] = 0;
        if(parent.hasNochild())
          result[p_height] = 1;
    }
    else if(parent.hasNochild())
        result[p_height] += 1;
    }

    auto e = result.begin();
    if(e==result.end())
      return 0;
    cout << e->second;
    for (auto e = ++result.begin(); e != result.end(); e++)
    {
      cout << " " << e->second;
  }
  return 0;
}

/*
1. 层序遍历一棵树
  可以用bfs 或者dfs+depth
2. 问题是如何找到树的根节点以及确定树的最大深度

3.技巧 map用数组来实现 只要key值为整数 都可以用数组代替
*/