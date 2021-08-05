#include <string>
#include <vector>
#include <set>
#include <utility>
#include <iostream>
using namespace std;

void move(vector<string>& board, set<pair<int, int>> index, int m, int n) {
    vector<int> cnt(n, 0);//�����ٸ��� ������� ���� ������ ������ ����.
    for (auto iter = index.begin(); iter != index.end(); iter++) {
        board[(*iter).first][(*iter).second] = '0';//��Ģ�� ���� ������� ���ҵ��� 0���� �ٲ���.
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == '0') {
                cnt[j] += 1;
            }
        }
    }

    vector<string> temp(n, "");//�����ٸ��� ������� ���Ҹ� ���� �ø��� �������� ������ ������ string �� ���� ����� ����. ex) ������: "A00BC"->"00ABC"
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            temp[i] += '0';
        }
        for (int j = 0; j < m; j++) {
            if (board[j][i] != '0') {
                temp[i] += board[j][i];
            }
        }
    }


    vector<string> ans(m, "");//�������� �ٽ� �����ٷ�.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[j] += temp[i][j];
        }
    }

    board = ans;//board ������Ʈ
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (true) {
        set<pair<int, int>> index;//����� �ε������� �����ϴ� set.
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {//��Ģ�� ���� ����� �ε����� ã�� loop
                if (board[i][j] == board[i + 1][j] && board[i][j + 1] == board[i + 1][j + 1] && board[i][j] == board[i][j + 1] && board[i][j] != '0') {
                    index.insert(make_pair(i, j));
                    index.insert(make_pair(i + 1, j));
                    index.insert(make_pair(i + 1, j + 1));
                    index.insert(make_pair(i, j + 1));
                }
            }
        }
        answer += index.size();
        if (index.size() == 0) break;//�ϳ��� ������� �� ���ٸ� ��.
        move(board, index, m, n);//����� �͵��� 0���� �ٲٰ� �� ���� ���ҵ��� �Ʒ��� �����ִ� �Լ�
    }
    return answer;
}