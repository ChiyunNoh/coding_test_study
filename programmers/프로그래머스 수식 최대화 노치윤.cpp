#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(string expression) {
    vector<long long> num;//expression �� ���ڵ� �����ϴ� ����
    vector<char> symbol;/expression �� ��ȣ �����ϴ� ����
    int index = 0;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] > '9' || expression[i] < '0') {
            int number = stoi(expression.substr(index, i));
            num.push_back((long long)number);
            index = i + 1;
            symbol.push_back(expression[i]);
        }
    }
    int number = stoi(expression.substr(index));
    num.push_back((long long)number);

    long long answer = 0;
    vector<char> oper = { '*','+','-' };
    do {
        vector<long long> temp_n = num;
        vector<char> temp_s = symbol;
        for (int i = 0; i < 3; i++) {//��� +, - * ���� �Ѱ��� ���ڸ� ���Ե�.(���� ���� �����)
            vector<long long> temp_num;
            vector<char> temp_oper;
            for (int j = 0; j < temp_s.size(); j++) {
                if (temp_s[j] == oper[i]) {//���� �켱������ �ش��ϴ� ��ȣ�̸� ���� �� ����ϰ� �� �ε����� ���ڴ� Ǫ�� ����.
                    if (oper[i] == '+') temp_n[j + 1] = temp_n[j] + temp_n[j + 1];
                    else if (oper[i] == '-') temp_n[j + 1] = temp_n[j] - temp_n[j + 1];
                    else if (oper[i] == '*') temp_n[j + 1] = temp_n[j] * temp_n[j + 1];
                }
                else {
                    temp_num.push_back(temp_n[j]);
                    temp_oper.push_back(temp_s[j]);
                }
            }
            temp_num.push_back(temp_n[temp_n.size() - 1]);
            temp_n = temp_num;
            temp_s = temp_oper;
        }
        //��, �����
        if (answer < abs(temp_n[0])) {
            answer = abs(temp_n[0]);
        }
    } while (next_permutation(oper.begin(), oper.end()));

    return answer;
}