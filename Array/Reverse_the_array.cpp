#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t; cin >> t;
	while(t--) {
	    int n; cin >> n;
	    vector<int> a(n);
	    for (auto &x:a) cin >> x;
	    for (int i = n - 1; i >= 0; i--) cout << a[i] << " "; cout << endl;
		cout << "Thank You" << endl;
	}
	return 0;
}
