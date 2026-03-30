class Solution {
public:
  
    int uniquePaths(int m, int n) {
        // math:
        long long  maxValue = max(m, n);
        long long minValue = min(m, n);

        long long a = (m+n-2);
        long long res = 1;
        for(long long i = a; i>=maxValue; i--){
            res *= i;
            
        }
        cout << res;
        for(long long i=1; i<minValue; i++){
            res /= i;
        }
        int resInt = (int)res;
        return resInt;
    }
};
