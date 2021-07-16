#include <string>
#include <vector>
#include <iostream>
using namespace std;
int compress(string s, int n) {//n���� s�� �����ؼ� ���̸� �����ϴ� �Լ�
    int cnt = s.length() / n;
    int count = 1;
    int num = 1;
    vector<int> vec;//���� ���� ����
    vector<string> s_vec;//�ݺ����ڿ� ����
    for (int i = 0; i < cnt; i++) {
        if (s.substr(i * n, n) == s.substr((i + 1) * (n), n)) {
            num += 1;
        }
        else {
            vec.push_back(num);
            s_vec.push_back(s.substr(i * n, n));
            num = 1;
        }
    }
    if (s.length() % n != 0) {//������ ���� ���ڿ� ó��
        vec.push_back(1);
        s_vec.push_back(s.substr(cnt * n, n));
    }
    string temp = "";
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == 1) {
            temp += s_vec[i];
        }
        else {
            temp += to_string(vec[i]) + s_vec[i];
        }
    }
    return temp.length();
}

int solution(string s) {
    int answer = 0;
    int min = s.length();
    for (int i = 1; i <= s.length() / 2; i++) {
        int n = compress(s, i);
        if (n < min) {
            min = n;
        }
    }
    answer = min;
    return answer;
}