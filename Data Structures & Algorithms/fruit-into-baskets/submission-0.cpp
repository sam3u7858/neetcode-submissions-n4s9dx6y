class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        int n = fruits.size();
        if(n == 0) return 0;
        unordered_map<int, int> freq;
        int l = 0;
        int r = 0;

        for(;r<n;r++){
            int curr = fruits[r];
            freq[curr]++; 
            
            if(freq.size() > 2){
                
                freq[fruits[l]]--;
                if(freq[fruits[l]] == 0){
                    freq.erase(fruits[l]);
                }
                l++;
            }

            res = max(r-l+1, res);

        }

        return res;
    }
};