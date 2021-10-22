#include <time.h>
#include <stdio.h>
#define TestSize 100000

int TestPalindrome(int x);

int main () {

    clock_t start = clock();
    printf("Starting...\n");

    FILE *fp;
    fp = fopen("Palindromes.txt", "w");
    register int c = 0;

    for (int i = 0; i <= TestSize; i++) {

        int ans = TestPalindrome(i);

        if (ans == 1) {

            fprintf(fp, "%i\n", i);
            c++;

        }

    }

    fclose(fp);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\033[0;94mIt took \033[0;31m%.3f\033[0;94m seconds.\nFound \033[0;32m%i\033[0;94m palindrom numbers\033[0m", time_spent, c);

    return 0;
}

int TestPalindrome (int x) {

    int sum = 0, r = 0;
    int temp = x, res = -1;

    while (x > 0) {

        r = x % 10;    
        sum = (sum * 10) + r;    
        x = x / 10; 

    }

    if(temp == sum) {    

        res = 1;

    } else {

        res = 0;

    }  

    return res;
}