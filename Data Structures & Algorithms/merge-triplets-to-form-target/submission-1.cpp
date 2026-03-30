class Solution {
public:

    bool isSafe(vector<int>& a, vector<int>& target){
        if(a.size() != target.size()) return false;
        for(int i=0; i<a.size(); i++){
            if(target[i] < a[i]) return false;
        }
        return true;
    }

    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        if(triplets.size() == 0) return false;
        int current_index = 0;
        bool res1 = false;
        bool res2 = false;
        bool res3 = false;

        for(int i=0; i<triplets.size(); i++){
            vector<int>& curr = triplets[i];
            if(isSafe(curr, target)){
                if(curr[0] == target[0]) res1 = true;
                if(curr[1] == target[1]) res2 = true;
                if(curr[2] == target[2]) res3 = true;
            }
        }

        return res1 && res2 && res3;
    }
};
