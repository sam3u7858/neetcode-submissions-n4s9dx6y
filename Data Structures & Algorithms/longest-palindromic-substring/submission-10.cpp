class Solution {
   public:
    pair<int, int> getPalindromic(string s, int mid) {
        int odd_ans_range_l = mid;
        int odd_ans_range_r = mid;
        int n = s.size();

        // is odd
        int l = mid - 1;
        int r = mid + 1;

        while (l >= 0 && r < n) {
            if (s[l] == s[r]) {
                odd_ans_range_l = l;
                odd_ans_range_r = r;
            } else {
                break;
            }
            --l;
            ++r;
        }

        int even_ans_range_l = mid;
        int even_ans_range_r = mid;

        if (mid + 1 < n && s[mid] == s[mid + 1]) {
            l = mid;
            r = mid + 1;

            while (l >= 0 && r < n) {
                if (s[l] == s[r]) {
                    even_ans_range_l = l;
                    even_ans_range_r = r;

                } else {
                    break;
                }
                --l;
                ++r;
            }
        }

        int sizeOdd = odd_ans_range_r - odd_ans_range_l;
        int sizeEven = even_ans_range_r - even_ans_range_l;
        if (sizeOdd >= sizeEven) {
            return {odd_ans_range_l, odd_ans_range_r};
        }

        return {even_ans_range_l, even_ans_range_r};
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int resLeng = 0;
        int resl = 0;
        int resr = 0;

        // Brute force
        for (int m = 0; m < n; m++) {
            pair<int, int> curr = getPalindromic(s, m);
            if(resLeng < curr.second - curr.first + 1){
                resLeng = curr.second - curr.first + 1;
                resl = curr.first;
                resr = curr.second;
            }
        }

        return s.substr(resl, resr - resl + 1);
    }
};
