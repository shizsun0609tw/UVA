#include<iostream>
#include<string>
#include<stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	string b[2001], trashcan;

	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> b[i];
        getline(cin,trashcan);
	}

	sort(b, b + n);

	for (int i = 0; i<n;) {
		cout << b[i] << ' ';
		int num = 1, j;
		for (j = i + 1; j<n; j++) {
			if (b[i] != b[j]) break;
			num++;
		}
		printf("%d\n", num);
		i = j;
	}
	return 0;
}


/*
#include<iostream>
#include<string>
#include<stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
int n, k = 0;
string A[2001] = { "" }, Z[2000];  //��W /�ƧǥΪ�
string trashcan;
int B[2001] = { 0 }, C[2001];    //�H��
cin >> n;   //n����
getline(cin, trashcan);   //��Ĥ@�ӪŮ�ᱼ
for (int i = 0; i < n; i++)
{
cin >> A[k];           //�Ĥ@�Ӹ��(��W)
getline(cin, trashcan);  //��W�᭱���H�W�ᱼ
B[k] = 1;        //�H��=1
int 	Q = k;           //����Q��k�s�_��  �]���U���|���ܨ�k
for (int j = k - 1; j >= 0; j--)  //�Ω󩹦^��P�˰�W
{
if (A[k] == A[j])
{
k = j;
B[k] += 1;
k = Q - 1;  //�л\�����ƪ���W
}
}
k++;
}

for (int i = k; i > 0; i--) {         //�Ƨ�
for (int j = 0; j < i; j++) {
if (A[j][0] > A[j + 1][0]) {
string n = A[j];
A[j] = A[j + 1];
A[j + 1] = n;
int a = B[j];
B[j] = B[j + 1];
B[j + 1] = a;
}
}
}

for (int p = 1; p <=0 k; p++)
{
cout << A[p] << ' ' << B[p] << '\n';
}
return 0;
}
*/