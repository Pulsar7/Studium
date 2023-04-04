    Bewertung: 100 / 100

# Aufgabe 1 - Fehler finden

Die Variablen *x*, *b* und *c* besitzen den Datentypen _integer_. Die Rechnung sieht demnach folgendermaßen aus: 

- c = (1 + 2); c = 3 -> integer
- x = c / b; x = 1.000000 -> float

Da jedoch *b* und *c* integer sind, wird **integer** durch **integer** geteilt. Das Problem könnte man beispielsweise durch *explicit conversion* beheben:

    #include <stdio.h>

    int main(int argc, char* argv[]) {
        int a = 1, b = 2, c;
        float x;

        c = (float)(a + b);
        x = c / (float)b;

        printf("%f\n", x);

        return 0;
    }

Oder man setzt die Datentypen von *a*,*b* & *c* gleich zu Beginn als **float**:

    #include <stdio.h>

    int main(int argc, char* argv[]) {
        float a = 1, b = 2, c;
        float x;

        c = (a + b);
        x = c / b;
        
        printf("%f\n", x);

        return 0;
    }



## Teil b

Der *character* 9 wird nicht einfach in den Integer *9* umgewandelt, sondern erhält den fest zugeschriebenen Wert *57* (ASCII-Code). Deshalb folgt: 33 - 57 = -24.
Welcher *character* welchen Zahlenwert erhält, lässt sich mit einer `for-Schleife` zeigen:

    #include <stdio.h>

    int main(int argc, char* argv[]) {
        char elements[] = {
            '0','1','2','3','4','6','7','8','9','\0'
        };
        for (int i = 0; i < 10; i++) {
            printf("%c = %d\n",elements[i],elements[i]);
        }
        return 0;
    }


| char number | int number |
|:-----------:|:----------:|
| 0           | 48         |
| 1           | 49         |
| 2           | 50         |
| 3           | 51         |
| 4           | 52         |
| 6           | 54         |
| 7           | 55         |
| 8           | 56         |
| 9           | 57         |
| ...         | ...        |


## Teil c

Beim Compilen mit *gcc* wird direkt der Fehler ausgeworfen: Bei dem Datentypen der Variablen *a* handelt es sich um einen *integer* und nicht um *double*. Ändert man in Zeile 9 das `%f` zu `%d`, wird das gewünschte Ergebnis -32 ausgegeben.


## Teil d

In Zeile 7 wird zwar die Variable *a* mit dem Datentypen *integer* in einen *float* durch *explicit conversion* umgewandelt, jedoch besitzt dieser nicht mehr die vorgegebenen Nachkommastellen. Fügt man folgenden Code hinzu: 

    printf("%d und %f\n",a,(float)a);

...kann man sehr gut erkennen, dass durch die Deklarierung in Zeile 4 die *0.9* wegfällt.




# Aufgabe 2: Binärzahlen - Addition

Zu Beginn sollen vier Variablen *a1*,*a0*,*b0* und *b1* deklariert werden. Nachdem mit `scanf()` deren Werte festgelegt wurden, soll zuerst geprüft werden, ob denn auch nur die Zahlen **0** und **1** verwendet wurden.
Dann werden jeweils zwei Fälle pro *a*- und *b*-Paar untersucht &rArr; &forall; X &isin; {1,2}:

1. Sind **aX** und **bX** gleich 1? Dann "merke" eine *1* und setze **sX** gleich 0.

2. Ist **aX** gleich 0 und **bX** gleich 1 oder ist **aX** gleich 1 und **bX** gleich 0? Dann setze **sX** gleich 1.


Gilt **Fall 1** für *s0*, soll die gemerkte 1 mit *s1* addiert werden. Soll später jedoch *s1* gleich 1 gesetzt werden (wenn Fall 2 für *s1* eintrifft), wird *u* mit 1 addiert.




## Teil b
siehe *b_task2.c*


Die Überprüfung zu Beginn, ob nur 1 und 0 verwendet wurde, lässt sich ebenfalls in einer `for-Schleife` umsetzen:

    int numbers[] = {a1,a0,b1,b0};
    int status = 0;
    for (int i = 0; i < 4; i++) {
        if (numbers[i] != 1 && numbers[i] != 0) {
            status = 1;
            break;
        }
    }
    if (status == 0) {
        ... // Fallunterscheidungen mit Output
    } else {
        printf("Invalid input!\n");
    }