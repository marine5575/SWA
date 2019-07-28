/*
이번 문제는 앞에서 차례차례 비교하는 것보다 전체를 다 입력 받은 후 뒤엣값이 가장 크다고 가정하는 것이 key point였다.
때로는 한꺼번에 계산하는 것보다 그때그때 비교하면서 최선의 값을 구하는 것이 더 효율적임을 기억하자. 
*/



#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

ll cost[1000002];	// 매매 가격 


int main(void) {
	int t;	// 테스트 케이스 개수 
	scanf("%d", &t);
	
	for(int cs = 1; cs <= t; cs++) {
		int n, idx = 0;	// 장터 일 수, 현재 위치 
		ll max = 0, result = 0;	// 최대 매매 가격, 결과 이익 
		scanf("%d", &n);
		
		// 배열 초기화 
		fill_n(cost, n + 1, 0);
		 
		for(int i = 1; i <= n; i++) scanf("%lld", cost + i);
		
		max = cost[n];	// 맨 마지막 값이 최대 값이라 가정 
		idx = n - 1;	// 현재 위치는 그 바로 앞 
		
		// 모든 날들에 대해서 실행 
		while(idx) {
			// 최대값보다 현재 값이 큰가? 
			if(max < cost[idx]) {
				max = cost[idx];	// 값 갱신 
			}
			// 이익 계산 
			else result += max - cost[idx];
			
			idx--;	// 전날로 
		}
		
		printf("#%d %lld\n", cs, result);
	}
	
	return 0;
}
