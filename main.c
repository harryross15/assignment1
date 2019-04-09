#include <stdio.h>

//char task1(messageText, );

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
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            printf("Invalid task\n\nTask number must be between 1 and 6");
    }
    return 0;
}
