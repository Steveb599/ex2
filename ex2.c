/******************
Name: Steve Bendersky
Assignment: ex2
*******************/

#include <stdio.h>

int main()
{
	int optionNumber;
	do // I run a loop that gets the option and validates that its in the right range
	{
		printf("Choose an option:\n"
			   "1. Happy Face\n"
			   "2. Balanced Number\n"
			   "3. Generous Number\n"
			   "4. Circle Of Joy\n"
			   "5. Happy Numbers\n"
			   "6. Festival Of Laughter\n"
			   "7. Exit\n");

		scanf("%d", &optionNumber);

		while (optionNumber < 1 || optionNumber > 7)
		{
			printf("This option is not available, please try again.\n");
			printf("Choose an option:\n"
				   "1. Happy Face\n"
				   "2. Balanced Number\n"
				   "3. Generous Number\n"
				   "4. Circle Of Joy\n"
				   "5. Happy Numbers\n"
				   "6. Festival Of Laughter\n"
				   "7. Exit\n");

			scanf("%d", &optionNumber);
		}

		switch (optionNumber)
		{
		case 1:
		{
			char symbol1, symbol2, symbol3;
			int faceSize;

			printf("Enter symbols for the eyes, nose, and mouth (separated by spaces):\n");
			scanf(" %c %c %c", &symbol1, &symbol2, &symbol3);
			printf("Enter face size:\n");
			scanf(" %d", &faceSize);

			while (faceSize <= 0 || faceSize % 2 == 0) // check that face size is positive and an odd number
			{
				printf("The face's size must be an odd and positive number, please try again:\n");
				scanf("%d", &faceSize);
			}

			// Print eyes
			printf("%c", symbol1);
			for (int i = 0; i < faceSize; i++)
			{
				printf(" ");
			}
			printf("%c\n", symbol1);

			// Print nose
			for (int i = 0; i < faceSize / 2 + 1; i++)
			{
				printf(" ");
			}
			printf("%c\n", symbol2);

			// Print mouth
			printf("\\");
			for (int i = 0; i < faceSize; i++)
			{
				printf("%c", symbol3);
			}
			printf("/\n");
			break;
		}
		case 2:
		{
			int num2, numsDigitCount = 0, rightCount = 0, leftCount = 0;
			printf("Please enter a number:\n");
			scanf("%d", &num2);

			while (num2 <= 0)
			{
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &num2);
			}

			int shallowCopy = num2; // copying the number to another int so I can change the number to get the digits number
			while (shallowCopy != 0)
			{
				shallowCopy /= 10;
				numsDigitCount++;
			}

			// if number has only one digit, then its obviously a balanced number
			if (numsDigitCount == 1)
			{
				printf("The number is balanced and brings harmony!\n");
				break;
			}

			int halfOfNumsDigitCount = numsDigitCount / 2; // getting the half of numbers digit count so I can compare it later in the for loop
			shallowCopy = num2;							   // setting the shallow copy as number again so I can make changes on the number in the for loop
			for (int i = 0; i < numsDigitCount; i++)
			{
				// extracting each digit from the copy of the number
				int numDigit = shallowCopy % 10;
				// diving the number by 10 to get the next digit on next for loop iteration
				shallowCopy /= 10;

				// Skip the middle digit if odd number of digits, so it won't calculate it and compare the counts without it
				if (numsDigitCount % 2 != 0 && i == halfOfNumsDigitCount)
				{
					continue;
				}

				// sums the right count and the left count
				if (i < halfOfNumsDigitCount)
					rightCount += numDigit;
				else
					leftCount += numDigit;
			}

			if (rightCount == leftCount)
				printf("This number is balanced and brings harmony!\n");
			else
				printf("This number isn't balanced and destroys harmony.\n");

			break;
		}

		case 3:
		{
			int num3, divisorsSum = 0;
			printf("Enter a number:\n");
			scanf("%d", &num3);

			while (num3 <= 0)
			{
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &num3);
			}

			// checks if the index is a divisor of the number and then sums all the divisors of the number
			for (int i = 1; i < num3; i++)
			{
				if (num3 % i == 0)
					divisorsSum += i;
			}

			// checks if the sum of all the divisors is greater than the number itself
			if (divisorsSum > num3)
				printf("This number is generous!\n");
			else
				printf("This number does not share.\n");

			break;
		}

		case 4:
		{
			int num, notPrime = 0;
			printf("Enter a number:\n");
			scanf("%d", &num);

			while (num <= 0)
			{
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &num);
			}
			// initializing a reveredNumber which will be the reverse of the original number, the nums digit and a temp which will be equal to the number so I can change it and make opeartions without changing the original number
			int reversedNumber = 0;
			int numsDigit = 0;
			int temp = num;

			// getting the total number digits
			while (temp > 0)
			{
				temp /= 10;
				numsDigit++;
			}

			// checks if the number is prime (if it has a divisors other than 1 and the number itself)
			for (int i = 2; i < num; i++)
			{
				if (num % i == 0)
				{
					notPrime++;
					break;
				}
			}
			temp = num; // setting temp as num again so I can perform operation on the number
			for (int i = 0; i < numsDigit; i++)
			{
				// - Take the last digit of temp (temp % 10) and add it to 'reversedNumber' by multiplying 'reversedNumber' by 10 (shifting its digits to the left)
				//   and then adding the last digit of temp
				// - Remove the last digit from temp by dividing it by 10 (shifting the digits of temp to the right)
				reversedNumber = reversedNumber * 10 + temp % 10;
				temp /= 10;
			};

			// checking if the reversed number of the number is a prime or not
			for (int i = 2; i < reversedNumber; i++)
			{
				if (reversedNumber % i == 0)
				{
					notPrime++;
					break;
				}
			}

			// printing the required print with the condition if its not prime (true = 1) or (false = 0)
			if (notPrime)
			{
				printf("The circle remains incomplete.\n");
			}
			else
				printf("This number completes the circle of joy!\n");
			break;
		}

		case 5:
		{
			int num5, sum5, digit5, currentNum;
			printf("Enter a number:\n");
			scanf("%d", &num5);

			while (num5 <= 0)
			{
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &num5);
			}

			printf("Between 1 and %d, these numbers bring happiness: ", num5);
			for (int i = 1; i <= num5; i++)
			{
				currentNum = i;
				while (currentNum != 1 && currentNum != 4) // the while loop continues until 1 (happy number) or 4 (not a happy number)
				// all of the not happy numbers eventually the sum of their digits becomes 4 (by google)
				{
					sum5 = 0;
					while (currentNum > 0)
					{
						digit5 = currentNum % 10;
						sum5 += digit5 * digit5;
						currentNum /= 10;
					}
					currentNum = sum5; //  setting the current num as the sum to check if we can get out of the first while loop
				}

				if (currentNum == 1)
					printf("%d ", i);
			}
			printf("\n");
			break;
		}

		case 6:
		{
			int cheer = 0, smile = 0;
			printf("Enter a smile and a cheer number:\n");
			// cleaning the buffer
			scanf("%*[^\n]");
			scanf("%*c");
			scanf("smile: %d, cheer: %d", &smile, &cheer);
			while (smile <= 0 || cheer <= 0 || cheer == smile)
			{
				// cleaning the buffer
				scanf("%*[^\n]");
				scanf("%*c");
				printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
				scanf("smile: %d, cheer: %d", &smile, &cheer);
			}

			int n;
			printf("Enter maximum number for the festival:\n");
			scanf("%d", &n);
			while (n <= 0)
			{
				printf("Only positive number is allowed, please try again:\n");
				scanf("%d", &n);
			}

			for (int i = 1; i <= n; i++)
			{
				if (i % cheer == 0 && i % smile == 0)
				{
					printf("Festival!\n");
				}
				else if (i % smile == 0)
					printf("Smile!\n");
				else if (i % cheer == 0)
					printf("Cheer!\n");
				else
					printf("%d\n", i);
			}
			break;
		}

		case 7:
			printf("Thank you for your journey through Numeria!\n");
			return 0;
		}

	} while (optionNumber != 7);

	return 0;
}
