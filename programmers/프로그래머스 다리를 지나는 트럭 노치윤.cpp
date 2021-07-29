#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int current_truck = 0;
    int current_weight = 0;
    int finish = 0;
    queue<int> q;
    int cnt = 0;
    while (cnt < bridge_length) {
        q.push(0);
        cnt++;
    }//0�� ĭ ����� ��������. ex) �ٸ����̰� 4�̸� 4���� ���� �� �� �ְ� �� ������ 0.

    int idx = 0;
    while (true) {//���� 1 : 70 -> 07 -> 40 -> 54 -> 05 -> 60 -> 06 -> 00, 8��!
        int temp = q.front();
        if (temp != 0) {
            finish++;
            current_truck--;
            current_weight -= temp;
        }
        q.pop();
        if (finish == truck_weights.size()) {
            answer++;
            break;
        }
        if (current_weight + truck_weights[idx] <= weight) {
            q.push(truck_weights[idx]);
            current_truck++;
            current_weight += truck_weights[idx];
            idx++;
        }
        else {
            q.push(0);
        }
        answer++;

    }
    return answer;
}