/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */


struct sorter{
    bool operator()(const auto& a, const auto&b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int res = 0;
        int current = 0;
        vector<pair<int, int>> ps;

        for(int i=0; i<intervals.size(); i++){
            // start = +1, end = -1; (room)
            auto const& curr = intervals[i];
            ps.push_back({curr.start, 1});
            ps.push_back({curr.end, -1});
        }
        sort(ps.begin(), ps.end(), sorter());
    
        for(int i=0; i<ps.size(); i++){
            const pair<int, int>& curr = ps[i];
            current += curr.second;

            res = max(current, res);

        }
        


       
        return res; // can be pq.size();

    }
};
