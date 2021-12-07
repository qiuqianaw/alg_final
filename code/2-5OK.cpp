/*
 * @Descripttion: algFinal
 * @version: 1.0
 * @Author: qiuqian 19001020502邱谦
 * @LastEditors: qiquian
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * 2. 动态规划题目
 *  (5) 跳石板问题
 *      问题描述:有一条石板路，每块石板都有编号，依次是 1、2、3、...。
 *      在 这条石板路上前进需要依据特殊的规则:设当前所在石板的编号为 h，单 次只能往前跳 t 步(t 是 h 的因子，但其中不含 1 和 h)，跳到 h+t 的位 置。
 *      假设当前所在石板的编号为 s，请设计算法，求出要想跳到编号为 e 的石板，最少需要跳跃几次。
 */

vector<int> getNums(int n)
{
  vector<int> nums;
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      nums.push_back(i);
      if (n / i != i)
      {
        nums.push_back(n / i);
      }
    }
  }
  return nums;
}

int steps(int s, int e)
{
  vector<int> steps(e + 1, INT_MAX);
  steps[s] = 0;
  for (int i = s; i < e; i++)
  {
    if (steps[i] == INT_MAX)
    {
      continue;
    }
    // 求除 1 和自身以外的约数
    vector<int> nums = getNums(i);
    for (auto num : nums)
    {
      // 第一次到达这个台阶
      if (i + num <= e && steps[i + num] == INT_MAX)
      {
        steps[i + num] = steps[i] + 1;
      }
      else if (i + num <= e)
      {
        // 动态转移方程
        steps[i + num] = min(steps[i] + 1, steps[i + num]);
      }
    }
  }
  return steps[e] == INT_MAX ? -1 : steps[e];
}

int main()
{
  int s, e;
  // cin >> s >> e;
  cout << steps(4, 24) << endl;
  return 0;
}