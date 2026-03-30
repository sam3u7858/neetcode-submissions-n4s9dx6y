class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1; 

        while(right >= left){
            int mid = left + (right - left)/2;
            int v = nums[mid];

            if( v == target){
                return mid;
            }
            else if( v > target){
                right = mid - 1;
            }
            else if( v < target ){
                left = mid + 1;
            }
        }
        return -1;
    }
    
};
