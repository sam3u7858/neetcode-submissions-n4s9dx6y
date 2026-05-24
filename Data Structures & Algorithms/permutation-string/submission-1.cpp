class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        bool res = false;
        int n = s1.size();
        int m = s2.size();
        if(n>m)return res;

        int l = 0;
        int r = 0;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(int i=0; i<n; i++){
            freq1[s1[i]-'a']++;
        }
        
        for(r=0; r<m; r++){
            freq2[s2[r]-'a']++;

            while(freq2[s2[r]-'a'] > freq1[s2[r]-'a']){
                freq2[s2[l]-'a']--;
                l++;
                
            }

            if(r - l + 1 == n) return true;

        }


        return false;
    }
};
