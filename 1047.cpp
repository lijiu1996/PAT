#include<vector> 
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;

/*
int hashstr(char str[])
{
  int result = 0;
  for (int i = 0; i < 3;i++)
  {
    result += str[i] - 'A';
    result = result * 26;
  }
  result += str[3] - '0';
  return result;
}
*/

bool cmp(const char* s1,const char* s2)
{
  return strcmp(s1, s2)>0?0:1;
}

int main()
{
  char students[40000][5];
  vector<char*> classes[2510];
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N;++i)
  {
    int nclass;
    scanf("%s%d", students[i], &nclass);
    for (int j = 0; j < nclass; ++j)
    {
      int ct;
      scanf("%d",&ct);
      classes[ct].push_back(students[i]);
    }
  }
  for (int i = 1; i <= K;i++)
  {
    cout << i << " " << classes[i].size() << endl;
    sort(classes[i].begin(), classes[i].end(),cmp);
    for (auto e : classes[i])
      printf("%s\n",e);
  }
  return 0;
}

/** 1039/1047题笔记 vector&&hash
 * 1.数据量大的情况用string容易产生超时问题 可以改成char*
 * 2.cout 容易产生超时问题 可以改成printf
 * 3.比较两个char*时 使用strcmp函数注意strcmp结果为>0 0 <0
 * 4.排序时对字符串排序和对下标排序(使用char*的话就没差)
 * 
 * 1039
 * map<string,vector>效率低的问题 --> 改为vector数组
 * 
 * */