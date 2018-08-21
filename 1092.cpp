#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  bool ischecked[128];
  memset(ischecked, 0, sizeof(ischecked));

  string org, want;
  cin >> org >> want;

  int extraneed = 0;
  for (int i = 0; i < want.size();++i)
  {
    if(!ischecked[want[i]])
    {
      int t =count(want.begin(), want.end(), want[i])-count(org.begin(), org.end(), want[i]);
      extraneed += t <= 0 ? 0 : t;
      ischecked[want[i]] = true;
    }
  }
  if(!extraneed)
    cout << "Yes " << org.size()-want.size();
  else
    cout << "No " <<extraneed;
  return 0;
}

/** memset --> string.h
 *  检查string里面字符个数 需要使用全局count
 *  string.h 还写了 strcpy等一系列字符串函数
 * 
 * 
 * 
 * */