class Solution {
public:
    vector<vector<int>> res;
   

    void dfs(vector<int>& perm, vector<int>& nums, vector<int> &used){
        if(perm.size()==nums.size()){
            res.push_back(perm);
            return;
        }

        for(int i=0; i<nums.size(); i++){
           if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
           if(used[i]) continue;
        
           used[i] = true;
           perm.push_back(nums[i]);
           dfs(perm, nums, used);
           perm.pop_back();
           used[i] = false;

        }


        
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> perm = {};
        vector<int> usd(nums.size(), 0);
        sort(nums.begin(), nums.end());

        dfs(perm, nums, usd);
        return res;
    }
};