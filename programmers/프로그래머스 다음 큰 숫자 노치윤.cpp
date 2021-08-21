#include <string>
#include <vector>
using namespace std;

string make_bi(int num) {
    string ans = "";
    while (num != 0) {
        ans = to_string(num % 2) + ans;
        num /= 2;
    }
    return ans;
}
int solution(int n) {
    int answer = 0;
    string num = make_bi(n);
    int cnt = num.length() - 1;
    bool find = false;//�ڿ��� ��ĭ�� ���ٰ� 1�� ������ true�� �ٲ�
    int zero_finish = cnt;
    while (cnt >= 0) {
        if (!find && num[cnt] == '0') {
            cnt--;
            continue;
        }
        if (find && num[cnt] == '0') break;
        if (num[cnt] == '1') {
            if (!find) zero_finish = cnt + 1;//ó������ 1�� ������ 0�� ������ �ε����� ����.
            find = true;
        }
        cnt--;
    }//111~~~0'0(cnt)'111'0(zero_finish)'0
    int zero = num.length() - zero_finish;//�ڿ��� 1�� �������� ������ �������� 0�� ����
    int one = zero_finish - cnt - 1;//�ڿ��� 1�� �������� ������ �������� 1�� ����, ex) 1110000111100 -> zero=2, one=4

    string revised_num = "";
    if (cnt < 0) {//111110�� ��� 1011110 ����, 1�� �������� ������ ������ �� ó�� �ε��� ���� ���ӵ� ��� cnt = -1 �̴�.
        string temp1(zero, '0');
        string temp2(one - 1, '1');
        revised_num = "10" + temp1 + temp2;
    }
    else {
        string temp = num.substr(0, cnt);
        string temp1(zero, '0');
        string temp2(one - 1, '1');
        revised_num = temp + "10" + temp1 + temp2;//���� ���ڴ� temp+01+temp2+temp1 �̿���. �̸� temp+10+temp1+temp2�� �ٲٸ� �ּ�
    }
    int two = 1;
    for (int i = revised_num.length() - 1; i >= 0; i--) {//�ٽ� 10������
        answer += (revised_num[i] - '0') * two;
        two *= 2;
    }
    return answer;
}