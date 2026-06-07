class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int _max = INT_MIN;
        int n = arr.size();

        for(int i = n-1; i>=0; i--){
            
            int tmp = arr[i];
            arr[i] = _max;
            _max = max(tmp, _max);


            if(i == n-1) arr[i] = -1;
            
        }

        return arr;
    }
};