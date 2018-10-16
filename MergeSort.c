/*
	@breif:�鲢����
	@author:WavenZ
	@time:2018/10/16
*/
#define _CRT_SECURE_NO_WARNINGS
#include "MergeSort.h"
void Merge(RedType SR[], RedType *temp, int start, int mid, int end) {
	//�������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n]
	int i = start;
	int j = mid + 1;
	int k = start;
	for (; i <=mid &&j <= end; ++k) {
		if (LE(SR[i].key, SR[j].key))
			temp[k] = SR[i++];
		else 
			temp[k] = SR[j++];
	}
	if (i <= mid) {//ǰһ��ʣ�µ�
		for (int a = i; a <= mid; a++) {
			temp[a + end - mid] = SR[a];
		}
	}
	if (j <= end) {//��һ��ʣ�µ�
		for (int a = j; a <= end; a++) {
			temp[a] = SR[a];
		}
	}
	for (int a = start; a <= end; ++a) {
		SR[a] = temp[a];
	}
}
void MSort(RedType *SR,RedType *temp, int s, int t) {
	//��SR[s..t]�鲢����ΪTR1[s..t]
	int m = 0;
	if (s < t) {//��������Լ�����
		m = (s + t) / 2;
		MSort(SR, temp, s, m);
		MSort(SR, temp, m+1, t);
		Merge(SR, temp, s, m, t);
	}
}

void MergeSort(Sqlist *L) {
	//��˳���L���鲢����
	RedType* temp = NULL;
	temp = (RedType *)malloc(sizeof(RedType)*(L->length+1));//Ϊ�˷�ֹ��������ڴ�
															//�������Ŀ��������ͬ��С���ڴ�
	MSort(L->r, temp, 1, L->length);
	free(temp);
}