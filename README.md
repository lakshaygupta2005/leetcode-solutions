# 🚀 LeetCode Solutions by Lakshay Gupta

Welcome to my curated collection of LeetCode solutions. This repository is designed not just to showcase problem-solving skills, but also to maintain clean, readable, and well-documented code using modern C++ and for my personal DSA revision.

## 📁 Folder Structure

The repository is organized by topic to make navigation easier:
```
leetcode-solutions/
│
├── Arrays/
├── BinarySearch/
├── LinkedList/
├── DynamicProgramming/
├── Graphs/
├── Trees/
└── TwoPointers/
```
Each folder contains `.cpp` files named using the format:
[problem-number]-[kebab-case-title].cpp

### Example:  
`0875-koko-eating-bananas.cpp`

---

## 📌 Code Format & File Header Style

Every solution file includes a detailed header comment block like the example below:

```cpp
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
```

## Guidelines for New Solutions:
	•	Include the problem number, title, and link.
	•	Mention difficulty and relevant tags.
	•	Clearly describe your approach in plain English.
	•	State time and space complexities.

⸻

## 🧪 Local Testing

For local testing, you may optionally include a main() function within each .cpp file.
However, all solutions are designed to be submitted directly to LeetCode without modification.

### Example main stub:
```
int main() {
    Solution sol;
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << sol.findMin(nums) << endl;
    return 0;
}
```


## 🛠️ Technologies Used
	•	Language: C++17 (or later)
	•	Compiler: g++ for local testing


## 🧠 Why This Repo Exists
This repository helps me:
	•	Master data structures and algorithms
	•	Practice clean code and documentation
	•	Track personal DSA progress
	•	Showcase my problem-solving style

## 🏷️ Topics Covered
	•	Arrays
	•	Binary Search
	•	Dynamic Programming
	•	Linked Lists
	•	Trees
	•	Graphs
	•	Two Pointers
	•	and more…

## 👨‍💻 Author

**Lakshay Gupta**  
🔗 [GitHub: lakshaygupta2005](https://github.com/lakshaygupta2005)  
🔗 [LeetCode: guptalakshay2005](https://leetcode.com/guptalakshay2005)
