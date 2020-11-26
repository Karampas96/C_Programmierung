# 4. Formatierte Ein-/Ausgabe mit `scanf()` und `printf()`

## 4.1 Formatierte Eingabe mit `scanf()`

## 4.2 Formatierte Ausgabe mit `printf()`

Die Syntax von `printf()` sieht so aus:

```C
#include <stdio.h>

int printf(const char * restrict format, ...);
```

Der Rückgabewert von `printf()` ist die Anzahl der Zeichen, die ausgegeben werden (ohne das Terminierungszeichen '\0'), oder im Fehlerfall EOF. Folgendes Beispiel demonstriert dies:

[Source Code](https://github.com/YodaCh96/C-Programmierung/blob/master/C_von_A_bis_Z/printf1.c)

```C
/* printf1.c */
#include <stdio.h>

int main(void){
  int zeichen;
  zeichen = printf("Hallo Welt");
  printf("Enthaelt %d Zeichen\n", zeichen); // 10 Zeichen
  return 0;
}
```

`printf()` bekommt mindestens einen Parameter, nähmlich den Formatstring. 
