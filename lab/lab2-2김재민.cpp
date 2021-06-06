////////////////////////////////////////////////////////////////////////
// Lab2-2 : Finding Prime Numbers
// Name : 김재민
// ID : 20181592
/////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int Is_prime(int n);
int Large_prime(int n);

int main() {
	int n = 0;
	char answer = 'Y'; //첫실행은 무조건 해야하니 초기 answer을 Y로 설정

	while (answer == 'Y') { //answer이 Y값인 한 계속 실행
		cout << "Enter any Prime number : "; cin >> n;
		if (Is_prime(n) == 1) cout << n << " is prime number" << endl; //소수판별 함수가 1일때, 즉 n이 소수일때 작동
		else cout << n << " is not a prime number" << endl; //n이 소수가 아닐때 작동

		int Large = Large_prime(n); //주어진 n보다 큰 소수찾기 함수를 작동하여 리턴값을 int Large에 저장
		cout << "prime number larger than given number : " << Large << endl << endl;

		cout << "Again (Y,N)? : "; cin >> answer;
		cout << endl;
		if (answer == 'N') break; //answer이 N이 되는 순간 break 문을 통해 while문 종료(while문만 종료하고 return 0까지 도달해서 함수종료)
	}                             //이때 break대신 return을 작성하면 while문 탈출과 동시에 메인함수를 종료시키는거 것
	                              //즉 메인함수 맨 끝인 return 0까지 도달하지 않을 뿐더러 while문 다음에 또다른 코드 실행 불가
	return 0; //함수 종료
}

int Is_prime(int n) {
	for (int i = 2; i < n; i++) {
		if ((n % i) == 0) return 0;
	}
	return 1;
}
/*
<소수판별 함수>
정수 n을 입력받을 소수판별 함수 Is_prime을 정의한다.
n을 입력받으면 for문에서 i가 2부터 n-1까지 작동한다.
n을 i로 나눴을때 단 한번이라도 나머지가 0이 나오면 0을 리턴하고(소수가 아니라는 뜻) 함수를 종료한다.
반대로 if문이 한번도 작동을 안한다면 나머지가 0인경우가 없는, 즉 소수라는 뜻이므로 리턴값이 없는 상태로
for문을 나와서 1을 리턴하고 함수를 종료한다. (0을 리턴하면 소수가 아니고 1을 리턴하면 소수)
*/

int Large_prime(int n) {
	int m = n + 1;
	while (Is_prime(m) == 0) {
		m = m + 1;
	}
	return m;
}
/*
<주어진 수보다 큰 소수찾기>
정수 n을 입력받으면 m을 n+1로 설정하여 n보다 큰 수 중 가장 작은 수로 설정한다.
그리고 m을 소수판별 함수를 통해 리턴값이 0일때, 즉 소수가 아닐때는 m을 1만큼 더해서 다시 소수판별을 하도록 while문을 작성한다.
while문이 작동하다가 소수판별 함수가 1을 출력하여 while문의 조건을 만족하지 않는 순간 while문을 곧바로 탈출하여 현재의 m값, 
즉 소수를 리턴한다.
*/