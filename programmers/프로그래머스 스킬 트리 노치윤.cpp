#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); i++) {
        vector<int> order;//skill_trees[i]���� skill ���� ã���� �� skill ���ڿ��� ���� ��°�� �� �ִ� ����
        order.push_back(0);//ó�� ���Ϳ� 0�� �־������ν� ����ȭ ����.
        for (int j = 0; j < skill_trees[i].length(); j++) {
            int check = 0;
            for (int k = 0; k < skill.length(); k++) {
                if (skill_trees[i][j] == skill[k]) {//skill���ڿ��� ���Ҷ��
                    if (order.back() != k) {//�ռ� ���� ��ų�� ��°���� k�� �ƴϸ� �Ұ����� ��ų Ʈ��.(�ڽ��� k+1��° �����̹Ƿ� k��° ���Ұ� ������ �Ǿ����)
                        check = 1;
                        break;
                    }
                    order.push_back(k + 1);
                }
            }
            if (check == 1) break;
            if (j == skill_trees[i].length() - 1) {//������ �� �˻��� ���.
                if (check == 0) {
                    answer++;
                }
            }
        }
    }
    return answer;
}