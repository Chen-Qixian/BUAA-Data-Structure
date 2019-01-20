#include <stdio.h>
#include <string.h>
char s1[1000000],s2[1000000];
int main(void){
	void expand(char s1[],char s2[]);
	scanf("%[^\n]",s1);
	expand(s1,s2);
	return 0;
}
void expand(char s1[],char s2[]){
	int i,j=0,k,l;
	if(s1[0]!='-'){
		s2[j]=s1[0];
		j++;
	}
	for(i=1;i<strlen(s1);){
		if(s1[i]=='-'){
			if(s1[i-1]<s1[i+1]){
				if(s1[i-1]==' '){
						s2[j]=s1[i+1];
						j++;					
				}
			else{
				for(k=s1[i-1];k<s1[i+1];k++,j++){
					s2[j]=(char)(k+1);
					}
			    }
			}
			else if(s1[i-1]>s1[i+1]){
				for(k=i;k<=i+1;k++,j++){
					s2[j]=s1[k];
				}
			}
			i+=2;
		}
		else{
			s2[j]=s1[i];
			j++;
			i++;
		}
	}
	for(l=0;l<strlen(s2);l++){
		printf("%c",s2[l]);
	}
}
