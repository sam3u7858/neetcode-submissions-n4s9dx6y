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
    int minMeetingRooms(vector<Interval>& intervals) {
        int res = 1;
    

        std::priority_queue<int, vector<int>, std::greater<int>> pq;

        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), sorter());
        pq.push(intervals[0].end);

        for(int i=1; i<intervals.size(); i++){
            auto curr = intervals[i];
            if(curr.start >= pq.top()){
                pq.pop();
                pq.push(curr.end);
            }
            else{
                pq.push(curr.end);
                res+=1;

            }

        }


        return res;

    }
};
