class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int>& nums, vector<int> path, int start){
        
        if(start == nums.size())return;
        for(int i = start; i<nums.size(); i++){

            if( i > start && nums[i] == nums[i-1] ){
                continue;
            }

            path.push_back(nums[i]);
            res.push_back(path);
            dfs(nums, path, i+1);
            path.pop_back();
        }
    
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> p;
        sort(nums.begin(), nums.end());
        res.push_back({});
        dfs(nums, p, 0);
        return res;
    }
};
