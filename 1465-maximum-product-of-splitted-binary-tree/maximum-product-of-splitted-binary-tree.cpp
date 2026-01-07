/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    const int mod = 1e9 + 7 ;
public:
    long long res = 0 ;
    int dfs(TreeNode* root, int total){
        if(root == nullptr) return 0 ;
        
        int val = root -> val + dfs(root -> right, total) + dfs(root -> left, total) ;
        if(total != -1){
            res = max(res, 1LL * val * (total - val)) ;
        }
        return val ;
    }
    int maxProduct(TreeNode* root) {
        int total = -1 ;
        total = dfs(root, total) ;
        dfs(root, total) ;
        return res % mod;

        

        
    }
};