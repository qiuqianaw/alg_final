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
 *  (1) 设计一个算法求解简单装载问题。
 *      设有一批集装箱要装上一艘载重量为 W 的轮船，其中编号为 i(0≤i≤n-1)的集装箱的重量为 wi。
 *      现要 从 n 个集装箱中选出若干个装上轮船，使它们的重量之和正好为 W。
 *      如果找到任一种解，返回 true，否则返回 false。
 */

vector<vector<int>> result;
vector<int> path;
int getSum(vector<int> nums)
{
  int sum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    sum += nums[i];
  }
  return sum;
}

void backtrack(vector<int> &w, int W, int start, vector<bool> &isUsed)
{
  if (getSum(path) == W)
  {
    result.push_back(path);
    return;
  }

  for (int i = start; i < w.size(); i++)
  {
    if (i > 0 && isUsed[i - 1] == false && w[i] == w[i - 1])
    {
      continue;
    }
    path.push_back(w[i]);
    isUsed[i] = true;
    backtrack(w, W, i + 1, isUsed);
    isUsed[i] = false;
    path.pop_back();
  }
}

void print()
{
  for (auto a : result)
  {
    for (auto c : a)
    {
      cout << c << " ";
    }
    cout << endl;
  }
  if (result.size() < 1)
  {
    cout << "false" << endl;
  }
  else
  {
    cout << "true" << endl;
  }
}

int main()
{
  vector<int> w = {15, 5, 20, 10, 35, 25, 40};
  vector<bool> isUsed(w.size() + 1, false);
  sort(w.begin(), w.end());
  int W = 45;
  backtrack(w, W, 0, isUsed);
  print();
  return 0;
}