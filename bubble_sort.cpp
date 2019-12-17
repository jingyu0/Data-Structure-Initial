/**
 * 功能:冒泡排序
 * @param a:数组
 * @param n:数组的大小
 * 边界条件:
 * 1) 判断数组是否有数据
 * 算法思路:
 * 1)外循环 for 需要 n 个数据 n 次冒泡
 * 2)内循环每次冒泡的比较次数，每冒泡比较次数都 -1
 * 3)冒泡优化
 */
var flag = false;
const bubblesort = (a) = >
{
    if (a.length < 1) return;
    for (let i = 0; i < a.length; i++){
		 for (let j = 0; j < a.length - 1 - i; j++){
			if (a[j] >= a[j + 1])
			{
				 let temp = a[j];
				 a[j] = a[j + 1];
				 a[j + 1] = temp;
				 flag = true;
			}
		}
	if (!flag)
	{
		 break;
	}
 }
}