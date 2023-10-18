#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "TrueFalse.h"

int quizT_F(int _case) {
    int score;
    printf("Q1 ----------------- \n");
    //Gets the right question for the quiz you got
    switch(_case) {
        case 0:
            score = _1quiz1();
            break;
        case 1:
            score = _1quiz2();
            break;
        case 2:
            score = _1quiz3();
            break;
        default:
            score = 0;
    }
    return score;
}

int _1quiz1() {
    int score;
    char answer;
    char correct = 'T';
    printf("C is a programming language? (T/F) : ");
    answer = T_F();
    score = _1checkAnswer(answer, correct);
    return score;
}

int _1quiz2() {
    int score;
    char answer;
    char correct = 'F';
    printf("Python is the fastest programming language in the world? (T/F) : ");
    answer = T_F();
    score = _1checkAnswer(answer, correct);
    return score;
}

int _1quiz3() {
    int score;
    char answer;
    char correct = 'T';
    printf("SE 185 is the best class ever? (T/F) : ");
    answer = T_F();
    score = _1checkAnswer(answer, correct);
    return score;
}

char T_F() { //Function used for getting the users answer
    char answer;
    while(1) {
        fflush(stdin);
        scanf("%c", &answer);
        if(answer == 't' || answer == 'T' || answer == 'f' || answer == 'F') {
            return toupper(answer);
        } else {
            printf("Invalid. (T/F) : ");
        }
    }
}

int _1checkAnswer(char answer, char correct) { //Function used for checking the users answer
    if(answer == correct) {
        printf("Correct\n");
        return 1;
    } else {
        printf("Incorrect\n");
        return 0;
    }
}
