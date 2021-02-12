#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_ITEMS 10
#define MIN_ITEMS 0


int main(void)
{


	const double NET_MAX = 400000, NET_MIN = 500;							//	Constants to set maximums and minimums
	const double MIN_VALUE = 100.00;
	const int MAX_PRIORITY = 3, MIN_PRIORITY = 1;

	double netIncome = 0, netValid = 0, itemCost = 0.00, costTrue = 1;		//	Declarations for the user input data

	int nItems = 0, itemNum = 0, priorityRating = 0;
	int nitemsTrue = 1, priorityValid = 1;									//	Checking validity of entered data from user

	char financeOption, financeTrue = 0;

	int priority[MAX_ITEMS] = { 0 };										//	Parallel Array's for user data being entered
	char finance[MAX_ITEMS] = { 0 };
	double cost[MAX_ITEMS] = { 0.00 };



	//	Display program title and begin		//



	printf("+-------------------------+\n|   Wish List Forecaster  |\n+-------------------------+\n");

	do
	{
		printf("\n\nEnter your monthly NET income ($500 - $400000): $ ");										//	Prompt to user for income amount
		scanf("%lf", &netIncome);

		if (netIncome <= NET_MAX && netIncome >= NET_MIN)														// Validity check of income amount
		{
			netValid = 1;
			do 
			{
				printf("\nHow many wish list items you want to forecast:  ");									//	Setting items to forecast
				scanf("%d", &nItems);

				if (nItems <= MAX_ITEMS && nItems >= MIN_ITEMS)													// Checking its validity
				{
					nitemsTrue = 1;

				}
				else
				{
					nitemsTrue = 0;
					printf("\nList is restricted to between %d and %d lines\n", MAX_ITEMS, MIN_ITEMS);
				}
			} while (nitemsTrue == 0);
		}
		else if (netIncome < NET_MIN)
		{
			printf("\n\nERROR: You must have a consistent monthly income of at least $%.2lf", NET_MIN);
			netValid = 0;
		}
		else
		{
			printf("\n\nERROR: Liar! Ill believe you if you enter a value no more than $%.2lf", NET_MAX);
			netValid = 0;
		}
		
	} while (netValid == 0);

	/* OK so now I have both of the values for NET income and for how many items to forecast, I put the collection of the array data in its own section so it is easier to follow*/

	if (netValid == 1 && nitemsTrue == 1)
	{
		for (int itemNum = 1; itemNum < nItems + 1; itemNum++)
		{
			do
			{
				printf("\nItem-%d Cost: ", itemNum);
				scanf("%lf", &itemCost);
				if (itemCost >= MIN_VALUE)
				{
					cost[nItems] = itemCost;
					costTrue = 1;
					do 
					{
						printf("\n\nHow important is it to you? [1=must have, 2=important, 3=want]:  ");
						scanf("%d", &priorityRating);
						if (priorityRating <= MAX_PRIORITY && priorityRating >= MIN_PRIORITY)
						{
							priority[nItems] = priorityRating;
							priorityValid = 1;

							do
							{
								printf("\n\nDoes this item have financing options? [y/n]: ");
								scanf("%c", &financeOption);
								
								if (financeOption == 'y')
								{
									finance[nItems] = 'y';
									financeTrue = 1;									
									break;
								}
								else if (financeOption == 'n')
								{
									finance[nItems] = 'n';
									financeTrue = 1;
									break;
								}
								else
								{
									printf("\nERROR: Must be a lowercase 'y' or 'n'");
									financeTrue = 0;
								}
							} while (financeTrue == 0);

						}
						else
						{
							printf("\nERROR: Value must be between %d and %d", MIN_PRIORITY, MAX_PRIORITY);
							priorityValid = 0;
						}


					} while (priorityValid == 0);
				}
				else
				{
					printf("\nERROR: Cost must be more than $100\n");
					costTrue = 0;
				}
			} while (costTrue == 0);
		}

		


	}
		
	/*  I now have all the array data entered into the parallel arrays and now I can start processing the data for a summary and forecast   */

	if (financeTrue == 1 && priorityValid == 1 && costTrue == 1)
	{

	}
	
	
	
	
	
	return 0;
}

