/*
	@breif:归并排序
	@author:WavenZ
	@time:2018/10/16
*/
#define _CRT_SECURE_NO_WARNINGS
#include "MergeSort.h"
void Merge(RedType SR[], RedType *temp, int start, int mid, int end) {
	//将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]
	int i = start;
	int j = mid + 1;
	int k = start;
	for (; i <=mid &&j <= end; ++k) {
		if (LE(SR[i].key, SR[j].key))
			temp[k] = SR[i++];
		else 
			temp[k] = SR[j++];
	}
	if (i <= mid) {//前一半剩下的
		for (int a = i; a <= mid; a++) {
			temp[a + end - mid] = SR[a];
		}
	}
	if (j <= end) {//后一半剩下的
		for (int a = j; a <= end; a++) {
			temp[a] = SR[a];
		}
	}
	for (int a = start; a <= end; ++a) {
		SR[a] = temp[a];
	}
}
void MSort(RedType *SR,RedType *temp, int s, int t) {
	//将SR[s..t]归并排序为TR1[s..t]
	int m = 0;
	if (s < t) {//如果还可以继续分
		m = (s + t) / 2;
		MSort(SR, temp, s, m);
		MSort(SR, temp, m+1, t);
		Merge(SR, temp, s, m, t);
	}
}

void MergeSort(Sqlist *L) {
	//对顺序表L作归并排序
	RedType* temp = NULL;
	temp = (RedType *)malloc(sizeof(RedType)*(L->length+1));//为了防止多次申请内存
															//先申请和目标数组相同大小的内存
	MSort(L->r, temp, 1, L->length);
	free(temp);
}