class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> groupingMap;
        vector<vector<string>> res;
        int size = 0;

        for(int i=0; i<strs.size(); i++){
            string tmp(26, '0');
            string s = strs[i];

            for(int j=0; j<s.length(); j++){
                tmp[s[j] - 'a'] += 1;    
            }

            if(groupingMap.find(tmp) != groupingMap.end()){
                res[groupingMap[tmp]].push_back(strs[i]);
            }
            else{
                groupingMap[tmp] = size;
                vector<string> tmpVec;
                tmpVec.push_back(s);
                res.push_back(tmpVec);
                size +=1;
            }
         


        }
        return res;
    }
};
