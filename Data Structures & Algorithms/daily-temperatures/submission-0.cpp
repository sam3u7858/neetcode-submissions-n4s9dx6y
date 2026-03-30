class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> index;
        vector<int> res(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++){
            int t = temperatures[i];
            while(!index.empty() && t > index.top().first){
                auto pair = index.top();
                index.pop();
                res[pair.second] = i - pair.second;
            }

            index.push({t, i});
        }

        return res;

    }
};
