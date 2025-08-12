/*
LeetCode #1347: Minimum Number of Steps to Make Two Strings Anagram
Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
Difficulty: Medium
Tags: Hash Table, String, Counting

Approach:  
We use two frequency arrays to count the occurrences of each letter in both strings `s` and `t`.  
1. Count the frequency of each letter in `s` and `t` separately.  
2. For each letter, compute the absolute difference in counts between `s` and `t`.  
3. The sum of all differences gives the total number of misplaced characters.  
4. Since each replacement fixes two mismatches (removing one letter from one string and adding it to the other), the answer is `total_difference / 2`.  

Note: BETTER VERSION WITH FURTHER POSSIBLE SPACE OPTIMIZATION
This is the clear two-array approach.  
We can optimize to one array by counting up for `s` and down for `t`, then summing positives only — 
that approach has same complexity but uses slightly less space(one single hashmap instead of two seperate hashmaps for s and t).  
However, here i have used this version because it prioritizes clarity over minimal space.

Time Complexity: O(n + 26) ≈ O(n) — where `n` is the length of the strings.  
Space Complexity: O(26) ≈ O(1) — frequency arrays have constant size.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        //create frequency hashmaps
        vector<int> hashmap_s(26, 0);
        vector<int> hashmap_t(26, 0);

        for (int i = 0; i < s.size(); i++) {
            hashmap_s[s[i] - 'a']++;
            hashmap_t[t[i] - 'a']++;
        }
      
        //compare hashmaps
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (hashmap_s[i] != hashmap_t[i]) {
                count += abs(hashmap_s[i] - hashmap_t[i]);
            }
        }

        return count / 2;
    }
};

// ### OPTIONAL TEST - FOR LOCAL TESTING
// int main() {
//     Solution sol;
//     string s = "bab";
//     string t = "aba";
//     cout << sol.minSteps(s, t) << endl; // Expected output: 1
//     return 0;
// }
