class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;
        vector<int> res_final;
        for(int i=0; i<nums.size(); i++){
           
            if(indexMap.find(target - nums[i]) != indexMap.end()){    
                res_final.push_back(indexMap[target - nums[i]]);
                res_final.push_back(i);
                return res_final;
            }

            indexMap[nums[i]] = i;
        }

       return res_final;
    }
};
