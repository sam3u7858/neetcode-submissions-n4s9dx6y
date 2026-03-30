class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> result = {};

      for(int i=0; i<nums.size(); i++){

        // Skip duplicate i
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = nums.size() - 1;
        int target = -nums[i];

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});

            // Skip duplicates for left
            while (left < right && nums[left] == nums[left + 1]) left++;
            // Skip duplicates for right
            while (left < right && nums[right] == nums[right - 1]) right--;

            // Move both pointers
            left++;
            right--;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }

        }
         

      }
      return result;
    }
};
