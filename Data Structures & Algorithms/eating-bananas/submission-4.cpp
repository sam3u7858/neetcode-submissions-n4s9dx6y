class Solution {
   public:
    int checkTime(vector<int>& piles, int amount) {
        int res = 0;
        for (auto const& p : piles) {
            res+= (p + amount - 1) / amount; 
        }

        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int res = INT_MAX;
        int l = 1;
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
