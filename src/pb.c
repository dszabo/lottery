#include <stdio.h>
#include <stdlib.h>

#define LUCKY_NUMBER 7
#define MAX_WHITE_BALL 59
#define MAX_POWER_BALL 39

static int my_sort_func(const void* p1, const void* p2)
{
	int v1 = *((int *) p1);
	int v2 = *((int *) p2);

	if (v1 < v2)
	{
		return -1;
	}
	else if (v1 > v2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int calculate_result(int white_balls[5], int power_ball)
{
	for (int i=0; i<5; i++)
	{
		if ( (white_balls[i] < 1) || (white_balls[i] > MAX_WHITE_BALL) )
		{
			return -1;
		}
	
		if ( (power_ball < 1) || (power_ball > MAX_POWER_BALL) )
		{
			return -1;
		}
	}

	qsort(white_balls, 5, sizeof(int), my_sort_func);

    return 0;
}

int main(int argc, char** argv)
{
    if (argc != 7)
    {
        fprintf(stderr, "Usage: %s (5 white balls) power_ball\n", argv[0]);
        return -1;
    }

    int power_ball = atoi(argv[6]);
    int white_balls[5];
    for (int i=0; i<5; i++)
    {
        white_balls[i] = atoi(argv[1+i]);
    }

    int result = calculate_result(white_balls, power_ball);

	if (result < 0)
	{
		fprintf(stderr, "Invalid arguments\n");
		return -1;
	}

	if (LUCKY_NUMBER == power_ball)
	{
		result = result * 2;
	}
   
    printf("%d percent chance of winning\n", result);

    return 0;
}
