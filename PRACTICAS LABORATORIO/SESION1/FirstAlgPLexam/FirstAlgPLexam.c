#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

# define NUM_SIZES 10
# define REPITERA 100000
# define REPRECUR 10000
# define REPSEARCH 1000

// Functions prototypes

int fillOutMatrix(int **, int);
int fillOutVector(int *, int, int);
int FridayModelA(int **, int *, int);

// Main program
int main()
{
 int i,j;
 clock_t time_ini1, time_ini2, time_fin1, time_fin2;
 int sizes[NUM_SIZES]={1000,2000,3000,4000,5000,6000,7000,8000,9000,10000};
 int **Matrix=NULL, *Vector=NULL, AddIter=0, AddRecur=0;

 printf("\n\n  ANALYSIS OF ALGORITHMS  \n\n");
 printf("Time used:\n\n\n");

 printf("\t\tsizes\t\tTime Best case\t\tTime Worst case\n");
 printf("\t\t-----\t\t----------------\t----------------\n");

 for (i=0;i<NUM_SIZES;i++) {

    // ALLOCATE DYNAMIC MEMORY

    Matrix = (int **) malloc (sizes[i] * sizeof(int *));
    for(int j = 0; j < sizes[i]; j++) {
      Matrix[j] = (int *) malloc (sizes[i] * sizeof(int));
    }

    Vector = ( int * ) malloc ( sizes[i] * sizeof(int) );

    fillOutMatrix(Matrix,sizes[i]);

    // SNIPPET OF CODE TO ANALYSE THE SEARCH IN THE MATRIX

    /**   To measure the times for both best and worst case, I fill out the vector two times for each size.
     *    The matrix is fill out only once, and then, the vector is filled with zeros so the best branch can be tested.
     *    When the time is recorded for the best case, I fill out the vector again, this time with ones, so the worst path is taken.
    **/   

    //// BEST CASE

    // Fill out the vector for the best case (Always V[i] == 0, then no loop is executed and an only instruction is performed).
    fillOutVector(Vector,sizes[i], 0);

    time_ini1=clock();
    for (j=1;j<=REPSEARCH;j++)
      // CALL TO THE FUNCTION FridayModelA (Best case)
      FridayModelA(Matrix, Vector, sizes[i]);
    time_fin1=clock();


    ///// WORST CASE

    // Fill out vector for the worst case (It will never find a zero, and all the iterations will perform a nested loop).
    fillOutVector(Vector,sizes[i], 1);

    time_ini2=clock();
    for (j=1;j<=REPSEARCH;j++)
      // CALL TO THE FUNCTION FridayModelA (Worst case)
      FridayModelA(Matrix, Vector, sizes[i]);
    time_fin2=clock();


    //// SHOW RESULTS

    printf("\t\t%d\t\t%f", sizes[i],(time_fin1-time_ini1) /(double)CLOCKS_PER_SEC / REPSEARCH);
    printf("\t\t%f\n",              (time_fin2-time_ini2) /(double)CLOCKS_PER_SEC / REPSEARCH);


    //// RELEASE ALLOCATED MEMORY

    for (j = 0; j < sizes[i]; j++) {
      free(Matrix[j]);
    }
    free(Matrix);

    free(Vector);
 }
 return 0;
}


// Functions definition
int fillOutMatrix(int **M, int n){
 // STUDENT: FUNCTION DEFINITION
 for(int i = 0; i < n; i++) {
   for (int j = 0; j < n; j++) {
     M[i][j] = 1;
   }
 }
}

int fillOutVector(int *V, int n, int x){
  // STUDENT: FUNCTION DEFINITION
  for(int i = 0; i < n; i++) {
    V[i] = x;
  }
}

int FridayModelA(int **M, int *V, int n){
 // If the Vector element is 0, the first path will be taken.
 int i, j, s;
 for(i = 0; i < n; i++) {
   if(V[i] == 0) {
     //Best path. Only one instruction.
     s = s + M[i][i];
   }
   else {
     // Worst path. N instructions.
     for(j = 0; j < n; j++) {
       s = s + M[i][j];
     }
   }
 }
 return s;
}