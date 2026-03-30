class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        for(int i=0; i<gas.size(); i++){
            total_gas += gas[i];
            total_cost += cost[i];
        }
        if(total_gas < total_cost) return -1;

        int res = 0;
        int current_tank = 0;
        for(int i=0; i<gas.size(); i++){
            current_tank += gas[i] - cost[i];
            if(current_tank < 0){
                res =  i+1;
                current_tank = 0;
            }

        }

        return res;
    }
};
