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
 *  (2) 两种水果杂交出一种新水果，现在给新水果取名，要求这个名字中 包含了以前两种水果名字的字母，并且这个名字要尽量短。
 *      也就是说，以 前的一种水果名字 arr1 是新水果名字 arr 的子序列，另一种水果名字 arr2 也是新水果名字 arr 的子序列。
 *      设计一个算法求 arr。例如:输入以下两 组水果名称:
 *        apple peach
 *        pear peach 
 *        输出的新水果名称如下: 
 *        appleach
 *        pearch
 */

/**
 * 来自上方的记为 flag[i][j]=1,来自左边的记为 flag[i][j]=-1,来自斜上的记为 flag[i][j]=0，
 * 
 */

void show(int i, int j, string str1, string str2, vector<vector<int>> flag)
{
  if (!i && !j)
  {
    return;
  }
  if (flag[i][j] == 0)
  {
    show(i - 1, j - 1, str1, str2, flag);
    cout << str1[i - 1];
  }
  else if (flag[i][j] == 1)
  {
    show(i, j - 1, str1, str2, flag);
    cout << str2[j - 1];
  }
  else
  {
    show(i - 1, j, str1, str2, flag);
    cout << str1[i - 1];
  }
}

int LCS(string str1, string str2)
{
  vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
  vector<vector<int>> flag(str1.size() + 1, vector<int>(str2.size() + 1, 0));

  for (int i = 0; i <= str1.size(); i++)
  {
    flag[i][0] = -1;
  }
  for (int i = 0; i <= str1.size(); i++)
  {
    flag[0][i] = 1;
  }

  for (int i = 1; i <= str1.size(); i++)
  {
    for (int j = 1; j <= str2.size(); j++)
    {
      if (str1[i - 1] == str2[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        flag[i][j] = 0;
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        flag[i][j] = dp[i - 1][j] < dp[i][j - 1] ? 1 : -1;
      }
    }
  }

  // print dp array
  // for (auto nums : dp)
  // {
  //   for (auto n : nums)
  //   {
  //     cout << n << " ";
  //   }
  //   cout << endl;
  // }
  cout << dp[str1.size()][str2.size()] << endl;

  show(str1.size(), str2.size(), str1, str2, flag);

  return dp[str1.size()][str2.size()];
}

int main()
{
  int lcs = LCS("ananas", "banana");
  return 0;
}