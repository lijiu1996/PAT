#include<iostream>
#include<vector>

using namespace std;

const int maxN = 110;
// int heap[maxN];
vector<int> org;
vector<int> now;
vector<int> insert;
vector<int> heap;
int N;

void downadjust(int down,int high)
{
  int i = down;
  int j = 2 * i;
  while(j<=high)
  {
    if(j+1<=high && heap[j+1]>heap[j])
      j = j + 1;
    if(heap[j]>heap[i])
      {
        int t = heap[i];
        heap[i] = heap[j];
        heap[j] = t;
        i = j;
        j = 2 * i;
      }
      else
        break;
  }
}

void buildheap(int size)
{
  for (int i = size/2; i > 0;--i)
    downadjust(i, size);
}

int hsize;
int isize;

void heapsort()
{
  if(hsize==1)
    return;
  int t = heap[hsize];
  heap[hsize] = heap[1];
  heap[1] = t;
  downadjust(1, hsize - 1);
  hsize--;
}

void insertsort()
{
  if(isize>N)
    return;
  sort(insert.begin() + 1, insert.begin() + isize + 1);
  isize++;
}

void output(vector<int>& v)
{
  for (int i = 1; i <= N;i++)
  {
    cout << v[i];
    if(i!=N)
      cout << " ";
  }
  cout << endl;
}

int main()
{
  
  cin >> N;
  org.push_back(0);
  for (int i = 1; i <= N; ++i)
  {
    int t;
    cin >> t;
    org.push_back(t);
  }
  now.push_back(0);
  for (int i = 1; i <= N; ++i)
  {
      int t;
      cin >> t;
      now.push_back(t);
  }
  heap = org;
  insert = org;
  buildheap(N);
  hsize = N;
  isize = 2;

  while(1)
  {
    heapsort();
    insertsort();
    if(heap==now || insert==now)
      break;
  }
  if(heap==now)
  {
    cout << "HeapSort:" <<endl;
    heapsort();
    output(heap);
  }
  if(insert==now)
  {
    cout << "InsertSort:" << endl;
    insertsort();
    output(insert);
  }
  return 0;
}

/** 数据结构--堆
 * 
 * 建堆 
 * 
 * -- 使一个节点符合堆序 -- 向下调整法
 * -- 使整棵树符合堆序  --  从后往前遍历所有点
 *  
 * 堆的删除
 * 
 * -- 向下调整堆定点
 * 
 * 堆的插入
 * 
 * -- 向上调整
 * 
 * 堆排序
 * 
 * 注意堆这种数据结构也是没有随机遍历的迭代器的
 * 
 * 1099.问题是如何判定这两个是堆排序还是insertsort
 * 
 * 
 * */