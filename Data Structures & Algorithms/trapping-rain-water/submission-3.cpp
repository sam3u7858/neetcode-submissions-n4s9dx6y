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

// 也可以用雙指標法得到更好的空間效能 O(n)
// 這個做法同樣是檢查"每一格"能存的最大水量
// 並且利用了一個有趣的特性: 每一格能存的最大水量是min(h[l], h[r])
// 所以當兩邊等高或某一邊比較高的時候，就可以先把短邊當成"目前這格能裝的最大水量的決定因素
// 再扣掉自己的體積即可得到答案

class AlterSolution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int volume = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                volume += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                volume += rightMax - height[right];
                right--;
            }
        }
        return volume;
    }
};


