//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
//所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。//解析：
//解题思路：
//这道题原题是不需要保证奇偶位置不变的。
//现在新增了需求，解决方法也比较多，我们用较优方式解决一下，借鉴一下插入排序的思想

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int k = 0;
		for (int i = 0; i < array.size(); ++i){
			if (array[i] & 1){ //从左向右，每次遇到的，都是最前面的奇数，一定将来要被放在k
				下标处
					int temp = array[i]; //现将当前奇数保存起来
				int j = i;
				while (j > k){ //将该奇数之前的内容(偶数序列)，整体后移一个位置
					array[j] = array[j - 1];
					j--;
				}
				array[k++] = temp; //将奇数保存在它将来改在的位置，因为我们是从左往右放
				的，没有跨越奇数，所以一定是相对位置不变的
			}
		}
	}
};public class Solution {
	public void reOrderArray(int[] array) {
		int k = 0;
		for (int i = 0; i < array.length; i++){
			if ((array[i] & 1) == 1){
				int temp = array[i];
				int j = i;
				while (j > k){
					array[j] = array[j - 1];
					j--;
				}
				array[k++] = temp;
			}
		}
	}
}