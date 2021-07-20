#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> days;//�ɸ��� �۾��ϼ� ���
    for (int i = 0; i < progresses.size(); i++) {
        double a = (double)(100 - progresses[i]) / speeds[i];
        if (a != (int)a) days.push_back((int)a + 1);
        else days.push_back((int)a);
    }

    vector<int> cnt;
    int n = 0;
    int cmp = 1;
    while (true) {
        if (n >= days.size()) {
            break;
        }
        if (n + cmp < days.size() && days[n] >= days[n + cmp]) {//�ڽź��� �۾��ϼ��� ���� ���� �ڿ� ������ cmp++
            cmp++;
        }
        else {//days[n] < days[n + cmp] �̸� cmp�� �ʱ�ȭ. n�� n+cmp�� �ʱ�ȭ
            n = n + cmp;
            cnt.push_back(cmp);
            cmp = 1;
        }
    }
    return cnt;
}