# Frog Jump - Minimum Cost

**Platform:** GeeksforGeeks

**Difficulty:** Easy

**Topics:** Dynamic Programming, Arrays

---

## Problem

A frog is standing at the first stair and wants to reach the last stair.

The frog can jump either:

- **1 stair**, or
- **2 stairs**

The cost of a jump is the absolute difference between the heights of the two stairs.

Given an array `height`, return the minimum cost required for the frog to reach the last stair.

### Example

```text
Input:
height = [10, 20, 30, 10]

Output:
20
Explanation:
The frog can take:
0 → 1 → 2 → 3

Cost = |20 - 10| + |30 - 20| + |10 - 30|
     = 10 + 10 + 20
     = 40
But a better path is:
0 → 2 → 3

Cost = |30 - 10| + |10 - 30|
     = 20 + 20
     = 40
The exact minimum depends on the input; the DP considers all valid paths and chooses the minimum.
Approach
We solve this problem using Dynamic Programming with a bottom-up (tabulation) approach.
The key observation is that to reach stair i, the frog can only come from:
1. Stair i - 1 using a 1-stair jump.
2. Stair i - 2 using a 2-stair jump.
Therefore, we calculate the cost of both possibilities and take the minimum.
DP State
Define:
dp[i] = minimum cost required to reach stair i
This means that by the time we calculate dp[i], we already know the cheapest way to reach every previous stair.
Base Cases
Stair 0
The frog starts at stair 0, so there is no cost:
dp[0] = 0
Stair 1
There is only one possible jump:
0 → 1
Therefore:
dp[1] = abs(height[1] - height[0])
Recurrence
To reach stair i, there are two possibilities.
1. One-Stair Jump
The frog comes from stair i - 1:
cost = dp[i - 1] + abs(height[i] - height[i - 1])
2. Two-Stair Jump
The frog comes from stair i - 2:
cost = dp[i - 2] + abs(height[i] - height[i - 2])
Take the cheaper option:
dp[i] = min(
    dp[i - 1] + abs(height[i] - height[i - 1]),
    dp[i - 2] + abs(height[i] - height[i - 2])
)
Example Walkthrough
Consider:
height = [10, 20, 30, 10]
We start with:
dp[0] = 0

dp[1] = |20 - 10|
      = 10
For stair 2:
One jump:
dp[1] + |30 - 20|
= 10 + 10
= 20

Two jumps:
dp[0] + |30 - 10|
= 0 + 20
= 20

dp[2] = min(20, 20)
      = 20
For stair 3:
One jump:
dp[2] + |10 - 30|
= 20 + 20
= 40

Two jumps:
dp[1] + |10 - 20|
= 10 + 10
= 20

dp[3] = min(40, 20)
      = 20
Therefore:
dp = [0, 10, 20, 20]

Answer = 20
The optimal path is:
0 → 1 → 3
with cost:
|20 - 10| + |10 - 20|
= 10 + 10
= 20
Algorithm
1. Store the number of stairs in n.
2. If n <= 1, return 0.
3. If there are exactly two stairs, return the cost of jumping directly between them.
4. Create a DP array of size n.
5. Initialize:
   - dp[0] = 0
   - dp[1] = abs(height[1] - height[0])
6. For every stair from 2 to n - 1:
   - Calculate the cost of a 1-stair jump.
   - Calculate the cost of a 2-stair jump.
   - Store the minimum of the two in dp[i].
7. Return dp[n - 1].
Code
class Solution {
public:
    int minCost(vector<int>& height) {
        // Dynamic Programming - Bottom Up

        int n = height.size();

        // Base cases
        if (n <= 1) {
            return 0;
        }

        if (n == 2) {
            return abs(height[1] - height[0]);
        }

        vector<int> dp(n);

        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);

        // Build solution from bottom up
        for (int i = 2; i < n; i++) {

            int cost_of_one_jump =
                dp[i - 1] + abs(height[i] - height[i - 1]);

            int cost_of_two_jumps =
                dp[i - 2] + abs(height[i] - height[i - 2]);

            dp[i] = min(cost_of_one_jump, cost_of_two_jumps);
        }

        return dp[n - 1];
    }
};
Complexity
- Time: O(n)
- Space: O(n)
We visit each stair exactly once, so the time complexity is O(n).
The DP array stores the minimum cost for every stair, giving O(n) space.
Space Optimized Version
Notice that dp[i] only depends on:
dp[i - 1]
dp[i - 2]
Therefore, we don't actually need to store the entire DP array.
We can keep only the previous two DP values.
class Solution {
public:
    int minCost(vector<int>& height) {

        int n = height.size();

        if (n <= 1) {
            return 0;
        }

        int prev2 = 0;
        int prev1 = abs(height[1] - height[0]);

        for (int i = 2; i < n; i++) {

            int cost_of_one_jump =
                prev1 + abs(height[i] - height[i - 1]);

            int cost_of_two_jumps =
                prev2 + abs(height[i] - height[i - 2]);

            int current = min(cost_of_one_jump, cost_of_two_jumps);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
Optimized Complexity
- Time: O(n)
- Space: O(1)
For learning DP, however, the O(n) tabulation solution should be your primary version. The space optimization is something to recognize after you've understood the state and recurrence.
Key Takeaway
The important DP pattern in this problem is:
dp[i] = minimum cost to reach stair i
Then ask:
What are all the ways I can reach stair i?

Here there are only two:
                 stair i
                /       \
               /         \
          from i-1     from i-2
             ↓             ↓
         1-step jump   2-step jump
             ↓             ↓
           cost          cost
              \           /
               \         /
                  min()
                    ↓
                  dp[i]
The recurrence is:
dp[i] = min(
    dp[i-1] + abs(height[i] - height[i-1]),
    dp[i-2] + abs(height[i] - height[i-2])
)
DP Progression
This problem builds naturally on the DP problems learned previously:
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

Frog Jump
    ↓
dp[i] = min(
    cost from i-1,
    cost from i-2
)
The common pattern is:
Define what dp[i] represents, identify all possible ways to reach state i, calculate the result for each choice, and select the optimal one.

For Frog Jump, the optimal operation is min() because we are minimizing cost.

One correction to the README's example is worth noting: for `[10, 20, 30, 10]`, the minimum is indeed **20**, via `0 → 1 → 3`. That walkthrough is consistent with the recurrence.