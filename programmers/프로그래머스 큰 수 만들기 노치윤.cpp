#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int start_idx = 0;
    int cnt = 0;
    int length = number.length() - k;//k���� ������ ���ڿ� ����
    while (cnt < length) {
        int idx = 0;
        char max = '0' - 1;//���ڿ� ���� 0�� ���� �� �����Ƿ� 1�� ����.
        for (int i = start_idx; i <= number.length() - (length - cnt); i++) {
            if (number[i] > max) {
                max = number[i];
                idx = i;
            }
        }
        answer += max;
        start_idx = idx + 1;
        cnt++;
    }
    return answer;
}