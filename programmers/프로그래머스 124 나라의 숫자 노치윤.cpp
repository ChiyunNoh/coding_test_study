#include <string>
#include <algorithm>
using namespace std;

string solution(int n) {
    string answer = "";
    while (true) {//��Ģ: 1�� ���� 3���� ���� �������� ������ �� 0�̸� 1, 1�̸� 2, 2�̸� 4,~~~��� �ݺ�
        if (n == 0) break;
        if ((n - 1) % 3 == 0) answer += to_string(1);
        else if ((n - 1) % 3 == 1) answer += to_string(2);
        else if ((n - 1) % 3 == 2) answer += to_string(4);
        n = (n - 1) / 3;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}