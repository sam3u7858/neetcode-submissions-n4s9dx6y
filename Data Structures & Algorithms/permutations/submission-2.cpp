class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> &nums, vector<int> &perm, int k){
        if(nums.size()==perm.size()){
            res.push_back(perm);
            return;
        }

        for(int i=k; i<nums.size(); i++){
            
            perm.push_back(nums[i]);
            swap(nums[i], nums[k]);
            dfs(nums, perm, k+1);
            perm.pop_back();
            swap(nums[i], nums[k]);
            
        }


    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm = {};
        dfs(nums, perm ,0);
        return res;
    }
};
