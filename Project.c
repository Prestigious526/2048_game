#include <stdio.h> 
#include <stdlib.h> //for rand function and clear functioN
#include <time.h> //get and manipulate date and time information
  
#define MAXRAND 4

//Game grid
int arr[4][4]={0};
//Temporary array used for moving rows and columns
int c[4];
//To check if move is valid, we use temp
int temp=0;
//To find length of number 
int length=0;
//score is calculated by two tiles combining 
//highsore is maximum score in all the games
int score=0,highscore=0;
//count is used to count number of steps
int count=0; 

// Function to find the length of a number (count of digits) 
int findlength(int n){ 
    if (n==0) { 
        return length; 
    } 
    else { 
        length++; 
        findlength(n/10); 
    } 
} 
  
// Function to print the game board 
void print() 
{ 
    int i, j, k, length1; 
  
    printf( 
        "\n\t\t\t\t\t===============2048==============\n"); 
    printf("\t\t\t\t\tYOUR SCORE=%d\n\t\t\t\t\t",score); 
    if (score < highscore) {                               //prints and gives value of highscore
        printf("HIGH SCORE=%d\t\t\t\t\t\n",highscore); 
    } 
    else { 
        highscore = score; 
        printf("HIGH SCORE=%d\t\t\t\t\t\n",highscore); 
    } 
    printf("\t\t\t\t\tMOVES=%d\t\t\t\t\t\n",count);
    printf("\t\t\t\t\t---------------------------------\n"); //prints the first top row
    for (i = 0; i < 4; i++) { 
        for (j = 0; j < 4; j++) { 
            if (j == 0) { 
                printf("\t\t\t\t\t|");                      //prints the first side row
            } 
            if (arr[i][j] != 0) { 
                length1 = findlength(arr[i][j]); 
  
                for (k = 0; k < 4 - length; k++) { 
                    printf(" "); 
                } 
                printf("%d", arr[i][j]); 
  
                for (k = 0; k < 4 - length; k++) { 
                    printf(" "); 
                } 
                for (k = 0; k < length - 1; k++) { 
                    printf(" "); 
                } 
                printf("|"); 
            } 
            else { 
                for (k = 0; k < 8 - 2 * length - 1; k++) { 
                    printf(" "); 
                } 
                printf("|"); 
            } 
            length = 0; 
        } 
        if (i != 3) { 
            printf("\n"); 
            printf("\t\t\t\t\t---------------------------------\n"); //prints the last top row
        } 
    } 
    printf( 
        "\n\t\t\t\t\t---------------------------------\n"); 
    printf("\t\t\t\t\tRESTART-> R\t\t\t\t\t\n"); 
    printf("\t\t\t\t\tEXIT-> U\t\t\t\t\t\n"); 
    printf("\t\t\t\t\tENTER YOUR CHOICE -> "
           "W,S,A,D\n\t\t\t\t\t"); 
} 
  
// Function to move values in the array 
void movevalue(int k) 
{ 
    for (int i = k; i < 4; i++) { 
        if (c[i] != 0) { 
            movevalue(i + 1); 
                if (c[i + 1] != 0) { 
                    break; 
                } 
                c[i + 1] = c[i]; 
                c[i] = 0; 
            } 
    } 
} 

// Function to add a random number to the game board 
void addrandomno() 
{ 
    int no,i, j;
    do { 
        i = (rand()) % (MAXRAND); 
        j = (rand()) % (MAXRAND); 
    } 
    while (arr[i][j] != 0);
    no = 2 * (rand() % 10) + 1; 
    if (no == 3 || no == 2) { 
        arr[i][j] = 4; 
    } 
    else { 
        arr[i][j] = 2; 
    } 
} 
  
// Function to update the array after moving values 
void rupdate() 
{ 
    for (int i = 3; i > 0; i--) { 
        if (c[i] == c[i - 1]) { 
            c[i] = c[i] + c[i - 1]; 
            score = score + c[i]; 
            temp = 1; 
            c[i - 1] = 0; 
        } 
        else if (c[i - 1] == 0 && c[i] != 0) { 
            c[i - 1] = c[i]; 
            c[i] = 0; 
            temp = 1; 
        } 
        else if (c[i] == 0) { 
            temp = 1; 
        } 
    } 
    movevalue(0); 
} 
  
// Function to reset the game 
void resetgame() 
{ 
    int i, j; 
    for (i = 0; i < 4; i++) { 
        for (j = 0; j < 4; j++) { 
            arr[i][j] = 0; 
        } 
    } 
    system("clear || cls"); 
    score = 0; 
    addrandomno(); 
} 

int main(){ 
    int i, j, k, m, n, same = 0; 
    char choice, regame; 
    printf("===============2048==============\n"); 
    printf("WELCOME TO PUZZLE 2048\n"); 
    printf("> CONTROLS\n"); 
    printf("  FOR MOVES:- 'W','S','A','D'\n"); 
    printf("  RESTAT THE GAME:- 'R'\n"); 
    printf("  EXIT:-'U'\n"); 
  
    printf("\nPRESS ANY KEY TO START THE GAME...."); 
  
    getchar(); 
    system("clear || cls"); 
    
    addrandomno(); 
    print(); 
    while (1) { 
        choice = getchar(); 
        while (getchar() != '\n'); 
        if (choice == 'D' || choice == 'd') { 
            count++; 
            for (i = 0; i < 4; i++) { 
                for (j = 0; j < 4; j++) { 
                    c[j] = arr[i][j]; 
                } 
                rupdate(); 
                for (k = 0; k < 4; k++) { 
                    arr[i][k] = c[k]; 
                } 
            } 
        } 
        else if (choice == 'a' || choice == 'A') { 
            count++; 
            for (i = 0; i < 4; i++) { 
                for (j = 3; j >= 0; j--) { 
                    c[3 - j] = arr[i][j]; 
                } 
                rupdate(); 
                for (k = 0; k < 4; k++) { 
                    arr[i][3 - k] = c[k]; 
                } 
            } 
        } 
        else if (choice == 's' || choice == 'S') { 
            count++; 
            for (i = 0; i < 4; i++) { 
                for (j = 0; j < 4; j++) { 
                    c[j] = arr[j][i]; 
                } 
                rupdate(); 
                for (k = 0; k < 4; k++) { 
                    arr[k][i] = c[k]; 
                } 
            } 
        } 
        else if (choice == 'w' || choice == 'W') { 
            count++; 
            for (i = 0; i < 4; i++) { 
                for (j = 3; j >= 0; j--) { 
                    c[3 - j] = arr[j][i]; 
                } 
                rupdate(); 
                for (k = 0; k < 4; k++) { 
                    arr[3 - k][i] = c[k]; 
                } 
            } 
        } 
        else if (choice == 'R' || choice == 'r') { 
            count = 0; 
            resetgame(); 
            print(); 
            continue; 
        } 
        else if (choice == 'u' || choice == 'U') { 
            exit(0); 
        } 
  
        if (temp == 1) { 
            temp = 0; 
            system("clear || cls"); 
            printf("\n%c\n", choice); 
            addrandomno(); 
            print(); 
        } 
        else { 
            for (m = 0; m < 4; m++) { 
                for (n = 3; n > 0; n--) { 
                    if (arr[m][n] == arr[m][n - 1] || arr[m][n] == 0 || arr[m][n - 1] == 0) { 
                        same = 1; 
                        break; 
                    } 
                    if (arr[n][m] == arr[n - 1][m] || arr[m][n] == 0 || arr[m][n - 1] == 0) { 
                        same = 1; 
                        break; 
                    } 
                } 
                if (same == 1) 
                    break; 
            } 
            if (same == 1) { 
                printf("\n============INVALID KEY==========\n"); 
                same = 0; 
            } 
            else { 
                printf( 
                    "\n=============GAME OVER============"); 
                printf("\nWANT TO PLAY MORE?? Y/N??\n"); 
                regame = getchar(); 
                while (getchar() != '\n') 
                switch (regame) { 
                case 'Y': 
                case 'y': 
                    resetgame(); 
                    print(); 
                    break; 
                case 'n': 
                case 'N': 
                    exit(0); 
                } 
                continue; 
            } 
        } 
    } 
    return 0; 
}