class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vs;
        for(int i=0; i<position.size(); i++){
            vs.push_back({position[i], speed[i]});
        }

        // Sorting 
        std::sort(vs.begin(), vs.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        
        //debug print out:
        for(auto const p : vs){
            cout << p.first << "," << p.second << endl;
        }

        // Add to stack
        stack<pair<int, int>> stack_res;
        for(auto const& p:vs){
                if(stack_res.empty()){
                    stack_res.push(p);
                    continue;
                }
            // check if we should remove or not
          
                double time_front = 0;
                double time_back = 0;

                time_front = (double)(target - stack_res.top().first) / stack_res.top().second;
                time_back =  (double) (target - p.first) / p.second;

                cout << stack_res.top().first << "," << stack_res.top().second << endl;
                cout << "time_front:" << time_front << "," << "time_back:" << time_back << endl;
                if(time_front >= time_back){
                    continue;
                }
                else{
                    stack_res.push(p);
                }
        }

        return stack_res.size();
 
    }
};
