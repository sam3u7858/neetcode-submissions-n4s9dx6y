class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index_sum;
        vector<int> result;
        int index = 0;
        for(auto num:nums){
            
            int diff = target - num;
            if(index_sum.find(diff) == index_sum.end()){
                // not found
            }
            else{
                result.push_back(index_sum[diff]);
                result.push_back(index);
                return result;
            }
            index_sum[num] = index;
            index += 1;
        }
        return result;
    }
    
};
