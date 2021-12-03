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
 *  (2) 设计求解有重复元素的排列问题的算法。
 *      设有 n 个元素, a[ ]={a0,a1,...,an-1}，其中可能含有重复的元素，求这些元素的所有排列。
 *      例如 a[ ]={1,1,2}，输出结果是(1,1,2)、(1,2,1)、(2,1,1)。
 */

vector<vector<int>> result;
vector<int> path;

void backtrack(vector<int> nums, vector<bool> used)
{
  for (int i = 0; i < nums.size(); i++)
  {
    if (path.size() == nums.size())
    {
      result.push_back(path);
      return;
    }
    if (i > 0 && used[i - 1] == false && nums[i] == nums[i - 1])
    {
      continue;
    }
    if (used[i] == false)
    {
      used[i] = true;
      path.push_back(nums[i]);
      backtrack(nums, used);
      path.pop_back();
      used[i] = false;
    }
  }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
  vector<bool> used(nums.size() + 1, false);
  sort(nums.begin(), nums.end());
  backtrack(nums, used);
  return result;
}

int main()
{
  vector<int> nums = {1, 1, 2};
  vector<vector<int>> result = permuteUnique(nums);
  for (auto res : result)
  {
    for (auto r : res)
    {
      cout << r << " ";
    }
    cout << endl;
  }
  return 0;
}
