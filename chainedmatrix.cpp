#include <iostream>
 
using namespace std;
 
#define minimum(A, B) ((A)>(B)?(B):(A))
#define maximum_value 9999999
#define maximum_size 101
 
int M[maximum_size][maximum_size];
int d[maximum_size];
 
int main()
{
    int size = 4;
 
    d[0] = 10, d[1] = 1, d[2] = 40, d[3] = 30, d[4] = 10; //행렬 4개가 있을 때
 
    for (int diag = 0; diag < size; diag++)     //입력한 행렬의 사이즈만큼 반복한다.
    {
        for (int i = 1; i <= size - diag; i++) // i값은 상단 1부터 시작하여, 반복하는 횟수를 1씩 감소한다
        {
            int j = i + diag; //j값은 우측으로 diag만큼 반복할때마다 이동한다.
            if (j == i) //i와 j가 같을 경우 M[i][j] = 0으로 정한다.
            {
                M[i][j] = 0;
                continue;
            }
            M[i][j] = maximum_value; //k=i~j-1만큼 반복하며, 식을 입력하여 M[i][j]에 들어갈 곱의 최소값을 구한다.
            for (int k = i; k <= j - 1; k++)
                M[i][j] = minimum(M[i][j], M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j]);
 
        }
    }
 
    // 결과값 출력
    cout << M[1][size] << endl;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}