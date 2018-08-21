#include <iostream>
#include <stack>
using namespace std;


int M, N, K;

void check()
{
  stack<int> s;
  int temp[1010];
  int topt = 1;
  for (int i = 0; i < N; ++i)
  {
    cin >> temp[i];
  }
  for (int i = 0; i < N;++i)
  {
    if(s.empty())
      s.push(topt++);
    while (s.top() != temp[i] && s.top() <= N && s.size()<M)
      s.push(topt++);
    if(s.top()==temp[i])
      s.pop();
    else 
    {
      cout << "NO" << endl;
      return ;
    }
  }
  cout << "YES" << endl;
}

int main()
{
  
  cin >> M >> N >> K;
  for (int i = 0; i < K;++i)
  {
    check();
  }
  return 0;
}
/** 1051 堆栈模拟
 * 
 * stack 只有push pop top size选项
 * 也就是说只能访问栈顶元素 无法遍历 也没有begin end 无法转换成vector
 * 
 * */