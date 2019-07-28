/*
����ȭ �� �ڵ�. 
�����̵� ������ Ǯ��Ҵ�.
ó���� �Է��� ���� �� �ٷ� �����Ͱ� ���Ͱ� ���ؼ� �������� Ȯ���� �� �ִ��� �����ϰ�,
�����Ϳ� ���ؼ��� �ڽŰ� �� ������ ���ؼ� �ִ񰪰� ���ϴ� ���� ����Ʈ����. 
*/
#include <cstdio>
#include <algorithm>

using namespace std;

int height[1001], isSee[1001];	// �ǹ� ����, ���̴°�? 

int main(void) {
	// �׽�Ʈ ���̽� 10�� 
	for(int cs = 1; cs <= 10; cs++) {
		int n, cnt = 0;	// input ����, ������ Ȯ�� ���� ���� �� 
		scanf("%d", &n);
		fill_n(isSee, n, 0);	// �ʱ�ȭ
		scanf("%d %d", &height[0], &height[1]);	// �̸� �־���� 
		
		for(int i = 2; i < n; i++) {
			scanf("%d", height + i);
			
			// ������, ���� �� �ִ� 
			int maxi = max(height[i - 2], height[i - 1]);
			// ������ �������� ���� �� ������ Ȯ�� ���� ����� ���� 
			if(maxi < height[i]) isSee[i] = height[i] - maxi;
			
			// ���� ���� �� �ִ� 
			maxi = max(height[i - 1], height[i]);
			// �������� �ִ°�? 
			if(isSee[i - 2]) {
				// ���� ������ ũ�� ������ ���� 
				if(maxi >= height[i - 2]) isSee[i - 2] = 0;
				// �����ͺ��� ���� �ִ��� ū��? 
				else if(height[i - 2] - isSee[i - 2] < maxi) isSee[i - 2] = height[i - 2] - maxi;
			}
			
			cnt += isSee[i - 2];
		}
		
		printf("#%d %d\n", cs, cnt);
	}
	
	return 0;
}
