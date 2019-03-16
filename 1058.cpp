#include <stdio.h>

int main(void) {
	int i,j,k,a,b,c,x,y,z,k1,j1;

	scanf("%d.%d.%d%d.%d.%d",&a,&b,&c,&x,&y,&z);
//	scanf("%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z);
//	printf("%d %d %d %d %d %d\n",a,b,c,x,y,z);
	k1 = (c + z);
	k = k1 % 29;
	j1 = (b + y + k1/29);
	j = j1 % 17;
	i = a + x + j1/17;
	printf("%d.%d.%d",i,j,k);

	return 0;
}
