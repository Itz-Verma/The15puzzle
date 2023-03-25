#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
int key;
void display (int array[][4]); //this function is used to display the 15 numers with a
// 0 as 4X4 matrix.

int check (int array[][4]); //this function is used to check whether the updated
// matrix is arranged in ascending order or not.
void user_feed (int array[][4]);/* this function is used to generate user filled puzzle
*/
void computer_feed (int array[4][4], int a[]);/* this function is used to generate
computer filled puzzle */
void moveup (int arr[4][4], int *x, int *y);/* this function is used to swap zero with
a number just above it. */
void movedown (int arr[4][4], int *x, int *y);/* this function is used to swap zero
with a number just below it. */
void moveleft( int arr[4][4], int *x, int *y);/* this function is used to swap zero with
a number just to the left of it. */
void moveright (int arr[4][4], int *x, int *y);/* this function is used to swap zero
with a number just to the right of it. */
void swapvalues(int *a, int *b);/* this function is used to swap value given by
move functions. */
void swaprandom (int a[], int i, int j);// THESE TWO FUNCTION ARE USED TO
void random(int a[], int n); // GENERATED COMPUTER FILLED PUZZLE.

int main()
{
printf("\t\tWELCOME TO THE 15PUZZLE GAME\n");
printf("\t\t______________________________\n");

int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
int x = 3, y = 3;
char Key_scancode, keywaste;
int n = sizeof(a) / sizeof(a[0]); /* computer generated puzzle code */
srand(time(NULL));
random(a, n);//GENERATED random numbers in given array a.
int moves = 0;
static int puzzle[4][4];
char per;
start:
fflush(stdin);
printf("DO YOU WANT TO PLAY?(y/n)\n");
per = getch();
if (per == 'y' || per == 'Y')
{
printf("\t\t1.want a computer generated puzzle \n");
printf("\t\t2.want a usergenerated puzzle\n");
int i;
i = getch();
switch (i)
{
case 49://ASCII CODE FOR 1 IS 49

computer_feed(puzzle, a);
break;
case 50://ASCII CODE FOR 2 IS 50
user_feed(puzzle);
break;
default:
printf("\t\tINVALID INPUT TRY AGAIN!\n");
goto start;
break;
}
}
else
{
printf("\t\tTHANKS FOR VISIT.\n");
exit(1);
}
printf ("\n\t\t*INSTRUCTIONS*\n");
printf("1.Use only arrow key to interchange zero with other numbers\n");
printf("2.Do not enter any chracters except digits while user\
generating puzzle entries\n");
printf("3.Enter only intgers between 1 to 15 ,enclusive,");
printf("for user generated puzzle\n");
printf("PRESS ENTER TO START THE GAME:");
getch();
system("cls");
while (check(puzzle))
{
display(puzzle);
printf("total moves=%d\t\t\t\t\t\tTO QUIT--> PRESS 'ESC' KEY\n",moves);

fflush(stdin);
keywaste = getch(); /* it takes the unnecessary scan code associated with
arrow key */
if (keywaste == 0)
{
Key_scancode = getch(); /* it is the main container of scan codes of arrow
keys */
switch (Key_scancode)
{
case 72:
moveup(puzzle, &x, &y);
break;
case 75:
moveleft(puzzle, &x, &y);

break;
case 80:
movedown(puzzle, &x, &y);
break;
case 77:
moveright(puzzle, &x, &y);
break;

default:
printf("invalid key pressed!\n");
break;
}
moves++;
}
else if (keywaste == 27)//ASCII CODE OF 'ESC' KEY IS 27
{
printf("\t\tYOU QUIT !!!\n");
printf("\t\tTHANKS FOR PLAYING\n");
exit(2);
}
else
{

system("cls");

printf("\t\tINVALID KEY PRESSED\n");
}
}
display(puzzle);
printf("\t\tCONGRATULATION GENIUS!!!\n\t\tYOU WON.\n");
printf("\t\ttotal moves takes=%d\n", moves);
printf("\t\tTHANKS FOR PLAYING\n");

return 0;
}
void user_feed(int array[][4])
{
for (int j = 0; j < 4; j++)
{
for (int k = 0; k < 4; k++)
{
if (j == 3 && k == 3)
{
array[j][k] = 0;
break;

}
else
{
printf("element at (%d,%d)=", j + 1, k + 1);
scanf("%d", &array[j][k]);
}
}
}
}
void computer_feed(int array[4][4], int a[])
{
int c = 0;
for (int i = 0; i < 4; i++)
{
for (int j = 0; j < 4; j++)
{
if (i == 3 && j == 3)
{
array[i][j] = 0;
}
else
{

array[i][j] = a[c];
c++;
}
}
}
}
void display(int array[][4])
{
for (int i = 0; i < 4; i++)
{
printf("\t\t");
for (int j = 0; j < 4; j++)
printf("%d\t", array[i][j]);
printf("\n");
}
}
int check(int array[][4])
{
int loop_counter = 0;
for (int i = 0; i < 4; i++)
{
for (int j = 0; j < 4; j++)

{
if (i != 3 && j != 3)
{
if (*(*(array + i) + j) > *(*(array + i) + j + 1))
{
loop_counter = 1;
break;
}
}
}
}
return loop_counter;
}

void moveup(int arr[4][4], int *x, int *y)
{
/* code for moving zero up */
system("CLS");
if (*x != 0)
{
swapvalues(&arr[*x - 1][*y], &arr[*x][*y]);
--(*x);

}
else
printf("\t\tIMPOSSIBLE MOVE!!\n");
}
void movedown(int arr[4][4], int *x, int *y)
{
/* code for moving zero down */
system("CLS");
if (*x != 3)
{
swapvalues(&arr[*x + 1][*y], &arr[*x][*y]);
++(*x);
}
else
printf("\t\tIMPOSSIBLE MOVE!!\n");
}
void moveleft(int arr[4][4], int *x, int *y)
{
/* code for moving zero left */
system("CLS");
if (*y != 0)
{

swapvalues(&arr[*x][*y - 1], &arr[*x][*y]);
--(*y);
}
else
printf("\t\tIMPOSSIBLE MOVE!!\n");
}
void moveright(int arr[4][4], int *x, int *y)
{
/* code for moving zero right */
system("CLS");
if (*y != 3)
{
swapvalues(&arr[*x][*y + 1], &arr[*x][*y]);
++(*y);
}
else
printf("\t\tIMPOSSIBLE MOVE!!\n");
}
void swaprandom(int a[], int i, int j)
{
int temp = a[i];
a[i] = a[j];

a[j] = temp;
}
void random(int a[], int n)
{
for (int i = n - 1; i >= 1; i--)
{
int j = rand() % (i + 1);
swaprandom(a, i, j);
}
}
void swapvalues(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}
