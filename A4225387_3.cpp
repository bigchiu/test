#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>

using namespace std;

int ack(int m, int n) {
	if (m == 0) return(n + 1);
	else if (n == 0) return(ack(m - 1, 1));
	else return(ack(m - 1, ack(m, n - 1)));
}



void Magic(const int n) {
	//產生一個大小為n的魔術方陣，其中n為奇數  {
	const int MaxSize = 51; // 最大方陣大小
	int square[MaxSize][MaxSize], k, l;
	int sum;
	// 確定n的正確性
	if ((n > MaxSize) || (n < 1))
		throw "Error!..n out of range ";
	else if (!(n % 2)) throw "Error!..n is even \n";

	// n是奇數，可以用 Coxeter 規則
	for (int i = 0; i < n; i++)  // 將方陣起始為0
		fill(square[i], square[i] + n, 0); // STL演算法
	square[0][(n - 1) / 2] = 1; // 第一列的中間位置

	// i 跟 j 是目前的位置
	int key = 2; int i = 0; int j = (n - 1) / 2;
	while (key <= n*n) {
		// 向左上移動
		if (i - 1 < 0) k = n - 1; else k = i - 1;
		if (j - 1 < 0) l = n - 1; else l = j - 1;
		if (square[k][l]) i = (i + 1) % n; // square已經被填滿，往下移動
		else { // square[k][l]未被填滿
			i = k; j = l;
		}
		square[i][j] = key;
		key++;
	} // while結束

	// 輸出魔術方陣
	cout << "magic square of size " << n << endl;
	/*for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			cout << square[i][j] << "\t";
		cout << endl;*/
		for(i=0; i<n; i++) {	
  sum = 0;	
  for(j=0; j<n; j++) {	
    cout<<square[i][j]<<"\t";
	sum += square[i][j];	
 	

	} 
	cout <<"橫列的和為"<< sum <<endl ;
 	
}	
 
	}


main() {
	Magic(11);
	getchar();
	cout << "ackerman(3, 2) is " << ack(3, 3) << endl;
	getchar();
	for(int i = 0; i < 100; i++) {
		int a = rand() % 1000;
		cout << a << endl; 
	}
}



