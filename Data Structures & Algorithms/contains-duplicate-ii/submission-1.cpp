class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;

        unordered_map<int, int> _map;
        for(int i=0; i<nums.size(); i++){
            if(_map.find(nums[i]) != _map.end()){
                if(i - _map[nums[i]] <=k) return true;
            }
            _map[nums[i]] = i;
        }

        return false;

    }
};