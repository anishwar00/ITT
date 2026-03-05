#include <iostream>
#include <algorithm> 

using namespace std;

 
 
 
    return max(max(a, b), max(c, d));
}

int main() {
    int a, b, c, d;
 
    cin >> a >> b >> c >> d;
    
    int ans = max_of_four(a, b, c, d);
    cout << ans << endl;
    
    return 0;
}
