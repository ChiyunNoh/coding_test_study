#include <string>
#include <vector>

using namespace std;

vector<int> find_num(int x, int y, int width, vector<vector<int>>& arr) {
    vector<int> ans(2, 0);
    if (width == 1) { //���Ұ� 1���� ���
        if (arr[x][y] == 1) ans[1]++;
        else ans[0]++;
        return ans;
    }
    int comp = arr[x][y];
    bool check = true;
    for (int i = x; i < x + width; i++) { //���� �� ��� ���Ұ� ������ Ȯ���ϴ� ����
        for (int j = y; j < y + width; j++) {
            if (arr[i][j] != comp) {
                check = false;
                break;
            }
        }
        if (!check) break;
    }
    if (check) { //���� ��� ���Ұ� ���ٸ� �� ���Ұ� 0�̶�� ans[0]++, 1�̶�� ans[1]++
        ans[comp]++;
        return ans;
    }
    //�Ѱ��� ������ �� 4���� �������� ����
    vector<int> temp1 = find_num(x, y, width / 2, arr);
    vector<int> temp2 = find_num(x + width / 2, y, width / 2, arr);
    vector<int> temp3 = find_num(x, y + width / 2, width / 2, arr);
    vector<int> temp4 = find_num(x + width / 2, y + width / 2, width / 2, arr);
    ans[0] = ans[0] + temp1[0] + temp2[0] + temp3[0] + temp4[0];
    ans[1] = ans[1] + temp1[1] + temp2[1] + temp3[1] + temp4[1];
    return ans;
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    answer = find_num(0, 0, arr.size(), arr);
    return answer;
}