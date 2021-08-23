#include <iostream>
#include <vector>
using namespace std;

void max_idx(vector<vector<int> >& land, int row) {//row ���� ������ �ε����� �� �� �ִ� ���� �ִ񰪵��� ���� 
    for (int i = 0; i < land[row].size(); i++) {
        int max = 0;
        for (int j = 0; j < land[row - 1].size(); j++) {
            if (j == i) continue;
            if (max < land[row - 1][j]) max = land[row - 1][j];
        }
        land[row][i] += max;
    }
}
int solution(vector<vector<int> > land)
{
    int answer = 0;

    for (int i = 1; i < land.size(); i++) {
        max_idx(land, i);
    }

    for (int i = 0; i < land[land.size() - 1].size(); i++) {//������ ���� �ִ��� ����!
        if (land[land.size() - 1][i] > answer) answer = land[land.size() - 1][i];
    }

    return answer;
}