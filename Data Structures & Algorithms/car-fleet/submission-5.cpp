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
        stack<double> stack_res;
        for(auto const& p:vs){
            double timeToEnd = (double)(target - p.first)/ p.second;    
            if(stack_res.empty()){
                    stack_res.push(timeToEnd);
                    continue;
                }
            else if( timeToEnd <= stack_res.top()){
                continue;
            }
            else{
                stack_res.push(timeToEnd);
            }
        }

        return stack_res.size();
 
    }
};
