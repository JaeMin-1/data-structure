////////////////////////////////////////////////////////////////////////
// Lab11 : Prim's Algorithm (Minimal Spanning Tree) 
// Name : 김재민
// ID : 20181592
/////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int cost[][100] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 100, 6, 1, 5, 100, 100},
        {0, 6, 100, 4, 100, 3, 100},
        {0, 1, 4, 100, 5, 6, 5},
        {0, 5, 100, 5, 100, 100, 2},
        {0, 100, 3, 6, 100, 100, 6},
        {0, 100, 100, 5, 2, 6, 100},
};

class MST {
public:
    int total = 0;
    int lowcost[10];
    int closest[10];

    void print(int cost[][100], int size) {
        cout << "      ";
        for (int i = 1; i < size; i++)
            cout << "v" << i << "   ";
        cout << endl;
        for (int i = 1; i < size; i++) {
            cout << "v" << i << "   ";
            for (int j = 1; j < size; j++) {
                if (cost[i][j] < 10) {
                    cout << "  ";
                }
                else if ( 10 <= cost[i][j] && cost[i][j] < 100) {
                    cout << " ";
                }
                cout << cost[i][j] << "  ";
            } cout << endl;
        }
    }

    void mst(int cost[][100], int size) {
        int T = 0;
        int k = 0;
        int large = 120;

        for (int i = 1; i < size; i++) {
            lowcost[i] = cost[1][i];
            closest[i] = 1;
        }
        while(T < size - 2) {
            for (int i = 1; i < size; i++) {
                int min = lowcost[i];
                k = i;
                for (int j = 1; j < size; j++) {
                    if (lowcost[j] < min) {
                        min = lowcost[j];
                        k = j;
                    }
                }   
            }
            cout << closest[k] << " , " << k << endl;
            total += lowcost[k];
            lowcost[k] = large;
            cost[k][closest[k]] = large;

            for (int j = 1; j < size; j++) {
                if (cost[k][j] < lowcost[j]&&lowcost[j] <large) { //lowcost[j] < large
                    lowcost[j] = cost[k][j];
                    closest[j] = k;
                }
            } T++;
        }
    }
};   

int main() {
    MST m;
    cout << "******   Weighted Graph   ******" << endl << endl;
    m.print(cost, 7);
    cout << endl;
    cout << "*****  Minimal Spanning Tree  *****" << endl << endl;
    m.mst(cost, 7);
    cout << "Total = " << m.total;

    return 0;
}