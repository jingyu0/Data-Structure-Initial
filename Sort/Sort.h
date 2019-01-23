#pragma once
#include<time.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
void PrintArray(int *a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void InsertSort(int *a, int n)
{
	for (int i = 0; i< n - 1; ++i)
	{
		//将[end+1]插入到有序区间[0-n-1]
		int end =i ;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
//希尔排序   缩小增量法
void ShellSort(int *a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//保证最后一趟为一
		for (int i = 0; i <= n - gap - 1; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void TestShellSort()
{
	int a[] = { 9, 2, 1, 5, 4, 3, 6, 8, 7, 5 };
 //	InsertSort(a, sizeof(a) / sizeof(int));
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
//归并排序
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	if (end - begin <= 20)
	{
		InsertSort(a + begin, end - begin + 1);
		return;
	}
	int mid = begin + ((end - begin) >> 1);

	//子问题：对[begin,mid-1][mid,end]排序
	_MergeSort(a, begin, mid - 1, tmp);
	_MergeSort(a, mid, end, tmp);

	//归并[begin,mid-1] [mid,end]
	int begin1 = begin, end1 = mid-1;
	int begin2 = mid, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//归并结果拷回原数组
	index = begin;
	while (begin <= end)
	{
		a[index++] = tmp[begin++];
	}
}
//计数排序
//通过统计数据的个数进行排序（适用于整数和数字范围小的数组）
void CountSort(int *a, int n)
{
	//计算范围
	int max = a[0], min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i]>max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//统计数据个数
	int range = max - min + 1;
	int *count = (int*)malloc(sizeof(int));
	memset(count, 0, sizeof(int)*range);
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
}
void AdjustDown(int *a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n
			&&a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child]>a[parent])
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
void HeapSort(int *a, int n)
{
	assert(a);
	//建堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(a[0], a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
void MergeSort(int* a,int n)
{
	int *tmp = (int*)malloc(sizeof(int)*n);

	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
void TestMergeSort()
{
	int a[] = { 9, 2, 1, 5, 4, 3, 6, 8, 7, 5 };
	//	InsertSort(a, sizeof(a) / sizeof(int));
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestCountSort()
{
	int a[] = { 9, 2, 1, 5, 4, 3, 6, 8, 7, 5 };
	//	InsertSort(a, sizeof(a) / sizeof(int));
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void BenchMark()
{
	int n=10000;
	//scanf("%d", &n);
	int *a1 = (int *)malloc(sizeof(int)*n);
	int *a2 = (int *)malloc(sizeof(int)*n);
	int *a3 = (int *)malloc(sizeof(int)*n);
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
	{
		a1[i] = rand();
		a2[i] = rand();
		a3[i] = rand();
	}
	int begin1 = clock();
	InsertSort(a1, n);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, n);
	int end2 = clock();

	int begin3 = clock();
	CountSort(a3, n);
	int end3 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("CountSort:%d\n", end3 - begin3);
}