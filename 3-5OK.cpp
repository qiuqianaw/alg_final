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
 *  (5) 加油站问题。问题描述:一辆汽车加满油可行驶 n 千米。
 *      旅途中有若干加油站。设计一个算法，指出应在哪些加油站停靠加油，使沿途加 油次数最少。
 *      对于给定的 n(n≤5000)和 k(k≤1000)个加油站位置， 编程计算最少的加油次数。
 * 
 *    第一行有 2 个正整数n和 k（k<=1000 )，表示汽车加满油后可行驶n公里，且旅途中有 k个加油站。 
 *    第二行有 k+1 个整数，表示第 k 个加油站与第k-1 个加油站之间的距离。 
 *    第 0 个加油站表示出发地，汽车已加满油。 
 *    第 k+1 个加油站表示目的地。
 */

// n=7 k=7
// nums = {1 2 3 4 5 1 6 6 }

void gas(int n, vector<int> nums)
{
  int sum = 0;
  int ans = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (sum + nums[i] <= n)
    {
      sum += nums[i];
    }
    else if (nums[i] > n)
    {
      cout << "null" << endl;
    }
    else
    {
      cout << i << " ";
      ans++;
      sum = nums[i];
    }
  }
  cout << endl;
  cout << ans << endl;
}

int main()
{
  int n = 7;
  vector<int> nums = {1, 2, 3, 4, 5, 1, 6, 6};
  gas(n, nums);
  return 0;
}