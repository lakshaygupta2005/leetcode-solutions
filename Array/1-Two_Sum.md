# 1. Two Sum

**Difficulty:** Easy  
**Topics:** Array, Hash Table

---

## Problem

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to `target`.

- Each input has exactly one solution.
- You may not use the same element twice.
- Return the answer in any order.

---

## Intuition

For every element, determine the number required to reach the target (`target - nums[i]`).

Instead of searching the remaining array every time, store previously visited numbers in a hash map.

At each iteration:

- Compute the complement.
- If the complement already exists in the hash map, we've found the answer.
- Otherwise, store the current number and its index for future lookups.

---

## Approach

1. Create an `unordered_map<int, int>` to store:
   - **Key:** Number
   - **Value:** Index of the number
2. Traverse the array once.
3. For each element:
   - Compute the complement.
   - Check if the complement exists in the hash map.
   - If found, return the stored index and the current index.
   - Otherwise, insert the current element into the hash map.
4. Since the problem guarantees exactly one solution, the answer will always be found.

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //create a hashmap
        //the first location in the hashmap is the number and the second location is the index of that number in the nums vector
        unordered_map<int, int> hashmap;

        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if(hashmap.find(complement) != hashmap.end()) 
            {
                return {hashmap[complement], i};
            }
            else
            {
                hashmap.insert({nums[i], i});
            }
        }

        return {};
    }
};
```

---

## Complexity Analysis

**Time Complexity:** `O(n)`

- Each element is processed exactly once.
- Hash map insertion and lookup take **O(1)** on average.

**Space Complexity:** `O(n)`

- In the worst case, the hash map stores every element.

---

## Key Takeaways

- `unordered_map` provides average **O(1)** lookup and insertion.
- Store previously seen numbers instead of searching the remaining array.
- Computing the complement (`target - nums[i]`) is the key insight.
- This is the standard optimal solution for the Two Sum problem.

---

## Pattern Learned

**Hash Map for Constant-Time Lookup**

Whenever a problem asks whether a value needed to complete a condition has already been seen, consider storing previously visited elements in a hash map to reduce repeated searching.

This pattern appears in many problems involving:
- Pair Sum
- Difference of Two Numbers
- Frequency Counting
- Duplicate Detection
- Prefix Sum + Hash Map problems