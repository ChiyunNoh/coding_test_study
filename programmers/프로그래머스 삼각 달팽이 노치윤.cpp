#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> check;
vector<vector<int>> num;
void rotate(int x, int y, int n) {
    if (check[x + 1][y]) return;
    int cnt = num[x][y];
    check[x][y] = true;
    x++;
    while (x < n) {//���� �Ʒ��� ��������
        if (check[x][y]) break;
        check[x][y] = true;
        num[x][y] = ++cnt;
        x++;
    }
    x--;//while������ ���������� ���� x���ֱ�
    y++;
    while (y < n) {
        if (check[x][y]) break;
        check[x][y] = true;
        num[x][y] = ++cnt;
        y++;
    }
    y--;//while������ ���������� ���� y���ֱ�
    x--;
    y--;
    while (x >= 0 && y >= 0) {
        if (check[x][y]) break;
        check[x][y] = true;
        num[x][y] = ++cnt;
        x--;
        y--;
    }
    x++;//while������ ���������� �� x�����ֱ�
    y++;//while������ ���������� �� y�����ֱ�
    rotate(x, y, n);
}

vector<int> solution(int n) {
    vector<int> answer;
    //1�� 2�� ������ �ɷ����� �����Ƿ� ���� üũ.
    if (n == 1) {
        answer.push_back(1);
        return answer;
    }
    if (n == 2) {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
        return answer;
    }
    for (int i = 0; i < n; i++) {
        vector<bool> temp;
        vector<int> tmp;
        for (int j = 0; j <= i; j++) {
            temp.push_back(false);
            tmp.push_back(1);
        }
        check.push_back(temp);
        num.push_back(tmp);
    }
    rotate(0, 0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(num[i][j]);
        }

    }
    return answer;
}