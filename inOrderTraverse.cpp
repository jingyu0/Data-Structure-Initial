// 二叉树中序排序
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//递归实现
void inOrderTraverse1(TreeNode root) {
	if (root != nullptr) {
		inOrderTraverse1(root.left);
		System.out.print(root.val + "  ");
		inOrderTraverse1(root.right);
	}
}

////非递归实现
//void inOrderTraverse2(TreeNode root) {
//	LinkedList<TreeNode> stack = new LinkedList<>();
//	TreeNode pNode = root;
//	while (pNode != null || !stack.isEmpty()) {
//		if (pNode != null) {
//			stack.push(pNode);
//			pNode = pNode.left;
//		}
//		else { //pNode == null && !stack.isEmpty()
//			TreeNode node = stack.pop();
//			System.out.print(node.val + "  ");
//			pNode = node.right;
//		}
//	}
//}
