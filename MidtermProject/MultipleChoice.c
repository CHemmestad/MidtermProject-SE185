#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "MultipleChoice.h"

int quizMulti_Choi(int _case) {
    int score;
    printf("Q2 ----------------- \n");
    //Gets the right question for the quiz you got (Same as TrueFalse.c)
    switch(_case) {
        case 0:
            score = _2quiz1();
            break;
        case 1:
            score = _2quiz2();
            break;
        case 2:
            score = _2quiz3();
            break;
        default:
            score = 0;
    }
    return score;
}

int _2quiz1() {
    int score;
    char answer;
    char correct = 'C';
    printf("What is the name of this class? (A, B, C, D)\n");
    printf("A) CPR E 281\n");
    printf("B) Your mom\n");
    printf("C) SE 185\n");
    printf("D) Calculus VI\n");
    answer = ABCD();
    score = _2checkAnswer(answer, correct);
    return score;
}

int _2quiz2() {
    int score;
    char answer;
    char correct = 'D';
    printf("How many bytes are in a tarabyte? (A, B, C, D)\n");
    printf("A) 1\n");
    printf("B) 1000\n");
    printf("C) 1000000000\n");
    printf("D) 1e12\n");
    answer = ABCD();
    score = _2checkAnswer(answer, correct);
    return score;
}

int _2quiz3() {
    int score;
    char answer;
    char correct = 'A';
    printf("Strings are an array of ______? (A, B, C, D)\n");
    printf("A) Characters\n");
    printf("B) Integers\n");
    printf("C) Structs\n");
    printf("D) Pointers\n");
    answer = ABCD();
    score = _2checkAnswer(answer, correct);
    return score;
}

char ABCD() {
    const int size = 8;
    char letters[size] = "aAbBcCdD";
    char answer;
    while(1) {
        fflush(stdin);
        scanf("%c", &answer);
        for(int i = 0; i < size; i++) {
            if(answer == letters[i]) {
                return toupper(answer);
            }
        }
        printf("Invalid. (A, B, C, D) : \n");
    }
}

int _2checkAnswer(char answer, char correct) {
    if(answer == correct) {
        printf("Correct\n");
        return 1;
    } else {
        printf("Incorrect\n");
        return 0;
    }
}