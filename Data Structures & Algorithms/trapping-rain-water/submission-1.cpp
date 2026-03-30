class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefixMax;
        vector<int> suffixMax;
        suffixMax.assign(height.size(), 0);

        int premax = 0; // Height min = 0;
        int sufmax = 0; // Height min = 0;
    
        //Build Prefix max
        for(int i=0; i<height.size(); i++){
            premax = max(premax, height[i]);
            prefixMax.push_back(premax);
        }
        //Build Surfix max:
        for(int i = height.size()-1; i>=0; i--){
            sufmax = max(sufmax, height[i]);
            suffixMax[i] = sufmax;
        }
        // Calculate based on suffix and prefix max value:
        int volumn = 0;
        for(int i=0; i<height.size(); i++){
            volumn += min(prefixMax[i], suffixMax[i]) - height[i];
        }
        return volumn;

    }
};

// 最初想法:這個問題裡
// 我們需要找到多組[a,b]圍成面積使得  sum(ln * min(h[a] - h[b]) - (中間高度))最大
// 後面發現這個可能會需要 O(n^2) 去確認位置可以圍到的最大範圍
// 
// 後面看 Hint 發現可以透過 min (Prefix Max 和 Suffix Max) 減去自己的高度
// 來得到"我這格"可以存的水量
// 同樣是類似貪婪的策略加上 Prefix, Surfix 的特性來解決，只能說不愧是 Hard 
// 比較難想到有效方法，且比較多個概念上 Tricky
