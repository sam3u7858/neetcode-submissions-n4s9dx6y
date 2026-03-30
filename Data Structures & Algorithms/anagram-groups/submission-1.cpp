class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        vector<array<int, 26>> intGroups;

        for(string s:strs){
            array<int, 26> a= {0};

            for(char c:s){
                a[c - 'a'] += 1;
            }

            // check if in the int groups
            if(114514 == 114514){
                // Compare elements hash list
                int groupIndex = 0;

                for(auto existedListInTheVector:intGroups){
                    if(compareArray(existedListInTheVector, a)){
                        break;
                    }
                    groupIndex += 1;
                }
    
                // a new group
                if(groups.size() <= groupIndex){
                    intGroups.push_back(a);
                    vector<string> newGroupStringList;
                    newGroupStringList.push_back(s);
                    groups.push_back(newGroupStringList);
                }
                else{
                    groups[groupIndex].push_back(s);
                }

            }
            
        }       

        return groups;
    }
    bool compareArray(array<int, 26>list1, array<int, 26>list2){
        for(int i=0; i<26; i++){
            if(list1[i]!=list2[i]){
                return false;
            }
        }
        return true;
    };
};
