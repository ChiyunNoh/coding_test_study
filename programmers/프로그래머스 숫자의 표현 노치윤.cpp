#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    //x���� ���ӵ� a���� �� = (2x+a-1)*a/2=n => 2n=(2x+a-1)*a
    //x �� a �� ��� �ڿ��� �̹Ƿ� (2x+a-1) > a , (2x+a-1)�� a (Ȧ��. ¦��) , (¦��, Ȧ��)
    n *= 2;
    for (int i = 1; i * i < n; i++) {
        if (n % i == 0) {
            if ((i + n / i) % 2 == 1) answer++;
            //n/i �� (2x+a-1), i�� a�� �ش�. Ȧ��, ¦�� �̿��� �ϹǷ� ���� Ȧ�� ���� üũ.
        }
    }
    return answer;
}