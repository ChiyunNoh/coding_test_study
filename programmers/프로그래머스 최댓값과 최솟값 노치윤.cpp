#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    int idx = 0;//ó�� ������ ��ĭ�� �ε����� ����� ����
    while (true) {//min �� max�� ù ��° ������ ���ڷ� �ʱ�ȭ �ϱ� ���� ù��° ���ڸ� ã�´�.
        if (s[idx] == ' ') break;
        temp += s[idx];
        idx++;
    }
    int min = stoi(temp);
    int max = stoi(temp);
    temp = "";
    s += " ";//"����+��ĭ" �������� �ڸ��� ���� �� ���������� ��ĭ�� �߰�����.
    for (int i = idx + 1; i < s.length(); i++) {
        if (s[i] != ' ') {
            temp += s[i];
        }
        if (s[i] == ' ') {
            if (min > stoi(temp)) min = stoi(temp);
            if (max < stoi(temp)) max = stoi(temp);
            temp = "";
        }
    }
    answer += to_string(min) + " ";
    answer += to_string(max);
    return answer;
}