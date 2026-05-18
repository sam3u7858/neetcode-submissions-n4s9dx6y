class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> idxs;

        for(int i=0; i<n; i++){
            while(!idxs.empty() && temperatures[i] > temperatures[idxs.top()]){
                res[idxs.top()] = i - idxs.top();
                idxs.pop();

            }

            idxs.push(i);

        }
        
            


        return res;
    }
};
