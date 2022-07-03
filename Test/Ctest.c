#include <stdio.h>
 
void preToPost(char *arrPre,char *arrPost,int l1,int h1,int l2,int h2) {
	//l1,h1,l2,h2代表arrPre和arrPost的起点和末尾
	int half;
	if (l1 <= h1) {
		half = (h1 - l1) / 2;
		*(arrPost + h2) = *(arrPre + l1);
        printf("%d",arrPost[h2]);
		preToPost(arrPre, arrPost, l1 + 1, l1 + half, l2, l2 + half - 1);//左边
		preToPost(arrPre, arrPost, l1 + half + 1, h1, l2+ half, h2-1);//右边
	}
 
}
int main() {
	char arrPre[] = {'A','B','D','E','C','F','G'},arrPost[7];
	preToPost(arrPre,arrPost,0,6,0,6);
	for (int i = 0; i < 7;i++) {
		printf("%c ",*(arrPost+i));
	}
	return 0;
}