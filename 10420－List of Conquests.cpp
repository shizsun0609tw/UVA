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
string A[2001] = { "" }, Z[2000];  //國名 /排序用的
string trashcan;
int B[2001] = { 0 }, C[2001];    //人數
cin >> n;   //n比資料
getline(cin, trashcan);   //把第一個空格丟掉
for (int i = 0; i < n; i++)
{
cin >> A[k];           //第一個資料(國名)
getline(cin, trashcan);  //國名後面的人名丟掉
B[k] = 1;        //人數=1
int 	Q = k;           //先用Q把k存起來  因為下面會改變到k
for (int j = k - 1; j >= 0; j--)  //用於往回找同樣國名
{
if (A[k] == A[j])
{
k = j;
B[k] += 1;
k = Q - 1;  //覆蓋掉重複的國名
}
}
k++;
}

for (int i = k; i > 0; i--) {         //排序
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