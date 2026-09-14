# 213. House Robber II

**LeetCode:** [213. House Robber II](https://leetcode.com/problems/house-robber-ii/)

**Difficulty:** Medium

**Topics:** Dynamic Programming, Array

---

## Problem

You are a professional robber planning to rob houses along a street.

Each house contains a certain amount of money. However, you cannot rob two adjacent houses because the security system will automatically alert the police.

In this version, the houses are arranged in a **circle**.

This means the first and last houses are also adjacent.

Given an integer array `nums`, return the maximum amount of money you can rob without robbing two adjacent houses.

### Example

```text
Input:
nums = [2, 3, 2]

Output:
3

Explanation:
We cannot rob both the first and last house because they are adjacent.

The best choice is to rob the second house:
3
Approach
This problem is a variation of House Robber I.
The main difference is that the houses are arranged in a circle, meaning:
nums[0]
   ↕
nums[n-1]
are also adjacent.
Therefore, we cannot rob both the first and last house.
This allows us to split the problem into two independent House Robber I problems.
Case 1: Exclude the Last House
Consider:
nums[0 ... n-2]
The first house can be robbed, but the last house is excluded.
Case 2: Exclude the First House
Consider:
nums[1 ... n-1]
The last house can be robbed, but the first house is excluded.
Then take the maximum of the two cases:
answer = max(
    rob(nums[0 ... n-2]),
    rob(nums[1 ... n-1])
)
Why Does This Work?
Since the first and last houses are adjacent, every valid solution must fall into one of two categories:
1. First house is considered
   Last house is excluded

or

2. First house is excluded
   Last house is considered
We solve both possibilities independently using the House Robber I DP recurrence.
The better of the two is the optimal solution.
DP State
For each linear range, we use the same state definition as House Robber I:
dp[i] = maximum amount of money that can be robbed
        from the houses considered up to index i
At each house, we have two choices:
Choice 1: Don't Rob House i
The best answer remains the answer from the previous house:
dp[i - 1]
Choice 2: Rob House i
If we rob house i, we cannot rob house i - 1.
Therefore:
nums[i] + dp[i - 2]
Recurrence
dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])
Helper Function
We use a helper function to apply the House Robber I logic to a specific range.
The helper uses the standard C++ range convention:
[start, end)
This means:
start → included
end   → excluded
Therefore, the number of houses in the range is:
end - start
For example:
helper(0, n - 1)
considers:
nums[0 ... n-2]
while:
helper(1, n)
considers:
nums[1 ... n-1]
Because the DP array starts at index 0 while the original array may start at start, we convert the original index i to the corresponding DP index using:
i - start
Base Cases
If the range contains only one house:
end - start == 1
then the answer is simply:
nums[start]
For two houses:
dp[0] = nums[start]

dp[1] = max(nums[start], nums[start + 1])
Example Walkthrough
Consider:
nums = [2, 3, 2]
Case 1: Exclude Last House
Consider:
[2, 3]
House Robber I:
dp[0] = 2

dp[1] = max(2, 3)
      = 3
Result:
3
Case 2: Exclude First House
Consider:
[3, 2]
House Robber I:
dp[0] = 3

dp[1] = max(3, 2)
      = 3
Result:
3
Therefore:
answer = max(3, 3)
       = 3
Algorithm
1. If there is only one house, return nums[0].
2. Call the helper for the range nums[0 ... n-2].
3. Call the helper for the range nums[1 ... n-1].
4. Return the maximum of the two results.
Code
class Solution {
public:
    int helper(int start, int end, vector<int>& nums)
    {
        // If there is only one house
        if (end - start == 1)
        {
            return nums[start];
        }

        // end is exclusive
        vector<int> dp(end - start);

        // Base cases
        dp[0] = nums[start];
        dp[1] = max(nums[start + 1], dp[0]);

        // Build solution from bottom up
        for (int i = start + 2; i < end; i++)
        {
            dp[i - start] = max(
                dp[i - start - 1],
                nums[i] + dp[i - start - 2]
            );
        }

        return dp[end - start - 1];
    }

    int rob(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        int n = nums.size();

        // Case 1: Exclude the last house
        // Case 2: Exclude the first house
        return max(
            helper(0, n - 1, nums),
            helper(1, n, nums)
        );
    }
};
Complexity
Each helper processes at most n houses.
We call the helper twice:
O(n) + O(n) = O(n)
Therefore:
- Time: O(n)
- Space: O(n)
The DP array requires O(n) space.
Space Optimized Version
The DP recurrence only depends on the previous two states:
dp[i - 1]
dp[i - 2]
Therefore, we can eliminate the DP array and keep only the previous two values.
class Solution {
public:
    int helper(int start, int end, vector<int>& nums)
    {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = start; i < end; i++)
        {
            int current = max(
                prev1,
                nums[i] + prev2
            );

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }

    int rob(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        int n = nums.size();

        return max(
            helper(0, n - 1, nums),
            helper(1, n, nums)
        );
    }
};
Optimized Complexity
- Time: O(n)
- Space: O(1)
Key Takeaway
House Robber II demonstrates an important DP technique:
A more complicated problem can sometimes be broken into multiple instances of a simpler DP problem that we already know how to solve.

The transformation is:
                House Robber II
                       │
             ┌─────────┴─────────┐
             ↓                   ↓
      Exclude last          Exclude first
        house                 house
             ↓                   ↓
      nums[0 ... n-2]      nums[1 ... n-1]
             ↓                   ↓
       House Robber I       House Robber I
             │                   │
             └─────────┬─────────┘
                       ↓
                     max()
The underlying recurrence remains:
dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])
The new insight is how to transform the circular constraint into two linear problems.
DP Progression
The DP problems learned so far build on each other:
Fibonacci
    ↓
dp[i] = dp[i-1] + dp[i-2]

Climbing Stairs
    ↓
dp[i] = dp[i-1] + dp[i-2]

House Robber
    ↓
dp[i] = max(dp[i-1], nums[i] + dp[i-2])

House Robber II
    ↓
Break circular problem into
two House Robber problems
    ↓
max(
    rob(0 ... n-2),
    rob(1 ... n-1)
)
The important lesson is:
Dynamic Programming is not always about finding a new recurrence. Sometimes the key is recognizing and transforming the problem into simpler DP subproblems.