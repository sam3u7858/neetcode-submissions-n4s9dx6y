class Solution {
public:



    vector<vector<int>> res;

    void bt(vector<int>& arr, int start, int end, int k){
        if(arr.size() == k){
            res.push_back(arr);
            return;
        }

        for(int i=start; i<=end; i++){
            arr.push_back(i);
            bt(arr, i+1, end, k);
            arr.pop_back();
        }
     

    }

    vector<vector<int>> combine(int n, int k) {
        
        vector<int> ans ={};
        bt(ans, 1, n, k);

        return res;
        
    }
};