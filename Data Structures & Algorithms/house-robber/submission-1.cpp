class Solution {
public:

    int dfs(const vector<int>& nums, vector<int>& credit, int i){
        int n = nums.size();
        if(i >= n) return 0;

        if(credit[i] != -1) return credit[i];
        
        int take = nums[i] + dfs(nums, credit, i+2); // take this and you skip next;
        int next = dfs(nums, credit, i+1);

        credit[i] = max(take, next);
        return credit[i];
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> credit(size, -1);

        int res = dfs(nums, credit, 0);
        return res;
    }
};
