/*
LeetCode #242: Valid Anagram
Link: https://leetcode.com/problems/valid-anagram/
Difficulty: Easy
Tags: Hash Table, String

Approach:
We use a frequency map to count the occurrences of each character.

- First, check whether both strings have the same length. If they don't,
  they cannot be anagrams.
- Count the frequency of every character in `s`.
- For every character in `t`, decrease its frequency.
- If the frequency of any character becomes negative, `t` contains that
  character more times than `s`, so the strings are not anagrams.
- If we finish processing `t` without any frequency becoming negative,
  the two strings are anagrams.

We use `unordered_map` instead of `map` because we only need key-value
lookup and do not require the keys to be sorted.


Time Complexity: O(n) average — Each character is processed once, and
unordered_map operations take O(1) average time.

Space Complexity: O(k) — where k is the number of distinct characters in
the strings.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Anagrams must have the same number of characters
        if(s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> frequency_map;

        // Count characters in s
        for(char c : s)
        {
            frequency_map[c]++;
        }

        // Subtract characters of t
        for(char c : t)
        {
            frequency_map[c]--;

            // t contains this character more times than s
            if(frequency_map[c] < 0)
            {
                return false;
            }
        }

        return true;
    }
};

// ### OPTIONAL TEST - FOR LOCAL TESTING
// int main() {
//     Solution sol;
//
//     cout << sol.isAnagram("anagram", "nagaram") << endl; // Expected: 1
//     cout << sol.isAnagram("rat", "car") << endl;         // Expected: 0
//
//     return 0;
// }