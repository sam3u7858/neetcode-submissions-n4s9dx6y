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
        vector<int> dp;
        dp.push_back(nums[0]);

        int LIS = 1;
        for(int i = 1; i < nums.size(); i++){
            if(dp.back() < nums[i]){
                dp.push_back(nums[i]);
                LIS ++;
                continue;

            }

            // if nums[i] <= dp.back();
            // check if we can replace
            int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            dp[idx] = nums[i];


        }
        return LIS;
    
    }


};
