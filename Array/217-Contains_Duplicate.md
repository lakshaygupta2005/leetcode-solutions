/*
LeetCode #217: Contains Duplicate
Link: https://leetcode.com/problems/contains-duplicate/description/
Difficulty: Easy
Tags: Array

Approach:
We use a set data structure. set only stores unique elements(no duplicates)
-when we loop over the nums, we check whether set already has that value
    -if it already has that value, then it's a duplicate, return true
    -else add the value to the set
-if the entire loop completes, then that means no duplicates were present
*/

##code (C++)

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> unique_elements;

        for(int i = 0; i < nums.size(); i++)
        {
            if(unique_elements.count(nums[i]))
            {
                return true;
            }
            unique_elements.insert(nums[i]);
        }
        return false;
    }
};
```