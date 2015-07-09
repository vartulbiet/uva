#include<cstdio>
 
int T, N, P;
int h[110];
 
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        scanf("%d", &P);
        for(int i = 0; i < P; i++) {
            scanf("%d", &h[i]);
        }
 
        int day = 0;
        int hartals = 0;
        while(day < N) {
            // not friday or saturday
            int mod = (day + 1) % 7;
            if(mod != 0 && mod != 6) {
                bool hartal = false;
                for(int i = 0; i < P; i++) {
                    if((day + 1) % h[i] == 0) {
                        hartal = true;
                    }
                }
                if(hartal) hartals++;
            }
 
            day++;
        }
 
        printf("%d\n", hartals);
    }
}