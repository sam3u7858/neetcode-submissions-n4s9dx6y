class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int>& nums, vector<int>& path, int index, int sum, int target){
        if(sum == target){
            res.push_back(path);
            return;
        }

        for(int i=index; i<nums.size(); i++){
            if(sum + nums[i] > target){
                return;
            }
            path.push_back(nums[i]);
            dfs(nums, path, i, sum+nums[i], target);
            path.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        dfs(nums, temp, 0, 0, target);
        return res;
    }
};
