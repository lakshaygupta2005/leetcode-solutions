/*
LeetCode #981: Time Based Key-Value Store
Link: https://leetcode.com/problems/time-based-key-value-store/
Difficulty: Medium
Tags: Hash Table, Binary Search, Design

Approach:
- Maintain a mapping from `key` → list of (value, timestamp) pairs.
- Each `set` operation appends (value, timestamp) for that key (timestamps are strictly increasing per key).
- To `get`, perform binary search on the vector of pairs for that key:
  - Find the rightmost value with timestamp <= given timestamp.
  - If exact timestamp match is found, return immediately.
  - Otherwise, return the last value encountered that was less than the given timestamp.

Time Complexity:
- set(): O(1) (append to vector)
- get(): O(log n) per query (binary search on timestamps)

Space Complexity:
- O(n) for storing all values.
*/

#include <bits/stdc++.h>
using namespace std;

class TimeMap {
private:
    // Store: key -> vector of (value, timestamp) pairs
    unordered_map<string, vector<pair<string, int>>> key_store;

public:
    TimeMap() {}

    // Store the key with value and timestamp
    void set(string key, string value, int timestamp) {
        key_store[key].push_back({value, timestamp});
    }

    // Get the value at or before the given timestamp
    string get(string key, int timestamp) {
        string res = "";
        auto& vec = key_store[key];  // reference to the vector of (value, timestamp)

        int low = 0, high = vec.size() - 1;

        // Binary search to find rightmost timestamp <= given timestamp
        while (low <= high) {
            int mid = low + ((high - low) / 2);

            if (vec[mid].second == timestamp) {
                // Exact timestamp found
                return vec[mid].first;
            }

            if (vec[mid].second < timestamp) {
                // Candidate answer found, but continue searching right
                res = vec[mid].first;
                low = mid + 1;
            } else {
                // Current timestamp too big, search left
                high = mid - 1;
            }
        }

        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

// ### OPTIONAL TEST - FOR LOCAL TESTING
// int main() {
//     TimeMap* obj = new TimeMap();
//     obj->set("love", "high", 10);
//     obj->set("love", "low", 20);
//     cout << obj->get("love", 5) << endl;   // Output: ""
//     cout << obj->get("love", 10) << endl;  // Output: "high"
//     cout << obj->get("love", 15) << endl;  // Output: "high"
//     cout << obj->get("love", 20) << endl;  // Output: "low"
//     cout << obj->get("love", 25) << endl;  // Output: "low"
//     return 0;
// }