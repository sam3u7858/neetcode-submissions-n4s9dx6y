class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0;
        sort(people.begin(), people.end());
        
        int l = 0;
        int r = people.size()-1;
        while(l<=r){
            // Put heavy one first
            res+=1;
            int diff = limit - people[r];
            if(diff < people[l]){
                r--;
                continue;
            }




            r--;
            l++;


        }
        
        return res;
    }
};