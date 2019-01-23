//#include<stdio.h>
//
////常见排序算法（插入排序（直接插入排序，希尔排序），选择排序（选择排序，堆排序)，
////               交换排序(冒泡排序，快速排序），归并排序）
////插入排序
//void InsertSort(int *a, int n)
//{
//	int end = a[0];
//	int key = end + 1;
//	
//	if (key > end)
//   
//
//}
////前后指针法
//void Swap(int *x, int*y)
//{
//	int *temp;
//	temp = x;
//	x = y;
//	y = temp;
//}
//int PartSort3(int *a, int begin, int end)
//{
//	int key = begin;
//	int prev = begin;
//	int cur = begin + 1;
//	while (cur <= end)
//	{
//		if (a[cur] < a[key] && ++prev != cur)
//			Swap(&a[cur], &a[++prev]);
//
//			++cur;
//	}
//	Swap(&a[key], &a[prev]);
//	return prev;
//}
//void QuickSort(int *a, int left, int right)
//{
//	if (left >= right)
//		return;
//	//[left,div-1][div+1,right]
//	int div = PartSort3(a, left, right);
//	QuickSort(a, left, div - 1);
//	QuickSort(a, div + 1, right);
//}
//////小区间优化
////void QuickSortOp(int *a, int left, int right)
////{
////	if (left >= right)
////		return;
////	//[left,div-1][div+1,right]
////	if (right - left > 10)
////	{
////		int div = PartSort3(a, left, right);
////		QuickSort(a, left, div - 1);
////		QuickSort(a, div + 1, right);
////	}
////	else
////	{
////		InsertSort(a + left, right - left + 1);
////	}
////}
////非递归快速排序
////运用栈来实现。
//int PrintArray(int *a, int end)
//{
//	int 
//	if ()
//}
//void TestQuickSort()
//{
//	int a[] = { 9, 2, 1, 5, 4, 3, 6, 8, 7, 5 };
//	QuickSort(a, 0, sizeof(a) / sizeof(int)-1);
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
//int main()
//{
//	TestQuickSort;
//	return 0;
//}