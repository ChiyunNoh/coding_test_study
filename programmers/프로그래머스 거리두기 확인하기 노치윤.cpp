#include <string>
#include <vector>
#include <utility>
using namespace std;

bool dist(pair<int, int> a, pair<int, int> b, vector<vector<string>> places, int i) {//������� �ֱ⿡ a�� ������ b���� �۴�.(x���� ���ٸ� y���� �۰�, y���� ���ٸ� x���� ����)
    if (abs(a.second - b.second) + abs(a.first - b.first) > 2) {
        return true;
    }
    else {
        if (a.first == b.first) {
            if (abs(a.second - b.second) == 2 && places[i][a.first][a.second + 1] == 'X') return true;
        }
        else if (a.second == b.second) {
            if (abs(a.first - b.first) == 2 && places[i][a.first + 1][a.second] == 'X') return true;
        }
        else if (a.second != b.second) {
            if (places[i][b.first][a.second] == 'X' && places[i][a.first][b.second] == 'X') return true;
        }
    }
    return false;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < 5; i++) {//������ ���� �ǹ�
        vector<pair<int, int>> vec;
        for (int j = 0; j < 5; j++) {
            for (int a = 0; a < 5; a++) {
                if (places[i][j][a] == 'P') {
                    vec.push_back(make_pair(j, a));//p�� �ִ� ��ǥ�� vec�� Ǫ��
                }
            }
        }
        int size = vec.size();
        int cont = 0;
        for (int k = 0; k < size - 1; k++) {
            if (cont == 1) {
                break;
            }
            for (int z = k + 1; z < size; z++) {
                bool check = dist(vec[k], vec[z], places, i);
                if (check == false) {

                    answer.push_back(0);
                    cont = 1;
                    break;
                }
            }
        }
        if (cont == 0) {
            answer.push_back(1);
        }
    }

    return answer;
}