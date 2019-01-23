#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//struct BinaryTreeNode
//{
//	struct BinTreeNode* _Left;   // 指向当前节点左孩子
//	struct BinTreeNode* _Right; // 指向当前节点右孩子
//	BTDataType _data; // 当前节点值域 
//};
//typedef char BTDataType;
//
//typedef struct BinaryTreeNode 
//{ 
//	BTDataType _data;    
//    struct BinaryTreeNode* _left;    
//    struct BinaryTreeNode* _right; 
//}BTNode;
//int BinaryTreeSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	return 1 + BinaryTreeSize(root->_left)
//		+ BinaryTreeSize(root->_right);
//}
//int BinaryTreeLevelKSize(BTNode* root, int k)
//{
//	if (k == 1)
//		return 1;
//	return BinaryTreeLevelKSize(root->_left, k - 1)
//		+ BinaryTreeLevelKSize(root->_right, k - 1);
//}
//int BTreeHeight(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	int leftHeight = BTreeHeight(root->_left);
//	int rightHeight = BTreeHeight(root->_right);
//	return leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
//}
//BTNode* BinTreeFind(BTNode* root, BTDataType x)
//{
//	if (root == NULL)
//		return 0;
//	if (root->_data == x)
//		return root;
//
//	BTNode*ret = BinTreeFind(root->_left, x);
//	if (ret)
//		return ret;
//
//	ret = BinTreeFind(root->_right, x);
//	if (ret)
//		return ret;
//
//	return NULL;
//}
//
//
//////前序排列
//struct TreeNode 
// {
//      int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };
//
//int treeSize(struct TreeNode* root)
//{
//	if (root == NULL)
//		return 0;
//	else
//		return treeSize(root->left) + treeSize(root->right) + 1;
//}
//
//void _preorderTraversal(struct TreeNode* root, int* preorder, int* pindex)
//{
//	if (root == NULL)
//		return;
//
//	printf("%d->[%d]\n", root->val, *pindex);
//	preorder[*pindex] = root->val;
//	++(*pindex);
//
//	_preorderTraversal(root->left, preorder, pindex);
//	_preorderTraversal(root->right, preorder, pindex);
//
//}
//int* preorderTraversal(struct TreeNode* root, int* returnSize)
//{
//	*returnSize = treeSize(root);
//	int* preorder = (int*)malloc(*returnSize * sizeof(int));
//	printf("%d",*returnSize);
//	int index = 0;
//	_preorderTraversal(root, preorder, &index);
//	system("pause");
//	return preorder;
//}
//int main()
//{
//	int a[5] = { 3, 4, 2, 5, 9 };
//	printf("先序遍历二叉排序数：\n");
//	int* preorderTraversal(root,returnSize);
//	system("pause");
//}
//
////中序排列
//int treeSize(struct TreeNode* root)
//{
//	if (root == NULL)
//		return 0;
//	else
//		return treeSize(root->left) + treeSize(root->right) + 1;
//}
//void _inorderTraversal(struct TreeNode* root, int * inorder, int* pindex)
//{
//	if (root == NULL)
//		return;
//
//	_inorderTraversal(root->left, inorder, pindex);
//	inorder[*pindex] = root->val;
//	(*pindex)++;
//	_inorderTraversal(root->right, inorder, pindex);
//}
//int* inorderTraversal(struct TreeNode* root, int* returnSize)
//{
//	*returnSize = treeSize(root);
//	int* inorder = (int*)malloc(*returnSize * sizeof(int));
//	int index = 0;
//	_inorderTraversal(root, inorder, &index);
//	return inorder;
//}
////后序排序
//int TreeSize(struct TreeNode* root)
//{
//	if (root == NULL)
//		return 0;
//	return TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//void _postorderTraversal(struct TreeNode* root, int* array, int* pindex)
//{
//	if (root == NULL)
//		return;
//	_postorderTraversal(root->left, array, pindex);
//	_postorderTraversal(root->right, array, pindex);
//	array[*pindex] = root->val;
//	(*pindex++);
//}
//int* postorderTraversal(struct TreeNode* root, int* returnSize) {
//	*returnSize = TreeSize(root);
//	int *array = (int*)malloc(*returnSize * sizeof(int));
//	int index = 0;
//	_postorderTraversal(root, array, &index);
//	return array;
//}
//
////判断两树是否相等（先序遍历）
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//	//一个为空，一个不为空
//	//两个都为空，两个都不为空
//	if (p == NULL&&q == NULL)
//		return true;
//	else if (p != NULL&&q != NULL)
//	{
//		return p->val == q->val
//			&&isSameTree(p->left, q->left)
//			&& isSameTree(p->right, q->right);
//	}
//	else
//	{
//		return false;
//	}
//}
//
////判断一棵树是否是另一棵树的子树
////判断两树是否相等（先序遍历）
////bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
////	//一个为空，一个不为空
////	//两个都为空，两个都不为空
////	if (p == NULL&&q == NULL)
////		return true;
////	else if (p != NULL&&q != NULL)
////	{
////		return p->val == q->val
////			&&isSameTree(p->left, q->left)
////			&& isSameTree(p->right, q->right);
////	}
////	else
////	{
////		return false;
////	}
////}
////struct TreeNode* FindNode(struct TreeNode* root, int val)
////{
////	if (root == NULL)
////		return NULL;
////
////	if (root->val == val)
////		return root;
////
////	struct TreeNode*leftsub = FindNode(root->left, val);
////	if (leftsub != NULL)
////		return leftsub;
////
////	struct TreeNode*rightsub = FindNode(root->right, val);
////	if (rightsub != NULL)
////		return rightsub;
////
////	return NULL;
////}
////bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
////	struct TreeNode* sub = FindNode(s, t->val);
////	if (sub != NULL)
////	{
////		return isSameTree(sub, t);
////	}
////	else
////	{
////		return false;
////	}
////}
//
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//	//一个为空，一个不为空
//	//两个都为空，两个都不为空
//	if (p == NULL&&q == NULL)
//		return true;
//	else if (p != NULL&&q != NULL)
//	{
//		return p->val == q->val
//			&&isSameTree(p->left, q->left)
//			&& isSameTree(p->right, q->right);
//	}
//	else
//	{
//		return false;
//	}
//}
//bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
//	if (s == NULL)
//		return false;
//
//	if (s->val == t->val)
//	{
//		if (isSameTree(s, t))
//			return true;
//	}
//
//	if (isSubtree(s->left, t))
//		return true;
//
//	if (isSubTree(s->right, t))
//		return true;
//
//	return false;
//}
//
////判断二叉树的最大深度
//int maxDepth(struct TreeNode* root) 
//{
//	if (root == NULL)
//		return 0;
//	int leftdepth = maxDepth(root->left) + 1;
//	int rightdepth = maxDepth(root->right) + 1;
//	return leftdepth>rightdepth ? leftdepth : rightdepth;
//}
//
////判断对称二叉树
//bool isSubTreeSymmetric(struct TreeNode* left, struct TreeNode*right)
//{
//	if (left == NULL&&right == NULL)
//		return true;
//	else if (left != NULL&&right != NULL)
//	{
//		return left->val == right->val
//			&&isSubTreeSymmetric(left->right, right->left)
//			&& isSubTreeSymmetric(left->left, right->right)
//	}
//	return false;
//}
//bool isSymmetric(struct TreeNode* root) {
//	if (root == NULL)
//		return true;
//	return isSubTreeSymmetric(root->left, root->right);
//}
//
//////平衡二叉树的判断
////int TreeHeight(struct TreeNode*root)
////{
////	if (root == NULL)
////		return 0;
////
////	int LeftHeight = TreeHeight(root->left);
////	int RightHeight = TreeHeight(root->right);
////
////	return LeftHeight > RightHeight ? LeftHeight+1 : RightHeight+1;
////}
////bool isBalanced(struct TreeNode*root)
////{
////	if (root == NULL)
////		return true;
////
////	int LeftHeight = TreeHeight(root->left);
////	int RightHeight = TreeHeight(root->right);
////
////	return abs(LeftHeight - RightHeight <= 1)
////		&& isBalanced(root->left)
////		&& isBalanced(root->right);
////}
////
////从上述n^2的时间复杂度优化到n的时间复杂度(需要多次研究体会）
//struct Result
//{
//	bool isBalance;
//	int height;
//};
//struct Result _isBalanced(struct TreeNode* root)
//{
//	struct Result ret;
//	ret.height = 0;
//	ret.isBalance = true;
//
//	if (root == NULL)
//		return ret;
//
//	struct Result lret;
//	lret = _isBalanced(root->left);
//	if (lret.isbalance == false)
//	{
//		return lret;
//	}
//
//	struct Result rret;
//	rret = _isBalanced(root->right);
//	if (rret.isbalance == false)
//	{
//		return rret;
//	}
//
//	ret.isbalance = abs(lret.height-rret.height)<=1;
//	ret.height = lret.height > rret.height ? lret.height + 1 : rret.height + 1;
//	return ret;
//}
//bool isBalanced(struct TreeNode* root)
//{
//	/*struct Result ret = _isBalanced(root);
//	return ret.isbalance;*/
//	return _isBalanced(root).isbalance;
//}
//二叉树的构建与遍历
#include<string.h>
#include<memory.h>

typedef char BTDataType;

typedef struct BinaryTreeNode 
{ 
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* CreatreTree(char* array, int* pIndex)
{
	if (array[*pIndex] == '#')
	{
		++(*pIndex);
		return NULL;
	}
		
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = array[*pIndex];
	++(*pIndex);

	root->_left = CreatreTree(array, pIndex);
	root->_right = CreatreTree(array, pIndex);
	 
	return root;
}

void Inorder(BTNode* root)
{
	if (root == NULL)  return;
	Inorder(root->_left);
	printf("%c ", root->_data);
	Inorder(root->_right);
}
void DestoryTree(BTNode* root)
{
	if (root == NULL)
		return;
	DestoryTree(root->_left);
	DestoryTree(root->_right);
	free(root);
	root = NULL;
}
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}
void LevelOrder(BTNode* root)
{

}

int main()
{
	char array[100]="abc##de#g##f###";
	//scanf("%s",array);
	//构建树
	int index = 0;
	BTNode* tree = CreatreTree(array, &index);
	Inorder(tree);

	printf("\n");
	DestoryTree(tree);
	tree = NULL;
	system("pause");

	return 0;
}
 
