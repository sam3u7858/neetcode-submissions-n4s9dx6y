
class Solution {
    struct Compare{
        unordered_map<int, int>& _count;
        Compare(unordered_map<int, int>& count) : _count(count) {}
        bool operator()(int a, int b) {
            return _count[a] > _count[b]; 
        }
};

public:


    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(const int n: nums) count[n]++;
        
       
        vector<int> keys;
        for(auto const& [val, cnt]:count){
            keys.push_back(val);
        }
        sort(keys.begin(),  keys.end(), Compare(count));
        return vector<int>(keys.begin(), keys.begin()+k);

    }
};
