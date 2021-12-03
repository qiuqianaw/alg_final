/*
 * @Descripttion: algFinal
 * @version: 1.0
 * @Author: qiuqian 19001020502邱谦
 * @LastEditors: qiquian
 */
#include <bits/stdc++.h>
using namespace std;
/**
 * 4. 回溯法和分支限界题目
 *  (3) 采用回溯法设计一个算法，求从 1~n 的 n 个整数中取出 m 个元素 的排列，要求每个元素最多只能取一次。
 *      例如:n=3，m=2 的输出结果是 (1,2)、(1,3)、(2,1)、(2,3)、(3,1)、(3,2)。
 */

int m = 2, n = 3;
// 存放序列
vector<int> arr(10);
// 用于标记是否已取出过
vector<bool> isUsed(20, false);

void myPrint(vector<int> arr)
{
  cout << "( ";

  for (int i = 1; i <= m; i++)
  {
    cout << arr[i];
    if (i != m)
    {
      cout << ", ";
    }
  }
  cout << " )" << endl;
}

void backtrack(int i)
{
  if (i > m)
  {
    myPrint(arr);
  }
  else
  {
    for (int j = 1; j <= n; j++)
    {
      if (isUsed[j] == false)
      {
        // 回溯核心
        // 满足条件 -> 选择 -> 进入下一层决策树 -> 撤销选择
        isUsed[j] = true;
        arr[i] = j;
        backtrack(i + 1);
        isUsed[j] = false;
      }
    }
  }
}

int main()
{
  // cin >> n >> m;
  if (m > n)
  {
    cout << "params error!" << endl;
    return 0;
  }
  cout << "n=" << n << ", m=" << m << endl;
  backtrack(1);
  return 0;
}
