class Solution {
public:

    int isFit(vector<int>& nums, int k, int capa){
        int curr = 0;
        int sp = 1;

        for(auto const& n:nums){
            if(curr + n > capa){
                sp += 1;
                curr = 0;

                if(sp > k) return false;
            }
            curr+=n;
        }

        return true;

    }

    int splitArray(vector<int>& nums, int k) {

        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        while(l <= r){
            int mid = (r-l)/2 + l;
            if(isFit(nums, k, mid)) r = mid - 1;
            else{
                l = mid + 1;
            } 
        }


        return l;

        
    }
};