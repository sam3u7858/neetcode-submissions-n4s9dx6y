class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;

        // 顯式捕獲 (Explicit Capture)：只抓取需要的 k 和 result 的引用
        // 使用 auto 避免 std::function 的效能開銷
        auto dfs = [&k, &result](auto&& self, TreeNode* node) -> void {
            if (!node || result != -1) return;

            self(self, node->left); // 顯式地將自己傳入以達成遞迴

            if (--k == 0) {
                result = node->val;
                return;
            }

            self(self, node->right);
        };

        dfs(dfs, root);
        return result;
    }
};