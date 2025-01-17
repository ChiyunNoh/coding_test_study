#include <string>
#include <vector>
using namespace std;

int Answer;
bool Select[8];
char ItoC[8] = { 'A','C','F','J','M','N','R','T' };

void DFS(int Cnt, char Arr[], vector<string> data)
{
    if (Cnt == 8)
    {
        for (int i = 0; i < data.size(); i++)
        {
            char N1 = data[i][0];
            char N2 = data[i][2];
            char Cond = data[i][3];
            int Dist = data[i][4] - '0';
            Dist++;

            int Idx, IIdx;
            Idx = IIdx = -1;
            for (int j = 0; j < 8; j++)
            {
                if (Arr[j] == N1) Idx = j;
                if (Arr[j] == N2) IIdx = j;
                if (Idx != -1 && IIdx != -1) break;
            }

            if (Cond == '=' && abs(Idx - IIdx) != Dist) return;
            if (Cond == '<' && abs(Idx - IIdx) >= Dist) return;
            if (Cond == '>' && abs(Idx - IIdx) <= Dist) return;
        }
        Answer++;
        return;
    }

    for (int i = 0; i < 8; i++)//순열 만들어서 Arr에 저장
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        Arr[Cnt] = ItoC[i];
        DFS(Cnt + 1, Arr, data);//인덱스가 Cnt에 ItoC[i]가 들어갔을 경우 
        Select[i] = false;//다시 false로 바꿔줌으로써 다른 경우도 계속 돌릴 수 있음.
    }
}

int solution(int n, vector<string> data)
{
    char Arr[8] = { NULL, };
    Answer = 0;
    DFS(0, Arr, data);
    return Answer;
}