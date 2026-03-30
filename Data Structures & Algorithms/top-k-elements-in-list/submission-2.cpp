class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(const int n : nums) freq[n]++;

        // Min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for(auto& [val, cnt]: freq){
            minHeap.push({cnt, val});
            if(minHeap.size() > k) minHeap.pop();
        }
        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;


    }
};
