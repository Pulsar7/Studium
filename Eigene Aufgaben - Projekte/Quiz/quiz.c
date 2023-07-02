#include "questions.h"


int main(int argc, const char **argv) {
    Question questions[MAX_QUESTIONS];
    create_questions(questions);
    char user_input[100];
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question: %s\n (1) %s\n (2) %s\n (3) %s\n",
            questions[i].question_text,
            questions[i].answers[0],questions[i].answers[1],questions[i].answers[2]
        );
    }
    return 0;
}