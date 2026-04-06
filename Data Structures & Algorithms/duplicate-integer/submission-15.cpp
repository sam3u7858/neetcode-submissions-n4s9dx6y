class Solution {
public:
    
   
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> number_map;
        for(auto &s:nums){
            if(number_map.find(s) == number_map.end()){
                number_map[s] = true;
            }
            else{
                return true;
            }
        }
        return false;
    }
};