class Solution {
public:
    // index flatten; [prevIndex][i] -> [(prevIndex) * n + i]
    // becare of prevIndex = -1
    unordered_map<int, int> memo;

    // recursion 
    int recursion(vector<int>& nums, int i, int prevIndex){
        if(i == nums.size()) return 0;

        int n = nums.size();
        int key = (prevIndex + 1) * n + i;

        if(memo.count(key)) return memo[key];

        int notTake = recursion(nums, i + 1, prevIndex);
        int take = 0;

        if(prevIndex == -1 || nums[i] > nums[prevIndex]){
            take = 1 + recursion(nums, i + 1, i);
        }

        return memo[key] = max(take, notTake);

    }


    int lengthOfLIS(vector<int>& nums) {
        // top down
        // int ans = recursion(nums, 0, -1);
        // return ans;
        // bottom down
        int res = 1;
        int n = nums.size();
        vector<int> dp(n, 1);

        for(int i=1; i<n; ++i){
            for(int j=0; j < i; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());


    
    }


};
