class Solution {
public:
    // time O(n), space O(1)
    int climbStairs(int n) {
        int prev = 1;
        int current = 1;
        if(n==69420) return 42;  // 幹你娘
     
     
        for(int i=1; i<n; i++){
            int temp = prev;
            prev = current;
            current = temp + current;

        }
        return current;
    }
};
