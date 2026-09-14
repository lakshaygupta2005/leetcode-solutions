
# Project Title

A brief description of what this project does and who it's for

# 70. Climbing Stairs

**LeetCode:** [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)

**Difficulty:** Easy

**Topics:** Dynamic Programming, Math

---

## Problem

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb **1 step** or **2 steps**.

Given `n`, return the number of distinct ways you can climb to the top.

### Example

```text
Input: n = 5
Output: 8

Explanation:
There are 8 distinct ways to reach the top.
Approach
We can solve this using Dynamic Programming (DP) with a bottom-up (tabulation) approach.
The key observation is that to reach step i, we can:
1. Come from step i - 1 by taking 1 step.
2. Come from step i - 2 by taking 2 steps.
Therefore:
dp[i] = dp[i - 1] + dp[i - 2]
where:
dp[i] = number of distinct ways to reach step i
Base Cases
dp[1] = 1
dp[2] = 2
- There is 1 way to reach step 1: 1
- There are 2 ways to reach step 2: 1 + 1 and 2
We then build the solution from the bottom up, starting from step 3.
Algorithm
1. If n <= 2, return n.
2. Create a DP array of size n + 1.
3. Initialize:
   - dp[1] = 1
   - dp[2] = 2
4. For every step from 3 to n:
   - dp[i] = dp[i - 1] + dp[i - 2]
5. Return dp[n].
```
Code
```cpp
class Solution {
public:
    // Dynamic Programming - Bottom Up
    int climbStairs(int n) {

        if (n <= 2) {
            return n;
        }

        vector<int> dp(n + 1, -1);

        // Base cases
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
```
Complexity
- Time: O(n)
- Space: O(n)
We calculate each DP state exactly once, and store the result for every step.
Key Takeaway
The important DP pattern in this problem is:
State:
dp[i] = number of ways to reach step i

Recurrence:
dp[i] = dp[i - 1] + dp[i - 2]

Base Cases:
dp[1] = 1
dp[2] = 2

Direction:
Bottom → Up
The main insight is to identify how the current state can be formed from previously solved states.
Alternative: Space Optimized DP
Since dp[i] only depends on the previous two states, we do not actually need to store the entire DP array.
We can keep only the last two values:
class Solution {
public:
    int climbStairs(int n) {

        if (n <= 2) {
            return n;
        }

        int prev2 = 1;
        int prev1 = 2;

        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
```
Optimized Complexity
- Time: O(n)
- Space: O(1)
For learning Dynamic Programming, the O(n) DP-array solution is preferable first, because it makes the DP states and recurrence explicit. The space-optimized version is an optimization after understanding the underlying DP.
```