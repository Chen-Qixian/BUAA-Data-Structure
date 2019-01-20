#include <stdio.h>
int main(void){
	int ax1,ax2,ay1,ay2,bx1,bx2,by1,by2,width,height,max_a,min_a,max_b,min_b,max,min;
	scanf("%d %d %d %d %d %d %d %d",&ax1,&ay1,&ax2,&ay2,&bx1,&by1,&bx2,&by2);
	if(ax1>ax2) {
		max_a=ax1;
		min_a=ax2;
	}
	else{
		max_a=ax2;
		min_a=ax1;
	} 
	if(bx1>bx2){
		max_b=bx1;
		min_b=bx2;
	}
	else{
		max_b=bx2;
		min_b=bx1;
	}
	if(max_a<max_b){
		max=max_a;
	}
	else{
		max=max_b;
	}
	if(min_a>min_b){
		min=min_a;
	}
	else{
		min=min_b;
	}
	if(max-min<=0){
		width=0;
	}
	else {
		width=max-min;
	}
	if(ay1>ay2) {
		max_a=ay1;
		min_a=ay2;
	}
	else{
		max_a=ay2;
		min_a=ay1;
	} 
	if(by1>by2){
		max_b=by1;
		min_b=by2;
	}
	else{
		max_b=by2;
		min_b=by1;
	}
	if(max_a<max_b){
		max=max_a;
	}
	else{
		max=max_b;
	}
	if(min_a>min_b){
		min=min_a;
	}
	else{
		min=min_b;
	}
	if(max-min<=0){
		height=0;
	}
	else {
		height=max-min;
	}
	
	printf("%d",width*height);
	return 0;
}
