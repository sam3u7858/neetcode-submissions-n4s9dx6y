class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> cache(n + 1);
       
        for(int i=2; i<=n; i++){
            cache[i] = min(cache[i-1]+cost[i-1], cache[i-2]+cost[i-2]);
            //概念上就是透過"cache"是走到[n]階段的花費
        }


        return cache[n];
    }
};
