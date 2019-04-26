#include<stdio.h>
#include<string.h>
char a[500000];
char c[] = { '1','2','3','4','5','6','7','8','9','0','-','=','q','w','e','r','t','y','u','i','o','p','[',']','a','s','d','f','g','h','j','k','l',';','\'','z','x','c','v','b','n','m',',','.','/'};
int main() {
	fgets(a, sizeof(a), stdin);
	for (int i = 0; i < strlen(a); i++) {
		int label = 0;
		if (a[i] >= 'A' && a[i] <= 'Z')a[i] += 32;
		for (int j = 0; j < 45; j++) {
			
			if (c[j] == a[i] && c[j] != 'q' &&c[j] != 'w' &&c[j] != 'a' && c[j] != 's' && c[j] != 'z' &&c[j] != 'x' && c[j] != '1' && c[j] != '2') {
				printf("%c", c[j - 2]);
				label = 1;
				break;
			}
		}
		if (label == 0)printf("%c",a[i]);
	}
	return 0;
}