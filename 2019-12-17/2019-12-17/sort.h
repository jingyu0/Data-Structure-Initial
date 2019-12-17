#pragma once
#include <stdio.h>
//插入排序
void InsertSort(int *a, int n)
{
	//单趟排序
	//5  2  4  6  1  3
	for (int i = 0; i < n - 1;i++)
		//排序截至到数组结尾前一个值，
		//如果顺序不对，交换；顺序正确则不做修改。
	{
		//a[end+1] 插入a[0]---a[end]有序区间
		int end = i;
		int temp = a[end + 1];
		//即将插入的值
		while (end >= 0)
		{
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				//当需要插入的值大于其后面的值
				//或者没有比他大的数时，跳出循环
				break;
			}
		}
		a[end + 1] = temp;
	}
}

void Swap(int* p1,int* p2)
{
	int x = *p1;
	*p1 = *p2;
	*p2 = x;
}

//选择排序
void SelectSort(int* a, int n)
{
	//7 4 5 9 8 2 1
	int begin = 0;
	int end = n - 1;
	int min_index, max_index;
	while (begin <= end)
	{
		//将小的数和第一个数进行交换；
		//大的数字和最后一个进行交换；并不是覆盖
		min_index = max_index = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] < a[min_index])
			{
				min_index = i;
			}
			if (a[i]>a[max_index])
			{
				max_index = i;
			}
		}
		Swap(&a[begin], &a[min_index]);

		//需要注意容易出bug的地方
		//特例:如果是 9 5 7 8 6 1 3 4 2 会出错
		//加个特例情况
		if (max_index == begin)
			//当最大值max在开始位置时，就会被最小值先换走，
			//此时需要更新max值的下标，max_index = min_index;
		{
			max_index = min_index;
		}
		Swap(&a[end], &a[max_index]);

		++begin;
		--end;
	}
}

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
		//当孩子大于等于n时，就不存在了
	{
		if (child + 1 < n &&a[child + 1] > a[child])
			//如果右孩子存在  且  右孩子大于左孩子
		{
			++child;
		}
		//此时child指向的是孩子中大的那个

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//升序
void HeapSort(int*a, int n)
{
	//建大堆
	//2^20=100万；2^19=50万；2^17=12.5万  所以10万大概是16和17之间
	//使用堆排序10万个数据只需要16、17次，与10万次之间的差距就比较大了
	for (int i = (n - 2) / 2; i >= 0; --i)
		//从倒数第一个非类节点开始调整
	{
		AdjustDown(a, n, i);
	}
	//选数排序
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//冒泡排序
void BubbleSort(int* a, int n)
{
	//单趟排序
	int end = n;
	while (end > 0)
	{
		for (int i = 1; i < end; ++i)
		{
			//从头开始前后两个索引，进行比较，
			//如果后面的值大于前面的值，进行交换，保持升序
			if (a[i - 1]>a[i])
			{
				Swap(&a[i - 1], &a[i]);
			}
		}
		--end;
		//比较结束的值一直在变
	}
}

//法一
//不断划分小区间递归进行快排思想
//49 38 65 97 76 13 27 49
//以右边值为key，先动左边；左边做key，先动右边
//以右边值为key，左边值停会停在比key的≥值，交换没有问题；但反之，会停在小的值上，交换不合适
//先动那边决定了数字的升降序走向

//第一次排序：49   38  27 13  49  97  65  76
//第二次排序：49   38  27 13  49  65  76  97
int PartSort1(int *a, int left, int right)
{
	int key = a[right];
	int keyindex = right;
	while (left < right)
	{
		//left找比key大的值；right找比key小的值
		while (left<right && a[left] <= key)
		{
			++left;
		}

		while (left<right && a[right] >= key)
		{
			--right;
		}
		if (left < right)
		{
			Swap(&a[left], &a[right]);
			++left;//left找大
			--right;//right找小
		}
	}
	Swap(&a[left], &a[keyindex]);
	return left;
}
  
//法二：挖坑法
int PartSort2(int *a, int left, int right)
{
	int key = a[right];
	while (left < right)
	{
		//左边找大，放到右边的坑
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[right] = a[left];
		//右边找小，放到左边的坑
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[left] = a[right];
	}
	a[left] = key;
	return left;
}

//法三:三数取中法
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left]>a[right])
			return left;
		else
			return right;
	}
	else //a[left] > a[mid]
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
}

int PartSort3(int *a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);
	int key = a[right];
	while (left < right)
	{
		//左边找大，放到右边的坑
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[right] = a[left];
		//右边找小，放到左边的坑
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[left] = a[right];
	}
	a[left] = key;
	return left;
}

//快排单趟时间复杂度：O（N）
//快排的时间复杂度：N*logn
//计算方法：N个节点，二叉树高度(递归次数)为log n.
void QuickSort(int*a, int left,int right)
{
	if (left >= right)
	{
		return;
	}
	if (right - left+1 > 10)
	{
		//大于10的时候选择，递归快排求解
		int keyindex = PartSort3(a, left, right);
		//[left, keyindex-1] key [keyindex+1, right]
		QuickSort(a, left, keyindex - 1);
		QuickSort(a, keyindex + 1, right);
	}
	else
	{
		//优化准则：小区间不用递归方法求解，选用插入方法提高效率
		InsertSort(a+left,right-left+1);
	}
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void TestInsertSort()
{
	int a[] = {2,5,1,8,6,9,3,4,7};
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestSelectSort()
{
	int a[] = { 9,5,7,8,6,1,3,4,2};
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestHeapSort()
{
	int a[] = { 9, 5, 7, 8, 6, 1, 3, 4, 2 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestQuickSort()
{
	int a[] = { 9, 5, 7, 8, 6, 1, 3, 4, 2 };
	QuickSort(a, 0, sizeof(a) / sizeof(int)-1);
	PrintArray(a, sizeof(a) / sizeof(int));
}