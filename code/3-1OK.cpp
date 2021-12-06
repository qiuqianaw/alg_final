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
 *  (1) 求解硬币问题。有 1 分、2 分、5 分、10 分、50 分和 100 分的硬币各若干枚，现在要用这些硬币来支付 W 元，最少需要多少枚硬币?
 */

/**
 * @key:
 *  每次选择最大面值的最多能选择的硬币数量 
 */

vector<int> coins = {1, 2, 5, 10, 50, 100};

int getMinCoins(int n)
{
  int result = 0;
  if (n <= 0)
  {
    cout << result << endl;
    return result;
  }
  for (int i = coins.size() - 1; i >= 0; i--)
  {
    int current_coins_num = n / coins[i];
    n %= coins[i];
    result += current_coins_num;
  }
  cout << result << endl;
  return result;
}

int main()
{
  int W;
  cin >> W;
  W *= 100;
  cout << getMinCoins(W) << endl;
  return 0;
}