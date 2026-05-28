class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        
        // area
        int res = 0;
        while(l < r){

            res = max(res, min(heights[l], heights[r]) * (r-l));

            printf("l:%d, r:%d ,min:%d, res:%d\n", l, r, min(heights[l], heights[r]), res);
            
            if(heights[l] > heights[r]){
                r--;
            }

            else{
                l++;
            }

        }
        return res;
        
    }
};
