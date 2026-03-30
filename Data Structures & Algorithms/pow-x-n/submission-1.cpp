class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            return 1 / myPow(x, abs(n));
        }

        if (n == 0){
            return 1;
        }
        else if(n  == 1){
            return x;
        }
        else{
            if(n%2==0){
                return myPow(x,n/2) * myPow(x, n/2);
            }
            else{
                return myPow(x,(n)/2) * x * myPow(x,(n)/2);
            }

        }
        
    }
};
