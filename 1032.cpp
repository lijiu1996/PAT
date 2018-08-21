#include <iostream>

using namespace std;

struct node{
  int address;
  char data;
  int next;
  bool visit;
};

int main()
{
  node nodes[100010];
  int first, second, N;
  cin >> first >> second >> N;
  for (int i = 0; i < N;++i)
  {
    int address, next;
    char data;
    // cin >> address >> data >> next;
    scanf("%d %c %d", &address, &data, &next);
    nodes[address].data = data;
    nodes[address].next = next;
    nodes[address].visit = false;
  }

  bool found = false;
  int p = first;
  while(p!=-1)
  {
    nodes[p].visit = true;
    p = nodes[p].next;
  }

  p = second;
  while(p!=-1)
  {
    if(nodes[p].visit)
    {
      cout << p <<" "<< nodes[p].data ;
      found = true;
      break;
    }
    p = nodes[p].next;
  }

  if(!found)
    cout << -1;
  return 0;
}