#include<stdio.h>

#define MIN 1
#define MAX_ZEILEN 4
#define TRUE 1
#define FALSE 0
#define ROW_FLAG 1
#define ZERO 0
#define GAME_OBJ '|'
#define INVALID_INPUT_ERROR_MSG "\n\nDiese Eingabe ist nicht gueltig\n"
#define ENTER_ROW_CHOICE "\n\nAus welcher Zeile sollen Staebchen genommen werden: "
#define ENTER_REMOVE_COUNT "\nWie viele Staebchen sollen entfernt werden: "
#define COMPUTER "Yoda"

void printHomeMenu();
void initZeilen(int *zeilen);
void displayGame(const int *zeilen, const char gameObj);
void playWithYoda();
int getValidInput(const int *zeilen, const int maxLimit, const char* msg, const int rowFlag);
short gameOver(const int *zeilen);
void declareWinner(const char *winner);

int main() {
	char choice;
    printHomeMenu();

	printf("\nDo you want to play with me? y/n: ");
	scanf("%c", &choice);
    if (choice == 'y'){
    	playWithYoda();
	}
	else{
		printf("\nGoodbye...\n");
	}

    return 0;
}

void printHomeMenu() {
    printf("**************************************************\n");
    printf("*                  NIM SPIEL                     *\n");
    printf("**************************************************\n");
}

void initZeilen(int *zeilen) {
    int i;

    zeilen[0] = 1;
    for(i = 1;i < MAX_ZEILEN;i++) {
        zeilen[i] = zeilen[i - 1] + 2;
    }
}

void displayGame(const int *zeilen, const char gameObj) {
    int i, j;
    printHomeMenu();
    for(i = 0;i < MAX_ZEILEN;i++) {
        printf("\nZeile %d (%d): ", i + 1, zeilen[i]);
        /*
        for(j = 1;j < MAX_ZEILEN - i;j++) {
            printf("   ");
        }
        */
        for(j = 0;j < zeilen[i];j++) {
            printf("%c  ", gameObj);
        }
    }

    printf("\n\n**************************************************\n");
    printf("\n**************************************************\n");
}

void declareWinner(const char *winner) {
	system("cls");
	printf("The Winner: %s\n", winner);
}

void playWithYoda() {
    int zeilen[MAX_ZEILEN];
    int rowChoice;
    int removeCount;
    short player = 1;
    char gameObj = GAME_OBJ;

    initZeilen(zeilen);
    
    do {
    	// moves[0] is row number, moves[1] is the number of removed objects
        int moves[2];
        system("cls");
        displayGame(zeilen, gameObj);

        // Zeilenauswahl
        rowChoice = getValidInput(zeilen, MAX_ZEILEN, ENTER_ROW_CHOICE, ROW_FLAG);
        
        // Staebchen entfernen
		removeCount = getValidInput(zeilen, zeilen[rowChoice], ENTER_REMOVE_COUNT, ZERO);
		
        // end of receiving input - rowChoice and removeCount
        zeilen[rowChoice] -= removeCount;
        
		//player = (player == 1)? 2 : 1;

        // Yoda turn goes in the following if block
        if(player == 2 && gameOver(zeilen) != TRUE) {
            system("cls");
            displayGame(zeilen, gameObj);
            printf("\n\nYoda has decided the move! Press enter to find what Yoda is going to play...");
            fflush(stdin);
            getchar();
            fflush(stdin);
            player = (player == 1)? 2 : 1;
        }
    } while(gameOver(zeilen) != TRUE);
	
	
    if(player == 1) {
        declareWinner("You");
    } else {
        declareWinner(COMPUTER);
    }
    
}

int getValidInput(const int *zeilen, const int maxLimit, const char* msg, const int rowFlag) {
    int input;
    short invalidInput = TRUE;
    do {
            printf(msg);
            fflush(stdin);
            scanf("%d", &input);
            if(input < MIN || input > maxLimit || (rowFlag == ROW_FLAG && zeilen[--input] < MIN)) {
				printf(INVALID_INPUT_ERROR_MSG);
            }
			else
			{
                invalidInput = FALSE;
            }
    } while(invalidInput == TRUE);
    return input;
}

short gameOver(const int *zeilen) {
    int i;
    for(i = 0;i < MAX_ZEILEN; i++) {
        if(zeilen[i] > 0) {
            return FALSE;
        }
    }
    return TRUE;
}
