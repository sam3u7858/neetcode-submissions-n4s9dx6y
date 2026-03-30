class Solution {
public:
    // time O(n), space O(N)
    int climbStairs(int n) {
        int prev = 1;
        int current = 2;

        if(n==1)return 1;
        if(n==2)return 2;
     
        for(int i=2; i<n; i++){
            int temp = prev;
            prev = current;
            current = temp + current;

        }
        return current;
    }
};
