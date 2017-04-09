#include<bits/stdc++.h>
using namespace std;

int64_t getMeNumber(string a, int64_t T = 0){

    stringstream ss;
    int b,c;
    char e;
    ss<<a;
    ss>>b>>e>>c;
    if(b == 23 && (c+T) < c )
        b = 0;
    b = (b*100 + c);


    return (b + T);
}


int main(){

    freopen("B-large-practice.in", "r", stdin);
    freopen("inputlarge.out", "w", stdout);

    int64_t N;
    cin>>N;

    for(int64_t i=1; i<=N; i++){

        int64_t T, NA, NB, ansA = 0, ansB = 0;
        cin>>T>>NA>>NB;
        vector<int64_t> AD;
        vector<int64_t> BD;
        vector<int64_t> C;
        vector<int64_t> D;

        for(int64_t j=0; j<NA; j++){
            string c, d;
            cin>>c>>d;
            AD.push_back(getMeNumber(c));
            C.push_back(getMeNumber(d, T));
        }
        for(int64_t j=0; j<NB; j++){
            string c, d;
            cin>>c>>d;
            BD.push_back(getMeNumber(c));
            D.push_back(getMeNumber(d, T));
        }

        sort(AD.begin(), AD.end());
        sort(BD.begin(), BD.end());
        sort(D.begin(), D.end());
        sort(C.begin(), C.end());

        int64_t j, k, isOut = 0, isIn = 0;
        for(j=0, k = 0;;  ){

            if(j==NA || k==NB)
                break;

            if(AD[j] < D[k]){
                cout<<AD[j++]<<" OUT"<<endl;
               //AD[j++];
                if(isIn == 0)
                    isOut += 1;
                if(isIn != 0)
                    isIn -= 1;
            }
            else{
                cout<<D[k++]<<" IN"<<endl;
            //    D[k++];
                isIn += 1;
            }
        }
        while(j < NA){
            cout<<AD[j++]<<" OUT"<<endl;
          // AD[j++];
            if(isIn == 0)
                    isOut += 1;
            if(isIn != 0)
                    isIn -= 1;
        }
        while(k < NB)
            cout<<D[k++]<<" IN"<<endl;

       cout<<endl<<endl;
        ansA = max(isOut, ansA);
        isOut = 0;
        isIn = 0;
        for(j=0, k = 0;;  ){

            if(j==NB || k==NA)
                break;

            if(BD[j] < C[k]){
                cout<<BD[j++]<<" OUT"<<endl;
              // BD[j++];
                if(isIn == 0)
                    isOut += 1;
                if(isIn != 0)
                    isIn -= 1;
            }
            else{
                cout<<C[k++]<<" IN"<<endl;
             //   C[k++];
                isIn += 1;
            }
        }
        while(j < NB){
            cout<<BD[j++]<<" OUT"<<endl;
          //  BD[j++];
            if(isIn == 0)
                isOut += 1;
            if(isIn != 0)
                isIn -= 1;
        }
        while(k < NA)
            cout<<C[k++]<<" IN"<<endl;

        ansB = max(isOut, ansB);

        cout<<"Case #"<<i<<": "<<ansA<<" "<<ansB<<endl;
    }

    return 0;
}
