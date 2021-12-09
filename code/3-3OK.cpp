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
 *  (3) 求解会议安排问题。有一组会议 A 和一组会议室 B，A[i]表示第 i 个会议的参加人数，B[j]表示第 j 个会议室最多可以容纳的人数。
 *      当且仅 当 A[i]≤B[j]时，第 j 个会议室可以用于举办第 i 个会议。
 *      给定数组 A 和数 组 B，最多可以同时举办多少个会议。
 *      例如，A[ ]={1,2,3}，B[ ]={3,2,4}， 结果为 3;
 *      若 A[ ]={3,4,3,1}，B[ ]={1,2,2,6}，结果为 2。
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

int arrange(vector<int> A, vector<int> B)
{
  // sort(A.begin(), A.end());
  // sort(B.begin(), B.end());

  A = sortArray(A);
  B = sortArray(B);

  int sum = 0;
  int j = B.size() - 1;

  // 双指针技巧
  for (int i = A.size() - 1; i >= 0; i--)
  {
    if (A[i] <= B[j] && j >= 0)
    {
      sum++;
      j--;
    }
  }
  return sum;
}

int main()
{
  vector<int> A = {1, 2, 3};
  vector<int> B = {3, 2, 4};
  cout << arrange(A, B) << endl;
  return 0;
}