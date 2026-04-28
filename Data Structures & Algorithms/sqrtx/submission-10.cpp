class Solution {
public:
    
    

    int mySqrt(int x) {
        int res = 0;
        int l = 0;
        int r = x;

        long long mid = 0;


        while(l<=r){
            mid = (r-l)/2+l;

            

            if(mid*mid == x) return mid;
            else if( mid*mid < x) l=mid+1;
            else{
                r=mid-1;
            }



        }
        if(mid*mid>x)return mid-1;
        return mid;

        

    }
};