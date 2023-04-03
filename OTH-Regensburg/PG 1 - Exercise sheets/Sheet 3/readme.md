# Aufgabe 1: Wechselautomat

Siehe `task_1.c`

# Aufgabe 2: Kleine Testprogramme

Die kleinste Dezimalzahl, die mit dem Datentypen **int** dargestellt werden kann ist eine einzelne Ziffer. Mit der Funktion `sizeof(int)` ist es möglich nachzusehen, wie viel Speicherplatz eine Ziffer benötigt.

Mit der Bibliothek `limits.h` können die jeweiligen Grenzen von verschiedenen Datentypen angezeigt werden, wie z.B.: **CHAR_MAX**,**INT_MAX**,**LONG_MAX**, **CHAR_MIN**,**INT_MIN**,...


- `short int`: 
- `long int`:
- `unsigned`: 

Wo genau die minimale und maximale Grenze der jeweiligen Variable liegt, ist von System zu System unterschiedlich.


## zu C

Wird durch *0* dividiert, wird folgender Fehler ausgeworfen:

> `Gleitkomma-Ausnahme (Speicherabzug geschrieben)`

Ist dabei die *0* in einer Variablen gespeichert, gibt der **gcc**-Compiler keine Fehlermeldung aus. Der Fehler wird demnach erst beim Ausführen der Datei erkannt.
Wird durch eine Konstante *0.0* dividiert, erkennt dies der Compiler und zeigt folgende Fehlermeldung an:


> `task_2.c:54:15: warning: division by zero [-Wdiv-by-zero]`

Werden die obigen Operationen wiederholt, dieses Mal jedoch auf **Gleitkomma-Variablen** angewandt, wird bei beiden Fällen beim Compilen mit **gcc** kein Fehler ausgeworfen. Als Ausgabe erhält man lediglich die drei Buchstaben `inf`.


## zu D


## zu E

Das Ergebnis bei Ausführung von `printf("%.20f\n",(float)(4.4444*3.333));` = 14.81318473815917968750

Das Ergebnis bei Ausführung von `printf("%.20f\n",(double)(4.4444*3.333));` = 14.81318520000000127368
