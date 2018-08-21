#include <iostream> 
#include <vector>
using namespace std;

struct node{
  int data;
  int next;
  int pre;
  node() {}
  node(int d, int n) : data(d), next(n){}
};



int main()
{
  node nodes[100010];
  int begin, N, K;
  cin >> begin >> N >> K;
  for (int i = 0; i < N;++i)
  {
    int address, data, next;
    cin >> address >> data >> next;
    nodes[address].data =data;
    nodes[address].next = next;
    if (next != -1)
      nodes[next].pre = address;
  }
  nodes[begin].pre = -1;

  //out 
  int p = begin;
  int c = K-1;
  while(c--)
  {
    p = nodes[p].next;
  }
  nodes[begin].pre = nodes[p].next;
  c = K;
  while(c--)
  {
    // cout << p << " " << nodes[p].data << " " << nodes[p].pre << endl;
    if(nodes[p].pre<0){
      printf("%05d %d %d\n", p, nodes[p].data, nodes[p].pre);
      return 0;
    }
    else 
      printf("%05d %d %05d\n", p, nodes[p].data, nodes[p].pre);
    p = nodes[p].pre;
  }
  c = N - K;
  while(c--)
  {
    // cout << p << " " << nodes[p].data << " " << nodes[p].next << endl;
    if(nodes[p].next<0){
      printf("%05d %d %d\n", p, nodes[p].data, nodes[p].next);
      return 0;
    }
    else
      printf("%05d %d %05d\n", p, nodes[p].data, nodes[p].next);
    p = nodes[p].next;
  }

  return 0;
}

/** printf 输出格式控制
 * 1.
 * 
 * */