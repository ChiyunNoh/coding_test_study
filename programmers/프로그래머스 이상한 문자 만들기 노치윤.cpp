#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            if (idx % 2 == 0) answer += toupper(s[i]);
            else answer += tolower(s[i]);
            idx++;
        }
        else {//������ ���´ٸ� �ٽ� index�� 0���� �������
            idx = 0;
            answer += ' ';
        }
    }

    return answer;
}