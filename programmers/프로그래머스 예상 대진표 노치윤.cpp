using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    while (true) {
        a = (a - 1) / 2 + 1;//a�� ���� ���� ��ȣ
        b = (b - 1) / 2 + 1;//b�� ���� ���� ��ȣ
        if (a == b) {//a,b�� �ºٰ� �Ǵ� ��� �� ���� ���� ��ȣ�� ���Ե�.
            break;
        }
        else {
            answer++;
        }
    }

    return answer;
}