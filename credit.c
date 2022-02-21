// prompt the user for their credit card number
// printf if it is a VISA, AMEX, MASTERCARD or INVALID

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");

    // calculate the checksum

    int digit = number % 100;
    int tenthsDigit = digit / 10;
    int multipliedTenthsDigit = tenthsDigit * 2;


    int digitTwo = number % 10000;
    int thousandthsDigit = digitTwo / 1000;
    int multipliedThousandthsDigit = thousandthsDigit * 2;

    int digitThree = number % 1000000;
    int thirdDigit = digitThree / 100000;
    int multipliedThirdDigit = thirdDigit * 2;

    int digitFour = number % 100000000;
    int fourthDigit = digitFour / 10000000;
    int multipliedFourthDigit = fourthDigit * 2;

    long digitFive = number % 10000000000;
    long fifthDigit = digitFive / 1000000000;
    long multipliedFifthDigit = fifthDigit * 2;

    long digitSix = number % 1000000000000;
    long sixthDigit = digitSix / 100000000000;
    long multipliedSixthDigit = sixthDigit * 2;

    long digitSeven = number % 100000000000000;
    long seventhDigit = digitSeven / 10000000000000;
    long multipliedSeventhDigit = seventhDigit * 2;

    long digitEight = number % 10000000000000000;
    long eigthDigit = digitEight / 1000000000000000;
    long multipliedEigthDigit = eigthDigit * 2;

    // add multiplied products' digits together to get firstSum

    int a = multipliedTenthsDigit;
    int aTenths = a / 10;
    int aOnes = a % 10;

    int b = multipliedThousandthsDigit;
    int bTenths = b / 10;
    int bOnes = b % 10;

    int c = multipliedThirdDigit;
    int cTenths = c / 10;
    int cOnes = c % 10;

    int d = multipliedFourthDigit;
    int dTenths = d / 10;
    int dOnes = d % 10;

    int e = multipliedFifthDigit;
    int eTenths = e / 10;
    int eOnes = e % 10;

    int f = multipliedSixthDigit;
    int fTenths = f / 10;
    int fOnes = f % 10;

    int g = multipliedSeventhDigit;
    int gTenths = g / 10;
    int gOnes = g % 10;

    int h = multipliedEigthDigit;
    int hTenths = h / 10;
    int hOnes = h % 10;

    int firstSum = aTenths + aOnes + bTenths + bOnes + cTenths + cOnes + dTenths + dOnes + eTenths + eOnes + fTenths + fOnes + gTenths +
                   gOnes + hTenths + hOnes;

    // add firstSum + other digits

    int lastDigit = number % 10;

    int digit2 = number % 1000;
    int digit2d = digit2 / 100;

    int digit3 = number % 100000;
    int digit3d = digit3 / 10000;

    int digit4 = number % 10000000;
    int digit4d = digit4 / 1000000;

    long digit5 = number % 1000000000;
    long digit5d = digit5 / 100000000;

    long digit6 = number % 100000000000;
    long digit6d = digit6 / 10000000000;

    long digit7 = number % 10000000000000;
    long digit7d = digit7 / 1000000000000;

    long digit8 = number % 1000000000000000;
    long digit8d = digit8 / 100000000000000;

    int sum = firstSum + lastDigit + digit2d + digit3d + digit4d + digit5d + digit6d + digit7d + digit8d;

    // distinguish between AMEX, VISA, and MASTERCARD

    int count = 0;

    while (number != 0)
    {
        count++;
        number = number / 10;
    }

    if (count == 15 && digit8d == 3 && (seventhDigit == 4 || seventhDigit == 7) && (sum % 10 == 0))
    {
        printf("AMEX\n");
    }
    else if (count == 16 && eigthDigit == 5 && (digit8d == 1 || digit8d == 2 || digit8d == 3 || digit8d == 4 || digit8d == 5)
             && (sum % 10 == 0))
    {
        printf("MASTERCARD\n");
    }
    else if ((count == 13 || count == 16) && (eigthDigit == 4 || digit7d == 4) && (sum % 10 == 0))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }







}