/******************
Name: Steve Bendersky
Assignment: ex2
*******************/

#include <stdio.h>

int main()
{
	int optionNumber;
    printf("Choose an option:\n"
           "1. Happy Face\n"
           "2. Balanced Number\n"
           "3. Generous Number\n"
           "4. Circle Of Joy\n"
           "5. Happy Numbers\n"
           "6. Festival Of Laughter\n"
           "7. Exit\n");

	scanf("%d", &optionNumber);
	while (optionNumber < 1 || optionNumber > 7) {
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
	// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
	/* Example:
	 * n = 3:
	 * 0   0
	 *   o
	 * \___/
	 */

	// Case 1
	switch (optionNumber) {
	case 1: {
			char symbol1, symbol2, symbol3;
	int faceSize;
	printf("Enter symbols for the eyes, nose, and mouse:\n");
	scanf("%c %c %c", &symbol1, &symbol2, &symbol3);
	printf("Enter face size:\n");
	scanf("%d", &faceSize);
	while (faceSize <= 0 || faceSize % 2 == 0)
	{
		printf("The face's size must be an odd and positive number, please try again:\n");
		scanf("%d", &faceSize);
	}
	printf("%c", symbol1);
	for (int i = 0; i < faceSize; i++)
	{
		printf(" ");
	}
	printf("%c\n", symbol1);
	int halfFaceSize = faceSize / 2;
	for (int i = 0; i < halfFaceSize + 1; i++)
	{
		printf(" ");
	}
	printf("%c", symbol2);
	for (int i = halfFaceSize + 1; i <= faceSize; i++)
	{
		printf(" ");
	}
	printf("\n");
	printf("\\");
	for (int i = 0; i < faceSize; i++)
	{
		printf("%c", symbol3);
	}
	printf("/\n");
	break;
	}

	// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
	// and the sum of all digits to the right of the middle digit(s) are equal
	/* Examples:
	Balanced: 1533, 450810, 99
	Not blanced: 1552, 34
	Please notice: the number has to be bigger than 0.
	*/
	case 2: {
			int num2, numsDigitCount = 0, rightCount = 0, leftCount = 0;
	printf("Please enter a number\n");
	scanf("%d", &num2);

	while (num2 <= 0)
	{
		printf("Only positive number is allowed, please try again:\n");
		scanf("%d", &num2);
	}

	if (num2 < 10)
	{
		printf("The number is balanced and brings harmony!");
	}
	int shallowCopy = num2;
	while (shallowCopy != 0)
	{
		shallowCopy = shallowCopy / 10;
		numsDigitCount++;
	}

	int halfOfNumsDigitCount = numsDigitCount / 2;
	printf("%d\n", halfOfNumsDigitCount);
	for (int i = 0; i < numsDigitCount; i++)
	{
		int numDigit = num2 % 10;
		num2 = num2 / 10;
				if (numsDigitCount %2 != 0 && i == halfOfNumsDigitCount + 1) {
					printf("%d", i);
			rightCount += numDigit;
			leftCount += numDigit;
		}

		if (i < halfOfNumsDigitCount)
		{
			rightCount += numDigit;
		}
		else
		{
			leftCount += numDigit;
		}
	}

	if (rightCount == leftCount)
		printf("This number is balanced and brings harmony!\n");
	else
		printf("This number isn't balanced and destroys harmony.\n");
	break;
	}
		// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
	/* Examples:
	Abudant: 12, 20, 24
	Not Abudant: 3, 7, 10
	Please notice: the number has to be bigger than 0.
	*/

	case 3: {
			int num3, divisorsSum = 0;
	printf("Enter a number:\n");
	scanf("%d", &num3);

	while (num3 <= 0)
	{
		printf("Only positive number is allowed, please try again:\n");
		scanf("%d", &num3);
	}

	for (int i = 1; i < num3; i++)
	{
		if (num3 % i == 0)
			divisorsSum += i;
	}

	if (divisorsSum > num3)
	{
		printf("This number is generous!\n");
	}
	else
		printf("This number does not share.\n");
		break;
	}
		// Case 4: determine wether a number is a prime.
	/* Examples:
	This one brings joy: 3, 5, 11
	This one does not bring joy: 15, 8, 99
	Please notice: the number has to be bigger than 0.
	*/

	case 4: {
	int num, notPrime = 0;
	printf("Please enter a number\n");
	scanf("%d", &num);

	while (num < 0) {
		printf("Only positive number is allowed, please try again:\n");
		scanf("%d", &num);
	}
	for (int i=2; i<num; i++) {
		if (num % i == 0) {
			notPrime++;
			break;
		}
	}

	if (notPrime) {
		printf("This one does not bring joy%d\n", num);
	} else printf("This one brings joy: %d\n", num);
	break;
	} case 7: {
		printf("Thank you for your journey through Numeria!");
			return 0;
	}
	} while (1);

	// Happy numbers: Print all the happy numbers between 1 to the given number.
	// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
	/* Examples:
	Happy :) : 7, 10
	Not Happy :( : 5, 9
	Please notice: the number has to be bigger than 0.
	*/

	// int num5;
	// printf("Please enter a number\n");
	// scanf("%d", &num5);

	// while (num5 <= 0) {
	// 	printf("Only positive number is allowed, please try again:\n");
	// 	scanf("%d", &num5);
	// }

	// printf("Between 1 and %d only these numbers bring happiness: 1 ", num5);
	// for (int i=2; i<num5; i++) {
	// 	int num6 = i;
	// 	int sum = 0;
	// 	while (num6 !== 1) {
			
	// 	}
	// }
	// Festival of Laughter: Prints all the numbers between 1 the given number:
	// and replace with "Smile!" every number that divided by the given smile number
	// and replace with "Cheer!" every number that divided by the given cheer number
	// and replace with "Festival!" every number that divided by both of them
	/* Example:
	6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
	*/
}
