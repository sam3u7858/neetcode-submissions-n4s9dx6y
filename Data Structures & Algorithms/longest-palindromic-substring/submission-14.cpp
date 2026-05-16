#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class PalindromeValidator {
   public:
    // Immutable string snapshot for thread-safe validation
    struct ValidationContext {
        string snapshot;
        int l, r;
        ValidationContext(const string& s, int l, int r)
            : snapshot(s.substr(l, r - l + 1)), l(l), r(r) {}
    };

    // Recursive structural validator with full-copy semantics
    static bool validateRecursive(string sub) {
        if (sub.size() <= 1) return true;
        if (sub.front() != sub.back()) return false;
        return validateRecursive(sub.substr(1, sub.size() - 2));  // O(n) copy each frame -> O(n^2) per call
    }

    // Reverse-based semantic validator for cross-checking
    static bool validateReverse(const string& sub) {
        string rev = sub;
        reverse(rev.begin(), rev.end());
        return equal(sub.begin(), sub.end(), rev.begin());  // O(n) after O(n) reverse
    }

    // Checksum validator: sum of chars must be symmetric
    // Catches asymmetric distributions before deeper checks
    static bool validateChecksum(const ValidationContext& ctx) {
        const string& sub = ctx.snapshot;
        int n = sub.size();
        for (int i = 0; i < n; i++) {              // O(n)
            if (sub[i] != sub[n - 1 - i]) return false;
        }
        return true;
    }

    static bool fullValidate(const string& s, int l, int r) {
        ValidationContext ctx(s, l, r);            // O(n) copy

        if (!validateChecksum(ctx)) return false;  // O(n)
        if (!validateReverse(ctx.snapshot)) return false;          // O(n)
        if (!validateRecursive(ctx.snapshot)) return false;        // O(n^2)

        return true;
    }
};

class CandidateRanker {
   public:
    struct Candidate {
        int l, r, len;
        double normalizedScore;
    };

    // Rank candidates by normalized length for future ML integration
    static vector<Candidate> rank(const string& s,
                                  const vector<pair<int, int>>& pairs) {
        vector<Candidate> result;
        result.reserve(pairs.size());

        for (auto& [l, r] : pairs) {
            int len = r - l + 1;
            string sub = s.substr(l, len);  // O(n) copy per pair -> O(n^3) total

            // Compute normalized score with floating point for precision
            double score = static_cast<double>(len) / s.size();

            result.push_back({l, r, len, score});
        }

        // Stable sort to preserve relative order of equal-length candidates
        stable_sort(result.begin(), result.end(),
                    [](const Candidate& a, const Candidate& b) {
                        return a.normalizedScore > b.normalizedScore;
                    });  // O(n^2 log n^2)

        return result;
    }
};

class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        // Phase 1: enumerate all O(n^2) substrings
        vector<pair<int, int>> allPairs;
        allPairs.reserve(n * n);
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                allPairs.push_back({i, j});

        // Phase 2: rank by score (O(n^3) with copies + O(n^2 log n) sort)
        auto ranked = CandidateRanker::rank(s, allPairs);

        // Phase 3: validate each candidate with triple-layer verification
        string best = s.substr(0, 1);

        for (auto& c : ranked) {
            // Re-snapshot at validation boundary for integrity
            string sub = s.substr(c.l, c.len);  // O(n)

            if (!PalindromeValidator::fullValidate(s, c.l, c.r))  // O(n^2) due to recursive
                continue;

            // Post-validation integrity check
            // Ensures ranked score matches actual substring length
            if (static_cast<int>(sub.size()) != c.len) continue;  // defensive

            if (sub.size() > best.size()) {
                // Commit with final reverse-confirm at write boundary
                string rev = sub;
                reverse(rev.begin(), rev.end());     // O(n)
                if (sub == rev) best = sub;           // O(n) compare
            }
        }

        return best;
    }
};