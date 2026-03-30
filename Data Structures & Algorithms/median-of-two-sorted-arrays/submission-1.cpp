class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }


        double res = 0;

        // We take n as the search target
        int lower = 0;
        int upper = n;

        while(lower <= upper){
            // Get i value each step using binary search;
            int i = lower + (upper - lower) / 2;
            //  correct final example : 
            //  nums1 -> [XXXX | OOO]
            //  nums2 -> [X | OO]

            // total = (n + m) / 2  
            // j = total - i?
            // Better way: halfLen 
            // i+j = halfLen;
            // j = halfLen - i
            int halfLen = (m + n + 1)/2;
            int j = halfLen - i;
            int maxLeft1;
            int maxLeft2;
            int minRight1;
            int minRight2;

            if(i==0){
                maxLeft1 = INT_MIN;
            }
            else{
                maxLeft1 = nums1[i-1];
            }

            if(i==n){
                minRight1 = INT_MAX;
            }
            else{
                minRight1 = nums1[i];
            }    


            if(j==0){
                maxLeft2 = INT_MIN;
            }
            else{
                maxLeft2 = nums2[j-1];
            }

            if(j==m){
                minRight2 = INT_MAX;
            }
            else{
                minRight2 = nums2[j];
            }
            
            
            if(maxLeft1 > minRight2){
                upper = i - 1;
            }

            else if(maxLeft2 > minRight1){
                lower = i + 1;
            }
            else{
                if((n+m)%2==0){
                    res = (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) /2.0;
                }   
                else{
                    res = max(maxLeft1, maxLeft2);
                }
                return res;
            }

        }

        

        return res;
        
    }
};
