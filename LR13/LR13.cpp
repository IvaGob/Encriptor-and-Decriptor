#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 3
#define N 100

//���������� ��� �������
void encript(char* word, int len) 
{
    int shift = len / 2;
    //��������� ����������� ������ � �������� ���'�� ��� �����
    char* temp = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) 
    {
        //��������� ����������� ������ ������� ������ � �������� (������ �� ������ i+shift �� ������� ������)
        temp[(i + shift) % len] = word[i];
    }
    temp[len] = '\0';
    //����� ������������� ����������� ������ � �����
    strcpy(word, temp);
    //�������� ���'�� �� ����������� ������
    free(temp);
}

//������������ ��� �������
void decript(char* word, int len) 
{
    int shift = len - len / 2;
    //��������� ����������� ������ � �������� ���'�� ��� �����
    char* temp = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) 
    {
        //��������� ����������� ������ ������� ������ � �������� (������ �� ������ i+shift �� ������� ������)
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
        printf("\n������ �������: ");
        fgets(sentence[i], N, stdin);
    }
    for (int i = 0; i < M; i++)
    {
        char tempsent[N] = "";
        //��������� \n � ���� �����
        sentence[i][strcspn(sentence[i], "\n")] = 0;
        char* word = strtok(sentence[i], divider);
        while (word != NULL) 
        {
            
            int len = strlen(word);
            encript(word, len);
            //������ �� ���� ������ �����
            strcat(tempsent, word);
            strcat(tempsent, " ");
            word = strtok(NULL, divider);
            
        }
        strcpy(encriptedSentence[i], tempsent);
        //printf("String: %s \n", encriptedSentence[i]);
    }
    printf("\n���������� �������:\n");
    for (int i = 0; i < M; i++) 
    {
        printf("%s\n", encriptedSentence[i]);
    }
    //����������� ������
    for (int i = 0; i < M; i++)
    {
        char tempsent[N] = "";
        //��������� \n � ���� �����
        encriptedSentence[i][strcspn(encriptedSentence[i], "\n")] = 0;
        
        char* word = strtok(encriptedSentence[i], divider);
        while (word != NULL) 
        {

            int len = strlen(word);
            decript(word, len);
            //������ �� ���� ������ �����
            strcat(tempsent, word);
            strcat(tempsent, " ");
            word = strtok(NULL, divider);

        }
        strcpy(decriptedSentence[i], tempsent);
    }
    printf("\n����������� �������:\n");
    for (int i = 0; i < M; i++)
    {
        printf("%s\n", decriptedSentence[i]);
    }
    getchar();
    return 0;
}

