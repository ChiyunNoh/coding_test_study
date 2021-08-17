#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> m;//�˻��� �����ϰ� hashmap ���
    char start = 'A';
    for (int i = 1; i <= 26; i++) {
        string temp = "";
        temp += start;
        m.insert(make_pair(temp, i));
        start++;
    }//A���� Z����
    int last_idx = 26;//hashmap �μ�Ʈ �Ǿ���ϴ� idx
    int cur_idx = 0;
    string w = "";
    while (cur_idx != msg.length()) {
        string temp = w;
        w += msg[cur_idx];
        if (m.find(w) != m.end()) {//ã��
            cur_idx++;
            if (cur_idx == msg.length()) {//���������� hashmap�� ������� �ʰ� �����⿡ ���� ����
                answer.push_back(m[w]);
            }
        }
        else {
            last_idx++;
            m.insert(make_pair(w, last_idx));
            answer.push_back(m[temp]);//temp���� hashmap�� �ִ� ������ ���� �� ���Ұ� ����Ǿ�����.
            w = "";
        }
    }
    return answer;
}