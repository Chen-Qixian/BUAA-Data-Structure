#include <stdio.h>
int main(void){
	char c;
	c=getchar();
	putchar(c-1);
	putchar(' ');
	putchar(c);
	putchar(' ');
	putchar(c+1);
	putchar('\n');
	printf("%d %d %d",c-1,c,c+1);	
	return 0;
}
