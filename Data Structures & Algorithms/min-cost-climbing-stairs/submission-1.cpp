class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //另外還有一個空間最佳化的做法，直接cost來計算
        //這是一個top-down的方法
        //概念上就是: 我在 i 的位置，可能的最小花費以走到i+2或i+1
        
        for(int i=cost.size()-3; i>=0; i--){
            cost[i] += min(cost[i+1], cost[i+2]);
        }
        return min(cost[0], cost[1]);
    }
};
