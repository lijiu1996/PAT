#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

string s[10]= {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
  string N;
  ifstream fin("data.txt");
  cin >> N;

  int sum = 0;
  for (int i = 0; i < N.length();i++){
    sum += int(N[i] - '0');
  }

  vector<string> output;
  if(sum ==0)
    output.push_back(s[0]);
  while(sum){
    int digit = sum % 10;
    output.push_back(s[digit]);
    sum = sum / 10;
  }
  for (auto e = --output.end(); e != output.begin();e--){
    cout << *e << " ";
  }
  cout << output.front();
  return 0;
}

/*
问题 如何遍历一个字符串？

问题 如何遍历一个数的每一位
方法一 循环
  问题是 数如果是0的话不进入循环
        且倒序遍历比较麻烦
方法二 转化成字符串然后遍历
*/