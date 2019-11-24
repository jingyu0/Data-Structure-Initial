https://leetcode-cn.com/problems/binary-tree-level-order-traversal/submissions/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodeQue;
        queue<int> levelQue;

        if(root != nullptr)
        {
            nodeQue.push(root);
            levelQue.push(0);
        }

        int curLevel = -1;
        vector<vector<int>> vv;
        while(!nodeQue.empty())
        {
            TreeNode* node = nodeQue.front();
            nodeQue.pop();
            int level = levelQue.front();
            levelQue.pop();
            if(level > curLevel)
            {
                vv.push_back(vector<int>());
                curLevel = level;
            }

            vv[level].push_back(node->val);
            if(node->left)
            {
                nodeQue.push(node->left);
                levelQue.push(level+1);
            }

            if(node->right)
            {
                nodeQue.push(node->right);
                levelQue.push(level+1);
            }
        }

        return vv;
    }
};


https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
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
    bool Find(TreeNode* root, TreeNode* x)
    {
        if(root == nullptr)
            return false;

        if(root == x)
            return true;

        if(Find(root->left, x))
            return true;
        
        if(Find(root->right, x))
            return true;
        
        return false;
    }

    // 时间复杂度：O(N*N) 尝试优化一个O(N)的版本出来
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)
            return root;

        bool ispInLeft = Find(root->left, p);
        bool ispInRight = !ispInLeft;
        bool isqInLeft = Find(root->left, q);
        bool isqInRight = !isqInLeft;

        if((ispInLeft && isqInRight) || (ispInRight&&isqInLeft))
        {
            return root;
        }
        else if(isqInLeft && ispInLeft)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};

https://leetcode-cn.com/problems/construct-string-from-binary-tree/
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
    void _tree2str(TreeNode* t, string& str) {
        if(t == nullptr)
            return;
        
        str += to_string(t->val);
        if(t->left != nullptr || t->right != nullptr)
        {
            str += '(';
            _tree2str(t->left, str);
            str += ')';
        }

        if(t->right != nullptr)
        {
            str += '(';
            _tree2str(t->right, str);
            str += ')';
        }
    }

    string tree2str(TreeNode* t) {
        string str;
        _tree2str(t, str);
        return str;
    }

    /*string tree2str(TreeNode* t) {
        if(t == nullptr)
            return "";

        string str = std::to_string(t->val);

        if(t->left != nullptr)
        {
            str += '(';
            str += tree2str(t->left);
            str += ')';
        }
        else if(t->right != nullptr)
        {
            str += "()";
        }
        
        if(t->right != nullptr)
        {
            str += '(';
            str += tree2str(t->right);
            str += ')';
        }
        
        return str;
    }
    */
};


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
	void _tree2str(TreeNode* t, string& str) {
		if (t == nullptr)
			return;

		str += to_string(t->val);
		if (t->left != nullptr || t->right != nullptr)
		{
			str += '(';
			_tree2str(t->left, str);
			str += ')';
		}

		if (t->right != nullptr)
		{
			str += '(';
			_tree2str(t->right, str);
			str += ')';
		}
	}

	string tree2str(TreeNode* t) {
		string str;
		_tree2str(t, str);
		return str;
	}

	/*string tree2str(TreeNode* t) {
	if(t == nullptr)
	return "";

	string str = std::to_string(t->val);

	if(t->left != nullptr)
	{
	str += '(';
	str += tree2str(t->left);
	str += ')';
	}
	else if(t->right != nullptr)
	{
	str += "()";
	}

	if(t->right != nullptr)
	{
	str += '(';
	str += tree2str(t->right);
	str += ')';
	}

	return str;
	}
	*/
};

