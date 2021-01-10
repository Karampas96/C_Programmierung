#include<stdio.h>
#include<string.h>
#define MAX_ZEILEN 4
#define GAME_OBJ '|'
#define MINIMUM 1
#define FLAG 1
#define ERROR_MSG "\n\nDiese Eingabe ist nicht gueltig\n"
#define ROW_CHOICE "\n\nAus welcher Zeile sollen Staebchen genommen werden: "
#define REMOVE_COUNT "\nWie viele Staebchen sollen entfernt werden: "
#define COMPUTER_NAME "Yoda"

void introGame();
void initGame(int *zeilen);
void displayGame(const int *zeilen, const char gameObj);
void playWithYoda();
int checkInput(const int *zeilen, const int maxLimit, const char* msg, const int rowFlag);
short endOfGame(const int *zeilen);
void showWinner(const char *winner);

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
    return 0;
}

void introGame(){
    printf("**************************************************\n");
    printf("*                  NIM GAME                      *\n");
    printf("**************************************************\n");
}

void initGame(int *zeilen){
    int i;
    zeilen[0] = 1;
    for(i = 1;i < MAX_ZEILEN;i++){
        zeilen[i] = zeilen[i - 1] + 2;
    }
}

void displayGame(const int *zeilen, const char gameObj){
    int i, j;
    introGame();
    for(i = 0;i < MAX_ZEILEN;i++){
        printf("\nZeile %d (%d): ", i + 1, zeilen[i]);
        /*
        for(j = 1;j < MAX_ZEILEN - i;j++) {
            printf("   ");
        }
        */
        for(j = 0;j < zeilen[i];j++){
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
    int zeilen[MAX_ZEILEN];
    int rowChoice;
    int removeCount;
    short player = 1;
    char gameObj = GAME_OBJ;
    initGame(zeilen);
    do {
        // moves[0] is row number, moves[1] is the number of removed objects
        int moves[2];
        system("cls");
        displayGame(zeilen, gameObj);
        // Zeilenauswahl
        rowChoice = checkInput(zeilen, MAX_ZEILEN, ROW_CHOICE, 1); 
        // Staebchen entfernen
        removeCount = checkInput(zeilen, zeilen[rowChoice], REMOVE_COUNT, 0);  
        // end of receiving input - rowChoice and removeCount
        zeilen[rowChoice] -= removeCount;
        //player = (player == 1)? 2 : 1;
        // Yoda turn goes in the following if block
        if(player == 2 && endOfGame(zeilen) != 1){
            system("cls");
            displayGame(zeilen, gameObj);
            printf("\n\nYoda has decided the move! Press enter to find what Yoda is going to play...");
            fflush(stdin);
            getchar();
            fflush(stdin);
            player = (player == 1)? 2 : 1;
        }
    } while(endOfGame(zeilen) != 1);
    if(player == 1){
        showWinner("You");
    }
    else{
        showWinner(COMPUTER_NAME);
    }
}

int checkInput(const int *zeilen, const int max, const char* msg, const int rowFlag){
    int input;
    short invalid = 1;
    do{
            printf(msg);
            fflush(stdin);
            scanf("%d", &input);
            if(input < MINIMUM || input > max || (rowFlag == FLAG && zeilen[--input] < MINIMUM)){
                printf(ERROR_MSG);
            }
            else{
                invalid = 0;
            }
    }while(invalid == 1);
    return input;
}

short endOfGame(const int *zeilen ){
    int i;
    for(i = 0;i < MAX_ZEILEN; i++){
        if(zeilen[i] > 0){
            return 0;
        }
    }
    return 1;
}
