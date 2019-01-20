#include <stdio.h>
#define SIZE 19
int data[21][21];
int row,line;
int p1(){
	int i,j,k,p;
	for(i=1;i<=SIZE;i++){		
		for(j=1;j<=SIZE-3;j++){
			if(data[i][j-1]==0||data[i][j+4]==0){
				p=1;
				for(k=j;k<j+3;k++){
					if(data[i][k]!=data[i][k+1]||data[i][k]==0){
						p=0;
					}
				}
				if(p){
					row=i;
					line=j;
					return data[i][j];
				}
			}
		}
	}
	return 0;
}
int p2(){
	int i,j,k,p;
	for(j=1;j<=SIZE;j++){		
		for(i=1;i<=SIZE-3;i++){
			if(data[i-1][j]==0||data[i+4][j]==0){
				p=1;
				for(k=i;k<i+3;k++){
					if(data[k][j]!=data[k+1][j]||data[k][j]==0){
						p=0;
					}
				}
				if(p){
					row=i;
					line=j;
					return data[i][j];
				}
			}
		}
	}
	return 0;
}
int p3(){
	int i,j,k,l,p;
	for(i=1;i<=SIZE-3;i++){
		for(j=1;j<=SIZE-3;j++){
			if(data[i-1][j-1]==0||data[i+4][j+4]==0){
				p=1;
				for(k=i,l=j;k<i+3;k++,l++){
					if(data[k][l]!=data[k+1][l+1]||data[k][l]==0){
						p=0;
					}
				}
				if(p){
					row=i;
					line=j;
					return data[i][j];
				}
			}
		}
	}
	return 0;
}
int p4(){
	int i,j,k,l,p;
	for(i=1;i<=SIZE-3;i++){
		for(j=4;j<=SIZE;j++){
			if(data[i-1][j+1]==0||data[i+4][j-4]==0){
				p=1;
				for(k=i,l=j;k<i+3;k++,l--){
					if(data[k][l]!=data[k+1][l-1]||data[k][l]==0){
						p=0;
					}
				}
				if(p){
					row=i;
					line=j;
					return data[i][j];
				}
			}
		}
	}
	return 0;
}
int main(void){
	int i,j;
	for(i=1;i<=SIZE;i++){
		for(j=1;j<=SIZE;j++){
			scanf("%d",&data[i][j]);
		}
	}
	for(i=0;i<=SIZE+1;i++){
		data[i][0]=3;
		data[i][SIZE+1]=3;
	}
	for(j=1;j<=SIZE;j++){
		data[0][j]=3;
		data[SIZE+1][j]=3;
	}
	if(p1()==1||p2()==1||p3()==1||p4()==1){
		printf("1:%d,%d\n",row,line);
	}
	else if(p1()==2||p2()==2||p3()==2||p4()==2){
		printf("2:%d,%d\n",row,line);
	}
	else{
		printf("No\n");
	}
	return 0;
} 
