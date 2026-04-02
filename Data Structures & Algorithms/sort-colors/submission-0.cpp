class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0;
        int w=0;
        int b=0;

        for(auto const& n:nums){
            if(n==0) r++;
            else if(n==1) w++;
            else if(n==2) b++;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(r>0){
                nums[i] =0;
                r--;
            }
            else if(w>0){
                nums[i]= 1;
                w--;
            }
            else if(b>0){
                nums[i]= 2;
                b--;
            }
        }
        
    }
};