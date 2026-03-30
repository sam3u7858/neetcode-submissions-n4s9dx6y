class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> bucket;
        for(int n:nums){
            bucket[n] = bucket[n] + 1 ;
        }

        // Building bucket
        vector<vector<int>> freq(nums.size() + 1);
        for(auto entry: bucket){
            freq[entry.second].push_back(entry.first);

        }
        // Fetch result
        vector<int> result;
        for(int i=freq.size()-1; i>=0; i--){
            for(int num : freq[i]){
                result.push_back(num);
                if(result.size() == k){
                    return result;
                }
            }

        }

     
        return result;
    }
};
