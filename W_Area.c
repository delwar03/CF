#include <stdio.h>

#define ll long long

const int dx[] = {0, -1, 0, 1, -1, 5, 1, -1, 0, 1};
const int dy[] = {0, -1, -1, -1, 0, 5, 0, 1, 1, 1};

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        char s[1000005]; scanf("%s", s);
        int n = strlen(s);

        ll area = 0, x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '5') break;
            ll a = x, b = y;
            x += dx[s[i] - '0'], y += dy[s[i] - '0'];
            area += a * y - b * x;
        }
        if(area < 0) area = -area;
        if(area & 1) printf("%lld.5\n", area / 2);
        else printf("%lld\n", area / 2);
    }
}