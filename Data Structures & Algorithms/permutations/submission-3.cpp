class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> &nums, int k){
        if(nums.size() == k){
            res.push_back(nums);
            return;
        }

        for(int i=k; i<nums.size(); i++){
            
           
            swap(nums[i], nums[k]);
            dfs(nums,k+1);
            swap(nums[i], nums[k]);
            
        }


    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm = {};
        dfs(nums, 0);
        return res;
    }
};
