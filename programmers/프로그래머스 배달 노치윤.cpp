#include <iostream>
#include <vector>
#include <utility>
using namespace std;


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<int>> weight(N, vector<int>(N, 500001));
    vector<bool> visit(N, false);
    vector<int> dist(N, 500001);
    for (int i = 0; i < road.size(); i++) {//��� ������ ��ķ� ǥ��.
        if (weight[road[i][0] - 1][road[i][1] - 1] > road[i][2]) {
            weight[road[i][0] - 1][road[i][1] - 1] = road[i][2];
        }
        if (weight[road[i][1] - 1][road[i][0] - 1] > road[i][2]) {
            weight[road[i][1] - 1][road[i][0] - 1] = road[i][2];
        }
    }

    //���ͽ�Ʈ�� ����.
    dist[0] = 0;
    visit[0] = true;

    for (int i = 1; i < N; i++) {
        dist[i] = weight[0][i];
    }

    for (int i = 1; i < N; i++) {
        //������� �湮 ���� ���� �� �ּ� �Ÿ� ���ϱ�.
        int Min_Dist, Min_Idx;
        Min_Dist = 500001;
        Min_Idx = -1;

        for (int i = 1; i < N; i++)
        {
            if (visit[i] == true) continue;
            if (dist[i] < Min_Dist)
            {
                Min_Dist = dist[i];
                Min_Idx = i;
            }
        }
        int NewNode = Min_Idx;//�ּ��ε���
        visit[NewNode] = true;//�ּ��ε��� ��带 �湮.
        for (int i = 1; i < N; i++) {//relaxation ����.
            if (visit[i] == true) continue;
            if (dist[i] > dist[NewNode] + weight[NewNode][i])
                dist[i] = dist[NewNode] + weight[NewNode][i];
        }
    }

    for (int i = 0; i < N; i++) {
        if (dist[i] <= K) {
            answer++;
        }
    }

    return answer;
}