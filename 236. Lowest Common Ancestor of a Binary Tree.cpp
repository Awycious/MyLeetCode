/* **************************************************************************************
 *          Annie Wang 2016.11.18                                                       *
 * Idea: combine the searching results from the two subtrees                            *
 * Remark: simpler structure is more readable and can be more efficient                 *
 *                                                                                      *
 * **************************************************************************************
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /* first trial dfs, using stack, got correct answer but Runtime Error,
    but stack is so convient for dfs */
 /*
class Solution {
private:
    bool mySearch(TreeNode* root, TreeNode* p){
        // input root and a TreeNode p, return True if p is in the tree
        // false otherwise, where p != NULL
        return (root != NULL 
                && (root == p || mySearch(root->left, p) || mySearch(root->right, p)));
        }
        
    
    TreeNode* LCA(stack<TreeNode *> myStack, TreeNode* q){
        // when the first TreeNode was found by dfs, use LCA to continue dfs 
        // and locate LCA
        cout << "I'm looking " << myStack.top()->val << " and " << q->val << endl;
        TreeNode *p = myStack.top();
        if(mySearch(p, q)){ // q is descendant of p
            return p;
        } else { // q is not descendant of p
            myStack.pop(); // pop p
            while( !(myStack.empty() || mySearch(myStack.top()->right, q))){
                myStack.pop();
            }
            cout<< "I'm returning something!\n";
            return myStack.top();
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode *> myStack;
        myStack.push(root);
        while(myStack.top() != p && myStack.top() != q){
            if(myStack.top()->left != NULL){
                myStack.push(myStack.top()->left);
            }
            else if(myStack.top()->left != NULL){
                myStack.push(myStack.top()->right);
            }
            else{ // the top is a leaf
                TreeNode * leaf = myStack.top();
                myStack.pop();
                while(!myStack.empty() && leaf == myStack.top()->right){
                    // this is a right leaf => this node has been finished
                    // go to the parent's right
                    leaf = myStack.top();
                    myStack.pop();
                }
                if(myStack.empty()) cout << "Error!!!!! TreeNode not exists\n";
                else myStack.push(myStack.top()->right);
                
            }
        }
        if(myStack.top() == p){
            return LCA(myStack, q);
        } else {
            return LCA(myStack, p);
        }
    }
};
*/
/* 2nd trial, give up stack, use recursion, same complexity and space, but clearer 
    structure and less risks */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q) return NULL;
        if(root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(!l && !r) return NULL; // not found p nor q 
        else if(l && r && l != r) return root; // p and q are found respectively
        else if(l) return l; // all in left
        else if(r) return r; // all in right
        else{
            cout << "Input ERROR!\n";
            return NULL;
        }
        
    }
};
