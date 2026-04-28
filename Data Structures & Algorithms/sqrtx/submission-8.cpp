class Solution {
public:
    

    int mySqrt(int x) {
        int res = 0;
   
        

        for(long long i=0; i<=x; i++){
            long long tmp = i*i;
            if(tmp == x) return i;
            else if(tmp>x){
                return i-1;
            }

        }

        return 0;

        

    }
};