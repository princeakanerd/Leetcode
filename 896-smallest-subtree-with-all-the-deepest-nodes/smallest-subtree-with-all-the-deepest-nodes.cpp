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
public:
    int maxdepth = 0 ;
    TreeNode* res ;
    int f(TreeNode* root, int level){
        if(root == nullptr) return 0 ;
        int l = f(root -> left, level + 1), r = f(root ->right, level + 1);
        maxdepth = max(level, maxdepth) ;
        return 1 + max(l, r) ;
    }
    bool fn(TreeNode* root, int level){
        bool l = false, r = false;
        if(root -> right){
            l = fn(root -> right, level + 1) ;
        }

        if(root -> left){
            r = fn(root -> left, level + 1) ;
        }
        
        if(l && r && l == r) res = root ;
        if(level == maxdepth) {
            res = root ;
            return true ;
        }
        return l || r;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        f(root, 1) ;
        fn(root, 1);
        return res ;
    }
};