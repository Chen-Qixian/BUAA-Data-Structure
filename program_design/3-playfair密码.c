#include <stdio.h>
#include <string.h>
char keyword[26],ori[51],keyc[26],rep[51];
char key[6][6];
void formkey(){
	int i,j,k=0,p;
	char c;
	scanf("%s",keyword);
	scanf("%s",ori);
	for(c='a';c<='z';c++){
		p=1;
		for(i=0;keyword[i]!='\0';i++){
			if(c==keyword[i]){
				p=0;
				break;
			}
		}
		if(p){
			keyc[k++]=c;
		}
	}
	for(i=0;k<25;k++,i++){
		keyc[k]=keyword[i];
	}
	k=0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			key[i][j]=keyc[k++];
		}
	}
}
void replace(){
	int i,j,k,x1=0,x2=0,y1=0,y2=0;
	char ch=keyword[strlen(keyword)-1];
	for(i=0;ori[i]!='\0';i+=2){
		if(ori[i+1]=='\0'){
			rep[i]=ori[i];
			rep[i+1]='\0';
		}
		else if(ori[i]==ori[i+1]){
			rep[i]=ori[i];
			rep[i+1]=ori[i+1];
		}
		else if(ori[i]==ch||ori[i+1]==ch){
			rep[i]=ori[i];
			rep[i+1]=ori[i+1];
		}
		else{
			for(j=0;j<5;j++){
				for(k=0;k<5;k++){
					if(key[j][k]==ori[i]){
						x1=j;
						y1=k;
					}
				}
			}
			for(j=0;j<5;j++){
				for(k=0;k<5;k++){
					if(key[j][k]==ori[i+1]){
						x2=j;
						y2=k;
					}
				}
			}
			if(x1==x2||y1==y2){
				rep[i]=ori[i+1];
				rep[i+1]=ori[i];
			}
			else{
				rep[i]=key[x1][y2];
				rep[i+1]=key[x2][y1];
			}
	    }
	}
	rep[i]='\0';
}
int main(void){
	formkey();
	replace();
	printf("%s",rep);
	return 0;
}
