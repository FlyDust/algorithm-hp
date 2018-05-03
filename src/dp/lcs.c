#include <string.h>
#include "dp.h"

#define MAX 100

int lcs_length(char *x, char *y)
{
	int m = strlen(x);
	int n = strlen(y);
	int c[MAX+1][MAX+1];
	int i, j;
	for(i = 0; i < m + 1; i++)
		c[i][0] = 0;
	for(i = 0; i < n + 1; i++)
		c[0][i] = 0;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			if(x[i] == y[j]){
				c[i+1][j+1] = c[i][j] + 1;
			}
			else if(c[i+1][j] >= c[i][j+1]){
				c[i+1][j+1] = c[i+1][j];
			}
			else{
				c[i+1][j+1] = c[i][j+1];
			}
		}
	}
	return c[m][n];
}
