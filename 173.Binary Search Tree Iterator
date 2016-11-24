/* ************************************************************* * 
 *      Annie Wang 2016.11.23                                    *
 * Idea: a cursor moved along the dfs route on a BST, each time  *
 *      give the smallest, move the cursor to the next smallest. *
 * Remark: push to NULL then come back same a lot of time on     *
 *      finding ->right, check and change. Got better coding     *
 *      style.                                                   *
 * ************************************************************* *
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    // define the variables sharing between BSTIterator(). 
    //   hasNext(), and next()
    stack<TreeNode *> myStack;
    TreeNode * myCursor;
public:
    BSTIterator(TreeNode *root) {
        // move myCursor from root to the smallest node's 
        myCursor = root;
        while(myCursor){
            myStack.push(myCursor);
            myCursor = myCursor->left;
        }
        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        
        myCursor = myStack.top();
        myStack.pop();
        // record the value
        int opt = myCursor->val;
        // move to next
        myCursor = myCursor->right;
        while(myCursor){
            myStack.push(myCursor);
            myCursor = myCursor->left;
        }
        return opt;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
