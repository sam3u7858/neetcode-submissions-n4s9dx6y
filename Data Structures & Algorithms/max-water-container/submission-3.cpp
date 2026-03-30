class Solution {
public:
    int maxArea(vector<int>& heights) {
        // Using max pointer
        int maxSize = 0;
        int left = 0;
        int right = heights.size()-1;

        while(left < right){
            int size =  (right - left) * min(heights[right], heights[left]);
            maxSize = max(maxSize, size);
            if(heights[right] > heights[left]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxSize;
    }
};
