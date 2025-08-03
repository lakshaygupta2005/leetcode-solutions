/*
LeetCode #153: Find Minimum in Rotated Sorted Array
Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Difficulty: Medium
Tags: Array, Binary Search

Approach: Use binary search to find the minimum element in a rotated sorted array.
At least one half (left or right) is always sorted.
If the range is already sorted, return the first element.
Otherwise, narrow the search to the unsorted part.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // implement binary search

        int min_element = INT_MAX;

        int low = 0; 
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) / 2);

            // left_half = from low to mid
            // right_half = from mid to high

            if (nums[low] <= nums[high]) // entire array from low to high is sorted.
            {
                min_element = min(nums[low], min_element);
                return min_element;
            } 
            else if (nums[low] <= nums[mid]) // check if left half is sorted
            {
                min_element = min(min_element, nums[low]);
                low = mid + 1;
            } 
            else // right half is sorted
            {
                min_element = min(min_element, nums[mid]);
                high = mid - 1;
            }
        }
        return min_element;
    }
};

// ### OPTIONAL TEST - FOR LOCAL TESTING
// int main() {
//     Solution sol;

//     vector<int> test1 = {3, 4, 5, 1, 2};
//     vector<int> test2 = {4, 5, 6, 7, 0, 1, 2};
//     vector<int> test3 = {11, 13, 15, 17};

//     cout << "Test 1: " << sol.findMin(test1) << endl; // Output: 1
//     cout << "Test 2: " << sol.findMin(test2) << endl; // Output: 0
//     cout << "Test 3: " << sol.findMin(test3) << endl; // Output: 11

//     return 0;
// }
