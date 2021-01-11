#include<stdio.h>
#include<string.h>
#include <time.h> // initialisierung des Zufallsgenerators

#define MAX_ZEILEN 4
#define MAX_STAEBCHEN 7
#define GAME_OBJ '|'
#define MINIMUM 1
#define FLAG 1
#define ERROR_MSG "\n\nDiese Eingabe ist nicht gueltig\n"
#define ROW_CHOICE "\n\nAus welcher Zeile sollen Staebchen genommen werden: "
#define REMOVE_COUNT "\nWie viele Staebchen sollen entfernt werden: "

void introGame();
void initGame(int *zeilearray);
void displayGame(const int *zeilearray, const char gameObj);
void playWithYoda();
int checkInput(const int *zeilearray, const int maxLimit, const char* msg, const int rowFlag);
short endOfGame(const int *zeilearray);
void showWinner(const char *winner);
void AI(int *zeilearray, int *zug);

int main(){
    char answer[5];
    introGame();
    printf("\nDo you want to play with me? yes/no: ");
    scanf("%s", answer);
    
    if (strcmp(answer, "yes") == 0){
        playWithYoda();
    }
    else if (strcmp(answer, "no") == 0){
        printf("\nGoodbye...\n");
    }
    else{
    	printf("\nInvalid answer...\n");
	}
	system ("PAUSE"); /* Nur w�hrend der Entwicklungsphase, sp�ter l�schen! */
    return 0;
}

void introGame(){
    printf("**************************************************\n");
    printf("*                  NIM GAME                      *\n");
    printf("**************************************************\n");
}

void initGame(int *zeilearray){
	// Initialization, should only be called once.
	srand(time(NULL));
    int i;
    for(i = 0;i < MAX_ZEILEN;i++){
    	/* random int between 0 and 7 */
        zeilearray[i] = rand() % MAX_STAEBCHEN + 1;
    }
}

void displayGame(const int *zeilearray, const char gameObj){
    int i, j;
    introGame();
    for(i = 0;i < MAX_ZEILEN;i++){
        printf("\nZeile %d (%d): ", i + 1, zeilearray[i]);
        for(j = 0;j < zeilearray[i];j++){
            printf("%c  ", gameObj);
        }
    }
    printf("\n\n**************************************************\n");
    printf("\n**************************************************\n");
}

void showWinner(const char *winner){
    system("cls");
    printf("The Winner: %s\n", winner);
}

void playWithYoda(){
    int zeilearray[MAX_ZEILEN];
    int rowChoice;
    int removeCount;
    short player = 1;
    char gameObj = GAME_OBJ;
    initGame(zeilearray);
    do {
        int zug[2]; // zug[0]: entf. Zeile, zug[1]: entf. Staebchen
        system("cls");
        displayGame(zeilearray, gameObj);
        // Zeile auswaehlen
        rowChoice = checkInput(zeilearray, MAX_ZEILEN, ROW_CHOICE, 1); 
        // Staebchen entfernen
        removeCount = checkInput(zeilearray, zeilearray[rowChoice], REMOVE_COUNT, 0);  
        zeilearray[rowChoice] -= removeCount;
        player = (player == 1)? 2 : 1;
        // Yoda ist dran...
        if(player == 2 && endOfGame(zeilearray) != 1){
            system("cls");
            displayGame(zeilearray, gameObj);
            AI(zeilearray, zug);
            printf("\n\nYoda has decided the move! Press enter to find what Yoda is going to play...");
            fflush(stdin);
            getchar();
            fflush(stdin);
            player = (player == 1)? 2 : 1;
        }
    } while(endOfGame(zeilearray) != 1);
    if(player == 2){
        showWinner("You");
    }
    else{
        showWinner("Yoda");
    }
    
}

int checkInput(const int *zeilearray, const int max, const char* msg, const int rowFlag){
    int input;
    short invalid = 1;
    do{
            printf(msg);
            fflush(stdin);
            scanf("%d", &input);
            if(input < MINIMUM || input > max || (rowFlag == FLAG && zeilearray[--input] < MINIMUM)){
                printf(ERROR_MSG);
            }
            else{
                invalid = 0;
            }
    }while(invalid == 1);
    return input;
}

short endOfGame(const int *zeilearray ){
    for(int i = 0;i < MAX_ZEILEN; i++){
        if(zeilearray[i] > 0){
            return 0;
        }
    }
    return 1;
}

void AI(int *zeilearray, int *zug){
    int i;
    int zeroes = 0;
    int oneRows = 0;
    int zielzeile = 0;
    int maxCount = 0;
    short bitArray[MAX_ZEILEN][3] = {0};
    int powersCount[3] = {0};
    int index = 0;

    for(i = 0;i < MAX_ZEILEN;i++){
        int temp = zeilearray[i];
		// Finde die Zeile, die kein Staebchen hat
        if(zeilearray[i] == 0){
            zeroes++;
        }
        // Finde die Zeile mit der maximalen Staebchen
        if(zeilearray[i] > maxCount){
            maxCount = zeilearray[i];
            zielzeile = i;
        }
        // Finde die Anzahl von zeilearray, die genau 1 Staebchen haben
        if(zeilearray[i] == MINIMUM){
            oneRows++;
        }

        // Es liefert die Anzahl der 2-Potenzen in jeder Zeile
        // z.B. die Zahl 7 = 111 hat ein 4, ein 2 und ein 1
        // z.B. die Zahl 5 = 101 hat ein 4 und ein 1
        if(temp >= 4) {
            bitArray[i][2] = 1;
            temp -= 4;
            powersCount[2]++;
        }
        if(temp >= 2) {
            bitArray[i][1] = 1;
            temp -= 2;
            powersCount[1]++;
        }
        if(temp >= 1) {
            bitArray[i][0] = 1;
            powersCount[0]++;
        }
    }
    
    //printf("PowerCount2: %d\n", powersCount[2]);
    //printf("PowerCount1: %d\n", powersCount[1]);
    //printf("PowerCount0: %d\n", powersCount[0]);

    if((powersCount[2] % 2) == 1){
        index = 2;
    } else if((powersCount[1] % 2) == 1){
        index = 1;
    }
    
    //printf("Index: %d\n", index);

    for(i=MAX_ZEILEN-1; i>=0; i--){
    	//printf("bit array: %d\n", bitArray[i][index]);
        if(bitArray[i][index] == 1){
            zielzeile = i;
            bitArray[i][index] = 0;
            powersCount[index]--;
            index--;
            break;
        }
    }

    while(index >= 0) {
        if((powersCount[index] % 2) == 1) {
            bitArray[zielzeile][index] = !bitArray[zielzeile][index];
        }
        index--;
    }

    zug[1] = zeilearray[zielzeile];
    
    zeilearray[zielzeile] = bitArray[i][0] * 1 + bitArray[i][1] * 2 + bitArray[i][2] * 4;

    if(maxCount == 1 && zeilearray[zielzeile] != MINIMUM){
        oneRows--;
    }
	else if(zeilearray[zielzeile] == MINIMUM){
        oneRows++;
    }
    
    if(zeilearray[zielzeile] == 0){
        zeroes++;
    }

    if((zeroes + oneRows) == MAX_ZEILEN && oneRows % 2 == 1 && maxCount != MINIMUM){
    	zeilearray[zielzeile] == 0 ? ++zeilearray[zielzeile] : --zeilearray[zielzeile];
    }

    // Gib die entfernte Zeile zurueck
    zug[0] = zielzeile;
    // Gib die Anzahl der entfernten Staebchen zurueck
    zug[1] -= zeilearray[zielzeile];
}
