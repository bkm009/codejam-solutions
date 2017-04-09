#include<bits/stdc++.h>
using namespace std;

int fathestE(int A, vector<int> B, int j){

    if(B.size() == 0)
        return -1;
    int V[A], E = B[0];

    for(int i=0; i<A; i++)
        V[i] = 0;

    for(int i=j; i<B.size(); i++){
        if(V[B[i]] == 0)
            E = B[i];
        V[B[i]] = 1;
    }
    for(int i=0; i<A; i++)
        if(V[i] == 0)
            return i;

    return E;
}

int main(){

    freopen("A-large-practice.in", "r", stdin);
    freopen("inputlarge.out", "w", stdout);

    int64_t N;
    cin>>N;

    for(int64_t i=1; i<=N; i++){

        int64_t S, Q, count=0;
        cin>>S;
        map<string, int> A;
        char h[1024*1024];
        gets(h);
        for(int64_t j=0; j<S; j++){
            gets(h);
            A[h] = j;
        }
        cin>>Q;
        vector<int> B;
        gets(h);
        for(int64_t j=0; j<Q; j++){
            gets(h);
            B.push_back(A[h]);
        }
        int E = fathestE(S,B,0);
        for(int64_t j=0; j<Q; j++)
            if(B[j] == E){
                count += 1;
                E = fathestE(S,B,j);
            }

        cout<<"Case #"<<i<<": "<<count<<endl;
    }

    return 0;
}
