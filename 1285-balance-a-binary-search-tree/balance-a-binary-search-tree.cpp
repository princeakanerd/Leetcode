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
    vector<int> temp ;
    void f(TreeNode* root){
        if(!root) return ;

        f(root -> left) ;
        temp.push_back(root -> val) ;
        f(root -> right) ;
    }

    TreeNode* fn(int i, int j){
        if(i > j) return nullptr ;

        int mid = (i + j) / 2;

        TreeNode* node = new TreeNode(temp[mid]) ;

        node-> left = fn(i, mid - 1) ;
        node -> right = fn(mid + 1, j) ;

        return node ;
    }
public:

    TreeNode* balanceBST(TreeNode* root) {
        
        f(root) ;
        int n = temp.size() ;
        return fn(0, n - 1) ;


        
    }
};