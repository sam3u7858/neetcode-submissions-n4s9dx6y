class Solution {
public:
  

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        
        unordered_map<int, int> ps;
        for(auto const& n:hand){
            if(ps.find(n) != ps.end()){
                ps[n] +=1;
            }
            else{
                ps[n] = 1;
            }
          
        }
        int n = hand.size();
        for(int i=0; i<n; i++){
            if(ps[hand[i]] > 0){
                ps[hand[i]] -= 1;
                for(int j=1; j<groupSize; j++){
                    int curr = hand[i] + j;
                    if(ps.find(curr) == ps.end()) return false;
                    else if(ps[curr] == 0) return false;
                    else{
                        ps[curr] -=1;
                    }
                }
            }

        }



        return true;

    }
};
