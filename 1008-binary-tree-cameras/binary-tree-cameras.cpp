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

    void dfs(TreeNode* node , TreeNode* par , set<TreeNode*> &st , int &cameras) {
        if(node != nullptr) {
            dfs(node->left , node , st , cameras) ;
            dfs(node->right , node , st , cameras) ;

            if((node->left && st.find(node->left) == st.end()) || (node->right && st.find(node->right) == st.end()) || (st.find(node) == st.end() && par == nullptr)){
                st.insert(node) ;
                if(node->left) st.insert(node->left) ;
                if(node->right)st.insert(node->right) ;
                if(par) st.insert(par) ;
                cameras ++ ;
            }
        }
    }

    int minCameraCover(TreeNode* root) {
        set<TreeNode*> covered ;
        int cameras = 0 ;
        dfs(root , nullptr ,covered , cameras) ;
        return cameras ;



        
    }
};