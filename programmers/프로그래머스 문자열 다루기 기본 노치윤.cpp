#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(string s) {
    bool answer = true;
    sort(s.begin(), s.end());
    if (s.length() == 4 || s.length() == 6) {
        if (s[s.length() - 1] > '9' || s[0] < '0') {
            //���� ASCII�ڵ尡 ū ����, ���� ���Ұ� ���� ������ ����� ���ڰ� �ƴ� ���ڰ� �����Ѵٴ� ��.
            answer = false;
        }
        return answer;
    }
    return false;
}