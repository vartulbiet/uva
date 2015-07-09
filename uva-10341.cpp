#include<cmath>
#include<cstdio>
 
using namespace std;
 
int p, q, r, s, t, u;
 
float eval(float x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2.0f) + u;
}
 
int main() {
 
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6) {
 
        double low = 0.0f, mid = 0.5f, high = 1.0f, emid, ehigh;
        while(high - low > 0.0000001f) {
            mid = (low + high) / 2.0f;
            emid = eval(mid), ehigh = eval(high);
            if((ehigh < 0 && emid > 0) || \
                    (ehigh >= 0 && emid > ehigh) || \
                    (ehigh <= 0 && ehigh > emid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
 
        if(abs(emid) <= 0.0001f)
            printf("%1.4f\n", mid);
        else
            printf("No solution\n");
    }
 
    return 0;
}