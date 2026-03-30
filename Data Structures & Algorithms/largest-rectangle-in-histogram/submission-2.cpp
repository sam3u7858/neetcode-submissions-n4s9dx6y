class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> stack;

        for(int i=0; i <heights.size (); i++){
            int start = i;
            while(!stack.empty() && stack.top().second > heights[i]){
                int index = stack.top().first;
                int height = stack.top().second;
                

                maxArea = max(maxArea, height * (i - index));
                start = index;
                stack.pop();

            
            }
            stack.push({start, heights[i]});
        }
        
        while(!stack.empty()){
            int index = stack.top().first;
            int h = stack.top().second;

            maxArea = max(maxArea, h * (static_cast<int>(heights.size()) - index));

            stack.pop();



        }
      return maxArea;
    }
    
};
