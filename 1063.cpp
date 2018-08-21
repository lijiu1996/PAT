#include <iostream> 
#include <vector>
#include <set>
#include <iomanip>

using namespace std;
int main()
{
  set<int> sets[55];
  int N,K;
  cin >> N;
  for (int i = 1; i <= N;++i)
  {
    int total;
    cin >> total;
    for (int j = 0; j < total;++j)
    {
      int t;
      cin >> t;
      sets[i].insert(t);
    } 
  }
  cin >> K;
  for (int i = 0; i < K;++i)
  {
    int first, second,repeat=0;
    cin >> first >> second;
    for(auto e:sets[first])
    {
      if(sets[second].find(e)!=sets[second].end())
        repeat++;
    }
    double p = repeat * 100.0 / (sets[first].size() + sets[second].size() - repeat);
    cout << fixed<<setprecision(1) << p <<"%"<< endl;
  }
  return 0;
}