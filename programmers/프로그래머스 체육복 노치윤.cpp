#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> total;
    int cnt = 0;
    //���͸� 1�� �ʱ�ȭ �ϰ� ü������ �Ҿ���� �л��� -1 �������� ���� �л��� +1�� ����
    while (cnt < n) {
        total.push_back(1);
        cnt++;
    }
    for (int i = 0; i < lost.size(); i++) {
        total[lost[i] - 1]--;
    }
    for (int i = 0; i < reserve.size(); i++) {
        total[reserve[i] - 1]++;
    }
    for (int i = 0; i < lost.size(); i++) {
        if (total[lost[i] - 1] == 0) {
            if (lost[i] == 1) {
                if (total[lost[i]] == 2) {
                    total[lost[i]]--;
                    total[lost[i] - 1]++;
                }
            }
            else if (lost[i] == n) {
                if (total[lost[i] - 2] == 2) {
                    total[lost[i] - 2]--;
                    total[lost[i] - 1]++;
                }
            }
            else {
                if (total[lost[i] - 2] == 2) {
                    total[lost[i] - 2]--;
                    total[lost[i] - 1]++;
                    continue;
                }
                else if (total[lost[i]] == 2) {
                    total[lost[i]]--;
                    total[lost[i] - 1]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (total[i] != 0) {
            answer++;
        }
    }
    return answer;
}