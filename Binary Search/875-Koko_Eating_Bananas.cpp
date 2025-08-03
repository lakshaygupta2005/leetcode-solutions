/*
LeetCode #875: Koko Eating Bananas
Link: https://leetcode.com/problems/koko-eating-bananas/
Difficulty: Medium
Tags: Array, Binary Search

Approach: Binary Search on the range of possible eating speeds [1, max(piles)].
For each candidate speed, compute the total hours Koko takes using ceiling division.
Narrow the search to find the minimum speed at which Koko can eat all bananas within h hours.

Time Complexity: O(n * log m), where n = number of piles, m = max pile size
Space Complexity: O(1)
*/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // Step 1: Find the max element
        int max_element = 0;
        for (int pile : piles) {
            max_element = max(pile, max_element);
        }

        // now we know that the correct answer lies in the range of 1 to max.
        // we can implement a binary search on range of 1 to max,for the correct
        // answer and keep on checking if that number works

        // Step 2: Binary search for minimum possible eating speed
        int low = 1;
        int high = max_element;
        int k = max_element; // worst-case, koko eats the largest pile in 1
                             // hour, the entire vector of pile in n hours.

        while (low <= high) {
            int mid = low + ((high - low) / 2);

            // Step 3: Compute total hours required at speed 'mid'
            long long hours_taken = 0;
            for (int pile : piles) {
                hours_taken += (pile + mid - 1) / mid; // this is just ceiling division
            }

            if (hours_taken <= h) {
                // we got a possible candidate k, but aren't sure, if it is the
                // minimum, so store the mid as k, but still keep on checking
                // for minimum until low <= max
                k = mid;
                high = mid - 1;
            } else if (hours_taken > h) {
                low = mid + 1;          //too slow, try faster speed.
            }
        }

        return k;
    }
};

// ### OPTIONAL TEST - FOR LOCAL TESTING
// int main() {
//     Solution sol;
//     vector<int> piles = {3, 6, 7, 11};
//     int h = 8;
//     cout << sol.minEatingSpeed(piles, h) << endl; // Output: 4
// }
