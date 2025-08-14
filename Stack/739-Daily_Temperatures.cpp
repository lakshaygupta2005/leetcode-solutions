/*
LeetCode #739: Daily Temperatures
Link: https://leetcode.com/problems/daily-temperatures/
Difficulty: Medium
Tags: Array, Stack, Monotonic Stack

Approach:  
We iterate over the temperatures array in reverse order, maintaining a monotonic decreasing stack that stores indices of days.  
For each day, we pop from the stack until we find a warmer temperature.  
If such a day exists, the difference in indices gives the number of days to wait.  
Otherwise, the result is 0 (already initialized).  

Time Complexity: O(n) — Each index is pushed and popped at most once.  
Space Complexity: O(n) — Stack stores at most n indices.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st; // stores indices of days
        int n = temperatures.size();
        vector<int> result(n, 0);

        // iterate in reverse order
        for (int i = n - 1; i >= 0; i--) {
            // Pop all days with temperature <= current day's temperature
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If stack is not empty, we found a warmer day
            if (!st.empty()) {
                result[i] = st.top() - i;
            }

            // Push current day's index
            st.push(i);
        }

        return result;
    }
};

// ### OPTIONAL TEST - FOR LOCAL TESTING
// int main() {
//     Solution sol;
//     vector<int> test = {89,62,70,58,47,47,46,76,100,70};
//     vector<int> output = sol.dailyTemperatures(test);
//     for (int days : output) cout << days << " "; 
//     // Expected: 8 1 5 4 3 2 1 1 0 0
//     return 0;
// }