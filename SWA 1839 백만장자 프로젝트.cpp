/*
�̹� ������ �տ��� �������� ���ϴ� �ͺ��� ��ü�� �� �Է� ���� �� �ڿ����� ���� ũ�ٰ� �����ϴ� ���� key point����.
���δ� �Ѳ����� ����ϴ� �ͺ��� �׶��׶� ���ϸ鼭 �ּ��� ���� ���ϴ� ���� �� ȿ�������� �������. 
*/



#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

ll cost[1000002];	// �Ÿ� ���� 


int main(void) {
	int t;	// �׽�Ʈ ���̽� ���� 
	scanf("%d", &t);
	
	for(int cs = 1; cs <= t; cs++) {
		int n, idx = 0;	// ���� �� ��, ���� ��ġ 
		ll max = 0, result = 0;	// �ִ� �Ÿ� ����, ��� ���� 
		scanf("%d", &n);
		
		// �迭 �ʱ�ȭ 
		fill_n(cost, n + 1, 0);
		 
		for(int i = 1; i <= n; i++) scanf("%lld", cost + i);
		
		max = cost[n];	// �� ������ ���� �ִ� ���̶� ���� 
		idx = n - 1;	// ���� ��ġ�� �� �ٷ� �� 
		
		// ��� ���鿡 ���ؼ� ���� 
		while(idx) {
			// �ִ밪���� ���� ���� ū��? 
			if(max < cost[idx]) {
				max = cost[idx];	// �� ���� 
			}
			// ���� ��� 
			else result += max - cost[idx];
			
			idx--;	// ������ 
		}
		
		printf("#%d %lld\n", cs, result);
	}
	
	return 0;
}
