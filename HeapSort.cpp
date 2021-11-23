#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> t;

void sift_up(int i){
    while (i){
        int p = (i - 1) >> 1;
        if(t[i] < t[p]){
            swap(t[i], t[p]);
            i = p;
        }
        else{
            break;
        }
    }
}


void sift_down(int i){
    while(2 * i + 1 < t.size()){
        int j = 2 * i + 1;
        if(2 * i + 2 < t.size() && t[2 * i + 2] < t[j]){
            ++j;
        }
        if(t[i] <= t[j]){
            break;
        }
        swap(t[i], t[j]);
        i = j;
    }
}

void insert(int x){
    t.push_back(x);
    sift_up((int) t.size() - 1);
}

int get_min(){
    return t[0];
}

void remove_min(){
    swap(t[0], t.back());
    t.pop_back();
    sift_down(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;

    t.resize(n);

    for(auto &x:t){
        cin >> x;
    }

    //auto tm = clock();

    for(int i = n - 1; i >= 0; --i){
        sift_down(i);
    }

    for(int i = 0; i < n; ++i){
        cout << get_min() << ' ';
        remove_min();
    }
    //cout << (long double) (clock() - tm) / CLOCKS_PER_SEC;
}
