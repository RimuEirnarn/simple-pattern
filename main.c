#include "include/simplify.h"
#include "include/general.h"

/*
  1
 1 2
1 2 3
*/
void piramida(int max) {
    if (max >= 10) {
        raise("Nope! Maksimal 9!");
    }
    printf("piramida\n");
    int maximum = (max + max);
    char border[maximum];
    frange(maximum) border[i] = '=';
    border[maximum] = '\0';
    printf("%s\n", border);
    for_range(max) {
        char base[maximum]; // yes
        frange(maximum) base[i] = ' ';
        if (current == 0) base[max-1] = '1';
        base[max - current-1] = '1';
        frange(current) {
            int x = i + 1 + (i);
            base[max - (current - 0) + x] = i + 2 + '0';
        }
        base[maximum] = '\0';
        printf("%s\n", base);
    }
    printf("%s\n", border);
}

/*
      1
    1 2
  1 2 3
1 2 3 4
*/
void kanan_kiri(int max) {
    if (max >= 10) {
        raise("Nope! Maksimal 9!");
    }
    printf("kanan -> kiri\n");
    int maximum = (max + max) - 1;
    char border[maximum];
    frange(maximum) border[i] = '=';
    border[maximum] = '\0';
    printf("%s\n", border);
    for_srange(1, max + 1) {
        char base[maximum];
        frange(maximum) base[i] = ' ';
        base[maximum - 1] = max + '0';
        fsrange(1, current) {
            int index = i - 1;
            base[maximum - 1] = max + '0';
            base[maximum - (i * 2 + 1)] = (max - i) + '0';
        }
        base[maximum] = '\0';
        printf("%s\n", base);
    }
    printf("%s\n", border);
}

/*
1
1 2
1 2 3
1 2 3 4
*/
void kiri_kanan(int max) {
    if (max >= 10) {
        raise("Nope! Maksimal 9!");
    }
    printf("kiri -> kanan\n");
    int maximum = (max + max) - 1;
    char border[maximum];
    frange(maximum) border[i] = '=';
    border[maximum] = '\0';
    printf("%s\n", border);
    for_srange(2, max + 2) {
        char base[maximum];
        frange(maximum) base[i] = ' ';
        base[0] = '1';
        fsrange(1, current) {
            int index = i - 2;
            base[0] = '1';
            base[index + i] = i + '0';
        }
        base[maximum] = '\0';
        printf("%s\n", base);
    }
    printf("%s\n", border);
}

/*
    |
   *|*
  **|**
 ***|***
----+----
 ***|***
  **|**
   *|*
    |  
*/
void belah_ketupat(int max) {
    printf("Belah ketupat\n");
    int maximum = (max + max)+1;
    char border[maximum];
    frange(maximum) border[i] = '=';
    border[maximum] = '\0';
    printf("%s\n", border);
    for_srange(0, maximum) {
        char base[maximum];
        frange(maximum) base[i] = ' ';
        base[max] = '|';
        if (current == max) {
            frange(maximum) base[i] = '-';
            base[max] = '+';
        } elif (current < max) {
            fsrange(0, current) {
                int left, right;
                left = max-1;
                right = max+1;
                base[right + i] = '*';
                base[left - i] = '*';
            }
        } else {
            frange(max) {
                int left, right;
                int b = current - max;
                int crn = max - (b);
                left = 1 + (b-1);
                right = max+1;
                for (int j=0;j<=(crn-1);j++) base[left+j] = '*';
                for (int j=0;j<=(crn-1);j++) base[right+j] = '*';
            }
        }
        printf("%s\n", base);
    }
    printf("%s\n", border);
}

start{
    piramida(9);
    kanan_kiri(9);
    kiri_kanan(9);
    belah_ketupat(9);
    endmain
}