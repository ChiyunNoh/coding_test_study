#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<vector<string>> repos;// ���� ����, ��� ��ε� ���� ����
    vector<int> music_len;//���� ��� �ð� ����

    for (int i = 0; i < musicinfos.size(); i++) {
        vector<int> location;//,�� �ε����� �����Ұ���.
        for (int j = 0; j < musicinfos[i].size(); j++) {
            if (musicinfos[i][j] == ',') {
                location.push_back(j);
            }
        }
        string s1, s2, s3, s4;
        s1 = musicinfos[i].substr(0, location[0]);
        s2 = musicinfos[i].substr(location[0] + 1, location[1] - location[0] - 1);
        s3 = musicinfos[i].substr(location[1] + 1, location[2] - location[1] - 1);
        s4 = musicinfos[i].substr(location[2] + 1);

        for (int k = 0; k < s4.length(); k++) {
            if (s4[k] == '#') {
                s4[k - 1] = tolower(s4[k - 1]);//C#�� c#���� �ҹ���ȭ. �׳� C�� ����ȭ�ϱ� ����
            }
        }
        s4.erase(remove(s4.begin(), s4.end(), '#'), s4.end());//��� #�� ����

        int s1_hour = stoi(s1.substr(0, 2));
        int s1_mi = stoi(s1.substr(3));
        int s2_hour = stoi(s2.substr(0, 2));
        int s2_mi = stoi(s2.substr(3));
        if (s1_hour != s2_hour) {
            if (s2_hour < s1_hour) s2_hour += 24;//���� �뷡 ��� ���� �Ϸ簡 �������� 24 ������.
            s2_mi += (s2_hour - s1_hour) * 60;
        }
        music_len.push_back(s2_mi - s1_mi);
        vector<string> temp;
        temp.push_back(s3);//�̸�
        string a = "";
        for (int j = 0; j < (s2_mi - s1_mi) / s4.length(); j++) {
            a += s4;
        }
        a += s4.substr(0, (s2_mi - s1_mi) % s4.length());
        temp.push_back(a);//a�� ������ ����Ǵ� ���� ���� ��ε� ����.
        repos.push_back(temp);
    }

    for (int i = 0; i < m.size(); i++) {
        if (m[i] == '#') {
            m[i - 1] = tolower(m[i - 1]);//C#�� c#���� �ҹ���ȭ. �׳� C�� ���ϱ� ����
        }
    }
    m.erase(remove(m.begin(), m.end(), '#'), m.end());

    int longest_idx = -1;
    for (int i = 0; i < repos.size(); i++) {
        if (repos[i][1].find(m) != string::npos) {
            if (longest_idx == -1) longest_idx = i;
            else if (music_len[longest_idx] < music_len[i]) {//��� �ð��� �� ��� longest_idx �ٲ�.
                longest_idx = i;
            }
        }
    }
    if (longest_idx == -1) {
        answer = "(None)";
        return answer;
    }
    answer = repos[longest_idx][0];
    return answer;
}