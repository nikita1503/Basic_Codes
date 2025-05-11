 struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
void visitNode(TreeNode * node){
   // cout<<(node->val);
}

void inorderTraverlsalBST(TreeNode* root) {
    stack<TreeNode*>ancestors;
    TreeNode* curr = root;

    while(curr!=nullptr || ancestors.size()!=0){
        while(curr!=nullptr){
            ancestors.push(curr);
            curr=(curr->left);
        }
        curr = ancestors.top();ancestors.pop();

        visitNode(curr);

        curr=(curr->right);
    }
}


#Usage

Update function visitNode() to logic when a node is visited in order of inorder traversal

inorderTraverlsalBST(root);
