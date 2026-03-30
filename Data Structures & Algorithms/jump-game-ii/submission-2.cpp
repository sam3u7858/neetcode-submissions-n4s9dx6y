class Solution {
public:
    int jump(vector<int>& nums) {

      if(nums.size() == 1) return 0;

      int jumps = 0;
      int current_bound = 0;
      int maxBound = 0;


      for(int i=0; i<nums.size()-1; i++){

          maxBound = max(maxBound, i + nums[i]);

          if(i==current_bound){
            jumps++;
            current_bound = maxBound;
            if(current_bound>=nums.size()-1){
                return jumps;
            }

          }
      }
      return jumps;
    }
};
