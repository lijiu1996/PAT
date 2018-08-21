#include <iostream>
using namespace std;
int main()
{
  bool has[100010];
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N;i++)
  {
    int t;
    cin >> t;
    has[t] = true;
  }
  bool flag = false;
  for (int i = 1; i <= M/2; ++i)
  {
    if(has[i]&& has[M-i] && i!=M-i)
    {
      cout << i << " " << M - i;
      flag = true;
      break;
    }
  }
  if(!flag)
    cout << "No Solution" << endl;
  return 0;
}