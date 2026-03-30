class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int n : nums){
            if (map.find(n) == map.end()){
                map[n] = 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
