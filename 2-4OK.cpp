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
 *  (4) 跨楼梯问题
 *      问题描述:现有一段楼梯，共 n 层台阶，假设每次只能往上走一层或两层台阶。如果要走上第 n 层台阶，请设计算法，求出共有多少走法。
 */

// 1 2 3 5 8 fib变形
void step(int n)
{
  if (n <= 0)
  {
    cout << "0" << endl;
    return;
  }
  if (n == 1 || n == 2)
  {
    cout << "要走上第" << n << "层台阶，共有" << n << "种走法" << endl;
    return;
  }
  vector<int> dp(n + 1);
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  cout << "要走上第" << n << "层台阶，共有" << dp[n] << "种走法" << endl;
  return;
}

/**
 * 爬楼梯，滚动数组做法
 *  1(pre) 1(cur) 2(nex) 3 5 8 13 21 34 ...
 *  1( x ) 1(pre) 2(cur) 3(nex) 5 8 13 21 34 ...
 * @param n 
 */
void step2(int n)
{
  if (n <= 0)
  {
    cout << "0" << endl;
    return;
  }
  if (n == 1 || n == 2)
  {
    cout << "要走上第" << n << "层台阶，共有" << n << "种走法" << endl;
    return;
  }
  int pre, cur, nex;
  pre = 1, cur = 2;
  for (int i = 3; i <= n; i++)
  {
    nex = pre + cur;
    pre = cur;
    cur = nex;
  }
  cout << "要走上第" << n << "层台阶，共有" << nex << "种走法" << endl;
}

int main()
{
  int n = 20;
  step(n);
  step2(n);
  return 0;
}