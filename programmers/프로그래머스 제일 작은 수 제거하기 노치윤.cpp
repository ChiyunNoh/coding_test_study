#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (arr.size() == 1) {
        answer.push_back(-1);
    }
    else {
        vector<int> temp = arr;
        sort(arr.begin(), arr.end());//���� ���� ������ ��ġ�� ã�� ���� 14~21��°
        int num = arr[0];
        for (vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++) {
            if (*iter == num) {
                temp.erase(iter);
                break;
            }
        }
        answer = temp;
    }
    return answer;
}

//14~21��° ���� min_element �Լ�(���ͷ����� ����)�� �ܼ�ȭ ��ų�� ����
/*
arr.erase(min_element(arr.begin(), arr.end()));

min_element(arr.begin(), arr.end()) : ���� ���� ���� ��ġ�� ���ͷ����� ����
erase: �־��� ���ͷ����� ��ġ�� �� ����

*/