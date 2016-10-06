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
	//���ͤ@�Ӥj�p��n���]�N��}�A�䤤n���_��  {
	const int MaxSize = 51; // �̤j��}�j�p
	int square[MaxSize][MaxSize], k, l;
	int sum;
	// �T�wn�����T��
	if ((n > MaxSize) || (n < 1))
		throw "Error!..n out of range ";
	else if (!(n % 2)) throw "Error!..n is even \n";

	// n�O�_�ơA�i�H�� Coxeter �W�h
	for (int i = 0; i < n; i++)  // �N��}�_�l��0
		fill(square[i], square[i] + n, 0); // STL�t��k
	square[0][(n - 1) / 2] = 1; // �Ĥ@�C��������m

	// i �� j �O�ثe����m
	int key = 2; int i = 0; int j = (n - 1) / 2;
	while (key <= n*n) {
		// �V���W����
		if (i - 1 < 0) k = n - 1; else k = i - 1;
		if (j - 1 < 0) l = n - 1; else l = j - 1;
		if (square[k][l]) i = (i + 1) % n; // square�w�g�Q�񺡡A���U����
		else { // square[k][l]���Q��
			i = k; j = l;
		}
		square[i][j] = key;
		key++;
	} // while����

	// ��X�]�N��}
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
	cout <<"��C���M��"<< sum <<endl ;
 	
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


