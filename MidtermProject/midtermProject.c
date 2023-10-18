/*----------------------------------------------------------------------------
- SE 185: Midterm Project -
- List the names of all team members, their roles, and their participation
1- Caleb Hemmestad - Role: Quiz Creator and debugger - Participation: 100%
I did it all.
2- 
3-
4-
5-
-
-----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
- Includes
-
-----------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "TrueFalse.h"
#include "MultipleChoice.h"
#include "FIllBlank.h"
/*----------------------------------------------------------------------------
- Functions Prototypes
-
-----------------------------------------------------------------------------*/
int theQuiz(int _case);
int explanation();
void welcome();
void transition();
void loading();
/*----------------------------------------------------------------------------
- Notes -
-----------------------------------------------------------------------------*/
// Compile with gcc midtermProject.c -o proj
// Compile with make 
// Run with ./proj
/*----------------------------------------------------------------------------
- Implementation
-
-----------------------------------------------------------------------------*/

int main() {
    //Creating the welcome messgae when the program starts
    welcome();
    //Creating variables for the quiz scores and averages
    float totalScore[3] = {0.0, 0.0, 0.0};
    float average[3] = {0.0, 0.0, 0.0};
    //Variable used for continuing the game
    char reply = 'y';
    while(1) {
        //Grabbing the seed used while explaining the game
        int seed = explanation();
        srand(seed);
        int quiz = rand()%3;
        int score = 0;
        int attempts = 0;
        switch(quiz) {
            // The first quiz
            case 0:
                totalScore[quiz] = 0; //Setting the score back to 0 if they take the same quiz again
                while(score != 15) { //Continues until they get 15 aka 100%
                    score = theQuiz(quiz); //Starts the quiz and collects the score for average when the quiz is over
                    totalScore[quiz] += score; //Adding all the scores together
                    attempts++; //Adding to the attempts
                }
                average[quiz] = totalScore[quiz]/attempts; //Calculating the average for the quiz
                printf("%d attempts needed for this quiz.\n", attempts); //Printing the attempts needed
                printf("Average score for this quiz is %.2f/15.\n", average[quiz]); //Printing the average for the quiz
                break;
                // The second quiz
            case 1:
                totalScore[quiz] = 0;
                while(score != 15) {
                    score = theQuiz(quiz);
                    totalScore[quiz] += score;
                    attempts++;
                }
                average[quiz] = totalScore[quiz]/attempts;
                printf("%d attempts needed for this quiz.\n", attempts);
                printf("Average score for this quiz is %.2f/15.\n", average[quiz]);
                break;
                // The third quiz
            case 2:
                totalScore[quiz] = 0;
                while(score != 15) {
                    score = theQuiz(quiz);
                    totalScore[quiz] += score;
                    attempts++;
                }
                average[quiz] = totalScore[quiz]/attempts;
                printf("%d attempts needed for this quiz.\n", attempts);
                printf("Average score for this quiz is %.2f/15.\n", average[quiz]);
                break;
            default:
                printf("Error\n");
        }
        printf("Do you want to take another quiz? (Y/N) : "); //Asking the user if they want to continue
        scanf("%c", &reply);
        if(reply != 'y' && reply != 'Y') { //If user puts anything but y then I assume thats a no and quit the game
            float overallAverage = (average[0] + average[1] + average[2])/3.0; //Calculating the average of all 3 quizzes
            printf("Overall average is %.2f/15 for all quizzes combined.\n", overallAverage); //Printing the average at the end of the game
            break; //Breaks the loop for the game
        }
    }
    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
int theQuiz(int _case) { //Function for the quizzes based off of the case number
    int total = 0;
    float average = 0;
    system("clear"); //Clearing the screen from previous stuff
    printf("Quiz 0%d\n", _case + 1); //Printing the quiz that you got
    sleep(1); //Pausing for dramatic effect
    loading(); //Was used for showing a loading screen between quizzes but I commented it out
    printf("\n\n\n\n");
    total += quizT_F(_case)*5; //Calculates the score for the type of question based off of the quiz you got
    transition(); //Pauses the game and clears the screen
    total += quizMulti_Choi(_case)*5; //Calculates the score for the type of question based off of the quiz you got
    transition();
    total += quizFill_Blank(_case)*5; //Calculates the score for the type of question based off of the quiz you got
    transition();
    average = total/15.0*100; //Calculates the percentage for all three questions
    printf("You got %d/15, %.1f%%\n", total, average); //Prints your score
    sleep(1);
    if(total != 15) {
        printf("You need 100%% to continue. Try again.\n"); //Tells you you need 100% to continue if you didnt get 100%
        sleep(3);
    }
    return total;
}

int explanation() {
    while(1) {
        int number;
        printf("List of available quizes :\nQuiz 01\nQuiz 02\nQuiz 03\n");
        printf("Pick a lucky number between 1 and 9 to decide your fate... : ");
        scanf("%d", &number);
        if(number < 1 || number > 9) {
            printf("Invalid\n");
        } else {
            return number;
        }
    }
}

void transition() {
    sleep(2);
    loading();
    printf("\n\n\n\n");
}

void loading() {
    sleep(1);
    system("clear");
    // printf("LOADING \n");
    // sleep(1);
    // system("clear");
    // printf("LOADING . \n");
    // sleep(1);
    // system("clear");
    // printf("LOADING . . \n");
    // sleep(1);
    // system("clear");
    // printf("LOADING . . . \n");
    // sleep(1);
    // system("clear");
    fflush(stdin);
}

//Stole from a previous project of mine on Github/CHemmestad/Lab7/Header() and then added a little bit more to it
void welcome() {
	system ( "clear" ) ;
		
	char welcomeMessage [9][240];

	// Simple variables for counting and filtering through array
	int v ; // v for vertical
	int h ; // h for horizontal
	// Variables for changing the way it looks
	//int s = 0 ; // s for shift because it shifts the word left or right to center it
	char c = 'O' ; // c for character to change the character used to form the letters for the banner
	char e = ' ' ; // e for empty to change the character used to fill in the empty spaces
	char b = '=' ; // b for border to change the border
	for(int s = 18; s < 90; s += 4) {
        if(s + 3 > 89) {
            s = 89;
        }
        system("clear");
        // Making welcome banner
        for ( v = 0 ; v < 8 ; v++ ) {
            for ( h = 0 ; h < 240 ; h++) {
                if (( v > 0 && v < 6 ) && ( h == 0+s || h == 4+s || h == 8+s )) { 
                    welcomeMessage [ v ] [ h ] = c ;
                } else if (( v == 6 ) && (( h > 0+s && h < 4+s ) || ( h > 4+s && h < 8+s ))) { // Makes the W
                    welcomeMessage [ v ] [ h ] = c ;
                } else if ((( v > 0 && v < 7 ) && ( h == 11+s )) || (( v == 1 || v == 6 || v == 4 ) && ( h > 11+s && h < 17+s ))) { // Makes the E
                    welcomeMessage [ v ] [ h ] = c ;
                } else if (( v > 0 && v < 7 && h == 19+s ) || ( v == 6 && h > 19+s && h < 25+s )) { // Makes the L
                    welcomeMessage [ v ] [ h ] = c ;
                } else if (( v > 1 && v < 6 && h == 27+s ) || (( v == 2 || v == 5 ) && ( h == 33+s )) || (( v == 1 || v == 6 ) && ( h > 27+s && h < 33+s ))) { // Makes the C
                    welcomeMessage [ v ] [ h ] = c ;
                } else if ((( v > 1 && v < 6 ) && ( h == 36+s || h == 42+s )) || (( v == 1 || v == 6 ) && ( h > 36+s && h < 42+s ))) { // Makes the O
                    welcomeMessage [ v ] [ h ] = c ;
                } else if ((( v > 0 && v < 7 ) && ( h == 45+s || h == 53+s )) || (( v == 2 ) && ( h == 46+s || h == 52+s )) || (( v == 3 ) && // Makes the M
                ( h == 47+s || h == 51+s )) || (( v == 4 ) && ( h == 48+s || h == 50+s )) || (( v == 5 ) && ( h == 49+s ))) { 
                    welcomeMessage [ v ] [ h ] = c ;
                } else if ((( v > 0 && v < 7 ) && ( h == 56+s )) || (( v == 1 || v == 6 || v == 4 ) && ( h > 56+s && h < 62+s ))) { // Makes the E
                    welcomeMessage [ v ] [ h ] = c ;
                } else if ( v == 0 || v == 7 ) {
                    welcomeMessage [ v ] [ h ] = b ;
                }
                else {
                    welcomeMessage [ v ] [ h ] = e ;
                }
            }
        }

        // Displaying banner
        printf("\n\n\n\n\n\n");
        for ( v = 0 ; v < 8 ; v++ ) {
            printf("\n");
            for ( h = 80 ; h < 160 ; h++) {
                printf("%c", welcomeMessage[v][h]);
            }
        }
        printf("\n\n");
        sleep(1);
    }
}