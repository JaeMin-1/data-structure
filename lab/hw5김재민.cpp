/******************
이름 : 육종호
학번 : 20181650
프로그램 : hw5_육종호.cpp
Description : Shortest path 알고리즘을 이용하여 최단경로를 찾아본다.
Algorithm : 
1. getData 함수 : 배열을 받아와 저장 및 출력 해주는 함수
2. Shortpath 함수 : 0에서 부터 다른 모든 정점까지의 최단 경로
3. choose 함수 : 각 라인에서 가장 작은 비용에 해당되는 인덱스 값을 반환해주는 함수

class 변수:
    bool found[100]; //찾았던 것인지, 아니면 처음 찾은것인지 판단
    int size;        //데이터 배열의 크기
    int Data[100][100]; //데이터 배열을 저장할 2차원 배열
    int distance[100];  //데이터의 한 라인을 저장할 1차원 베열
*******************/

#include <iostream>

#define Max 999
using namespace std;

class shortestPath
{
public:
    bool found[100];    //찾았던 것인지, 아니면 처음 찾은것인지 판단
    int size;           //데이터 배열의 크기
    int Data[100][100]; //데이터 배열을 저장할 2차원 배열
    int distance[100];  //데이터의 한 라인을 저장할 1차원 베열

    //getData 함수. 데이터 배열과, 크기를 매개변수로 받는다.
    void getData(int data[][100], int size)
    {
        this->size = size;
        cout << "      ";
        for (int i = 0; i < size; i++)
            cout << "   ";

        cout << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "   ";
            for (int j = 0; j < size; j++)
            {
                Data[i][j] = data[i][j];
                if (Data[i][j] < 100) // 크기가 100보다 작으면 공백 한칸
                {
                    cout << " ";
                    if (Data[i][j] < 10) // 크기가 10보다 작으면 공백 한칸 추가.
                    {
                        cout << " ";
                    }
                }
                cout << Data[i][j] << "  ";
            }
            cout << endl;
        }
    }
    /*
    //Shortest path 함수. 최단경로를 찾아주는 함수
    //var:  
            found : 방문 여부 확인.
            distance : 데이터 한 라인을 받아 저장
            u : 데이터의 각 라인 중에서 가장 작은 비용이 해당되는 인덱스 값.
    */
    void Shortpath()
    {
        cout << "Beginning Dist->    ";
        for (int i = 0; i < size; i++)
        {
            found[i] = false;
            distance[i] = Data[0][i];
            cout << distance[i] << " ";
        }
        cout << endl
             << endl;
        found[0] = true; //시작 지점 방문
        distance[0] = 0; //시작 지점 초기화

        for (int i = 0; i < size - 1; i++)
        {
            int u = choose();
            found[u] = true;
            cout << "Select[" << u << "] dist:     ";
            for (int w = 0; w < size; w++)
            {
                if (found[w] == false)
                {
                    if (distance[u] + Data[u][w] < distance[w])
                    {
                        distance[w] = distance[u] + Data[u][w];
                    }
                }
                cout << distance[w] << " ";
            }
            cout << endl;
        }
    }

    /*
    class: chosse
    description : 가장 작은 값 반환
    var:
         min 가장 작은 비용 저장
         minnode 가장 작은 비용 인덱스 저장
    */
    int choose()
    {
        int minnode;
        int min = 999;
        for (int i = 0; i < size; i++)
        {
            if (distance[i] < min && !found[i])
            {
                minnode = i;
                min = distance[i];
            }
        }
        return minnode;
    }
};

int main()
{
    int cost[][100] = {
        {0, 50, 10, Max, 45, Max},
        {Max, 0, 15, Max, 10, Max},
        {20, Max, 0, 15, Max, Max},
        {Max, 20, Max, 0, 35, Max},
        {Max, Max, Max, 30, 0, Max},
        {Max, Max, Max, 3, Max, 0},
    };
    shortestPath s1;
    cout << "*******  Adjacency matrix  *******" << endl;
    s1.getData(cost, 6);
    cout << endl;
    cout << "*******  Shortest Path  *******" << endl
         << endl;
    s1.Shortpath();
    cout << endl;

    int cost1[][100] = {
        {0, 3, 5, 9, Max, Max},
        {3, 0, 3, 4, 7, Max},
        {5, 3, 0, 2, 6, 8},
        {9, 4, 2, 0, 2, 2},
        {Max, 7, 6, 2, 0, 5},
        {Max, Max, 8, 2, 5, 0},
    };
    shortestPath s2;
    cout << "*******  Adjacency matrix  *******" << endl;
    s2.getData(cost1, 6);
    cout << endl;
    cout << "*******  Shortest Path  *******" << endl
         << endl;
    s2.Shortpath();
    return 0;
}