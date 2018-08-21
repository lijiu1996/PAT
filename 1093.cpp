#include <iostream> 
#include <vector> 
using namespace std;
 
class A{
  public:
    int T_before;
    int P_before;
    A(int t, int p) : T_before(t), P_before(p){}
};

int main()
{
  int total_T = 0;
  int total_P = 0;
  vector<A> v_A;
  string s;
  cin >> s;
  for (int i = 0; i < s.size();i++){
    if(s[i]=='A'){
      v_A.push_back(A(total_T, total_P));
    }
    else if(s[i]=='P'){
      total_P++;
    }
    else if(s[i]=='T'){
      total_T++;
    }
  }
  int npat = 0;
  for (auto e = v_A.begin(); e != v_A.end();e++){
    npat += e->P_before * (total_T - e->T_before);
  }
  cout << npat;
  return 0;
}