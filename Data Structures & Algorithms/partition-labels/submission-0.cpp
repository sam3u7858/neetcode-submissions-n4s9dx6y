class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastAppear(26, -1);
        vector<int> res;
        for(int i=0; i<s.length(); i++){
            lastAppear[s[i] - 'a' ] = i;
        }
        
        int start = -1;
        int end = 0;

        for(int i=0; i<s.size(); i++){
            end = max(end, lastAppear[s[i] - 'a']);

            if(end == i){
                res.push_back(end-start);
                start = end;
            }
        }



        return res;
    }
};
