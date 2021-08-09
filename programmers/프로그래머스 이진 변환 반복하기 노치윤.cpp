#include <string>
#include <vector>

using namespace std;
string makebinary(int a) { //ó������ int �� ��ȯ�� ��. ������ ���ڰ� Ŀ���� ���� ���� ǥ�� ���ؼ� ��� error�� ����. �׷��� string���� ��ȯ.
    string temp = "";
    while (a != 0) {
        temp += to_string(a % 2);
        a = a / 2;
    }
    return temp;
}
vector<int> solution(string s) {
    vector<int> answer(2, 0);
    while (s != "1") {
        int temp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') temp++;
        }
        answer[1] += temp;//0�� ���� ���ϱ�.
        s = (makebinary(s.length() - temp));//1�� ������ ������ ����� s�� �ٽ� ����.(��� s�� ������� ���������� ���� ������ �ʿ� x)
        answer[0]++;

    }
    return answer;
}