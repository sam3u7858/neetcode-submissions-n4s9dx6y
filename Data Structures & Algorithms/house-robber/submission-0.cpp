class Solution {
public:

    int dfs(const vector<int>& nums, vector<int>& credit, int i){
        if(i >= nums.size()){
            return 0;
        }
        if(credit[i] != -1){
            return credit[i];
        }
        int a =  dfs(nums, credit, i+2);
        int b = dfs(nums, credit, i+1);

        if(credit[i+2] == -1) credit[i+2] = a;
        if(credit[i+1] == -1) credit[i+1] = b;

        return max(nums[i]+a, b);
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> credit(size, -1);

        int res = max(dfs(nums, credit, 0), dfs(nums, credit, 1));
        return res;
    }
};
