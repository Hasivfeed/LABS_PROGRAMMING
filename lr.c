#include <stdio.h>
#include "lr.h"
#include <math.h> // лаба 1 (вычисление квадратного корня (sqrt))лаба 2 для (computeSeriesSum)
#include <string.h> // лаба доп 3; лаба 4
#include <limits.h> // лаба 6
//ЛР2 функция для вычисления факториала
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}


double factorial6(int n) {
    if (n == 0) {
            return 1;
    }
    else
        {
            return n * factorial(n - 1);
    }

}

//ЛР2 Функция для вычисления суммы первых n элементов ряда
float computerSeriesSum(float x, int n) {
    float sum = 0.0;
    int sign = 1;


    for (int i = 1; i <= n; i += 2) {
        float term = (sign * pow(x, i)) / factorial(i);
        sum += term;
        sign *= -1;
    }


    return sum;
}

// лаба 3 доп; лаба 4
int isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y'){
       return 1;
    }
    return 0;
}
//доп лаба 3 доп

int countWordsWithDoubleVowels(char *str) {
    char word[100];
    char result[100] = "";
    int i = 0, j = 0, k = 0;
    int hasDoubleVowels = 0;
    int wordCount = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\n') {
            word[k++] = str[i];
        } else {
            word[k] = '\0';
            k = 0;
            int wordLength = strlen(word);
            for (int m = 0; m < wordLength - 1; m++) {
                if (isVowel(word[m]) && isVowel(word[m + 1])) {
                    hasDoubleVowels = 0;
                    break;
                }
            }
            if (!hasDoubleVowels) {
                wordCount++;
            }
            hasDoubleVowels = 1;
        }
        i++;
    }

    return wordCount;
}



// доп лаба 5
typedef struct {
    int count_negative;
    float avg;
    char c;
} Stats;


//лаба 7
unsigned int reversePairs(unsigned int n) {
    unsigned int result = 0;
    int i;
    for (i = 0; i < 32; i += 2) {
        unsigned int mask = 3 << i;
        unsigned int pair = (n & mask) >> i;
        result |= pair << (30 - i);
    }
    return result;
}




int lab1(){
    float R, A;
    printf (" \nLab1 \n");
    printf("\n Enter radius(Vvedite radius) R: ");
    scanf("%f", &R);
    printf("\n Enter the side of the square(Vvedite storonu kvadrata) A: ");
    scanf("%f", &A);

    float areaCircle = 3.1415 * R * R;
    float areaSquare = A * A;
    float areaRemaining;
    if (2 * R < A) {
            printf("\nA square cannot be cut from a given circle.(Kvadrat nevozmozhno vyrezat' iz dannogo kruga).\n");
            }
            else {
                    areaRemaining = areaCircle - areaSquare;
            printf("\nArea of the remaining figure(Ploshchad' ostavsheysya figury): %.2f\n", areaRemaining);
        }
    return 0;
}

int labdop1 (){
    float R, A;

    printf (" \nLab1 \n");
    printf("\n Enter radius(Vvedite radius) R: ");
    scanf("%f", &R);
    printf("\n Enter the side of the square(Vvedite storonu kvadrata) A: ");
    scanf("%f", &A);

    float areaCircle = 3.1415 * R * R;
    float areaSquare = A * A;
    float areaDiametr = 2 * sqrt(areaCircle/3.1415);
    float areaRemaining = areaCircle - areaSquare;
    if (2 * R < A) {
            printf("\nA square cannot be cut from a given circle.The diameter is(Kvadrat nevozmozhno vyrezat' iz dannogo kruga. Diametr raven): %.2f", areaDiametr);
            }
            else {
                    areaRemaining = areaCircle - areaSquare;
            printf("\nArea of the remaining figure. The diameter is (Ploshchad' ostavsheysya figury.Diametr raven): %.2f\n", areaRemaining);
        }
    return 0;
}

int lab2(){
    double x;
    int n;
    double sum = 0;



    printf("Enter the value of(Vvedite znacheniye x: ");
    scanf("%lf", &x);
    printf("Enter the number of elements(Vvedite kolichestvo elementov) N: ");
    scanf("%d", &n);

    for (int i = 0; i < N; i++) {
        double term = pow(x, 2 * i + 1) / factorial(2 * i + 1);
        if (i % 2 == 0) {
            sum += term;
        }
        else
        {
            sum -= term;

        }

    printf("The sum of the first %d elements of the series is: %lf\n", n, sum);
    }
    return 0;
}

int labdop2(){
    double x;
    int n;

    printf (" \nLabdop2 \n");

    printf ("\nEnter value of(Vvedite znacheniye) x: ");
    scanf("%lf", &x);

    printf("Enter the number of elements(Vvedite kolichestvo elementov) N: ");
    scanf("%d", &n);

    for (int step = 1; step < n+1; step++){
        double sum = computerSeriesSum(x, step);

        printf("\nThe sum of the first %d elements of the series is equal to: %4lf\n", step, sum);


    }

    return 0;
}

int lab3(){
    char c;
    int word_count = 0;
    int in_word = 0;
    int starts_with_vowel = 0;
    int ends_with_consonant = 0;

    printf ("\nLab3 \n");
    printf("\nEnter text(Vvedite tekst):\n");
    scanf("%d", &c);

    while ((c = getchar()) != '\n') {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (in_word && starts_with_vowel && !ends_with_consonant) {
                word_count++;
            }
            in_word = 0;
            starts_with_vowel = 0;
            ends_with_consonant = 0;
        } else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
            if (!in_word) {
                switch (c) {
                    case 'a': case 'e': case 'i': case 'o': case 'u':
                    case 'A': case 'E': case 'I': case 'O': case 'U':
                        starts_with_vowel = 1;
                        break;
                }
            } else {
                switch (c) {
                    case 'a': case 'e': case 'i': case 'o': case 'u':
                    case 'A': case 'E': case 'I': case 'O': case 'U':
                        ends_with_consonant = 0;
                        break;
                }
            }
            in_word = 1;
        }
    }

    printf("\nNumber of words starting with a vowel and ending with a consonant(Kolichestvo slov, nachinayushchikhsya na glasnuyu i zakanchivayushchikhsya na soglasnuyu): %d\n,", word_count);

    return 0;
}

int labdop3(){
    char str[100];

    printf ("\nLabdop3 \n");



    printf("\nFor the correct answer, use a space after the last word.\n\nDlya pravil'nogo otveta ispol'zuyte probel, posle poslednego slova.\n");

    printf("\nEnter text(Vvedite tekst):\n");
    scanf("%d", str[100]);

    fgets(str, 100, stdin);

    int result = countWordsWithDoubleVowels(str);
    printf("The number of words in which consecutive vowels occur: %d\n", result);
    printf("Kolichestvo slov, v kotorykh vstrechayutsya podryad idushchiye glasnyye: %d\n", result);

    return 0;
}



int lab4() {

char str[100];

printf (" \nLab4 \n");
printf("\nEnter words(Vvedite slova): ");
scanf("%d", str[100]);
fgets(str, 100, stdin);

char result[100] = "", word[100];
int i = 0, j = 0, k = 0;
int hasTwoVowels = 0;

while(str[i] != '\0'){
    if(str[i] != ' ' && str[i] != '\n'){
        word[k++] = str[i];
    } else {
        word[k] = '\0';
        k = 0;

        int wordLength = strlen(word);
        for(int m = 0; m < wordLength - 1; m++){
            if(isVowel(word[m]) && isVowel(word[m+1])){
                hasTwoVowels = 1;
                break;
            }
        }

        if(!hasTwoVowels){
            strcat(result, word);
            strcat(result, " ");
        }
        hasTwoVowels = 0;
    }
    i++;


}
printf("\nResult(rezultat): %s\n", result);
return 0;
}


int lab5 (){
int numbers[10];
    int sum_even = 0;
    int sum_odd = 0;
    int i;

    printf (" \nLab5 \n");
    printf("\nEnter 10 integers (after each number, press enter)(Vvedite 10 tselykh chisel (posle kazhdogo chisla, nazhmite enter)):\n");

    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);

        if (numbers[i] % 2 == 0) {
            sum_even += numbers[i];
        } else {
            sum_odd += numbers[i];
        }
    }

    printf("\nSum of even numbers(Summa chetnykh chisel): %d\n", sum_even);
    printf("\nSum of odd numbers(Summa nechetnykh chisel): %d\n", sum_odd);

    if (sum_even > sum_odd) {
        printf("\nLargest amount(Naibol'shaya summa): %d sum of even numbers(summa chetnykh chisel)\n", sum_even);
    } else if (sum_odd > sum_even) {
        printf("\nLargest amount(Naibol'shaya summa): %d sum of odd numbers(summa nechetnykh chisel)\n", sum_odd);
    } else {
        printf("\nThe sums of even and odd numbers are equal(Summy chetnykh i nechetnykh chisel ravny): %d\n", sum_even);
    }
    return 0;
}

int labdop5 () {
    int numbers[10];
    int sum_even = 0;
    int sum_odd = 0;
    int i;
    Stats stats;

    stats.count_negative = 0;
    stats.avg = 0.0;
    stats.c = 'N';

    printf (" \nLabdop5 \n");
    printf("\nEnter 10 integers (after each number, press enter)(Vvedite 10 tselykh chisel (posle kazhdogo chisla, nazhmite enter)):\n");

    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);

        if (numbers[i] % 2 == 0) {
            sum_even += numbers[i];
        } else {
            sum_odd += numbers[i];
        }
    }

    printf("\nSum of even numbers(Summa chetnykh chisel): %d\n", sum_even);
    printf("\nSum of odd numbers(Summa nechetnykh chisel): %d\n", sum_odd);

    if (sum_even > sum_odd) {
        printf("\nLargest amount(Naibol'shaya summa): %d sum of even numbers(summa chetnykh chisel)\n", sum_even);
    } else if (sum_odd > sum_even) {
        printf("\nLargest amount(Naibol'shaya summa): %d sum of odd numbers(summa nechetnykh chisel)\n", sum_odd);
    } else {
        printf("\nThe sums of even and odd numbers are equal(Summy chetnykh i nechetnykh chisel ravny): %d\n", sum_even);
    }



    for (i = 0; i < 10; i++) {
        if (numbers[i] < 0) {
            stats.count_negative++;
        }

        stats.avg += numbers[i];
    }

    stats.avg /= 10;

    int diff = numbers[1] - numbers[0];
    int is_progression = 1;
    for (i = 2; i < 10; i++) {
        if (numbers[i] - numbers[i - 1] != diff) {
            is_progression = 0;
            break;
        }
    }

    if (is_progression) {
        stats.c = 'Y';
    }

    printf("\nNumber of negative numbers(Kolichestvo otritsatel'nykh chisel): %d\n", stats.count_negative);
    printf("\nAVG: %.2f\n", stats.avg);
    printf("\nAvailability of progression(Nalichiye progressii): %c\n", stats.c);

    return 0;
}


int lab6() {
    int N, K;
    printf (" \nLab6 \n");
    printf("\nN - Columns (Stolbtsy)\n K - Strings(stroki)\n" );
    printf("\nEnter array dimensions(Vvedite razmery massiva) N & K: ");
    scanf("%d %d", &N, &K);

    int arr[N][K];
    int min = INT_MAX, max = INT_MIN;

    printf("\nEnter Array Elements(Vvedite elementy massiva):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] < min) min = arr[i][j];
            if (arr[i][j] > max) max = arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (arr[i][j] < 0) arr[i][j] = min;
            else if (arr[i][j] > 0) arr[i][j] = max;
        }
    }

    printf("\nModified array(Izmenennyy massiv):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}


int lab7() {
    unsigned int N;
    printf (" \nLab7 \n");
    printf("\nEnter an integer(Vvedite tseloye chislo) N: ");
    scanf("%u", &N);
    unsigned int reversed = reversePairs(N);
    printf("\nNumber with rearranged bit pairs(Chislo s perestavlennymi parami bitov): %u\n", reversed);
    return 0;
}
