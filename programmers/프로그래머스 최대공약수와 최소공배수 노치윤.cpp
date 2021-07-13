#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> divisor(int num) {//����� ����ִ� ���͸� �����ϴ� �Լ�
    vector<int> temp;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            temp.push_back(i);
        }
    }
    return temp;
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    vector<int> n_divisor = divisor(n);
    vector<int> m_divisor = divisor(m);
    int GCD;
    for (int i = n_divisor.size() - 1; i >= 0; i--) {//n�� ��� ���� ū ������ ���ʷ� m�� ����� ����ִ� ���Ϳ� �ִ��� �Ǵ�
        if (find(m_divisor.begin(), m_divisor.end(), n_divisor[i]) != m_divisor.end()) {
            answer.push_back(n_divisor[i]);
            GCD = n_divisor[i];
            break;
        }
    }
    answer.push_back(n * m / GCD);
    return answer;
}