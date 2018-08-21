#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int strtoint(const string& s)
{
  int result=0;
  result += s[3] - '0';
  for (int i = 0; i <= 2; i++)
  {
    result += pow(26, 3-i) * (s[i] - 'A');
  }
  return result;
}

class Student
{
  public:
    int nclass;
    vector<int> classes;
    Student():nclass(0){}
    void addClass(int classid);
    friend ostream &operator<<(ostream &out, Student &s);
};

void Student::addClass(int classid)
{
  classes.push_back(classid);
  ++nclass;
}

ostream& operator<<(ostream& out, Student& s)
{
  sort(s.classes.begin(), s.classes.end());
  out << s.nclass;
  for(auto e:s.classes)
    out << " " << e;
  return out;
}


int main()
{
  // map<string, Student> students;
  map<int, Student> students;
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < K; i++)
  {
    int classid,nstu;
    cin >>classid>>nstu;
    for (int j = 0; j < nstu; j++)
    {
      string name;
      cin >> name;
      int iname = strtoint(name);
      students[iname].addClass(classid);
    }
  }
  for (int i = 0; i < N;i++)
  {
    string checkstu;
    cin >> checkstu;
    int iname = strtoint(checkstu);
    cout << checkstu << " " << students[iname] << endl;
  }
  return 0;
}