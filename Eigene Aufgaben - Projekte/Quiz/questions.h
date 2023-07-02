#ifndef QUESTIONS_H
#define QUESTIONS_H
#include <stdio.h>
#include <string.h>
#define QUESTION_TEXT_LEN 50
#define MAX_ANSWER_LEN 50
#define MAX_QUESTIONS 5

//
typedef enum {True,False} Bool;
typedef struct Question {
    char question_text[QUESTION_TEXT_LEN];
    char answers[3][MAX_ANSWER_LEN];
    char correct_answer[MAX_ANSWER_LEN];
} Question;

//
void create_questions(Question *questions);


#endif