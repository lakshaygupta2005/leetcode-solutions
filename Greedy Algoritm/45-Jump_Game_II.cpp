/*
LeetCode #45: Jump Game II
Link: https://leetcode.com/problems/jump-game-ii/
Difficulty: Medium
Tags: Array, Greedy

Approach:  
We solve this using a greedy, range-based BFS-like approach instead of recursion or dynamic programming.  
- Imagine the array as levels in a graph where each position can jump up to `nums[i]` steps forward.  
- `left` and `right` mark the current "range" (level) of indices we can reach with the current number of jumps.  
- We iterate within the current range to find the farthest index we can reach (`farthest`).  
- Once we've checked the current range, we increment the jump counter and update the range to `[right + 1, farthest]`.  
- Repeat until `right` reaches or passes the last index.  

Time Complexity: O(n) — Each index is visited at most once.  
Space Complexity: O(1) — Constant extra space.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int jumps = 0;
        int farthest;

        while (right < nums.size() - 1) {
            farthest = right;
            for (int i = left; i <= right; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            jumps++;
            left = right + 1;
            right = farthest;
        }

        return jumps;
    }
};

// ### OPTIONAL TEST - FOR LOCAL TESTING
// int main() {
//     Solution sol;
//     vector<int> test1 = {2,3,1,1,4};  // Expected output: 2
//     vector<int> test2 = {2,3,0,1,4};  // Expected output: 2
//     cout << sol.jump(test1) << endl;
//     cout << sol.jump(test2) << endl;
//     return 0;
// }