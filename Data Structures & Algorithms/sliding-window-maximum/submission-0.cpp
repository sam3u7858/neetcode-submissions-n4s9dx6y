class Solution {
public:

    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 原始想法
        // 先 sort list (O(n*logn))
        // 然後找每個 window的 list[r]? (n)
        // 不對，不能 sort 整個 list 因為這樣次序就錯了
        // 如果變成用 window的去做 那會變成 n * n* log (n) 
        
        vector<int> maxValues;
        //使用 max heap
        priority_queue<pair<int, int>> pq;

        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i] ,i});

            if(i >= k - 1){
                while(pq.top().second < j){
                    pq.pop();
                }
                maxValues.push_back(pq.top().first);
                j += 1;
            }


            


        }

        
        

        

        
        
        return maxValues;


    }
};
