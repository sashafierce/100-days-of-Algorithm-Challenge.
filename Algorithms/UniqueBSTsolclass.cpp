
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> Trees;
        if(n == 0) return Trees;
        else return util(1 , n);
    }
    vector<TreeNode*> util(int start , int end) {
         vector<TreeNode*> Trees;
        if(start > end ) {  Trees.push_back(NULL); return Trees;}
        for(int i = start ; i <= end ; i++) {
            vector<TreeNode*> leftSubTrees = util(start , i-1 );
            vector<TreeNode*> rightSubTrees = util(i+1 ,end );
            int nl = leftSubTrees.size();
            int nr = rightSubTrees.size();
            for(int j = 0 ; j < nl ; j++) {

                TreeNode *l = leftSubTrees[j];
                for(int k = 0 ; k < nr ; k++) {
                    TreeNode* root = (TreeNode *)malloc(sizeof(TreeNode));
                    root->val = i;
                    root->left = l;
                    root->right = rightSubTrees[k];
                    Trees.push_back(root);
                }
            }
        }
        return Trees;

    }
};
