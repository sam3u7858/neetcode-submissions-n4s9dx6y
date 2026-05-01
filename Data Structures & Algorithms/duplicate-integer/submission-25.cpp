class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> c;
        for(const int& num:nums){
            if(c.find(num) != c.end())return true;
            c[num] = 1;
            
        }
        return false;


    }
};