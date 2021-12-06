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
 *  (3) 排队买票问题
 *      问题描述:本周末有一场电影首映，有 n 个观众在排队买票，一个人买 一张票。
 *      售票处规定:一个人每次最多只能买两张票。
 *      假设第 i 位影迷买 一张票的时间是 ti(1≤i≤n)，
 *      队伍里相邻的两位观众(第 i 个人和第 i+1 个人)也可以由其中一个人一次买两张票，这样另外一位就不用排队了。 
 *      此时他们买两张票的时间就变成了 ei，如果 ei<ti+ti+1，就能够缩短后面观 众等待的时间，加快售票过程。
 *      设计算法，求让每个人都能买到票的最短时间。
 */
//dp[i] 有i个人买票的最短时间

// 动态转移方程：
//  n个人买票的最短时间 = min(第n个人单独买票， 第n个人和第n-1个人一起买票)
//  第n个人单独买票 = 前n-1个人买票的最短时间 + 第n个人单独买票的时间
//  第n个人和第n-1个人一起买票 = 前n-2个人买票的最短时间 + 第n个人和第n-1个人一起买票的时间

// dp[1] = 1, dp[2] = min(dp[1]+t[1], e[0]+dp[0]) = 2, dp[3] = min(dp[2]+t[2]=5, e[1]=2=3+dp[1]=1)=4 , dp[4] = min(dp[3]+t[3]=8, dp[2]+e[2]=12)=8

int buyTickets(int n, vector<int> t, vector<int> e)
{
  vector<int> dp(n + 1, 0);
  // 初始化 第一个人买票的最短时间只能是自己单独买
  dp[1] = t[0];
  for (int i = 2; i <= n; i++)
  {
    // n个人买票的最短时间 = min(第n个人单独买票， 第n个人和第n-1个人一起买票)
    dp[i] = min(dp[i - 1] + t[i - 1], e[i - 2] + dp[i - 2]);
  }
  return dp[4];
}

int main()
{
  int n = 4;
  vector<int> t = {1, 2, 3, 4};
  vector<int> e = {2, 3, 10};
  cout << buyTickets(n, t, e) << endl;
  return 0;
}