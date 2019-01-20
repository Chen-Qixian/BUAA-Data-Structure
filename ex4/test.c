#include <stdio.h>
int main()
{
 char *language[] = {"FORTRAN", "BASIC", "PASCAL", "JAVA", "C"};
 
 printf("%s",*(language+2));
 return 0;
}


