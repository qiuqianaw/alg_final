#include <iostream>
using namespace std;
#include <vector>
#include <limits.h>
#include <math.h>

void getDiv(int x, vector<int> &a)
{
  for (int i = 2; i <= sqrt(x); ++i)
  {
    if (x % i == 0)
    {
      a.push_back(i);
      if (x / i != i)
        a.push_back(x / i);
    }
  }
}

int getMinStep(int n, int m)
{
  vector<int> step(m + 1, INT_MAX);
  //初始化
  step[n] = 0;
  for (int i = n; i < m; ++i)
  {
    if (step[i] == INT_MAX)
    {
      continue;
    }
    vector<int> a;
    getDiv(i, a);

    for (int j = 0; j < a.size(); ++j)
    {
      if (i + a[j] <= m && step[i + a[j]] == INT_MAX) //第一次涉足这个台阶
      {
        step[i + a[j]] = step[i] + 1;
      }
      else if (i + a[j] <= m) //不是第一次涉足，比较取最小值，动态规划核心算法
      {
        step[i + a[j]] = min(step[i] + 1, step[i + a[j]]);
      }
    }
  }
  return step[m] == INT_MAX ? -1 : step[m];
}

int main()
{
  int N, M;
  cin >> N >> M;
  cout << getMinStep(N, M) << endl;
  return 0;
}