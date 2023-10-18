#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "FIllBlank.h"

int quizFill_Blank(int _case) {
    int score;
    printf("Q3 ----------------- \n");
    //Gets the right question for the quiz you got (Same as TrueFalse.c)
    switch(_case) {
        case 0:
            score = _3quiz1();
            break;
        case 1:
            score = _3quiz2();
            break;
        case 2:
            score = _3quiz3();
            break;
        default:
            score = 0;
    }
    return score;
}

int _3quiz1() {
    int score;
    char answer[30];
    char correct[] = "int hello;";
    printf("Declare a variable called hello that is type int.\n");
    strnAnswer(answer);
    score = _3checkAnswer(answer, correct);
    return score;
}

int _3quiz2() {
    int score;
    char answer[30];
    char correct[] = "int i = 0";
    printf("Fill in the blank: for(____; i < 10; i++)\n");
    strnAnswer(answer);
    score = _3checkAnswer(answer, correct);
    return score;
}

int _3quiz3() {
    int score;
    char answer[30];
    char correct[] = "printf";
    printf("Fill in the blank: _____(\"Hello World!\");\n");
    strnAnswer(answer);
    score = _3checkAnswer(answer, correct);
    return score;
}

void strnAnswer(char answer[]) {
    while(1) {
        fflush(stdin);
        fgets(answer, 30, stdin);
        if(strlen(answer) < 30) {
            break;
        } else {
            printf("Invalid. (Less than 30 length) : \n");
        }
    }
}

int _3checkAnswer(char answer[], char correct[]) {
    for(int i = 0; i < strlen(correct); i++) {
        if(isalpha(answer[i])) {
            answer[i] = tolower(answer[i]);
        }
    }
    if((strncmp(answer, correct, strlen(correct))) == 0) {
        printf("Correct\n");
        return 1;
    } else {
        printf("Incorrect\n");
        return 0;
    }
}