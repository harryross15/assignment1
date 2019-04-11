#include <stdio.h>

/*
 * char task1(messageText, );
 * char task2();
 * char task3();
 * char task4();
 * char task5();
 * char task6();
 */


int main() 
{
    int chosenTask = 0;
    //char messageText[100];
    
    printf("Choose one of the following tasks:\n\n");
    printf("1 - Encryption with Rotation Cipher\n");
    printf("2 - Decryption with Rotation Cipher\n");
    printf("3 - Encryption with Substitution Cipher\n");
    printf("4 - Decryption with Substitution Cipher\n");
    printf("5 - Decryption with Rotation Cipher (Cipher text only)\n");
    printf("6 - Decryption with Substitution Cipher (Cipher text only)\n\n");
    printf("Enter a task number: \n\n");
    scanf("%d", &chosenTask);
    printf("You selected: %d\n\n", chosenTask);
    switch(chosenTask)
    {
        case 1:
            printf("Task 1 output");
            break;
        case 2:
            printf("Task 2 output");
            break;
        case 3:
            printf("Task 3 output");
            break;
        case 4:
            printf("Task 4 output");
            break;
        case 5:
            printf("Task 5 output");
            break;
        case 6:
            printf("Task 6 output");
            break;
        default:
            printf("Invalid task\n\nTask number must be between 1 and 6");
    }
    return 0;
}

/*
 *char task1()
 * 
 *char task2()
 *
 *char task3()
 *
 *char task4()
 *
 *char task5()
 *
 *char task6()
 *
 */