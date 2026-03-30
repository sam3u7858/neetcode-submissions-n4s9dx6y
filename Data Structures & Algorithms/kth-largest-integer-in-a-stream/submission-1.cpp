class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums){
        this->k = k;
        for(auto const num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);

        if(minHeap.size() > k ){
            minHeap.pop(); // Maintaining only first k elements
        }

        return minHeap.top(); // return kth max (since it's piority queue)

    }
};
