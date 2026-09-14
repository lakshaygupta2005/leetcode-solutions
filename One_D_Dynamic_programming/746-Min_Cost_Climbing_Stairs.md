# 746. Min Cost Climbing Stairs

**LeetCode:** [746. Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)

**Difficulty:** Easy

**Topics:** Dynamic Programming, Array

---

## Problem

You are given an integer array `cost` where:

```text
cost[i] = cost of stepping on stair i
Once you pay the cost of a stair, you can climb either 1 or 2 stairs.
You can start from either stair 0 or stair 1.
The goal is to reach the top of the floor, which is located after the last stair, while minimizing the total cost.
Example
Input:
cost = [10, 15, 20]

Output:
15

Explanation:
Start at stair 1.

Pay 15 and climb two stairs directly to the top.
Approach
We solve this problem using Dynamic Programming with a bottom-up (tabulation) approach.
The key is to think about the top of the staircase as an additional position.
If:
cost.size() = n
then the top is at position:
n
There is no actual cost[n] because the top itself has no cost.
DP State
Define:
dp[i] = minimum cost required to reach position i
Here, i represents a position rather than necessarily an actual stair.
For example:
cost = [10, 15, 20]

positions:

0       1       2       3
↓       ↓       ↓       ↓
10      15      20      TOP
The goal is therefore:
dp[3]
Base Cases
We can start from either stair 0 or stair 1.
Therefore, reaching either of these positions costs nothing initially:
dp[0] = 0
dp[1] = 0
We don't pay for the starting position because the problem allows us to start from either of these stairs.
Recurrence
To reach position i, there are two possibilities.
1. Come from position i - 1
If we move one step:
i - 1 → i
we need to pay the cost of stair i - 1:
cost[i - 1] + dp[i - 1]
2. Come from position i - 2
If we move two steps:
i - 2 → i
we need to pay the cost of stair i - 2:
cost[i - 2] + dp[i - 2]
Therefore:
dp[i] = min(
    cost[i - 1] + dp[i - 1],
    cost[i - 2] + dp[i - 2]
)
Notice that the cost is associated with the stair we are leaving from, not the destination.
Example Walkthrough
Consider:
cost = [10, 15, 20]
We create:
dp = [0, 0, 0, 0]
Position 2
We can reach position 2 from either position 1 or position 0:
dp[2] = min(
    cost[1] + dp[1],
    cost[0] + dp[0]
)

     = min(
         15 + 0,
         10 + 0
       )

     = 10
Position 3 (Top)
Now we calculate:
dp[3] = min(
    cost[2] + dp[2],
    cost[1] + dp[1]
)

     = min(
         20 + 10,
         15 + 0
       )

     = 15
Therefore:
Answer = dp[3] = 15
The optimal path is:
Start at stair 1
     ↓
Pay 15
     ↓
Jump directly to the top
Algorithm
1. Let n = cost.size().
2. Create a DP array of size n + 1.
3. Initialize:
   - dp[0] = 0
   - dp[1] = 0
4. For every position from 2 through n:
   - Calculate the cost of arriving from i - 1.
   - Calculate the cost of arriving from i - 2.
   - Store the smaller value.
5. Return dp[n].
Code
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Dynamic Programming - Bottom Up

        int n = cost.size();

        vector<int> dp(n + 1);

        // Base cases
        dp[0] = 0;
        dp[1] = 0;

        // Build solution from bottom up
        for (int i = 2; i <= n; i++) {
            dp[i] = min(
                cost[i - 1] + dp[i - 1],
                cost[i - 2] + dp[i - 2]
            );
        }

        return dp[n];
    }
};
Complexity
- Time: O(n)
- Space: O(n)
We calculate each DP state exactly once, resulting in O(n) time.
The DP array contains n + 1 values, resulting in O(n) space.
Space Optimized Version
Notice that:
dp[i]
only depends on:
dp[i - 1]
dp[i - 2]
Therefore, we don't need the entire DP array.
We can store only the previous two states:
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        int prev2 = 0;  // dp[i - 2]
        int prev1 = 0;  // dp[i - 1]

        for (int i = 2; i <= n; i++) {

            int current = min(
                cost[i - 1] + prev1,
                cost[i - 2] + prev2
            );

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
Optimized Complexity
- Time: O(n)
- Space: O(1)
For learning Dynamic Programming, the O(n) tabulation solution is preferable initially because the DP states are explicit. The O(1) solution is the natural space optimization once the recurrence is understood.
Key Takeaway
This problem is a useful variation of the previous Frog Jump problem.
In both problems, the frog/staircase can move:
1 step
or
2 steps
But the meaning of the cost is slightly different.
Frog Jump
The cost is based on the height difference between the two stairs:
dp[i] = min(
    dp[i-1] + abs(height[i] - height[i-1]),
    dp[i-2] + abs(height[i] - height[i-2])
)
Min Cost Climbing Stairs
The cost is associated with the stair being left:
dp[i] = min(
    dp[i-1] + cost[i-1],
    dp[i-2] + cost[i-2]
)
The important skill is to carefully identify what dp[i] represents and what cost is incurred when transitioning between states.
DP Progression
The DP patterns learned so far:
Fibonacci
    ↓
dp[i] = dp[i-1] + dp[i-2]

Climbing Stairs
    ↓
dp[i] = dp[i-1] + dp[i-2]

House Robber
    ↓
dp[i] = max(
    dp[i-1],
    nums[i] + dp[i-2]
)

House Robber II
    ↓
Break the problem into
two House Robber problems

Frog Jump
    ↓
dp[i] = min(
    cost from i-1,
    cost from i-2
)

Min Cost Climbing Stairs
    ↓
dp[i] = min(
    cost[i-1] + dp[i-1],
    cost[i-2] + dp[i-2]
)
The recurring DP thought process is:
Define the state → identify all ways to reach the state → calculate the cost/value of each transition → choose the optimal one.


One small improvement I made to your code in the template is introducing:

```cpp
int n = cost.size();