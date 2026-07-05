class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> exist;
        for(auto n:nums){
            if(exist.count(n)){
                return true;
            }
            else{
                exist.insert(n);
            }
        }

        return false;
    }
};