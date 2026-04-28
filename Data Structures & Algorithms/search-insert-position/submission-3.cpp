class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while(l<=r){
            if(l==r && nums[l] != target){

                cout << l << ":" << nums[l] << endl;
                if(nums[l] > target){
                    return l;
                }
                else{
                    return l+1;
                }
                
            }

            int mid = (r-l)/2+l;

            cout << mid << ":" << l <<":" << r<< endl;
            if(target > nums[mid]) l = mid+1;
            else if(target < nums[mid]) r = mid;
            else{
                return mid;
            }

            

        }
        return 0;
    }
};