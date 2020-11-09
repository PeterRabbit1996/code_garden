#include <stdio.h>
#include <unistd.h>
#include <math.h>

int main()
{
	while (1) {
		double principal;
		double rate;
		double years;

		printf("principal: ");
		scanf("%lf", &principal);
		printf("rate: ");
		scanf("%lf", &rate);
		printf("years: ");
		scanf("%lf", &years);

		printf("the profit: %lf\n", principal * pow((1 + rate), years));

		sleep(1);
	}

	return 0;
}
