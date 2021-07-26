#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> brace_left;//{�� �ε����� ���� ����
    vector<int> brace_right;//}�� �ε����� ���� ����

    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == '{') brace_left.push_back(i);
        else if (s[i] == '}') brace_right.push_back(i);
    }

    vector<int> brace;//{ �� } ���� �Ÿ��� ���� ���� - ���� ���� �ͺ��� ���ʷ� �� ������ ���� ������ ��������.
    for (int i = 0; i < brace_left.size(); i++) {
        brace.push_back(brace_right[i] - brace_left[i]);
    }
    sort(brace.begin(), brace.end());

    for (int i = 0; i < brace.size(); i++) {//{ } ���� ���� ������ ���� �ͺ��� ���ʷ� answer�� ������ �ϼ�!

        //ex. {{2},{2,1},{2,1,3},{2,1,3,4}} �ΰ�� 2���� answer�� �ְ�, {2,1}���� 2�� �̹� answer�� �����Ƿ� 1�� �ְ�, {2,1,3}���� 2,1�� �̹� �����Ƿ� 3�� �ְ�~
        string temp = "";
        vector<int> repos;//,�� idx ����.
        for (int j = 0; j < brace_left.size(); j++) {
            if (brace_right[j] - brace_left[j] == brace[i]) {
                temp = s.substr(brace_left[j] + 1, brace[i] - 1);//temp���� {2,1,3}�� ��� 2,1,3�� ���.
                break;
            }
        }
        if (i == 0) {//���� ���� brace[0]�� temp���� ���� ���ڸ� �ֱ⿡ �̸� �ٷ� int������ ��ȯ�� answer�� Ǫ��
            answer.push_back(stoi(temp));
            continue;
        }
        repos.push_back(-1);//49��° ���� �����ϰ� �ϱ� ���� �ʿ�.
        for (int k = 0; k < temp.size(); k++) {
            if (temp[k] == ',') {
                repos.push_back(k);
            }
        }

        for (int z = 0; z < repos.size(); z++) {
            string t = "";
            if (z == repos.size() - 1) {
                t += temp.substr(repos[z] + 1);
            }
            else t += temp.substr(repos[z] + 1, repos[z + 1] - repos[z] - 1);
            //t���� ���ڸ� ���. ex) temp�� 2,1,3 �ΰ�� for ������ ���鼭 2 1 3 �� ���ʷ� t�� ���
            auto it = find(answer.begin(), answer.end(), stoi(t));
            if (it == answer.end()) {// ���� t�� answer�� ���ٸ� Ǫ��
                answer.push_back(stoi(t));
                break;
            }
        }

    }

    return answer;
}