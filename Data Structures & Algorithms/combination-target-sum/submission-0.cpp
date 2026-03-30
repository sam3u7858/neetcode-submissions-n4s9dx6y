class Solution {
public:
    vector<vector<int>> res;
    // unordered_map<int, int> indexFinder;
    void dfs(vector<int>& nums, vector<int>& path, int left, int start){
        // Base case
        if(left == 0){
            res.push_back(path);
            return;
        }


        // Continue finding value
        for(int i=start; i<nums.size(); i++){
            if(left - nums[i] < 0) break;
            path.push_back(nums[i]);
            dfs(nums, path, left-nums[i], i);
            path.pop_back();
        }




    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(nums, path, target, 0);
        return res;
    }
};
