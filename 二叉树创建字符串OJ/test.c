/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char valstr[30] = { 0 };
void _tree2str(struct TreeNode* t,char* str){
 if(t == NULL)
     return NULL;
 
    sprintf(valstr,"%d",t->val);
    strcat(str,valstr);
    //走到这里，根部分已转换完毕
    if(t->left == NULL)
    {
        if(t->right == NULL)
        {
            return;
        }
        else
        {
            strcat(str, "()");//当左边为空时，括号不能省略
        }
    }
    else//左边不为空
    {
        strcat(str, "(");
        _tree2str(t->left, str);
        strcat(str, ")");
    }
    //走到这里表示左子树已转换完
    if(t->right == NULL)
    {
        return;
    }
    else
    {
        strcat(str, "(");
        _tree2str(t->right, str);
        strcat(str, ")");
    }   
 }
 
char str[100000];
char* tree2str(struct TreeNode* t) {
     str[0] = '\0';
     _tree2str(t, str);
    
     return str;
}