//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{ 3, 4, 5, 1, 2 }为{ 1, 2, 3, 4, 5 }的一个旋转，该数组的最小值为1。
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

//数组问题，本质其实是一个求最小值问题
//方法一：理论上，遍历一次即可，但是我们可以根据题面使用稍微高效且更简单一点的做法
//按照要求，要么是一个非递减排序的数组（最小值在最开始），要么是一个旋转(最小值在中间某个地方)
//而且，旋转之后有个特征，就是在遍历的时候，原始数组是非递减的，旋转之后，就有可能出现递减，引起
//递减的数字，就是最小值

//方法二：采用二分查找的方式，进行定位
//定义首尾下标，因为是非递减数组旋转，所以旋转最后可以看做成两部分，前半部分整体非递减，后半部分
//整体非递减，前半部分整体大于后半部分。
//所以，我们假设如下定义，left指向最左侧，right指向最右侧，mid为二分之后的中间位置。
//则，a[mid] > a[left],说明mid位置在原数组前半部分，进一步说明，目标最小值，在mid的右侧，让
//left = mid
//a[mid] < a[left], 说明mid位置在原数组后半部分，进一步说明，目标最小值，在mid的左侧，让
//right = mid
//这个过程，会让[left, right]区间缩小
//这个过程中，left永远在原数组前半部分，right永远在原数组的后半部分，而范围会一直缩小
//当left和right相邻时，right指向的位置，就是最小元素的位置
//但是，因为题目说的是非递减，也就意味着数据允许重复，因为有重复发，就可能会有a[left] ==
//a[mid] == a[right]的情况，我们就无法判定数据在mid左侧还是右侧。（注意，只要有两者不相等，我
//们就能判定应该如何缩小范围）


//方法一
import java.util.ArrayList;
public class Solution {
	public int minNumberInRotateArray(int[] array) {
		if (array == null || array.length == 0){
			return 0;
		}
		for (int i = 0; i < array.length - 1; i++){
			if (array[i] > array[i + 1]){
				return array[i + 1];
			}
		}
		6. 核心考点：空间复杂度，fib理解，剪枝重复计算
			大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0
			项为0，第1项是1）。
			n <= 39
			解析：
			return array[0];
	}
}

//方法二
import java.util.ArrayList;
public class Solution {
	public int minNumberInRotateArray(int[] array) {
		if (array == null || array.length == 0){
			return 0;
		}
		int left = 0;
		int right = array.length - 1;
		int mid = 0;
		while (array[left] >= array[right]){
			if (right - left == 1){
				mid = right;
				break;
			}
			mid = left + ((right - left) >> 1);
			if (array[left] == array[right] && array[mid] == array[left]){ //1
				int result = array[left];
				for (int i = left + 1; i < right; i++){
					if (array[i] < result){
						result = array[i];
					}
				}
				return result;
			}
			if (array[mid] >= array[left]){
				//说明mid在原数组的前半部分
				//如果array[mid] == array[left]， 上面1处的条件不满足且array[left]
				>= array[right]，则，array[mid] > array[right]
					left = mid;
			}
			else{
				right = mid;
			}
		}
		return array[mid];
	}
}