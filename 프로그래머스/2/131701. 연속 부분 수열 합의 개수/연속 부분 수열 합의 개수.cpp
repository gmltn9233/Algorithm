#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    vector<int> v;
    for(int i=0; i<elements.size(); i++){
        v.push_back(elements[i]);
    }
    for(int i=0; i<elements.size(); i++){
        v.push_back(elements[i]);
    }
    set<int> st;
    for(int s=1; s<=elements.size(); s++){
        //cout<<s<<":\n";
        for(int i=0; i<elements.size(); i++){
            int sum = 0;
            for(int j=i; j<i+s; j++){
                //cout<<"j: "<<j<<"\n";
                sum +=v[j];
            }
            st.insert(sum);
            //cout<<sum<<"\n";
        }
    }
    return st.size();
}

// 7 9 1 1 4 7 9 1 1 4