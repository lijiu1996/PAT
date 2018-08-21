#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;
class Node{
public:
  int ni;
  float ani;
  Node(int ni_,float ani_):ni(ni_),ani(ani_){}
};
vector<Node> p1;
vector<Node> p2;
int main(void)
{
  int K1,K2;
  cin >> K1;
  for (int i = 0; i < K1;i++)
  {
    int ni;
    float ani;
    cin >> ni >> ani;
    p1.push_back(Node(ni, ani));
  }
  cin >> K2;
  for (int i = 0; i < K2;i++)
  {
    int ni;
    float ani;
    cin >> ni >> ani;
    p2.push_back(Node(ni,ani));
  }
  map<int, float> r;
  for(auto &e1:p1){
    for(auto &e2:p2){
      int nit = e1.ni + e2.ni;
      float anit = e1.ani * e2.ani;
      auto e = r.find(nit);
      if(e==r.end()) //not in
      {
        r[nit] = anit;
      }
      else
      {
        r[nit] += anit;
      }
    }
  }
  if(r.size()==0)
  {
    cout << 0;
    return 0;
  }
  cout << r.size();
  cout.setf(ios::fixed);
  for (auto e = r.rbegin(); e != r.rend(); e++)
    if(e->second!=0)
    cout <<" "<< e->first << " "  << setprecision(1) << e->second;
  return 0;
}

/*实现技巧:
1.如何反向遍历map rbegin
2.如何输出小数点后n位
include iomanip
cout.setf(ios::fixed)
setprecision(n)
3.本题适用的存储数据结构
一个需要遍历内容的多项式 vector
一个需要随时按指定值提取出来的字典 map
*/