#include <vector>
#include <deque>
#include<utility>
#include <iostream>
using namespace std;
void BFS_(vector<vector<int>> picture, vector <vector<int>>& check, deque<pair<int, int>> BFS, int& size) {
    if (BFS.size() == 0) {
        return;
    }
    int i = BFS[0].first;
    int j = BFS[0].second;
    check[i][j] = 1;
    int x = picture.size();
    int y = picture[0].size();
    int num = picture[i][j];
    pair<int, int> temp;
    if (i == 0 && j == 0) {
        if ((i + 1) != x && num == picture[i + 1][j]) {
            if (check[i + 1][j] != 1) {
                check[i + 1][j] = 1;
                temp = make_pair(i + 1, j);
                BFS.push_back(temp);
            }
        }
        if ((j + 1) != y && num == picture[i][j + 1]) {
            if (check[i][j + 1] != 1) {
                check[i][j + 1] = 1;
                temp = make_pair(i, j + 1);
                BFS.push_back(temp);
            }
        }
    }
    else if (i != 0 && j == 0) {
        if (num == picture[i - 1][j]) {
            if (check[i - 1][j] != 1) {
                check[i - 1][j] = 1;
                temp = make_pair(i - 1, j);
                BFS.push_back(temp);
            }
        }
        if ((i + 1) != x && num == picture[i + 1][j]) {
            if (check[i + 1][j] != 1) {
                check[i + 1][j] = 1;
                temp = make_pair(i + 1, j);
                BFS.push_back(temp);
            }
        }
        if ((j + 1) != y && num == picture[i][j + 1]) {
            if (check[i][j + 1] != 1) {
                check[i][j + 1] = 1;
                temp = make_pair(i, j + 1);
                BFS.push_back(temp);
            }
        }
    }
    else if (i == 0 && j != 0) {
        if (num == picture[i][j - 1]) {
            if (check[i][j - 1] != 1) {
                check[i][j - 1] = 1;
                temp = make_pair(i, j - 1);
                BFS.push_back(temp);
            }
        }
        if ((i + 1) != x && num == picture[i + 1][j]) {
            if (check[i + 1][j] != 1) {
                check[i + 1][j] = 1;
                temp = make_pair(i + 1, j);
                BFS.push_back(temp);
            }
        }
        if ((j + 1) != y && num == picture[i][j + 1]) {
            if (check[i][j + 1] != 1) {
                check[i][j + 1] = 1;
                temp = make_pair(i, j + 1);
                BFS.push_back(temp);
            }
        }
    }
    else if (i != 0 && j != 0) {
        if (num == picture[i][j - 1]) {
            if (check[i][j - 1] != 1) {
                check[i][j - 1] = 1;
                temp = make_pair(i, j - 1);
                BFS.push_back(temp);
            }
        }
        if (num == picture[i - 1][j]) {
            if (check[i - 1][j] != 1) {
                check[i - 1][j] = 1;
                temp = make_pair(i - 1, j);
                BFS.push_back(temp);
            }
        }
        if ((i + 1) != x && num == picture[i + 1][j]) {
            if (check[i + 1][j] != 1) {
                check[i + 1][j] = 1;
                temp = make_pair(i + 1, j);
                BFS.push_back(temp);
            }
        }
        if ((j + 1) != y && num == picture[i][j + 1]) {
            if (check[i][j + 1] != 1) {
                check[i][j + 1] = 1;
                temp = make_pair(i, j + 1);
                BFS.push_back(temp);
            }
        }
    }
    BFS.pop_front();
    size += 1;
    BFS_(picture, check, BFS, size);
}
// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector <vector<int>> check(picture.size(), vector<int>(picture[0].size(), 0));
    for (int i = 0; i < picture.size(); i++) {
        for (int j = 0; j < picture[i].size(); j++) {
            deque<pair<int, int>> BFS;
            if (check[i][j] == 1) {//�̹� �湮�� ���
                continue;
            }
            else {
                if (picture[i][j] != 0) {
                    int size = 0;
                    BFS.push_back(make_pair(i, j));
                    BFS_(picture, check, BFS, size);//size�� BFS queue���� �ϳ��� �������� ������ +1 �ǹǷ� �ᱹ ��� ��带 �湮�ߴ��Ķ� ���Ե�.
                    if (size > max_size_of_one_area) max_size_of_one_area = size;
                    number_of_area += 1;//BFS_�� �����ϴ� Ƚ��= ������ ����
                }
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
