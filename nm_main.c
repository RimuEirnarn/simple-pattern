#include "include/nm_general.h"

void piramida(int max) {
     if (max >= 10) {
          yeet("Maximal tidak boleh lebih dari 9!", __LINE__, __FILE__);
     }
     printf("piramida\n");
     int maximum = (max + max);
     char border[maximum];
     for (int i = 0; i <= (maximum - 1); i++) border[i] = '=';
     border[maximum] = '\0';
     printf("%s\n", border);
     for (int current = 0; current <= (max - 1); current++) {
          char base[maximum];
          for (int i = 0; i <= (maximum - 1); i++) base[i] = ' ';
          if (current == 0) base[max - 1] = '1';
          base[max - current - 1] = '1';
          for (int i = 0; i <= (current - 1); i++) {
               int x = i + 1 + (i);
               base[max - (current - 0) + x] = i + 2 + '0';
          }
          base[maximum] = '\0';
          printf("%s\n", base);
     }
     printf("%s\n", border);
}

void kanan_kiri(int max) {
     if (max >= 10) {
          yeet("Maximal tidak boleh lebih dari 9!", __LINE__, __FILE__);
     }
     printf("kanan -> kiri\n");
     int maximum = (max + max) - 1;
     char border[maximum];
     for (int i = 0; i <= (maximum - 1); i++) border[i] = '=';
     border[maximum] = '\0';
     printf("%s\n", border);
     for (int current = 1; current <= (max + 1 - 1); current++) {
          char base[maximum];
          for (int i = 0; i <= (maximum - 1); i++) base[i] = ' ';
          base[maximum - 1] = max + '0';
          for (int i = 1; i <= (current - 1); i++) {
               int index = i - 1;
               base[maximum - 1] = max + '0';
               base[maximum - (i * 2 + 1)] = (max - i) + '0';
          }
          base[maximum] = '\0';
          printf("%s\n", base);
     }
     printf("%s\n", border);
}

void kiri_kanan(int max) {
     if (max >= 10) {
          yeet("Maximal tidak boleh lebih dari 9!", __LINE__, __FILE__);
     }
     printf("kiri -> kanan\n");
     int maximum = (max + max) - 1;
     char border[maximum];
     for (int i = 0; i <= (maximum - 1); i++) border[i] = '=';
     border[maximum] = '\0';
     printf("%s\n", border);
     for (int current = 2; current <= (max + 2 - 1); current++) {
          char base[maximum];
          for (int i = 0; i <= (maximum - 1); i++) base[i] = ' ';
          base[0] = '1';
          for (int i = 1; i <= (current - 1); i++) {
               int index = i - 2;
               base[0] = '1';
               base[index + i] = i + '0';
          }
          base[maximum] = '\0';
          printf("%s\n", base);
     }
     printf("%s\n", border);
}

void belah_ketupat(int max) {
     printf("Belah ketupat\n");
     int maximum = (max + max) + 1;
     char border[maximum];
     for (int i = 0; i <= (maximum - 1); i++) border[i] = '=';
     border[maximum] = '\0';
     printf("%s\n", border);
     for (int current = 0; current <= (maximum - 1); current++) {
          char base[maximum];
          for (int i = 0; i <= (maximum - 1); i++) base[i] = ' ';
          base[max] = '|';
          if (current == max) {
               for (int i = 0; i <= (maximum - 1); i++) base[i] = '-';
               base[max] = '+';
          } else if (current < max) {
               for (int i = 0; i <= (current - 1); i++) {
                    int left, right;
                    left = max - 1;
                    right = max + 1;
                    base[right + i] = '*';
                    base[left - i] = '*';
               }
          } else {
               for (int i = 0; i <= (max - 1); i++) {
                    int left, right;
                    int b = current - max;
                    int crn = max - (b);
                    left = 1 + (b - 1);
                    right = max + 1;
                    for (int j = 0;j <= (crn - 1);j++) base[left + j] = '*';
                    for (int j = 0;j <= (crn - 1);j++) base[right + j] = '*';
               }
          }
          printf("%s\n", base);
     }
     printf("%s\n", border);
}

int main(int argc, char **argv) {
     piramida(9);
     kanan_kiri(9);
     kiri_kanan(9);
     belah_ketupat(9);
     return 0;
}
