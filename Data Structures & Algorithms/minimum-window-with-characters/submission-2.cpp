class Solution {
public:

    int charToIndex(char c) {
        if (c >= 'A' && c <= 'Z') return c - 'A';
        return c - 'a' + 26;
    }

    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        int t_list[52] = {0};
        int window[52] = {0};
        int requiredMatchCount = 0;

        for (char ch : t) {
            int idx = charToIndex(ch);
            if (t_list[idx] == 0) requiredMatchCount++;
            t_list[idx]++;
        }

        int matchCount = 0;
        int l = 0, r = 0;
        int min_len = INT_MAX, min_start = 0;

        while (r < s.length()) {
            int idx_r = charToIndex(s[r]);
            window[idx_r]++;

            if (t_list[idx_r] > 0 && window[idx_r] == t_list[idx_r]) {
                matchCount++;
            }

            while (matchCount == requiredMatchCount) {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    min_start = l;
                }

                int idx_l = charToIndex(s[l]);
                if (t_list[idx_l] > 0 && window[idx_l] == t_list[idx_l]) {
                    matchCount--;
                }
                window[idx_l]--;
                l++;
            }

            r++;
        }

        if (min_len == INT_MAX) return "";
        return s.substr(min_start, min_len);
    }
};
