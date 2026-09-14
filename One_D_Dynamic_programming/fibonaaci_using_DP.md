I've kept the structure consistent with the Climbing Stairs writeup we just made, while emphasizing the important distinction between memoization and tabulation.
# Fibonacci Number - Dynamic Programming

**Difficulty:** Easy

**Topics:** Dynamic Programming, Recursion, Memoization, Tabulation

---

## Problem

Given an integer `n`, return the `n`th Fibonacci number.

The Fibonacci sequence is defined as:

```text
F(0) = 0
F(1) = 1

F(n) = F(n - 1) + F(n - 2)
For example:
Input: n = 6

Fibonacci sequence:
0, 1, 1, 2, 3, 5, 8

Output: 8
Why Dynamic Programming?
The recursive Fibonacci solution repeatedly calculates the same subproblems.
For example:
fib(5)
├── fib(4)
│   ├── fib(3)
│   └── fib(2)
└── fib(3)
    ├── fib(2)
    └── fib(1)
Notice that fib(3) and fib(2) are calculated multiple times.
Dynamic Programming avoids this repeated work by storing results of already solved subproblems.
There are two common approaches:
1. Top Down - Memoization
2. Bottom Up - Tabulation
Approach 1: Top Down - Memoization
Top-down DP starts with the original problem and recursively breaks it into smaller subproblems.
Whenever we calculate a Fibonacci number, we store the result in an array.
If we encounter the same subproblem again, we return the stored result instead of calculating it again.
Algorithm
1. If n <= 1, return n.
2. Check whether fib[n] has already been calculated.
3. If it has, return the stored value.
4. Otherwise:fib[n] = fib[n - 1] + fib[n - 2]
5. Store and return the result.
Code
int fib_top_down(int n, vector<int>& f) {

    // Base case
    if (n <= 1) {
        return n;
    }

    // Return already computed result
    if (f[n] != -1) {
        return f[n];
    }

    // Compute and store result
    f[n] = fib_top_down(n - 1, f) + fib_top_down(n - 2, f);

    return f[n];
}
Complexity
- Time: O(n)
- Space: O(n)
The memoization array stores n results, and the recursion stack can also grow to O(n).
Approach 2: Bottom Up - Tabulation
Bottom-up DP solves the smallest subproblems first and uses them to build the final answer.
Instead of using recursion, we iteratively fill the DP array.
DP State
dp[i] = ith Fibonacci number
Base Cases
dp[0] = 0
dp[1] = 1
Recurrence
dp[i] = dp[i - 1] + dp[i - 2]
We calculate the values from:
0 → 1 → 2 → 3 → ... → n
Code
int fib_bottom_up(int n, vector<int>& f) {

    // Base case
    if (n <= 1) {
        return n;
    }

    f[0] = 0;
    f[1] = 1;

    // Build solution from bottom up
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}
Complexity
- Time: O(n)
- Space: O(n)
Complete Program
#include <iostream>
#include <vector>

using namespace std;

int fib_top_down(int n, vector<int>& f) {

    // Base case
    if (n <= 1) {
        return n;
    }

    // Return already computed result
    if (f[n] != -1) {
        return f[n];
    }

    // Compute and store result
    f[n] = fib_top_down(n - 1, f) + fib_top_down(n - 2, f);

    return f[n];
}

int fib_bottom_up(int n, vector<int>& f) {

    // Base case
    if (n <= 1) {
        return n;
    }

    f[0] = 0;
    f[1] = 1;

    // Build solution from bottom up
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

int main() {

    int n = 6;

    vector<int> fibDP(n + 1, -1);
    vector<int> fibDP_tab(n + 1, -1);

    cout << "Answer with top down: "
         << fib_top_down(n, fibDP) << endl;

    cout << "Answer with bottom up: "
         << fib_bottom_up(n, fibDP_tab) << endl;
}
Top Down vs Bottom Up
Feature	Top Down	Bottom Up
Technique	Recursion + Memoization	Tabulation
Direction	Large → Small	Small → Large
Uses recursion	Yes	No
Uses DP array	Yes	Yes
Time	O(n)	O(n)
Space	O(n)	O(n)
Easy to derive from recurrence	Yes	Yes


Key Takeaway
The most important DP concept from Fibonacci is:
                    Dynamic Programming
                           │
              ┌────────────┴────────────┐
              │                         │
         Top Down                   Bottom Up
       Memoization                 Tabulation
              │                         │
       Recursive calls            Iterative loop
              │                         │
      Store computed values       Build DP array
Both approaches solve the same recurrence:
dp[n] = dp[n - 1] + dp[n - 2]
The difference is when and how we compute the states.
General DP Pattern
When solving a DP problem, think:
1. Identify the state
2. Identify the recurrence
3. Identify the base cases
4. Choose Top Down or Bottom Up
5. Look for possible space optimization
Space Optimized Version
Since Fibonacci only depends on the previous two values, we don't actually need the entire DP array.
We can keep only two variables:
int fib(int n) {

    if (n <= 1) {
        return n;
    }

    int prev2 = 0;  // F(0)
    int prev1 = 1;  // F(1)

    for (int i = 2; i <= n; i++) {

        int current = prev1 + prev2;

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}
Optimized Complexity
- Time: O(n)
- Space: O(1)
For learning Dynamic Programming, however, the memoization and tabulation versions are more important because they demonstrate the core DP concepts. The O(1) version is an optimization that can be applied after understanding the recurrence.

One terminology point worth locking in now: **memoization = top-down**, while **tabulation = bottom-up**. You'll see these two terms constantly in DP interview questions, so getting that association automatic now is useful.