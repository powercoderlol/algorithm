#pragma once
#include <stdio.h>
#include <stdlib.h>

void findLongestSubstring(const char a[], const char b[], char res[]) {
    int i, j, k, len_a, len_b, substr_i, max_substr;
    int** matrix;

    for(i = 0; a[i] != '\0'; i++)
        ;
    len_a = i;

    for(j = 0; b[j] != '\0'; j++)
        ;
    len_b = j;

    matrix = (int**)malloc((len_a + 1) * sizeof(int*));

    for(i = 0; i < len_a; i++) {
        matrix[i] = (int*)malloc((len_b + 1) * sizeof(int));
        for(j = 0; j < len_b; j++) {
            matrix[i][j] = 0;
        }
    }
    printf("\n");

    max_substr = 0;
    substr_i = 0;

    for(i = 0; i < len_a; i++) {
        for(j = 0; j < len_b; j++) {
            if(a[i] == b[j]) {
                if((0 == i) || (0 == j))
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                if(matrix[i][j] > max_substr) {
                    max_substr = matrix[i][j];
                    substr_i = i;
                }
                else if(matrix[i][j] == max_substr)
                    substr_i = i;
            }
            else
                matrix[i][j] = 0;
        }
    }

    k = 0;
    for(i = (substr_i - max_substr + 1); i <= substr_i; i++) {
        res[k] = a[i];
        k++;
    }
    res[k] = '\0';
}
