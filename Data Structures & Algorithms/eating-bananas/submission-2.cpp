class Solution {
   public:
    int checkTime(vector<int>& piles, int amount) {
        int res = 0;
        if (amount == 0) return INT_MAX;
        for (auto const& p : piles) {
            if(p % amount != 0) res += 1 + p/amount;
            else{
                res+= p/amount;
            }
        }

        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());


      

        int res = INT_MAX;
        int l = 0;
        int r = piles[piles.size() - 1];

        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (checkTime(piles, mid) > h)
                l = mid + 1;
            else if (checkTime(piles, mid) <= h) {
                res = min(mid, res);
                r = mid - 1;
            }
        }
        return res;
    }
};
