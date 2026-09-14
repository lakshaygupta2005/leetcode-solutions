# 198. House Robber

**LeetCode:** [198. House Robber](https://leetcode.com/problems/house-robber/)

**Difficulty:** Medium

**Topics:** Dynamic Programming, Array

---

## Problem

You are a professional robber planning to rob houses along a street.

Each house contains a certain amount of money. However, you cannot rob two adjacent houses because the security system will automatically alert the police.

Given an integer array `nums`, where `nums[i]` represents the amount of money in the `i`th house, return the **maximum amount of money you can rob without robbing two adjacent houses**.

### Example

```text
Input:
nums = [2, 7, 9, 3, 1]

Output:
12

Explanation:
Rob house 0, house 2, and house 4:

2 + 9 + 1 = 12
Approach
We can solve this problem using Dynamic Programming with a bottom-up (tabulation) approach.
The key observation is that for every house i, we have two choices:
1. Don't rob house i
2. Rob house i
Choice 1: Don't Rob House i
If we don't rob house i, then the maximum amount remains the best amount we could get from houses 0 through i - 1.
dp[i - 1]
Choice 2: Rob House i
If we rob house i, we cannot rob house i - 1.
Therefore, the best amount we can have before house i is the best result from houses 0 through i - 2.
nums[i] + dp[i - 2]
We take the better of these two choices:
dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])
DP State
dp[i] = maximum amount of money that can be robbed
        from houses 0 through i
This definition is important because dp[i] does not necessarily mean that house i was robbed.
It represents the best possible answer considering all houses up to i.
Base Cases
For the first house:
dp[0] = nums[0]
For the first two houses, we can only rob one of them:
dp[1] = max(nums[0], nums[1])
Recurrence
For every house starting from index 2:
dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])
Example Walkthrough
Consider:
nums = [2, 7, 9, 3, 1]
We build the DP array:
dp[0] = 2

dp[1] = max(2, 7)
      = 7

dp[2] = max(dp[1], nums[2] + dp[0])
      = max(7, 9 + 2)
      = 11

dp[3] = max(dp[2], nums[3] + dp[1])
      = max(11, 3 + 7)
      = 11

dp[4] = max(dp[3], nums[4] + dp[2])
      = max(11, 1 + 11)
      = 12
Therefore:
dp = [2, 7, 11, 11, 12]

Answer = 12
Algorithm
1. Store the number of houses in n.
2. If there is only one house, return its value.
3. Create a DP array of size n.
4. Initialize the base cases:
   - dp[0] = nums[0]
   - dp[1] = max(nums[0], nums[1])
5. For every house from index 2 to n - 1:
   - Calculate the best answer using:max(dp[i - 1], nums[i] + dp[i - 2])
6. Return dp[n - 1].
Code
class Solution {
public:
    // Dynamic Programming - Bottom Up
    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        vector<int> dp(n, -1);

        // Base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // Build solution from bottom up
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[n - 1];
    }
};
Complexity
- Time: O(n)
- Space: O(n)
We iterate through every house once, so the time complexity is O(n).
The DP array stores one value for every house, resulting in O(n) space.
Space Optimized DP
Notice that to calculate dp[i], we only need:
dp[i - 1]
dp[i - 2]
We don't need the entire DP array.
Therefore, we can keep only the previous two values.
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {

            int current = max(prev1, nums[i] + prev2);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
Optimized Complexity
- Time: O(n)
- Space: O(1)
Key Takeaway
The important DP pattern in House Robber is:
State:
dp[i] = maximum amount that can be robbed from houses 0...i

Choices:
1. Don't rob house i → dp[i - 1]
2. Rob house i     → nums[i] + dp[i - 2]

Recurrence:
dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])

Base Cases:
dp[0] = nums[0]
dp[1] = max(nums[0], nums[1])

Direction:
Bottom → Up
The major DP insight is:
At every state, identify the possible choices and determine the best result among them.

This is a pattern that appears frequently in Dynamic Programming problems.

### One thing I'd especially remember from this problem

You've now seen three closely related DP problems:

```text
Fibonacci
    ↓
dp[i] = dp[i-1] + dp[i-2]

Climbing Stairs
    ↓
dp[i] = dp[i-1] + dp[i-2]

House Robber
    ↓
dp[i] = max(dp[i-1], nums[i] + dp[i-2])