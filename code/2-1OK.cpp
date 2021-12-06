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
 *  (1) 一个机器人只能向下和向右移动，每次只能移动一步，设计一个算 法求它从(0,0)移动到(m,n)有多少条路径。
 */

int path(int m, int n)
{
  vector<vector<int>> dp(m, vector<int>(n, 0));
  // 初始化 dp[][] 数组
  for (int i = 0; i < m; i++)
  {
    dp[i][0] = 1;
  }
  for (int i = 0; i < n; i++)
  {
    dp[0][i] = 1;
  }

  for (int i = 1; i < m; i++)
  {
    for (int j = 1; j < n; j++)
    {
      // 当前的位置只能从左边或者上边过来
      // 动态转移方程
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  cout << "从(0,0)移动到(" << m << "," << n << ")有" << dp[m - 1][n - 1] << "条路径" << endl;
  return dp[m - 1][n - 1];
}

int main()
{
  path(2, 3);
  return 0;
}