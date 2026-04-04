class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(const int n : nums) freq[n]++;

        vector<int> keys;
        for(auto& [val, cnt] : freq){
            keys.push_back(val);
        }
        sort(keys.begin(), keys.end(), [&](int a, int b){
            return freq[a] > freq[b];
        });

        return vector<int>(keys.begin(), keys.begin()+k);


    }
};
