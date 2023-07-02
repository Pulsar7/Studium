#include "questions.h"



void create_questions(Question *questions) {
    strcpy(questions[0].question_text, "Frage 1");
    strcpy(questions[0].answers[0], "Antwort A");
    strcpy(questions[0].answers[1], "Antwort B");
    strcpy(questions[0].answers[2], "Antwort C");
    strcpy(questions[0].correct_answer, questions[0].answers[1]);
}