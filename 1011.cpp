#include<iostream> 
#include<vector> 
#include <iomanip>
#include <map>

using namespace std; 

int main(){

  double data[3][4];
  int minlocat[3];
  map<int, char> swch;
  swch[0] = 'W';
  swch[1] = 'T';
  swch[2] = 'L';

  for (int i = 0; i < 3; i++)
  {
    double mindata = -1;
    int minloc = 0;
    for (int j = 0; j < 3; j++)
    {
      cin >> data[i][j];
      if(data[i][j]>mindata){
        mindata = data[i][j];
        minloc = j;
      }
    }
    data[i][3] = mindata;
    minlocat[i] = minloc;
  }
  double result = 1.0;
  for (int i = 0; i < 3; i++)
  {
    cout << swch[minlocat[i]] << " ";
    result *= data[i][3];
  }
  result = (result * 0.65 - 1) * 2;
  cout  <<fixed << setprecision(2) << result;
  return 0;
}