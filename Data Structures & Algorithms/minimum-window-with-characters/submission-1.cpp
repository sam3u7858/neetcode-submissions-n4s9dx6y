class Solution {
public:

    int charToIndex(char c) {
        if (c >= 'A' && c <= 'Z') return c - 'A';
        return c - 'a' + 26;
    }

    bool windowCoversTarget(int* a, int* b, int size){
        for(int i=0; i<size; i++) {
            if (b[i] < a[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {

       

        if(s.length() < t.length()) return "";

        int s_list[52] = {0};
        int t_list[52] =  {0};
      
  
        for(auto const& ch : t) {
            t_list[charToIndex(ch)] += 1;
        }
        int l = 0, r = 0;
        int min_len = INT_MAX;
        int min_start = 0;
        int window[52] = {0};

        while( r < s.length()){
            window[charToIndex(s[r])]++;
            while(windowCoversTarget(t_list, window, 52)){
                if(r - l + 1 < min_len){
                    min_len = r - l + 1;
                    min_start = l;
                }
                window[charToIndex(s[l])]--;
                l++;
            }
            r++;
        }

        if (min_len == INT_MAX) return "";
        return s.substr(min_start, min_len);
     
    }
};
