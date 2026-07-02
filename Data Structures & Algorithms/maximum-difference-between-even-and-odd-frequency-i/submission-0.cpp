class Solution {
public:
    int maxDifference(string s) {
     
        vector<int> freq(26, 0);

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;

        for(int i=0; i<s.size(); i++){
            freq[s[i] - 'a']++;
        }

        for(int i=0; i<26; i++){
            if(freq[i] == 0 )continue;
            
            if(freq[i] % 2 == 1){
                maxOdd = max(maxOdd, freq[i]);
            }
            else{
                minEven = min(minEven, freq[i]);
            }

        }
        return maxOdd - minEven;       
    }
};