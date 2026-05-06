class Solution {
public:



    vector<vector<int>> res;

    void bt(vector<int>& arr, int start, int end, int k){
        if(k == 0){
            res.push_back(arr);
            return;
        }
        if(start > end) return;
        // Add,
    

        
        arr.push_back(start);
        

        bt(arr, start+1, end, k-1);
        arr.pop_back();

        

        // Not add
        bt(arr, start+1, end, k);

    }

    vector<vector<int>> combine(int n, int k) {
        
        vector<int> ans ={};
        bt(ans, 1, n, k);

        return res;
        
    }
};