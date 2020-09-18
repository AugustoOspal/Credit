#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{

    // Declaring variables
    int p13;
    int p14;
    int p15;
    int p16;

    int counter1 = 0;
    int counter2 = 0;
    int last_num = 0;
    int last_num_counter2 = 0;

    // User input
    long card_num = get_long("Number: ");

    // Get size of long
    int size = floor(log10(card_num)) + 1;

    // checksum
    for (int i = 0; i < 16; i++)
    {
        last_num = card_num % 10;

        if (i % 2 == 0)
        {
            counter1 += last_num;
        }

        else
        {
            if ((last_num * 2) >= 10)
            {
                last_num_counter2 = (last_num * 2) % 10;
                counter2 += last_num_counter2;
                counter2 += ((last_num * 2) - last_num_counter2) / 10;
            }

            else
            {
                counter2 += last_num * 2;
            }
        }

        card_num = (card_num - (card_num % 10)) / 10;

        // log some numbers
        if (i == 12)
        {
            p13 = last_num;
        }

        else if (i == 13)
        {
            p14 = last_num;
        }

        else if (i == 14)
        {
            p15 = last_num;
        }

        else if (i == 15)
        {
            p16 = last_num;
        }

    }

    int total_num = counter1 + counter2;

    // type of credit card

    // VISA
    if (((p13 == 4 && size == 13) || (p16 == 4 && size == 16)) && total_num % 10 == 0)
    {
        printf("VISA\n");
    }

    // MASTERCARD
    else if ((p16 == 5 && (p15 == 1 || p15 == 2 || p15 == 3 || p15 == 4 || p15 == 5)) && size == 16 && total_num % 10 == 0)
    {
        printf("MASTERCARD\n");
    }

    // AMERICAN EXPRESS
    else if (p15 == 3 && (p14 == 4 || p14 == 7) && size == 15 && total_num % 10 == 0)
    {
        printf("AMEX\n");
    }

    else
    {
        printf("INVALID\n");
    }
}
