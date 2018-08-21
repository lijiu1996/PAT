#include <iostream>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

class Student{
  public:
    int C;
    int M;
    int E;
    int A;
    int high_range;
    char high_cat;
    Student() {}
    Student(int, int, int, int);
};

Student::Student(int C_,int M_,int E_,int A_):C(C_),M(M_),E(E_),A(A_){}

int
main()
{
  typedef int Node;

  Student Stu_list[2000];
  map<string, int> idtopos;

  Node Clist[2000];
  Node Mlist[2000];
  Node Elist[2000];
  Node Alist[2000];
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++)
  {
    string id;
    int C, M, E, A;
    cin >> id >> C >> M >> E;
    A = ( C + M + E ) / 3;   
    Clist[i] = C;
    Mlist[i] = M;
    Elist[i] = E;
    Alist[i] = A;
    Stu_list[i] = Student(C, M, E, A);

    idtopos[id] = i;
  }
  sort(Clist, Clist + N);
  sort(Mlist, Mlist + N);
  sort(Elist, Elist + N);
  sort(Alist, Alist + N);
  for (int i = 0; i < N;i++){
    int high_range = N + 1;
    char high_cat ='N';

    auto Apos = Alist + N - upper_bound(Alist, Alist + N, Stu_list[i].A);
    if(Apos<high_range)
    {
      high_range = Apos;
      high_cat = 'A';
    }
    auto Cpos = Clist + N - upper_bound(Clist, Clist + N, Stu_list[i].C);
    if(Cpos<high_range){
      high_range = Cpos;
      high_cat = 'C';
    }
    auto Mpos = Mlist+N-upper_bound(Mlist, Mlist + N, Stu_list[i].M);
    if(Mpos<high_range){
      high_range = Mpos;
      high_cat = 'M';
    }
    auto Epos = Elist+N-upper_bound(Elist, Elist + N, Stu_list[i].E);
    if(Epos<high_range){
      high_range = Epos;
      high_cat = 'E';
    }
    Stu_list[i].high_range = high_range;
    Stu_list[i].high_cat = high_cat;
  }
  for (int i = 0; i < M;i++){
    string fnd;
    cin >> fnd;
    auto idpos = idtopos.find(fnd);
    if(idpos==idtopos.end())
      cout << "N/A" << endl;
    else{
      int pos = idtopos[fnd];
      cout << Stu_list[pos].high_range+1 << " " << Stu_list[pos].high_cat << endl;
    }
  }

  return 0;
}

/** 1.问题是如何求一个值 在一列无序的值当中的位置
 *  排序以后用lower or upper bound
 * 
 *  2.map查找 不是find(begin,end) 而是map.find()
 * 
 *  3.源码里有许多许多重复并列结构 如何优化
 *  利用查表来优化 最后输出的时候用查最佳位置的表
 *  然后并列排序的话可以是用不同的cmp函数来排序 然后去一个最佳的pos
 * 
*/