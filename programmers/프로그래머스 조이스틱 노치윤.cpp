#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    string start = "";
    start.append(name.length(), 'A');
    vector<int> up_down;
    int min = 500;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] > 'N') {
            up_down.push_back(26 - (name[i] - 'A'));
        }
        else {
            up_down.push_back(name[i] - 'A');
        }
    }
    //���� up_down���� �� ���ں� Ŀ���� �������� �ϴ� Ƚ���� �����.
    for (int i = 0; i < name.length(); i++) {//Ŀ���� i index���� ��� �̵��ϰ� �� �������� �ٽ� �·� �̵�. �̸� �ݺ��ϸ鼭 �ּ� Ƚ���� ã��
        vector<int>::iterator iter = up_down.begin();
        iter = iter + i;//���� ��ġ index=i;
        string temp = start;//temp="AAA~"
        int cnt = i;//ó���� Ŀ���� ���������� i�� �������� �ϹǷ�
        int idx = i;
        while (temp != name) {
            cnt += *iter;//�� ��ġ�� ���Ʒ� Ŀ���� �������� �ϴ� Ƚ�� ����.
            if (iter == up_down.begin()) {
                iter = up_down.end();
            }
            iter--;
            cnt++;//�·� �����̴� Ŀ��
            temp[idx] = name[idx];
            if (idx == 0) {//index 0���� �������� ���� �� ������ �ε����ش�
                idx = name.length() - 1;
            }
            else {
                idx--;
            }
        }
        if (cnt < min)min = cnt;
    }
    if (min == 0) return min;

    return min - 1;//���������� Ŀ���� �������� �ʾƾ� �ϴµ� ���������Ƿ�.
}