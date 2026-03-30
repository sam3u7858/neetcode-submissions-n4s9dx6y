struct sorter
{
    bool operator()(const vector<int>& a,  const vector<int>& b){
        if(a[0] == b[0]){
           return a[1] < b[1];
        }
        return a[0] < b[0];
    }

};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.empty()) return {{}};
        sort(intervals.begin(), intervals.end(), sorter());
        
        int prev_min = intervals[0][0];
        int prev_max = intervals[0][1];

        vector<vector<int>> res;
        for(int i=1; i<intervals.size(); i++){
            vector<int>& curr = intervals[i];
            int current_min = curr[0];
            int current_max = curr[1];
            //  (increasing so no prev_min > current_min)
            // new-interval: if prev_min < current_min && prev_max < current_min

            if( prev_max < current_min){
                res.push_back({prev_min, prev_max});
                prev_min = current_min;
                prev_max = current_max;
            }

            else{
                prev_max = max(current_max, prev_max);
            }
            
            
           
        }

        res.push_back({prev_min, prev_max});

        return res;   
    }
};
