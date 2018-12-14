/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* _buildTree(int* postorder,int* pindex,int* inorder,int begin,int end)
{
    if(begin>end)
    {
        return NULL;
    }
    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=postorder[*pindex];
    int rootindex=begin;
    for(rootindex=begin;rootindex<=end;rootindex++)
    {
        if(inorder[rootindex]==root->val)
            break;
    }
     //构建右子树  
    (*pindex)--;
       root->right=_buildTree(postorder,pindex,inorder,rootindex+1,end);
    //构建左子树
       root->left=_buildTree(postorder,pindex,inorder,begin,rootindex-1);
      
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int index=postorderSize-1;
    return _buildTree(postorder,&index,inorder,0,inorderSize-1);
}