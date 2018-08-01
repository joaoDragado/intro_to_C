#include <stdio.h>
int main(void)
{
    int n;
	printf("Give the number of days\n");
	scanf("%d", &n);
	printf("%d year(s), %d month(s), %d day(s)", n/360,(n%360)/30, (n%360)%30);
	return (0);

}

