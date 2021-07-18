using namespace std;

long long GCD(int w, int h) {
    for (int i = w; i > 0; i--) {
        if (w % i == 0 && h % i == 0) {
            return i;
        }
    }
}
long long solution(int w, int h) {
    long long answer = (long long)w * h;
    long long gcd = GCD(w, h);
    long long part = ((long long)w / gcd) + ((long long)h / gcd) - 1;
    //���� ���� ��ŭ �簢���� ��ġ�� ���� ����-1 �� ��ŭ �� �����ٿ� 2���� �簢���� ���ÿ� �밢���� ���� �߸��� ������ ����.(���η� �̵��Ѵٰ� ��������.)
    answer -= part * gcd;
    return answer;
}