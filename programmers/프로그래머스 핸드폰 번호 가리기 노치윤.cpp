#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    answer.append(phone_number.length() - 4, '*');//phone_number.length() - 4���� ���� '*'�� �����δ�
    answer += phone_number.substr(phone_number.length() - 4);
    return answer;
}