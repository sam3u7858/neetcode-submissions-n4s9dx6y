class Solution {
public:
    

    int mySqrt(int x) {
        int res = 0;
        if(x>46340*46340) return 46340;
        

        for(int i=0; i<=x; i++){
            long long tmp = i*i;
            if(tmp == x) return i;
            else if(tmp>x){
                return i-1;
            }

        }

        return 0;

        

    }
};