#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/* declare global var's including a dynamic array of characters to store the Hamming code,
original parity bits, and new parity bits*/

char *hamming_string = NULL;
int *orig_parity, *new_parity;
int max_length, even_odd;

/*************************************************************/
void OPTION_1()
{
/* prompt for maximum length of hamming code and even/odd parity */
    printf("\nEnter the maximum length of the Hamming code: ");
    scanf("%d", &max_length);

    printf("Enter the parity (0=even, 1=odd): ");
    scanf("%d", &even_odd);

/* allocate memory for Hamming code */

    hamming_string = (char *) malloc(max_length* sizeof(char));
    return;
}


/*************************************************************/
void OPTION_2()
{
/* declare local var's */
    int actual_length;
    int num_parity;
    int highest_parity;
    int p;
    int hamming_index = 0;
    int check_parity;
    int start_of_j;
    int error_bit = 0;

/* prompt for Hamming code */
    printf("Enter the Hamming code: ");

//        works and every compiler loves this
// does not need &hamming_string[i]
// ill put & because code changed and its my doing but he didnt put it
    scanf("%s", hamming_string);

/* calculate actual length of input Hamming code, number of parity bits, and highest parity bit */
    actual_length = (int) strlen(hamming_string);
    num_parity = (int) ceil(log(actual_length) / log(2));
    highest_parity = (int) pow(2, num_parity - 1);
/* Allocate memory for original and new parity bits */
    orig_parity = (int *) malloc(num_parity * sizeof(int));
    new_parity = (int *) malloc(num_parity * sizeof(int));


    hamming_index = 0;
/* Map parity bits within Hamming code to original parity bit array */
// original party is now done
    for (p = highest_parity; p >  0; p = p/2) {
        orig_parity[hamming_index] = hamming_string[actual_length  - p] - '0';
        hamming_index++;
    }
/* Calculate new parity bits */
/* OUTER LOOP: FOR EACH PARITY BIT */
//plus plus for exponential function
// j for  for log function
    for (int i = 0; i < num_parity; i++) {
        /*for (int j = 0; j <actual_length ; j = j * 2) {}*/


        /* initialize parity bit to even/off parity */
        check_parity = even_odd;
        /* MIDDLE LOOP: FOR EACH STATING BIT OF A CONSECUTIVE SEQUENCE */
        /*start_of_j = i;*/
        start_of_j = pow(2, i);
//        if j is 2 its 4 then 8 then 16 then 32. probably a pow()
        for (int j = start_of_j; j <actual_length; j = k + i) {


            /* INNER LOOP: FOR EACH BIT OF A SEQUENCE TO BE CHECKED */
            for (int k = 0; (k <= actual_length) && (hamming_index != i /*it depends on i or j*/); ++k) {


                /* ignore original parity bit */
                if (k != start_of_j) {
                    /* update new parity bit value based on Hamming code bit checked */
                    check_parity = check_parity ^ (hamming_string[actual_length - k] - '0');
                }
                /* update new parity bit value based on Hamming code bit checked */

            } /* END INNER LOOP k loop */
            /*todo own code*/
            hamming_index = 0;
            /*no end of middle loop because middle loop only sets inner loop*/
            /* Map new parity bit value to new parity bit array */
//            check this statement because not sure
            new_parity[num_parity - i - 1] = check_parity;
        }
        error_bit = error_bit + check_parity;
    }/* END OUTER LOOP */


/* Calculate error bit by XORing original and new parity bits from respective arrays, weighted properly */
    for (int l = 0; l < ; ++l) {
        error_bit = error_bit + (orig_parity[] ^ new_parity[])* l;

    }

/* Print original parity bits & new parity bits and bit-wise difference */
    for (int m = 0; m < ; ++m) {
        /*todo heres what i think i need to have in the for loops*/
        printf("\t %d", orig_parity[m]);
    }
    for (int n = 0; n < ; ++n) {
        printf("\t %d", new_parity[n]);
    }
    for (int i1 = 0; i1 < ; ++i1) {
        printf("\t %d", orig_parity[i1] - new_parity[i1]);
    }
/* If error, correct the bit and print which bit is in error and corrected Hamming code */
//to correct just flip it
/*if 0 make it a 1 and if 1 make it a 0*/
//you know its an error bit because error_bit != 0

/* Else if no error, print message of no code bit error */
/*printf("")*/

    return;
}


/******************************* OPTIONAL ************************/
void FREE_MEMORY()
{
/* If daynamic array representing Hamming code is not NULL, free the memory */
    if (hamming_string != NULL){
        free(hamming_string);
    }

    return;
}

/*****************************************************************/
int main()
{
/* print menu of options, select user's choice, call appropriate procedure, and loop until user quits */
/* declare local var's */
    int choice = 0;

/* until user chooses to quit, print menu,
select choice via switch statement and call appropriate function*/


    printf("Error detection/correction: \n");
    printf("--------------------------- \n");

    printf("1) Enter parameters \n");
    printf("2) Check Hamming code  \n");
    printf("3) Quit program \n");

    scanf("%d", &choice);

    switch (choice){
        case 1:
            OPTION_1();
            main();
            break;
        case 2:
            OPTION_2();
            main();
            break;
        case 3:
            break;
        default:
            printf("Not a valid choice. Please try again. \n");
            main();
    }

    return 1;
}
