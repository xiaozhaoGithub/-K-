#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x) { left = nullptr; right = nullptr; }
};
class Solution {
public:
    vector<vector<int> >ret;
    void pathHelper(TreeNode* root, vector<int>& ans, int& sum, int k)
    {
        if (!root)
            return;

        ans.push_back(root->val);
        sum += ans.back();
        if (sum == k)
            ret.push_back(ans);
        //结点返回，用完从容器中删除
        if (root->left)
        {
            pathHelper(root->left, ans, sum, k);
            sum -= ans.back();
            ans.pop_back();
        }
        if (root->right)
        {
            pathHelper(root->right, ans, sum, k);
            sum -= ans.back();
            ans.pop_back();
        }
    }
    //前序遍历
    void dfs(TreeNode* root, int K)
    {
        if (!root)
            return;
        vector<int> ans;
        int sum = 0;

        pathHelper(root, ans, sum, K);
        //从不同结点 开始
        dfs(root->left, K);
        dfs(root->right, K);
    }
    vector<vector<int> > searchPath(TreeNode* root, int K)
    {
        dfs(root, K);
        return ret;
    }

    TreeNode* createTree(TreeNode* root)
    {
        TreeNode* node2 = new TreeNode(4);
        TreeNode* node3 = new TreeNode(8);
        TreeNode* node4 = new TreeNode(11);
        TreeNode* node5 = new TreeNode(13);
        TreeNode* node6 = new TreeNode(4);
        TreeNode* node7 = new TreeNode(7);
        TreeNode* node8 = new TreeNode(2);
        TreeNode* node9 = new TreeNode(5);
        TreeNode* node10 = new TreeNode(1);
        TreeNode* node11 = new TreeNode(8);
        TreeNode* node12 = new TreeNode(7);
        TreeNode* node13 = new TreeNode(10);
        TreeNode* node14 = new TreeNode(6);

        root->left = node2; root->right = node3;
        node2->left = node4; node2->right = nullptr;
        node3->left = node5; node3->right = node6;
        node4->left = node7; node4->right = node8;
        node5->left = nullptr; node5->right = nullptr;
        node6->left = node9; node6->right = node10;
        node7->left = node11; node7->right = nullptr;
        node8->left = node12; node8->right = node13;
        node9->left = node14; node9->right = nullptr;
        node10->left = nullptr; node10->right = nullptr;
        node11->left = nullptr; node11->right = nullptr;
        node12->left = nullptr; node12->right = nullptr;
        node13->left = nullptr; node13->right = nullptr;
        node14->left = nullptr; node14->right = nullptr;
        return root;
    }

};
int main()
{
    Solution s;
    //1 建树
    TreeNode* root = new TreeNode(5);
    s.createTree(root);

    //2 求sum=35的路径
    vector<vector<int> >vv;
    vv = s.searchPath(root, 35);
    //3 输出结果
    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
            cout << vv[i][j] << " ";
        cout << endl;
    }
    return 0;
}