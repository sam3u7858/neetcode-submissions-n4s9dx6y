class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> d;

        for(int n:nums){
            if(d.find(n) == d.end()){
                d[n] = true;
            }
            else{
                return true;
            }


        }
        return false;
        
    }
};