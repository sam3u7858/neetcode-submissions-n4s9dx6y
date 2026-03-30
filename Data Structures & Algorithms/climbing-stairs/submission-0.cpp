class Solution {
public:
    int climbStairs(int n) {
        vector<int> stairs;
        int methods = 0;

        if(n==1)return 1;
        if(n==2)return 2;

        stairs.push_back(1);
        stairs.push_back(2);
        for(int i=2; i<=n; i++){
            methods = stairs[i-1] + stairs[i-2]; 
            stairs.push_back(methods);
        }
        return stairs[n-1];
    }
};
