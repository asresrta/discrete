#include <stdio.h>

char tf(int value) {
    return value ? 'T' : 'F';
}

int main() {
    int p, q;

    printf("Truth Table for compound propositions (p and q)\n\n");
    printf("p  q  !p  p&&q  p||q  p->q  p<->q\n");
    printf("---------------------------------\n");

    for (p = 1; p >= 0; p--) {
        for (q = 1; q >= 0; q--) {
            int not_p = !p;
            int and_pq = p && q;
            int or_pq = p || q;
            int imp_pq = (!p) || q;
            int bicond_pq = (p == q);

            printf("%c  %c   %c    %c     %c     %c      %c\n",
                   tf(p), tf(q), tf(not_p),
                   tf(and_pq), tf(or_pq),
                   tf(imp_pq), tf(bicond_pq));
        }
    }

    return 0;
}
