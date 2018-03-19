#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1 
#define FALSE 0

// Notes 
// Consider remainder 
// update M/max_payemnet as we go  ?

#define gc getchar_unlocked

void distinct_m(int denominations, int max_pay, int *value_coin, int *each_coin);
int iterate_through_valid_coin(int denominations, int max_pay, int *value_coin, int *each_coin);
int _check_null_coins(int *each_coin, int denominations);

//  read_int()
//      reads in a single char at faster speeds
//      (https://discuss.codechef.com/questions/18401/fast-input)
int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

// main()
//	reads user input and calls functions 
int main() {
	
	 // number of test cases 
	int test_cases  = read_int();

	// iterates through T test cases 1 <= T <= 6
	for(int i = 0; i < test_cases; i++){ 

		// denominations 
		int denominations = read_int(); 


		// max Payment 
		int max_payment = read_int();


		// allocate space for value_coin array 
		// value of coin at the ith denomination 
		int *value_coin = malloc(sizeof(int) * denominations); 
		for(int i  = 0;  i < denominations; i++) { 
			value_coin[i] = read_int(); 
			
		}

		// alocate space for each_coin array 
		// number of of coins for the ith denomation
		int *each_coin = malloc(sizeof(int) * denominations);
		for(int i = 0; i < denominations; i++) {
			each_coin[i] = read_int(); 
		}

		distinct_m(denominations, max_payment, value_coin, each_coin);
	}

	return 0;
}


/* check_null_values: detects if there exist a null coin 
*
*
*/

int check_null_coin(int *each_coin, int denominations){
   	for(int i=0; i < denominations; i++){ 
   		if (each_coin[i] == 0){ 
   			return 1; /*There exist a null coin*/
   		}
   	}
   	return 0; /*There isnt any null coins, just compute product of all*/ 
}



/* terate_through_valid_coins: 
* Eventually do FFT ? 
*
*/
int iterate_through_valid_coins(int denominations, int max_pay, int *value_coin, int *each_coin) {
	int output = 0; 
	for (int i = 0; i < denominations; i++) { 
		for(int j = 0; j < denominations; j++) {
			if (i == j && output < max_pay) { 
				// value coin at i and each coin at j 
				output += (value_coin[i]) * (each_coin[j]);

			}
		}
	}
	printf("%i\n",output);
	// reset count for future test cases 
    output = 0; 
}


void distinct_m(int denominations, int max_pay, int *value_coin, int *each_coin) { 
	// this just outputs first test case 
	// set up  a count ... 
	// how much is actually payable if we want distinctiness 
	// iterate one set of coins at a time 
	// count if its able to output for each individual one set a disticnt count
	// if there exits m values ... 
	// different ways of adding values ? 

	// int distinct_counts = 0 

	// reset count for future test cases 
	int disticnt_count = 0;

	int null_coins = check_null_coin(each_coin, denominations);

	if (null_coins == TRUE) { 
		// eventually recurse through every possibilty 
		printf("%s\n","there exists a null coin" );
	}

	else { 
		// try running at o(n) ? 
		iterate_through_valid_coins(denominations,max_pay, value_coin, each_coin);
	}

}


