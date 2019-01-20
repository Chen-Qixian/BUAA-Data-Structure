#include<stdio.h>
#include<string.h>
#define N (1010)
#define M (10)

struct node{
	int cnt, left, right, id;
	char code[M];
	char ch;
};

char s[N], ans[N];
int cnt[N], inv[N], _ans[N];
struct node a[N];

void dfs(int u){
	if (a[u].left != -1){
		strcat(a[a[u].left].code, a[u].code);
		strcat(a[a[u].left].code, "0");
		dfs(a[u].left);
	}
	if (a[u].right != -1){
		strcat(a[a[u].right].code, a[u].code);
		strcat(a[a[u].right].code, "1");
		dfs(a[u].right);
	}
}

int main(){
	int i, j, len = 0;
	FILE *fp = fopen("input.txt", "r");
	while ((s[len ++] = fgetc(fp)) != EOF);
	s[-- len] = '\0';
	for (i = 0; i <= len; ++ i){
		if (s[i] != '\n'){
			++ cnt[s[i]];
		}
	}
	int cnta = 0;
	for (i = 0; i < N; ++ i){
		if (cnt[i] > 0){
			a[cnta].cnt = cnt[i];
			a[cnta].ch = i;
			a[cnta].left = a[cnta].right = -1;
			++ cnta;
		}
	}
	for (i = 0; i < cnta; ++ i){
		for (j = 0; j < cnta - i - 1; ++ j){
			if (a[j].cnt > a[j + 1].cnt){
				struct node p = a[j];
				a[j] = a[j + 1];
				a[j + 1] = p;
			}
		}
	}
	for (i = 0; i < cnta; ++ i){
		a[i].id = i;
		inv[a[i].ch] = i;
	}
	for (i = 0; i < cnta - 1; ++ i){
		a[i + cnta].cnt = a[i << 1].cnt + a[(i << 1) + 1].cnt;
		a[i + cnta].id = i + cnta;
		a[i + cnta].left = a[i << 1].id;
		a[i + cnta].right = a[(i << 1) + 1].id;
		for (j = i + cnta; j > i << 1; -- j){
			if (a[j].cnt < a[j - 1].cnt){
				struct node p = a[j];
				a[j] = a[j - 1];
				a[j - 1] = p;
			}
		}
	}
	int _flag = 1;
	while (_flag){
		_flag = 0;
		for (i = 0; i < (cnta << 1) - 1; ++ i){
			if (a[i].id != i){
				_flag = 1;
				struct node p = a[a[i].id];
				a[a[i].id] = a[i];
				a[i] = p;
			}
		}
	}
	dfs(cnta - 1 << 1);
	for (i = 0; i <= len; ++ i){
		if (s[i] == '\n'){
			continue;
		}
		strcat(ans, a[inv[s[i]]].code);
	}
	for (i = 0; i < 1 << 7; ++ i){
		printf("code[%c] = %s\n", (char) i, a[inv[i]].code);
	}
	int length = strlen(ans);
	for (i = 0; i < 8; ++ i){
		int x = x = length >> 3;
		if ((x << 3) + i < length){
			ans[length ++] = '0';
		}
	}
	for (i = 0; i < length; ++ i){
		_ans[i] = ans[i] - '0';
	}
	fclose(fp);
	fp = fopen("output.txt", "wb");
	for (i = 0; i < length; i += 8){
		unsigned char ch;
		for (j = 0; j < 8; ++ j){
			ch = ch << 1 | _ans[i + j];
		}
		printf("%x", ch);
		fwrite(&ch, 1, 1, fp);
	}
	fclose(fp);
	return 0;
}
