class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        vector<array<int, 26>> intGroups;

        for (string s : strs) {
            array<int, 26> a = {0};

            for (char c : s) {
                a[c - 'a'] += 1;
            }

            bool found = false;
            int groupIndex = 0;

            for (auto& existedList : intGroups) {
                if (compareArray(existedList, a)) {
                    groups[groupIndex].push_back(s);
                    found = true;
                    break;
                }
                groupIndex++;
            }

            if (!found) {
                intGroups.push_back(a);
                groups.push_back({s});
            }
        }

        return groups;
    }

    bool compareArray(const array<int, 26>& list1, const array<int, 26>& list2) {
        for (int i = 0; i < 26; ++i) {
            if (list1[i] != list2[i]) {
                return false;
            }
        }
        return true;
    }
};
