//With Space

class Solution {
public:
    void solve(TreeNode* root,vector<int>&v)
    {
        if(root)
        {
            solve(root->left,v);
            v.push_back(root->val);
            solve(root->right,v);
        }
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>v;
        solve(root,v);
        int m = INT_MAX;
        for(int i=0;i<v.size()-1;i++)
        {
            m = min(m,abs(v[i+1]-v[i]));
        }
        return m;
    }
}

//without Space

class Solution {
public:
    int s=INT_MAX;
    int m;
    int x=INT_MAX;
    int minDiffInBST(TreeNode* root) {
        if(!root)
            return 0;
        diff(root);
        return s;
    }
    void diff(TreeNode* root)
    {
        if(!root)
            return;
        diff(root->left);
        m=abs(x-root->val);
        s=min(m,s);
        x=root->val;
        diff(root->right);
        
    }
};
