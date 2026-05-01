class Solution {
public:

    int binarySearch(vector<int>& nums, int target, int s, int e)
    {
        int l = s;
        int r = e;
        while(l<=r){
            int mid = (r-l)/2 + l;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r = mid - 1;
            else{
                l = mid+1;
            }
        }
        return -1;

    }

    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int pivot = 0;

        while(l<=r){
            int mid = (r-l)/2 + l;

            if(mid<nums.size()-1 && nums[mid] > nums[mid+1]){
                pivot = mid;
                break;
            } 
            else if(nums[l] < nums[mid]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }


        }

        int a = binarySearch(nums, target, 0, pivot);
        int b = binarySearch(nums, target, pivot+1, nums.size()-1);
        return max(a, b);
    }
};
