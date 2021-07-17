#include <vector>
#include <string>
#include <iostream>
using namespace std;

int solution(string s)
{
    int answer = -1;
    vector<char> temp;
    temp.push_back(s[0]);
    for (int i = 1; i < s.length(); i++) {
        if (temp.size() == 0) {
            temp.push_back(s[i]);
        }
        else if (temp.back() == s[i]) {
            temp.pop_back();
        }
        else {
            temp.push_back(s[i]);
        }
    }
    if (temp.size() != 0) {
        answer = 0;
    }
    else {
        answer = 1;
    }
    return answer;
}

//substr�� ���ο� �޸� ������ �Ҵ��ϰ� �� ������ ���ڿ��� �Űܾ� �ϱ⿡ ȿ���� ���鿡�� ������ �� �ۿ� ����!