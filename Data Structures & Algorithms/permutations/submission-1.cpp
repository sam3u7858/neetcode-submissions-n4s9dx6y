class Solution {
public:
    vector<vector<int>> res;
 
    void dfs(vector<int>& nums, int start){
        // base case
        if(nums.size() == start){
            res.push_back(nums);
            return;
        }

        for(int i=start; i<nums.size(); i++){
            swap(nums[start], nums[i]);
            dfs(nums, start+1);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};
