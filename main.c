#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

void transposeMatrix(int matrix[SIZE][SIZE]) 
{
    int temp;
    for (int i = 0; i < SIZE; i += 1) 
    {
        for (int j = i + 1; j < SIZE; j++) 
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void findMaxInRows(int matrix[SIZE][SIZE], int maxValues[SIZE]) 
{
    for (int i = 0; i < SIZE; i += 1) 
    {
        maxValues[i] = matrix[i][0];
        for (int j = 1; j < SIZE; j +=1) 
        {
            if (matrix[i][j] > maxValues[i]) 
            {
                maxValues[i] = matrix[i][j];
            }
        }
    }
}

int main() 
{
    system("chcp 65001");
    FILE *inputFile, *outputFile;
    int matrix[SIZE][SIZE];
    int maxValues[SIZE];

    inputFile = fopen("vhid.txt", "r");
    if (inputFile == NULL) 
    {
        printf("Помилка відкриття файлу vhid.txt\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i += 1) 
    {
        for (int j = 0; j < SIZE; j += 1) 
        {
            if (fscanf(inputFile, "%d", &matrix[i][j]) != 1) 
            {
                printf("Помилка читання даних з файлу\n");
                fclose(inputFile);
                return 1;
            }
        }
    }
    fclose(inputFile);

    transposeMatrix(matrix);

    findMaxInRows(matrix, maxValues);

    outputFile = fopen("exit.txt", "w");
    if (outputFile == NULL) {
        printf("Помилка відкриття файлу exit.txt\n");
        return 1;
    }

    fprintf(outputFile, "Транспонована матриця:\n");
    for (int i = 0; i < SIZE; i += 1) 
    {
        for (int j = 0; j < SIZE; j += 1) 
        {
            fprintf(outputFile, "%d ", matrix[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    fprintf(outputFile, "\nМаксимальні елементи рядків:\n");
    for (int i = 0; i < SIZE; i += 1) 
    {
        fprintf(outputFile, "Рядок %d: %d\n", i + 1, maxValues[i]);
    }

    fclose(outputFile);
    printf("Результати успішно записано у файл exit.txt\n");

    return 0;
}