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
    bool operator()(const Interval& a, const Interval& b){
        return a.start < b.start;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), sorter());

        int endTime = intervals[0].end;

        for(int i=1; i<intervals.size(); i++){
           const auto& inter = intervals[i];
           if(inter.start < endTime) return false;
           else{
                endTime = inter.end;
           } 
        }
        


        return true;
    }
};
