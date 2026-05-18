class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        int res = 0;
        if(n == 0) return 0;

        vector<pair<int, int>> cars(n);
        for(int i=0; i<n; ++i){
            cars[i] = {position[i], speed[i]};
        }

        auto cmp = [](auto const& a, auto const& b){
            return a.first > b.first;
        };

        sort(cars.begin(), cars.end(), cmp);
        double max_time = 0.0;

        for(int i=0; i<n; ++i){
            double arrive_time = (double)(target-cars[i].first)/(cars[i].second);
            if(arrive_time > max_time){
                res++;
                max_time = arrive_time;
            }
        }





        return res;

    }
};
