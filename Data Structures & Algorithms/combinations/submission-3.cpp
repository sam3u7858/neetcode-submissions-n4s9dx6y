class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> arr(k, 0);
        int i = 0;

        while( i >= 0){
            arr[i]++;
            if(arr[i] > n){
                i--;
                continue;
            }

            if(i == k-1){
                res.push_back(arr);
            }
            else{
                i++;
                arr[i] = arr[i-1];
            }
        }
        return res;
    }
    
};