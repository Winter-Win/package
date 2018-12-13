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
    //�ߵ������������ת�����
    if(t->left == NULL)
    {
        if(t->right == NULL)
        {
            return;
        }
        else
        {
            strcat(str, "()");//�����Ϊ��ʱ�����Ų���ʡ��
        }
    }
    else//��߲�Ϊ��
    {
        strcat(str, "(");
        _tree2str(t->left, str);
        strcat(str, ")");
    }
    //�ߵ������ʾ��������ת����
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