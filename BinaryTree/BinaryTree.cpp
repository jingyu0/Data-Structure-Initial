//二叉树基础面试题OJ
//1.
https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

int GetTreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	return GetTreeSize(root->left)
		+ GetTreeSize(root->right)
		+ 1;
}

void _preorderTraversal(struct TreeNode* root, int* array, int* pIndex)
{
	if (root == NULL)
		return;

	array[*pIndex] = root->val;
	++(*pIndex);
	_preorderTraversal(root->left, array, pIndex);
	_preorderTraversal(root->right, array, pIndex);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetTreeSize(root);
	int* array = (int*)malloc(*returnSize * sizeof(int));
	int index = 0;

	_preorderTraversal(root, array, &index);

	return array;
}

//2.
//https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int GetTreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return GetTreeSize(root->left) + GetTreeSize(root->right) + 1;
}

void _inorderTraversal(struct TreeNode* root, int* array, int* pIndex)
{
	if (root == NULL)
		return;

	_inorderTraversal(root->left, array, pIndex);

	array[*pIndex] = root->val;
	(*pIndex)++;

	_inorderTraversal(root->right, array, pIndex);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetTreeSize(root);
	int* array = (int*)malloc(*returnSize*sizeof(int));
	int index = 0;
	_inorderTraversal(root, array, &index);

	return array;
}

//3.
//https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

int GetTreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return GetTreeSize(root->left) + GetTreeSize(root->right) + 1;
}

void _postorderTraversal(struct TreeNode* root, int* array, int* pIndex)
{
	if (root == NULL)
		return;

	_postorderTraversal(root->left, array, pIndex);
	_postorderTraversal(root->right, array, pIndex);
	array[*pIndex] = root->val;
	(*pIndex)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetTreeSize(root);
	int* array = (int*)malloc(*returnSize*sizeof(int));
	int index = 0;
	_postorderTraversal(root, array, &index);

	return array;
}

//4.
//https://leetcode-cn.com/problems/same-tree/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	// 都为空
	if (p == NULL && q == NULL)
		return true;

	// 其中一个为空
	if (p == NULL || q == NULL)
		return false;

	return p->val == q->val
		&& isSameTree(p->left, q->left)
		&& isSameTree(p->right, q->right);
}

//5.
//https://leetcode-cn.com/problems/subtree-of-another-tree/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool isSameTree(struct TreeNode* t1, struct TreeNode* t2)
{
	if (t1 == NULL && t2 == NULL)
		return true;

	if (t1 == NULL || t2 == NULL)
		return false;

	return t1->val == t2->val
		&& isSameTree(t1->left, t2->left)
		&& isSameTree(t1->right, t2->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (t == NULL)
		return true;

	if (s == NULL)
		return false;

	if (s->val == t->val && isSameTree(s, t))
		return true;

	return isSubtree(s->left, t)
		|| isSubtree(s->right, t);
}

//6.
//https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

//7.
//https://leetcode-cn.com/problems/balanced-binary-tree/
// O(N^2)的算法
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int _maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;

	int leftDepth = _maxDepth(root->left);
	int rightDepth = _maxDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;

	int leftDepth = _maxDepth(root->left);
	int rightDepth = _maxDepth(root->right);
	return abs(leftDepth - rightDepth) < 2
		&& isBalanced(root->left)
		&& isBalanced(root->right);
}

// O(N)的算法
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool _isBalanced(struct TreeNode* root, int* pDepth) {
	if (root == NULL) {
		*pDepth = 0;
		return true;
	}

	int leftDepth = 0, rightDepth = 0;
	if (_isBalanced(root->left, &leftDepth)
		&& _isBalanced(root->right, &rightDepth)
		&& abs(leftDepth - rightDepth) < 2)
	{
		*pDepth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
		return true;
	}
	else
	{
		return false;
	}

}

bool isBalanced(struct TreeNode* root) {
	int depth = 0;
	return _isBalanced(root, &depth);
}

//8.
//https://leetcode-cn.com/problems/symmetric-tree/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool _isSymmetric(struct TreeNode* left, struct TreeNode* right) {
	if (left == NULL && right == NULL)
		return true;

	if (left == NULL || right == NULL)
		return false;

	return left->val == right->val
		&& _isSymmetric(left->left, right->right)
		&& _isSymmetric(left->right, right->left);
}



bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;

	return _isSymmetric(root->left, root->right);
}

//9.
//https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking

#include<stdio.h>
#include<malloc.h>
typedef struct BTNode
{
	struct BTNode* _left;
	struct BTNode* _right;
	char _data;
}BTNode;

BTNode* CreateTree(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		return NULL;
	}
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = str[*pi];
		++(*pi);
		root->_left = CreateTree(str, pi);
		++(*pi);
		root->_right = CreateTree(str, pi);
		return root;
	}
}

void InOrder(BTNode* root)
{
	if (root == NULL) return;

	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

int main()
{
	char str[100] = { 0 };
	scanf("%s", str);
	int i = 0;
	BTNode* tree = CreateTree(str, &i);
	InOrder(tree);
	return 0;
}

////////////////////////////////////////////////////////////////////////
//二叉树进阶面试题
//1.
https://leetcode-cn.com/problems/construct-string-from-binary-tree/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

char valuestr[30] = { 0 };
void _tree2str(struct TreeNode* t, char* str) {
	if (t == NULL)
		return;

	//_itoa(t->val, valuestr, 10);
	sprintf(valuestr, "%d", t->val);
	strcat(str, valuestr);

	if (t->left == NULL)
	{
		if (t->right == NULL)
			return;
		else
			strcat(str, "()");
	}
	else
	{
		strcat(str, "(");
		_tree2str(t->left, str);
		strcat(str, ")");
	}

	if (t->right == NULL)
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

//2.
//https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
	if (root == NULL)
		return NULL;

	int depth = maxDepth(root);
	int** levelArray = (int**)malloc(sizeof(int*)*depth);

	int maxLevelSize = 1000;//pow(2, depth-1);
	struct TreeNode** a1 = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*maxLevelSize);

	struct TreeNode** a2 = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*maxLevelSize);
	int a1Size = 0;
	int a2Size = 0;

	*returnSize = depth;
	*columnSizes = (int*)malloc(sizeof(int)*depth);

	if (root)
	{
		a1[0] = root;
		a1Size = 1;
	}

	int level = 0;
	while (level < depth)
	{
		levelArray[level] = malloc(sizeof(int)*a1Size);
		for (int i = 0; i < a1Size; ++i)
		{
			levelArray[level][i] = a1[i]->val;
		}
		(*columnSizes)[level] = a1Size;

		int k = 0;
		for (int j = 0; j < a1Size; ++j)
		{
			if (a1[j]->left)
				a2[k++] = a1[j]->left;

			if (a1[j]->right)
				a2[k++] = a1[j]->right;
		}
		a2Size = k;

		struct TreeNode** a = a1;
		a1 = a2;
		a2 = a;

		a1Size = a2Size;
		a2Size = 0;

		++level;
	}

	return levelArray;
}

//3.
//https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool FindNode(struct TreeNode* root, struct TreeNode* node) {
	if (root == NULL)
		return false;

	if (root == node)
		return true;

	return FindNode(root->left, node)
		|| FindNode(root->right, node);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if (root == NULL)
		return NULL;

	if (root == p || root == q)
		return root;

	bool pInLeft, pInRight, qInLeft, qInRight;
	if (FindNode(root->left, p)){
		pInLeft = true;
		pInRight = false;
	}
	else{
		pInRight = true;
		pInLeft = false;
	}

	if (FindNode(root->left, q)) {
		qInLeft = true;
		qInRight = false;
	}
	else {
		qInRight = true;
		qInLeft = false;
	}

	if (pInLeft && qInLeft){
		return lowestCommonAncestor(root->left, p, q);
	}
	else if (pInRight && qInRight){
		return lowestCommonAncestor(root->right, p, q);
	}
	else {
		return root;
	}
}

//4.
//https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	void _Convert(TreeNode* cur, TreeNode** pprev)
	{
		if (cur == NULL)
			return;
		_Convert(cur->left, pprev);

		// 中序走，当前节点的左指向前一个
		// 前一个节点的右指向当前节点
		cur->left = *pprev;
		if (*pprev)
			(*pprev)->right = cur;

		*pprev = cur;

		_Convert(cur->right, pprev);
	}

	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode* prev = NULL;
		_Convert(pRootOfTree, &prev);

		TreeNode* head = pRootOfTree;
		while (head && head->left)
		{
			head = head->left;
		}

		return head;
	}
};

//5.
//https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
struct TreeNode* _buildTree(int* prevorder, int* pindex, int* inorder, int inbegin, int inend)
{
	if (inbegin > inend)
		return NULL;

	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = prevorder[*pindex];

	int rootindex = inbegin;
	for (; rootindex <= inend; ++rootindex)
	{
		if (inorder[rootindex] == root->val)
			break;
	}

	if (inbegin <= rootindex - 1)
	{
		(*pindex)++;
		root->left = _buildTree(prevorder, pindex, inorder, inbegin, rootindex - 1);
	}
	else
	{
		root->left = NULL;
	}

	if (rootindex + 1 <= inend)
	{
		(*pindex)++;
		root->right = _buildTree(prevorder, pindex, inorder, rootindex + 1, inend);
	}
	else
	{
		root->right = NULL;
	}


	return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	int index = 0;
	return _buildTree(preorder, &index, inorder, 0, inorderSize - 1);
}

//6.
//类似第五题，注意构建时，先构建根，再构建右子树，再构建左子树的顺序
//https ://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

//7.第7 - 9题作业完成。代码参考二叉树实现。