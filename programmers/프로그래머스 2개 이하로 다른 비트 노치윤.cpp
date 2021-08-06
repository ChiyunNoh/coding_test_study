#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

string makeBinary(long num) {
    string temp = "";
    while (num != 0) {
        temp += to_string(num % 2);
        num = num / 2;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 2 == 0) {
            answer.push_back(numbers[i] + 1);
        }
        else {//Ȧ�� �� ���
            string a = makeBinary(numbers[i]);
            int len = a.length();
            int cnt = 0;
            for (int j = len - 1; j >= 0; j--) {
                if (a[j] == '0') {
                    break;
                }
                else cnt++;
            }//�ڿ������� ������� 1�̳����� ������ cnt��� �ϸ� num+2^(cnt-1) �ϸ� �ּ� ���� ����. -> 01(v)11~~1 -> 1011111~~1�� �ٲٸ� �Ǳ⿡. 1(v)��ŭ�� �����ָ� ������ ���� �������� ���� ��. ���� 2^(cnt-1)�� ����. 
            answer.push_back(numbers[i] + pow(2, cnt - 1));
        }
    }
    return answer;
}