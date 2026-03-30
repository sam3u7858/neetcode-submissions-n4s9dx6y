class Solution {
public:

    struct CompareMaxHeap {
        int dist(const vector<int>& p) const {
            return p[0] * p[0] + p[1] * p[1];
        }

        bool operator()(const vector<int>& a, const vector<int>& b) {
            return dist(a) < dist(b);
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, CompareMaxHeap> pq;
        for(auto const& p : points){
            pq.push(p);
            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> res;
        for(int i=0; i<k; i++){
            if(pq.size()>0){
                res.push_back(pq.top()); pq.pop(); //oops, shouldn've use pq.pop to get element
            }
        }
        return res;
    }
};
