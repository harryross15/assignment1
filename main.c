#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * char task5();
 * char task6();
 */

void task1(char messageText[1000], int rotationKey);
void task2(char cipherText[1000], int rotationKey);
void task3(char messageText[1000], char substitutionKey[26]);
void task4(char cipherText[1000], char substitutionKey[26]);
int findCharacter(char substitutionKey[26], char cipherText);

int main() 
{
    int chosenTask = 0;
    int rotationKey;
    char messageText[1000], substitutionKey[26], cipherText[1000];
    
    printf("Choose one of the following tasks:\n\n");
    printf("1 - Encryption with Rotation Cipher\n");
    printf("2 - Decryption with Rotation Cipher\n");
    printf("3 - Encryption with Substitution Cipher\n");
    printf("4 - Decryption with Substitution Cipher\n");
    printf("5 - Decryption with Rotation Cipher (Cipher text only)\n");
    printf("6 - Decryption with Substitution Cipher (Cipher text only)\n\n");
    printf("Enter a task number: \n\n");
    scanf("%d", &chosenTask);
    printf("You selected: Task %d\n\n", chosenTask);
    switch(chosenTask)
    {
        case 1:
            printf("Enter a message to be encrypted: ");
            scanf("%99s", messageText);
            printf("\n\n");
            printf("Enter a rotation amount: ");
            scanf("%d", &rotationKey);
            printf("\n\n");
            printf("Encrypted text: ");
            task1(messageText, rotationKey);
            break;
        case 2:
            scanf("%99s", cipherText);
            scanf("%d", &rotationKey);
            printf("Decrypted text:\n\n");
            task2(cipherText, rotationKey);
            break;
        case 3:
            printf("Enter a message to be encrypted: ");
            scanf("%99s", messageText);
            printf("\n\n");
            printf("Enter an encryption key: ");
            scanf("%99s", substitutionKey);
            printf("\n\n");
            printf("Encrypted text: ");
            task3(messageText, substitutionKey);
            break;
        case 4:
            scanf("%99s", cipherText);
            scanf("%99s", substitutionKey);
            printf("Decrypted text:\n\n");
            task4(cipherText, substitutionKey);
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
 *char task5()
 *
 *char task6()
 *
 */

void task1(char messageText[1000], int rotationKey) 
{
    int len, i = 0;
    char encryption[1000];
    
    len = strlen(messageText);      // The length of messageText is assigned to len as an integer
    for(int i = 0;i < len;i++)      // The loop starts at i = 0, until the length of messageText is reached, and increments i by 1 each time
    {
        if(messageText[i] >= 'A' && messageText[i] <= 'Z')                   // Each character is tested for whether they are in the range of ASCII values for capital letters
        {                                                                    // Each character in messageText is assigned to textCharacter, going from left to right each loop
            encryption[i] = ((messageText[i] + rotationKey - 65) % 26) + 65; // 65 is subtracted from the character (to set A = 0, B = 1 etc.) the rotation key is added, and mod 26 is calculated,                                    
        }                                                                   // then 65 is re added to the ASCII value so it matches a captial letter
        else if(messageText[i] >= 'a' && messageText[i] <= 'z')             // If a character is not in the first range, then it is tested for whether is in the ASCII range of lowercase letters
        {
            encryption[i] = ((messageText[i] + rotationKey - 65 - 32) % 26) + 65;    // 32 is aditionally subtracted from lowercase letters to convert them into uppercase
        }
        else                                                                // If the character is not a capital or lower case letter, then it is added to the encryption array unchanged
        {
            encryption[i] = messageText[i];
        }    
    }
    for(i = 0;i < len;i++)
    {
        printf("%c", encryption[i]);
    }
}

void task2(char cipherText[1000], int rotationKey) 
{
int len, i = 0;
    char textCharacter = 'A', decryption[1000];
    
    len = strlen(cipherText);      // The length of messageText is assigned to len as an integer
    for(int i = 0;i < len;++i)      // The loop starts at i = 0, until the length of messageText is reached, and increments i by 1 each time
    {
        if(cipherText[i] >= 'A' && cipherText[i] <= 'Z')                  // Each character is tested for whether they are in the range of ASCII values for capital letters
        {
            textCharacter = cipherText[i];                                 // Each character in messageText is assigned to textCharacter, going from left to right each loop
            textCharacter = (textCharacter - rotationKey - 65);             // 65 is subtracted from the character (to set A = 0, B = 1 etc.) and the rotation key is also subtracted
            if (textCharacter < 0)
            {
                textCharacter = textCharacter + 26;                         // Before the modulus is calcuted, textCharacter is tested, and if it has become negative after subtracting 65, 26 is added.
            }
            textCharacter = (textCharacter % 26) + 65;                      // Mod 26 is found, and then 65 is re added to the ASCII value so it matches a captial letter                                 
            decryption[i] = textCharacter;
        }
        else if(cipherText[i] >= 'a' && cipherText[i] <= 'z')             // If a character is not in the first range, then it is tested for whether is in the ASCII range of lowercase letters
        {
            textCharacter = cipherText[i];
            textCharacter = (textCharacter + rotationKey - 65 - 32);        // 32 is aditionally subtracted from lowercase letters to convert them into uppercase
            if (textCharacter < 0)
            {
                textCharacter = textCharacter + 26;
            }
            textCharacter = (textCharacter % 26) + 65;
            decryption[i] = textCharacter;
        }
        else                                                                // If the character is not a capital or lower case letter, then it is unchanged
        {
            decryption[i] = cipherText[i];
        }
    }
    for(i = 0;i < len;i++)
    {
        printf("%c", decryption[i]);
    }
}

void task3(char messageText[1000], char substitutionKey[26])
{
    int len, i = 0, keyIndex = 0;
    char encryption[1000], textCharacter;
    
    len = strlen(messageText);      // The length of messageText is assigned to len as an integer
    for(int i = 0;i < len;++i)      // The loop starts at i = 0, until the length of messageText is reached, and increments i by 1 each time
    {
        
        if(messageText[i] >= 'A' && messageText[i] <= 'Z')              
        {
            keyIndex = messageText[i] - 'A';
            if(keyIndex >= 0 && keyIndex < 26)
            {
                encryption[i] = substitutionKey[keyIndex];
            }
        }   
        else if(messageText[i] >= 'a' && messageText[i] <= 'z')             
        {
            textCharacter = (messageText[i] - 32);
            keyIndex = textCharacter - 'A';
            if(keyIndex >= 0 && keyIndex < 26)
            {
                encryption[i] = substitutionKey[keyIndex];
            }
        }
        else                                                               // If the character is not a capital or lower case letter, then it is unchanged
        {
            encryption[i] = messageText[i];
        }    
    }
    for(i = 0;i < len;i++)
    {
        printf("%c", encryption[i]);
    }
}

void task4(char cipherText[1000], char substitutionKey[26])
{
    int len, i = 0, keyIndex = 0;
    char decryption[1000];
    
    len = strlen(cipherText);      // The length of messageText is assigned to len as an integer
    for(int i = 0;i < len;++i)      // The loop starts at i = 0, until the length of messageText is reached, and increments i by 1 each time
    {
        
        if(cipherText[i] >= 'A' && cipherText[i] <= 'Z')              
        {
            keyIndex = findCharacter(substitutionKey, cipherText[i]);
            decryption[i] = keyIndex + 'A';
        }   
        else if(cipherText[i] >= 'a' && cipherText[i] <= 'z')             
        {
            cipherText[i] = (cipherText[i] - 32);
            keyIndex = findCharacter(substitutionKey, cipherText[i]);
            decryption[i] = keyIndex + 'A';
        }
        else                                                               // If the character is not a capital or lower case letter, then it is unchanged
        {
            decryption[i] = cipherText[i];
        }    
    }
    for(i = 0;i < len;i++)
    {
        printf("%c", decryption[i]);
    }
}

int findCharacter(char substitutionKey[26], char cipherText)
{
    for(int i = 0;i < 26 ;i++)
    {
        if(substitutionKey[i] == cipherText)
        {
            return i;
        }
    }
    return 0;
}