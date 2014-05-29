/* 
 * File:   main.c
 * Author: roy.smart
 *
 * Created on May 29, 2014, 11:19 AM
 */

#include <stdio.h>
#include <stdlib.h>

#define G 6.67e-11
#define TRUE 1;
#define FALSE 0;

double problem_1(double, double, double);
double problem_1_exp(double, double, double);
void problem_2_IO(int);
void problem_2_shuffle_left(char*, char*, char*);
void function_A(int);
void function_B(int);

/*
 * main program to drive homework problems
 */
int main(int argc, char** argv) {
    double mass_1 = 2e30; //mass of earth
    double mass_2 = 70; //mass of human
    double distance = 6.37e6; //radius of earth 

    puts("Problem 1");
    printf("%e\n", problem_1(mass_1, mass_2, distance));
    printf("%e\n", problem_1_exp(mass_1, mass_2, distance));

    puts("\nProblem 2");
    problem_2_IO(5);

    return (EXIT_SUCCESS);
}

/*
 * problem 1 takes the mass of two objects and the distance between them and
 * computes the force between two objects
 */
double problem_1(double mass_1, double mass_2, double distance_m1m2) {
    double force; //variable used to compute the force and return to main
    force = G;
    force *= mass_1;
    force *= mass_2;
    force /= distance_m1m2;
    force /= distance_m1m2;
    return force;
}

/*
 * try to do problem 1 more eloquently
 */
double problem_1_exp(double mass_1, double mass_2, double distance_m1m2) {
    double p = 1;
    double gravity = G;
    gravity *= mass_2 *= mass_1 *= p *= p /= distance_m1m2;
    return mass_2;
}

/*
 * problem 2 IO opens a file and then shifts it to the left based off of the
 * parameter passed to it
 */
void problem_2_IO(int n_shuffle) {
    FILE* shuffle_file = fopen("i_goes_last.txt", "r");
    char f_buf[3]; //create array buffer for characters in file (only 3 chars)

    /*scan in file into array*/
    puts("Input file");
    int i;
    for (i = 0; i < (sizeof (f_buf) / sizeof (char)); i++) {
        fscanf(shuffle_file, "%c", (f_buf + i));
        printf("%c", f_buf[i]);
    }

    puts("\nOutput file");

    int j;
    for (i = 0; i < n_shuffle; i++) {
        problem_2_shuffle_left(f_buf, f_buf+1, f_buf+2);
        
        /*print array*/
        for (j = 0; j < (sizeof (f_buf) / sizeof (char)); j++) {
            printf("%c", f_buf[j]);    
        }
        printf("\n");
    }
}

/*
 * problem 2 shuffle left takes in 3 pointers and shuffles them left
 */
void problem_2_shuffle_left(char* c1, char* c2, char* c3) {
    char temp = *c1;    //Store first value so it doesn't get lost
    *c1 = *(c1 + 1);
    *c2 = *(c2 + 1);
    *c3 = temp;
}

/*extra credit function A*/
void function_A(int stop_param, int* local_A){
    if(local_A){
        printf("Original value: &d\n", *local_A);
    }
}