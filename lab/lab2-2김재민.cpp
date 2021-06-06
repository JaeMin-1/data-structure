////////////////////////////////////////////////////////////////////////
// Lab2-2 : Finding Prime Numbers
// Name : �����
// ID : 20181592
/////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int Is_prime(int n);
int Large_prime(int n);

int main() {
	int n = 0;
	char answer = 'Y'; //ù������ ������ �ؾ��ϴ� �ʱ� answer�� Y�� ����

	while (answer == 'Y') { //answer�� Y���� �� ��� ����
		cout << "Enter any Prime number : "; cin >> n;
		if (Is_prime(n) == 1) cout << n << " is prime number" << endl; //�Ҽ��Ǻ� �Լ��� 1�϶�, �� n�� �Ҽ��϶� �۵�
		else cout << n << " is not a prime number" << endl; //n�� �Ҽ��� �ƴҶ� �۵�

		int Large = Large_prime(n); //�־��� n���� ū �Ҽ�ã�� �Լ��� �۵��Ͽ� ���ϰ��� int Large�� ����
		cout << "prime number larger than given number : " << Large << endl << endl;

		cout << "Again (Y,N)? : "; cin >> answer;
		cout << endl;
		if (answer == 'N') break; //answer�� N�� �Ǵ� ���� break ���� ���� while�� ����(while���� �����ϰ� return 0���� �����ؼ� �Լ�����)
	}                             //�̶� break��� return�� �ۼ��ϸ� while�� Ż��� ���ÿ� �����Լ��� �����Ű�°� ��
	                              //�� �����Լ� �� ���� return 0���� �������� ���� �Ӵ��� while�� ������ �Ǵٸ� �ڵ� ���� �Ұ�
	return 0; //�Լ� ����
}

int Is_prime(int n) {
	for (int i = 2; i < n; i++) {
		if ((n % i) == 0) return 0;
	}
	return 1;
}
/*
<�Ҽ��Ǻ� �Լ�>
���� n�� �Է¹��� �Ҽ��Ǻ� �Լ� Is_prime�� �����Ѵ�.
n�� �Է¹����� for������ i�� 2���� n-1���� �۵��Ѵ�.
n�� i�� �������� �� �ѹ��̶� �������� 0�� ������ 0�� �����ϰ�(�Ҽ��� �ƴ϶�� ��) �Լ��� �����Ѵ�.
�ݴ�� if���� �ѹ��� �۵��� ���Ѵٸ� �������� 0�ΰ�찡 ����, �� �Ҽ���� ���̹Ƿ� ���ϰ��� ���� ���·�
for���� ���ͼ� 1�� �����ϰ� �Լ��� �����Ѵ�. (0�� �����ϸ� �Ҽ��� �ƴϰ� 1�� �����ϸ� �Ҽ�)
*/

int Large_prime(int n) {
	int m = n + 1;
	while (Is_prime(m) == 0) {
		m = m + 1;
	}
	return m;
}
/*
<�־��� ������ ū �Ҽ�ã��>
���� n�� �Է¹����� m�� n+1�� �����Ͽ� n���� ū �� �� ���� ���� ���� �����Ѵ�.
�׸��� m�� �Ҽ��Ǻ� �Լ��� ���� ���ϰ��� 0�϶�, �� �Ҽ��� �ƴҶ��� m�� 1��ŭ ���ؼ� �ٽ� �Ҽ��Ǻ��� �ϵ��� while���� �ۼ��Ѵ�.
while���� �۵��ϴٰ� �Ҽ��Ǻ� �Լ��� 1�� ����Ͽ� while���� ������ �������� �ʴ� ���� while���� ��ٷ� Ż���Ͽ� ������ m��, 
�� �Ҽ��� �����Ѵ�.
*/