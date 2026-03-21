#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> parent(N+1);
    vector<int> child(N+1, 0);
    vector<int> level(N+1, 0);

    int M = 0;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        parent[i] = x;
        child[x] += 1;

        level[i] = level[x] + 1;
    }

    for (int i = 0; i <= N; i++) {
        if (child[i]==0) {M+=1;}
    }

    vector<int> queries(M, 0);

    for (int i = 0; i < M; i++) {
        cin >> queries[i];    
    }
    for (int q : queries) {
      //  cout << " At " << q << endl;
        int check = parent[q];

        while (check != 0 && child[check] == 1) {
            //cout << " - visiting " << check << " and its still not specific enough " << endl;
            child[check] -= 1;
          //  cout << " - " << check << " now has " << child[check] << " kids " << endl;
            check = parent[check];

        }

        if (check == 0 && child[check] == 1) {
            cout << 0 << endl;
        } else {
            cout << level[check] + 1 << endl;
        }
        child[check] -= 1;
 //       cout << " - " << check << " now has " << child[check] << " kids " << endl;



    }
}