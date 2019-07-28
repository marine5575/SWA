/*
����ȭ�� ��Ű���� ������, c++������ �Ʊ� �ڵ尡 �ּ��� �� ����.
�� �ڵ带 �̿����� �� �޸𸮴� 4kb �پ�������, ���� �ð��� 5ms �����ߴ�.
�׳� ���� �ڵ带 �̿��ϵ��� ����.
������ ���̵��� �Ȱ���. 
*/
#include <cstdio>
#include <iostream>	// fill_n
#define INF 987654321

int height[1001];	// ���� ���� 

int main(void) {
	// �׽�Ʈ ���̽� 10�� 
	for(int cs = 1; cs <= 10; cs++) {
		int n, ans = 0;	// input ����, ���� 
		scanf("%d", &n);
		std::fill_n(height, n, 0);	// �ʱ�ȭ 
		
		for(int i = 0; i < n; i++) {
			scanf("%d", height + i);
		}
		
		for(int i = 2; i < n; i++) {
			int min = INF;	// �ּڰ� ���� 
			
			// height[i]���� ū ���� ���� (+-)2 �ȿ� ��� �ִ°�? 
			if(height[i] < height[i - 1] || height[i] < height[i - 2] || height[i] < height[i + 1] || height[i] < height[i + 2]) {
				min = 0;
			}
			// ���� �ȿ� height[i]���� ���� �͵鸸 ���� 
			else {
				int m1 = height[i] - height[i - 1];
				int m2 = height[i] - height[i - 2];
				int m3 = height[i] - height[i + 1];
				int m4 = height[i] - height[i + 2];
				
				// �ּڰ����� ���� 
				if(min > m1) min = m1;
				if(min > m2) min = m2;
				if(min > m3) min = m3;
				if(min > m4) min = m4;
			}
			
			ans += min;	// ���� 
		}
		
		printf("#%d %d\n", cs, ans);
	}
	
	return 0;
}
