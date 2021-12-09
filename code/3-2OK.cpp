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
 *  (2) 求解乘船问题。有 n 个人，第 i 个人体重为 wi(0≤i<n)。每艘船的最大载重量均为 C，且最多只能乘两个人。试用最少的船装载所有人。
 */
vector<int> sortArray(vector<int> &nums);
int partation(vector<int> &arr, int left, int right);
void quickSort(vector<int> &arr, int left, int right);

/**
 * @brief 
 * 快速排序：数组中随机选择基准点，遍历剩余数组，将所有比基准点小的元素放在其左边，所有比基准点大的元素放在其右边。
 * 一次遍历后，该基准点就位于已经排序完成时它应该处于的位置。
 * 循环这个操作，直到所有元素排序完成。
 * @param nums 
 * @return vector<int> 
 */
vector<int> sortArray(vector<int> &nums)
{
  quickSort(nums, 0, nums.size() - 1);
  return nums;
}
int partation(vector<int> &arr, int left, int right)
{
  int random = left + rand() % (right - left + 1);
  swap(arr[random], arr[left]);
  int pivot = arr[left];
  while (left < right)
  {
    while (left < right && arr[right] >= pivot)
    {
      right--;
    }
    arr[left] = arr[right];
    while (left < right && arr[left] <= pivot)
    {
      left++;
    }
    arr[right] = arr[left];
  }
  arr[left] = pivot;
  return left;
}
void quickSort(vector<int> &arr, int left, int right)
{
  if (arr.size() < 2 || left >= right)
    return;
  // 主要增加的细节处理在下面这部分的函数中
  int p = partation(arr, left, right);
  quickSort(arr, left, p - 1);
  quickSort(arr, p + 1, right);
}

int getMinBoats(vector<int> &w, int C)
{
  // sort(w.begin(), w.end());
  w = sortArray(w);
  int left = 0, right = w.size() - 1;
  int result = 0;
  while (left < right)
  {
    if (w[left] + w[right] <= C)
    {
      result++;
      left++, right--;
    }
    else
    {
      result++;
      right--;
    }
    if (left == right)
    {
      result++;
    }
  }
  return result;
}

int main()
{
  vector<int> w = {50, 60, 60, 65, 75};
  int C = 110;
  cout << getMinBoats(w, C) << endl;
  return 0;
}