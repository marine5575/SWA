/*
그리디하게 풀었다.
크게 다른 방법이 떠오르지 않아 무작정 비교하고 진행하는 방식을 택하였다.
그러나 생각보다 메모리를 많이 잡아먹어 더 최적화하는 작업이 필요할 것 같다. 
*/
#include <iostream>
#include <string>
#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

using namespace std;

string s;	// 주어진 문자열 
int num;	// 바꿀 수 있는 횟수 


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int tc, t;	// 테스트 케이스 수 
	cin >> tc;
	
	for(int cs = 1; cs <= tc; cs++) {
		int max = 0, idx = 0, odx, cnt = 0;	// 최댓값 위치, 예전 최댓값 위치, 바꾼 횟수 
		cin >> s >> num;
		
		// 모든 문자열 차례차례 살펴봄 
		for(int i = 0; i < s.size(); i++) {
			// 바꿀 수 있는 횟수를 다 썼는가? 
			if(cnt == num) break;
			// 끝에서 두번째까지 왔는가? 
			if(i == s.size() - 2) {
				// 이전 것들이 같은 숫자이면 그냥 두기 
				if(s[i] == s[i - 1]) break;
				// 남은 횟수가 홀수인가? 
				if((num - cnt) % 2) swap(s[i], s[i + 1], t);
				break;
			}
			
			max = 0;
			// 현재 위치 다음 것부터 모두 찾기 
			for(int j = i + 1; j < s.size(); j++) {
				// 이곳의 값이 최댓값인가? 
				if(max <= s[j] - '0') max = (s[j] - '0'), idx = j;
			}
			
			// 현재값이 사실 최댓값인가? 
			if(max <= s[i] - '0') continue;
			// 예전에 바꾼 것도 최댓값이었나? 
			if(i != 0 && max == s[i - 1] - '0') {
				swap(s[i], s[idx], t);
				// 뒤로 갔던 값들의 대소관계 따지기 
				if(s[odx] > s[idx]) swap(s[idx], s[odx], t);
				cnt++;	// 횟수 증가 
				continue;
			}
			
			// 바꿔주고 횟수 증가. 혹시 모르니 최댓값 idx 저장 
			swap(s[i], s[idx], t);
			cnt++;
			odx = idx;
		}
		cout << "#" << cs << " " << s << "\n";
	}
	
	return 0;
}
