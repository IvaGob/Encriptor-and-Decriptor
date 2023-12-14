#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 3
#define N 100

//шифрування слів речення
void encript(char* word, int len) 
{
    int shift = len / 2;
    //створення тимчасового масиву і виділення пам'яті дял нього
    char* temp = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) 
    {
        //присвоєння тимчасовому масиву елемент масиву з індексом (остачи від ділення i+shift на довжину масиву)
        temp[(i + shift) % len] = word[i];
    }
    temp[len] = '\0';
    //запис перетвореного тимчасового масиву в масив
    strcpy(word, temp);
    //очищення пам'яті від тимчасового масиву
    free(temp);
}

//дешифрування слів речення
void decript(char* word, int len) 
{
    int shift = len - len / 2;
    //створення тимчасового масиву і виділення пам'яті дял нього
    char* temp = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) 
    {
        //присвоєння тимчасовому масиву елемент масиву з індексом (остачи від ділення i+shift на довжину масиву)
        temp[(i + shift) % len] = word[i];
    }
    temp[len] = '\0';
    strcpy(word, temp);
    free(temp);
}

int main() 
{
    system("chcp 1251");
    char sentence[M][N];
    char encriptedSentence[M][N];
    char decriptedSentence[M][N];
    char divider[] = " .,";
    for (int i = 0; i < M;i++) 
    {
        printf("\nВведіть речення: ");
        fgets(sentence[i], N, stdin);
    }
    for (int i = 0; i < M; i++)
    {
        char tempsent[N] = "";
        //прибираємо \n в кінці рядка
        sentence[i][strcspn(sentence[i], "\n")] = 0;
        char* word = strtok(sentence[i], divider);
        while (word != NULL) 
        {
            
            int len = strlen(word);
            encript(word, len);
            //Додаємо до кінця строки слово
            strcat(tempsent, word);
            strcat(tempsent, " ");
            word = strtok(NULL, divider);
            
        }
        strcpy(encriptedSentence[i], tempsent);
        //printf("String: %s \n", encriptedSentence[i]);
    }
    printf("\nЗашифровані речення:\n");
    for (int i = 0; i < M; i++) 
    {
        printf("%s\n", encriptedSentence[i]);
    }
    //Розшифровка речень
    for (int i = 0; i < M; i++)
    {
        char tempsent[N] = "";
        //прибираємо \n в кінці рядка
        encriptedSentence[i][strcspn(encriptedSentence[i], "\n")] = 0;
        
        char* word = strtok(encriptedSentence[i], divider);
        while (word != NULL) 
        {

            int len = strlen(word);
            decript(word, len);
            //Додаємо до кінця строки слово
            strcat(tempsent, word);
            strcat(tempsent, " ");
            word = strtok(NULL, divider);

        }
        strcpy(decriptedSentence[i], tempsent);
    }
    printf("\nРозшифровані речення:\n");
    for (int i = 0; i < M; i++)
    {
        printf("%s\n", decriptedSentence[i]);
    }
    getchar();
    return 0;
}

