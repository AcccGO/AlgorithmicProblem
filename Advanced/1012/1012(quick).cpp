//https://www.nowcoder.com/pat/5/submission-detail/33969788
#include <iostream>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main() 
{

	char s[300], a[300];
	int i, n, length = 256;
	int len1, len2;
	int j, k;

	scanf("%d", &n);
	getchar();//回车
	gets_s(s);
	len1 = strlen(s);//输入第一行
	for (i = 1; i<n; i++) {
		gets_s(a);
		len2 = strlen(a);
		k = len1>len2 ? len2 : len1;
		for (j = 1; j <= k; j++)
			if (a[len2 - j] != s[len1 - j])    break;
		--j;
		if (j<length) length = j;
	}
	if (length == 0)   printf("nai");
	else for (i = length; i >= 1; i--) printf("%c", s[len1 - i]);
	return 0;
}
