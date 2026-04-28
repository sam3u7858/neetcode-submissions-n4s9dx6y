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

        // Since there are two possibility:
        // for x = 13 ~ 3.6... => 3
        // mid -> 3*3 = 9

        // for x = 8 ~ 2.82 =>2
        // mid = 3, however 3 > 2.82
        if(mid*mid>x)return mid-1;
        return mid;

        

    }
};