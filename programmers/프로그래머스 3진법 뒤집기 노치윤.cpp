#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> three;
    int r;//������
    while (true) {

        r = n % 3;
        n /= 3;
        three.push_back(r);
        if (n < 3 && n>0) {
            three.push_back(n);
            break;
        }
        else if (n == 0) {//���� 0�̸� three�� ������ �ȵ�. ex)2%3=0~~~2 �������� 2, not 20
            break;
        }
    }
    int cnt = 1;
    int size = three.size();
    for (int i = 0; i < size; i++) {
        answer += three.back() * cnt;
        three.pop_back();
        cnt *= 3;
    }
    return answer;
}