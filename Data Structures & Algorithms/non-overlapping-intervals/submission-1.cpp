struct MyComparator{
    bool operator()(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
};

class myInterval{
    public:
        int start, end;
    bool operator<(const myInterval& other) const{
        return this->end < other.end;
    }

};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), MyComparator());
        int last_end = intervals[0][1];
        int res = 0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] >= last_end ) last_end = intervals[i][1];
            else{
                res++;
            }
        }
        return res;
    }
};
