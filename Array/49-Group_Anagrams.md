# 49. Group Anagrams

**Difficulty:** Medium  
**Topics:** Array, Hash Table, String, Sorting

---

# Problem

Given an array of strings `strs`, group the anagrams together.

Two strings are anagrams if they contain the same characters with the same frequencies, regardless of their order.

Return the groups in any order.

---

# Key Observation

Anagrams are different strings that share the same set of characters with identical frequencies.

Therefore, if every string can be transformed into a common (canonical) representation, all anagrams will map to the same key.

There are two common ways to create this canonical representation:

1. Sort the string.
2. Count the frequency of every character.

---

# Solution 1: Sorting (Standard Interview Solution)

## Intuition

If two strings are anagrams, sorting both of them produces exactly the same string.

Example:

```
eat → aet
tea → aet
ate → aet
```

The sorted string can therefore be used as the hash map key.

---

## Approach

1. Create an unordered map.
   - **Key:** Sorted version of the string.
   - **Value:** Vector containing all strings with the same sorted form.
2. Traverse every string.
3. Make a copy and sort it.
4. Insert the original string into the corresponding vector.
5. Return all groups stored in the hash map.

---

## Code (C++)

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> groups;

        //create a hashmap with the key being the sorted_string
        //and the value being a vector that contains strings of the same anagram
        for(auto it: strs)
        {
            string sorted_string = it;
            sort(sorted_string.begin(), sorted_string.end());

            groups[sorted_string].push_back(it);
        }

        vector<vector<string>> result;

        for(auto it: groups)
        {
            result.push_back(it.second);
        }

        return result;
    }
};
```

---

## Complexity

**Time:** `O(n × k log k)`

- `n` = number of strings
- `k` = average string length

Sorting each string dominates the runtime.

**Space:** `O(n × k)`

---

## Pros

- Very intuitive.
- Easy to explain.
- Easy to implement.
- Standard interview solution.

---

## Cons

- Sorting every string costs `O(k log k)`.

---

# Solution 2: Character Frequency Encoding (Optimized)

## Intuition

Instead of sorting, count how many times every letter appears.

Every anagram has exactly the same character frequencies.

Example:

```
eat

a : 1
e : 1
t : 1

↓

1,0,0,0,1,0,...,1,...
```

This frequency representation becomes the hash map key.

---

## Approach

1. Create a frequency array of size 26.
2. Count the occurrence of every character.
3. Convert the frequency array into a unique string key.
4. Store the original string in the hash map using this key.
5. Return all grouped values.

---

## Code (C++)

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> groups;

        for (const string& str : strs) {

            vector<int> count(26, 0);

            for (char c : str) {
                count[c - 'a']++;
            }

            string key = to_string(count[0]);

            for (int i = 1; i < 26; i++) {
                key += "," + to_string(count[i]);
            }

            groups[key].push_back(str);
        }

        vector<vector<string>> result;

        for (const auto& entry : groups) {
            result.push_back(entry.second);
        }

        return result;
    }
};
```

---

## Complexity

**Time:** `O(n × k)`

- Counting characters takes `O(k)`.
- Building the key takes `O(26)`, which is constant.

**Space:** `O(n × k)`

---

## Pros

- Faster than sorting.
- Linear time with respect to the string length.
- Avoids repeated sorting.

---

## Cons

- More difficult to discover during an interview.
- Slightly more verbose.
- Works directly only because the problem specifies lowercase English letters (`a-z`). For arbitrary Unicode characters, the approach would need to be adapted.

---

# Comparison

| Feature | Sorting | Frequency Encoding |
|---------|---------|--------------------|
| Time Complexity | `O(n × k log k)` | `O(n × k)` |
| Space Complexity | `O(n × k)` | `O(n × k)` |
| Simplicity | ⭐⭐⭐⭐⭐ | ⭐⭐⭐ |
| Interview Friendliness | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐ |
| Performance | ⭐⭐⭐ | ⭐⭐⭐⭐⭐ |
| Handles Arbitrary Characters Easily | ✅ Yes | ❌ Requires adaptation |

---

# Pattern Learned

**Canonical Representation**

Transform every object into a standard representation so that equivalent objects produce the same key.

Examples:

- Group Anagrams
- Normalizing file paths
- Frequency encoding
- Sorted representation
- Email normalization

---

# Revision Note

Whenever a problem asks you to **group equivalent objects**, ask yourself:

> Can I transform each object into a canonical representation?

If yes:

- Use that representation as the **hash map key**.
- Store the original objects as the **hash map value**.

For Group Anagrams, there are two canonical representations:

- Sorted string
- Character frequency vector