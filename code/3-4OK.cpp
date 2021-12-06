/*
 * @Descripttion: algFinal
 * @version: 1.0
 * @Author: qiuqian 19001020502邱谦
 * @LastEditors: qiquian
 */
#include <bits/stdc++.h>
using namespace std;
/**
 * 3. 贪心法题目
 *  (4) 假设要在足够多的会场里安排一批活动，n 个活动编号为 1~n，每 个活动有开始时间 bi 和结束时间 ei(1≤i≤n)。
 *      设计一个贪心算法求出最少的会场个数。
 */

int getMinRooms(vector<vector<int>> meetings)
{
  unordered_map<int, int> map;
  int result = INT_MIN;
  for (auto meeting : meetings)
  {
    // cout << meeting[0] << " " << meeting[1] << endl;
    int start = meeting[0], end = meeting[1];
    for (int i = start; i <= end; i++)
    {
      map[i]++;
    }
  }
  for (auto it : map)
  {
    // cout << it.first << " " << it.second << endl;
    if (it.second > result)
    {
      result = it.second;
    }
  }
  cout << result << endl;
  return result;
}

int main()
{
  vector<vector<int>> meetings = {
      {0, 30},
      {5, 10},
      {15, 20}};
  getMinRooms(meetings);
  return 0;
}