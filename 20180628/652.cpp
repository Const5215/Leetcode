/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Subtree {
    int v;
    int lid;
    int rid;
    Subtree(int x, int l, int r) : v(x), lid(l), rid(r) {}
    bool operator == (const Subtree &r) const {
        return v==r.v && lid==r.lid && rid==r.rid;
    }
};
struct Hasher {
    size_t operator() (const Subtree& k) const{
        size_t key=k.v;
        return (key<<32)+(k.lid^k.rid);
    }
};   
struct Comp {
    bool operator() (const Subtree& l, const Subtree& r) const {
        return l.v==r.v && l.lid==r.lid && l.rid==r.rid;
    }
};

class Solution {
public:     
    unordered_map<Subtree, int, Hasher, Comp> fmap;
    vector<int> count;
    vector<TreeNode*> rmap;
    int PostTraverse(TreeNode* root) {
        if (root==NULL)
            return 0;
        int lid = PostTraverse(root->left);
        int rid = PostTraverse(root->right);
        Subtree st(root->val, lid, rid);
        if (fmap.find(st)==fmap.end()) {
            int newid = count.size();
            fmap[st] = newid;
            count.push_back(1);
            rmap.push_back(root);
        } else {
            count[fmap[st]]++;
        }
        return fmap[st];
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {       
        fmap[Subtree(INT_MAX,INT_MAX,INT_MAX)] = 0;
        count.push_back(1);
        rmap.push_back(NULL);
        PostTraverse(root);
        vector<TreeNode*> res;
        for (int i=0; i<count.size(); ++i)
            if (count[i]>1)
                res.push_back(rmap[i]);
        return res;   
    }
};
