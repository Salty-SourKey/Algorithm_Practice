#include <iostream>
using namespace std;

int uni[100000];

//정점 a가 root인지 확인
int root(int a){ 
    //음수가 들어있으면 root
    if(uni[a] < 0) return a;

    //양수라면 재귀적으로 root 탐색
    return uni[a] = root(uni[a]);
}

//정점 a와 b를 연결 / 이미 연결되있다면 false 리턴
bool connect(int a, int b){
    a = root(a); //정점 a의 부모 위치로 변경
    b = root(b); //정점 b의 부모 위치로 변경

    if(a==b) return false;

    //더 크기가 큰 정점으로 합칠 것이므로 크기 비교 후 교체
    if(uni[a] > uni[b]){
        a ^= b; //XOR 연산자
        b ^= a;
        a ^= b;
    }

    //정점 a와 정점 b의 결합, 정점 b의 부모를 a로 설정
    uni[a] = uni[a] + uni[b];
    uni[b] = a;
    return true;
}

//정점 a와 정점 b가 같은 그룹인지 확인
bool isConnect(int a, int b){
    return root(a) == root(b);
}

//정점 a를 포함하는 그룹의 정점 수 출력
int size(int a){
    return -uni[root(a)];
}

int main()
{
    int a = 5;
    int b = 10;
    a = a ^ b;
    b = b ^ a;

    cout << a << " " << b << endl;

}