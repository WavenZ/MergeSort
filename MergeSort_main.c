/*
	@breif:归并排序
	@author:WavenZ
	@time:2018/10/16
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "MergeSort.h"


int main(int argc, char* argv[]) {

	int data;
	Sqlist S;
	S.length = 0;
	//产生随机数
	freopen("data.txt", "w", stdout);
	for (int i = 1; i <= MAXSIZE; ++i) {
		printf("%d ", rand() % 1000);
	}
	fclose(stdout);

	//读入测试数据
	freopen("data.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	for (int i = 1; (scanf("%d", &data) != -1) && i < MAXSIZE; ++i) {
		S.r[i].key = data;
		S.length += 1;
	}
	//打印测试数据
	printf("Before sort:\n    ");
	for (int i = 1; i <= S.length; ++i) {
		printf("%d ", S.r[i]);
	}
	printf("\n");
	printf("After sort:\n    ");
	//调用算法
	MergeSort(&S);
	//打印运算结果
	for (int i = 1; i <= S.length; ++i) {
		printf("%d ", S.r[i]);
	}
	printf("\n");
	//后续处理
	fclose(stdin);
	fclose(stdout);
	system("pause");
	return 1;
}