class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //create a hashmap
        unordered_map<int, int> freq;
        for(auto num: nums)
        {
            freq[num]++;
        }

        //create buckets where index is the frequency of each element
        vector<vector<int>> buckets(nums.size() + 1);  // we have taken the size of bucket as nums.size +1 because the max frequency an element can have is the size of the nums array.

        //populate the buckets
        for(const auto& [num, count] : freq)
        {
            buckets[count].push_back(num);
        }

        //iterate backwards in the buckets to get the top k elements
        vector<int> result;
        for(int i = buckets.size()-1; i > 0 && result.size() < k; i--) 
        {
            if(buckets[i].empty())
            {
                continue;
            }
            else
            {
                for(int num : buckets[i])
                {
                    if(result.size() == k)
                    {
                        break;
                    }
                    result.push_back(num);
                }
            }
        }

        return result;
    }
};