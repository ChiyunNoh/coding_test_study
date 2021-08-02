#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int num = limit / 2;
    int left = 0;
    int right = -1;
    sort(people.begin(), people.end());
    for (int i = people.size() - 1; i >= 0; i--) {//�ǳ��� �� �ջ�� ��. �ǳ�+�Ǿ�>limit �̸� �ǳ������ ȥ�� Ÿ����.
        right = i;
        if (right == left) {
            answer++;
            break;
        }
        if (right < left) {
            break;
        }

        if (people[right] + people[left] <= limit) {
            answer++;
            left++;
        }
        else {
            answer++;
        }

    }
    return answer;
}