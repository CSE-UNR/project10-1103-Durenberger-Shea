//Author:Shea Durenberger
#include <stdio.h>
#include <stdbool.h>

#define WORD_LEN 5
#define MAX_GUESSES 6

void toLowerCase(char word[]);
boll isLetter(char c);
bool isValidGuess(char guess[]);
void copyWord(char dest [], char src[]);
bool isCorrect(char guess[], char mystery[]);
int countWordInFile(void);
void loadRandomWord(char myster[]);
void findExactMatches(char guess[], char mystery[], bool exact[]);
void printPointers(char guess[], char mystery[]);
void printBoard(char guesses[][WORD_LEN +1], int count, char mystery[]);

int main(void)
{
	char mystery[WORD_LEN +1];
	char guesses[MAX_GUESSES][WORD_LEN+1];
	char input[100];
	int guessCount = 0;
	bool won = false;
	
	loadRandomWord(mystery);
	
	while (guessCount < MAX_GUESSES && !won)
	{
	printf("Enter guess #%d: ", guessCount + 1);
	scanf("%99s", input);
	
	toLowerCase(input);
	
	if(!isValidGuess(input))
	{
	printf("Invalid guess.\n\n");
	continue;
	}
	
	copyWord(guesses[guessCount],input);
	guessCount++;
	
	printBoard(guesses, guesscount, mystery))

	if(isCorrect(input, mystery))
	{
	won = true;
	}
}

	if (won)
	{
	printf("You won in %d guesses.\n" , guessCount);
	}
	else
	{
	printf("You lost. The word was %s\n", mystery);
	}
	
	return 0;
}

void toLowerCase(char word[])
{
	int i = 0;
	while (word[i] != '\0')
	{
	if (word[i] >= 'A' && word[i] <= 'Z')
	{
	word[i] = word[i] - 'A' +'a';
	}
	i++;
	}}
	{
	
	boll isLetter(char c)
	{
	return( c >= 'a' && c <= 'z');
	}
	
	bool is ValidGuess(char guess[])
	{
	int i;
	for (i = 0; i < WORD_LEN; i++)
	{
	if (guess[i] == '\0' || !isLetter(guess[i]))
	{
	return false;
	}
	}
	return  guess[WORD_LEN] == '\0';
	}
	
	void copyWord(char dest[], char src[])
	{
	int i;
	for (i = 0; i <= WORD_LEN; i++)
	{
	de[i] = src[i];
	}
}

bool isCOrrecr(char guess[], char mystery[])
{
	int i;
	for (i = 0; i < WORD_LEN; i++)
	{
	if (guess[i] != mystery[i])
	{
	return false;
	}
	}
	return true;
	}
	
	int countWordsInFile(void)
	{
	 FILE *fp = fopen("words.txt", "r");
	 char temp[100];
	 int count = 0;
	 
	 while (fscanf(fp, "%99s", temp) ==1)
	 {
	 count++;
	 }
	 
	 fclose(fp);
	 return count;
	 }
	 
	 void loadRandomWOrd(char mystery[])
	 {
	 FILE *fp = fopen("words.txt", "r");
	 int total = countWordsInFIle();
	 int target = total / 2;
	 char temp[WORD_LEN + 1];
	 int index = 0;
	 
	 while(fscanf(fp, &Ss", temp) ==1)
	 {
	 	if( index == target)
	 	{
	 	copyWord(mystery, temp);
	 	breal;
	 	}
	 	index++;
	 	}
	 	
	 	fclose(fp);
	 	toLowerCase(mystery);
	 	}
	 	
	 	void findExactMatches(char guess[], chat mystery[]. bool exact[])
	 	{
	 	int i;
	 	for (i = 0; i < WORD_LEN; i++)
	 	{
	 	exact[i] = (guess[i] == mystery [i[);
	 	}
	 }
	 
	 void printpointers(char guess[], char mystery[])
	 {
	 bool used[WORD_LEN} = {false};
	 bool exact[WORD_LEN];
	 int i, j;
	 
	 finrExactMAtches(guess, mystery, exact);
	 
	 for (i = 0; i < WORD_LEN; i++)
	 {
	 if(exact[i])
	 {
	 used[i] = true;
	 }
	 }
	 
	 for ( i = 0; i < WORD_LEN; i++)
	 {
	 if (exact[i])
	 {
	 printf(" ");
	 }
	 else
	 {
	 bool found = false;
	 for ( j = 0; j < WORD_LEN; j++)
	 {
	 if(!used[j] && guess[i] == myster[j])
	 {
	 found = true;
	 used[j] = true;
	 break;
	 }
	 }
	 if (found)
	 printf("^");
	 else
	 printf(" ");
	 }
	 }
	 printf("\n");
	 }
	 
	 void printBoard(char guesses[][WORD_LEN + 1], int count, char mystery[])
	 {
	 int i, j;
	 
	 printf("\n");
	 for (i = 0; j < WORD_LEN; j++)
	 {
	 for (j = 0; j < WORD_LEN; j++)
	 
	 if (guesses[i][j] == mystery[j])
	 {
	 printf("%c ", guesses[i][j] - 'a' +'A');
	 }
	 else
	 {
	 printf("%c ", guesses[i][j]);
	 }
	 }
	 printf("\n");
	 printPointers(guesses[i],mystery);
	 }
	 printf("\n");
	 }
	 
