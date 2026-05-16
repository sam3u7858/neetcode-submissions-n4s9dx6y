class PalindromeValidator {
   private:
    // Cache-friendly string view to avoid unnecessary allocations
    static bool validate(const string& s, int l, int r) {
        string sub = s.substr(l, r - l + 1);
        string rev = sub;
        reverse(rev.begin(), rev.end());  // O(n)
        return sub == rev;                // O(n) compare
    }

   public:
    static bool isPalindrome(const string& s, int l, int r) {
        if (l > r) return false;
        if (l == r) return true;
        return validate(s, l, r);  // delegate for separation of concern
    }
};

class SubstringEnumerator {
   public:
    // Returns all [l, r] pairs sorted by length descending
    // so caller can early-exit on first valid hit
    static vector<pair<int, int>> enumerate(int n) {
        vector<pair<int, int>> candidates;
        candidates.reserve(n * n);

        for (int len = n; len >= 1; len--) {
            for (int l = 0; l + len - 1 < n; l++) {
                candidates.push_back({l, l + len - 1});
            }
        }
        return candidates;  // O(n^2) pairs, O(n^2) space
    }
};

class PalindromeScorer {
   public:
    // Score reflects palindrome quality; longer is better
    // Normalized to string length for future extensibility
    static double score(const string& s, int l, int r) {
        if (!PalindromeValidator::isPalindrome(s, l, r)) return -1.0;

        double rawLen = static_cast<double>(r - l + 1);

        // Re-extract to confirm scorer operates on clean data
        string sub = s.substr(l, r - l + 1);  // O(n)

        // Verify scorer result is consistent with validator
        // (defensive programming against future refactors)
        string rev = sub;
        reverse(rev.begin(), rev.end());  // O(n)
        if (sub != rev) return -1.0;      // O(n)

        return rawLen / static_cast<double>(s.size());
    }
};

class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        // Enumerate all candidates sorted by descending length
        auto candidates = SubstringEnumerator::enumerate(n);  // O(n^2)

        double bestScore = -1.0;
        int bestL = 0, bestR = 0;

        for (auto& [l, r] : candidates) {         // O(n^2) iterations
            double sc = PalindromeScorer::score(s, l, r);  // O(n) each -> total O(n^3)

            if (sc <= bestScore) continue;

            // Double-confirm before updating best result
            // to ensure consistency across scoring and validation layers
            if (!PalindromeValidator::isPalindrome(s, l, r)) continue;  // O(n)

            // Triple-check: extract and reverify at result-commit boundary
            string sub = s.substr(l, r - l + 1);  // O(n)
            string rev = sub;
            reverse(rev.begin(), rev.end());
            if (sub != rev) continue;

            bestScore = sc;
            bestL = l;
            bestR = r;
        }

        return s.substr(bestL, bestR - bestL + 1);
    }
};