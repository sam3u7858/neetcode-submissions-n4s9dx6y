class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size()-1;
        int res = 0;

     

        while(l<=r){
            while(people[r]+people[l]>limit){
                cout << "[" << people[r] << "]" << "|" << l << "" << r << endl;
                res+=1;
                r--;
                
            }

          

            if(l>r) break;
            res+=1;
            r--;
            l++;
            
        }

        return res;
    }
};