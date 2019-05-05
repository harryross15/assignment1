#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * This program is able to encrypt and decrypt text using a rotation (Caesar) cipher using a rotation amount, 
 * and also encrypt and decrypt text using a substitution cipher using a substitution key. 
 * The program will process text given to it, using a key entered by the user to encrypt or decrypt it with one of the two cipher methods.
 * A lot of ASCII vlaue manipulation is used to change the letters that are used in a message to either be output as encrypted or decrypted from a previous encryption.
 * Arrays are used to store and navigate messages and substitution keys to process them one character at a time and then adding them to a new array to be displayed as the result.
 * Splitting the program into function helps for better readbility and makes the program easier to work on.
 * 
 * 
 * To choose between tasks, you are prompted with options after initially running  the program, and to select a task, type the corresponding number into the console.
 * After a task is chosen, you will be prompted to enter either a plain message or cipher text into the console, followed by a prompt for the encryption/decrption key.
 * When both of those are entered, the program will return you text back to you, either encrypted or solved, dependning on the task selected.
 * 
 * 
 * Flow control - The function prototypes are declared, when int main() is entered, some variables are initialised, then the tasks slecting menu is displayed.
 * After a task is selected, the user will be prompted to enter some values, and then the corresponding function is called and the task is executed using the user provided values. 
 * When a task is successfully completed, the swtich/case statement is exited using a break statement and the program finishes.
 */

void task1(char messageText[1000], int rotationKey);
void task2(char cipherText[1000], int rotationKey);
void task3(char messageText[1000], char substitutionKey[26]);           // Function prototypes
void task4(char cipherText[1000], char substitutionKey[26]);
int findCharacter(char substitutionKey[26], char cipherText);

int main() 
{
    int chosenTask = 0; // Initialises the menu option, initially setting it to 0
    int rotationKey;        
    char messageText[1000], substitutionKey[26], cipherText[1000]; // Initialises the arrays to be used my the different cipher tasks, and specifying their sizes
    
    printf("Choose one of the following tasks:\n\n");
    printf("1 - Encryption with Rotation Cipher\n");
    printf("2 - Decryption with Rotation Cipher\n");                            // Displays the menu options to the user for task selection
    printf("3 - Encryption with Substitution Cipher\n");
    printf("4 - Decryption with Substitution Cipher\n");
    printf("5 - Decryption with Rotation Cipher (Cipher text only)\n");
    printf("6 - Decryption with Substitution Cipher (Cipher text only)\n\n");
    printf("Enter a task number: \n\n");                                        // Prompts the user to choose a task by number
    scanf("%d", &chosenTask);
    printf("You selected: Task %d\n\n", chosenTask);
    switch(chosenTask)
    {
        case 1:                                                           // Switch/case statement to make selection between the multiple tasks easier
            printf("Enter a message to be encrypted: ");
            scanf("%99s", messageText);
            printf("\n\n");                                              // Displayed instruction to the user using printf()
            printf("Enter a rotation amount: ");
            scanf("%d", &rotationKey);                                  // scanf() used to take user inputs for to-be processed text and encrption/decryption key
            printf("\n\n");
            printf("Encrypted text: ");
            task1(messageText, rotationKey);                            // Function being called with its arguments
            break;                                                      // Break statement to exit the switch/case after a task has been executed
        case 2:
            printf("Enter a cipher to be decrypted: ");
            scanf("%99s", cipherText);
            printf("Enter a rotation amount: ");
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
            printf("Enter a cipher to be decrypted: ");
            scanf("%99s", cipherText);
            printf("Enter a decryption key: ");
            scanf("%99s", substitutionKey);
            printf("Decrypted text:\n\n");
            task4(cipherText, substitutionKey);
            break;
        case 5:
            printf("Task 5 incomplete");
            break;
        case 6:
            printf("Task 6 incomplete");
            break;
        default:
            printf("Invalid task\n\nTask number must be between 1 and 6");       // Error message shown if a task outside of 1-6 is selected by the user
    }
    return 0;
}

// Function Definitions

/* 
 * Inputs: messageText[1000], rotationKey
 * Return value: Encrypted text which corresponds with the provided rotation key
 * Description: Takes a block of plain text (up to 1000 characters) and encrypts it by using the given key to rotate the positions of the standard alphabet by an amount between 0 and 26. The plain text is then rewritten using the rotated alphabet.
 * Limitations: Rotation values which are lower than 0, or higher than 26 won't work properly, and scanf() causes the encryption to stop at whitespace (hard coding the plain text doesn't cause this issue)
 */

void task1(char messageText[1000], int rotationKey) 
{
    int len, i = 0;
    char encryption[1000];
    
    len = strlen(messageText);      // The length of messageText is assigned to len as an integer
    for(int i = 0;i < len;i++)      // The loop starts at i = 0, until the length of messageText is reached, and increments i by 1 each time
    {
        if(messageText[i] >= 'A' && messageText[i] <= 'Z')                   // Each character is tested for whether they are in the range of ASCII values for capital letters
        {                                                                    // For each character in messageText,  65 is subtracted from the character (to set A = 0, B = 1 etc.)
            encryption[i] = ((messageText[i] + rotationKey - 65) % 26) + 65; // , then the rotation key is added, and mod 26 is calculated,                                    
        }                                                                   // then 65 is re added to the ASCII value so it matches the captial letter equivalent to the rotation amount
        else if(messageText[i] >= 'a' && messageText[i] <= 'z')             // If a character is not in the first range, then it is tested for whether is in the ASCII range of lowercase letters
        {
            encryption[i] = ((messageText[i] + rotationKey - 65 - 32) % 26) + 65;    // 32 is aditionally subtracted from lowercase letters to convert them into uppercase
        }
        else                                                                // If the character is not a capital or lower case letter, then it is added to the encryption array unchanged
        {
            encryption[i] = messageText[i];                             // The newly generally letters are then stored in the encryption array
        }    
    }
    for(i = 0;i < len;i++)
    {
        printf("%c", encryption[i]);                             // A for-loop is then used to print all the values of the encryption array, using i to increment
    }
}

/* 
 * Inputs: cipherText[1000], rotationKey
 * Return value: Decrypted text which corresponds with the provided rotation key
 * Description: Takes a block of text encrypted with a Caesar cipher (up to 1000 characters) and decrypts it by using the given key to rotate the positions of the standard alphabet by an amount between 0 and 26.
 * Limitations: Rotation values which are lower than 0, or higher than 26 won't work properly, and scanf() causes the encryption to stop at whitespace (hard coding the cipher text doesn't cause this issue)
 */

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
        printf("%c", decryption[i]);            // A for-loop is then used to print all the values of the decryption array, using i to increment
    }
}

/* 
 * Inputs: messageText[1000], substitutionKey[26]
 * Return value: encryption[1000]
 * Description: Produces encrypted text by replacing each regular letter of the alphabet with the new values given in the key
 * Limitations: The key must be 26 characters long, with no repeated letters, and scanf() causes the encryption to stop at whitespace (hard coding the cipher text doesn't cause this issue)
 */

void task3(char messageText[1000], char substitutionKey[26])
{
    int len, i = 0, keyIndex = 0;
    char encryption[1000], textCharacter;
    
    len = strlen(messageText);      // The length of messageText is assigned to len as an integer
    for(int i = 0;i < len;++i)      // The loop starts at i = 0, until the length of messageText is reached, and increments i by 1 each time
    {
        
        if(messageText[i] >= 'A' && messageText[i] <= 'Z')              // Each character is tested for whether they are in the range of ASCII values for capital letters
        {
            keyIndex = messageText[i] - 'A';                        
            encryption[i] = substitutionKey[keyIndex];
        }   
        else if(messageText[i] >= 'a' && messageText[i] <= 'z')             // If a character is not in the first range, then it is tested for whether is in the ASCII range of lowercase letters
        {
            textCharacter = (messageText[i] - 32);                         // Subtracts 32 from the ASCII value of the lower case letter to make it uppercase
            keyIndex = textCharacter - 'A';                                // Subtracts the value of upper case A to set the letter values to A=0, B=1, C=2 etc.
            encryption[i] = substitutionKey[keyIndex];                     // Matches the above value between 0 and 25 with a position in the substitutionKey array and stores that letter in the encryption array
        }
        else                                                               // If the character is not a capital or lower case letter, then it is unchanged
        {
            encryption[i] = messageText[i];
        }    
    }
    for(i = 0;i < len;i++)
    {
        printf("%c", encryption[i]);                        // A for-loop is then used to print all the values of the encryption array, using i to increment
    }
}

/* 
 * Inputs: messageText[1000], substitutionKey[26]
 * Return value: encryption[1000]
 * Description: Decrypts cipher text which has been encrypted with a substitution cipher by using the key to reverse the alphabet subsitutions to recover the original message
 * Limitations: The key must be 26 characters long, with no repeated letters, and scanf() causes the encryption to stop at whitespace (hard coding the cipher text doesn't cause this issue)
 */

void task4(char cipherText[1000], char substitutionKey[26])
{
    int len, i = 0, keyIndex = 0;
    char decryption[1000];
    
    len = strlen(cipherText);      // The length of messageText is assigned to len as an integer
    for(int i = 0;i < len;++i)      // The loop starts at i = 0, until the length of messageText is reached, and increments i by 1 each time
    {
        
        if(cipherText[i] >= 'A' && cipherText[i] <= 'Z')                // Each character is tested for whether they are in the range of ASCII values for capital letters
        {
            keyIndex = findCharacter(substitutionKey, cipherText[i]);      // The findCharacter function is called to determine a letters position within the substitutionKey array and the value is assigned to keyIndex
            decryption[i] = keyIndex + 'A';                                // The ASCI I value of 'A' is added to keyIndex, and the new generated letter is added to the decryption array
        }   
        else if(cipherText[i] >= 'a' && cipherText[i] <= 'z')             // If a character is not in the first range, then it is tested for whether is in the ASCII range of lowercase letters
        {
            cipherText[i] = (cipherText[i] - 32);                           // Subtracts 32 from the ASCII value of the lower case letter to make it uppercase
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
        printf("%c", decryption[i]);                    // A for-loop is then used to print all the values of the decryption array, using i to increment
    }
}

/* 
 * Inputs: substitutionKey[26], cipherText
 * Return value: i
 * Description: Checks to see what the array position of a character in the encrypted text is, then returns it to 'i' for the substitution decryption function to use 
 * Limitations: N/A
 */

int findCharacter(char substitutionKey[26], char cipherText)
{
    for(int i = 0;i < 26 ;i++)          // Tests for all characters in the substitutionKey array, starting at 0 and incrementing each loop
    {
        if(substitutionKey[i] == cipherText)                // Tests for all values of substitutionKey to find which is each to the cipher character being tested
        {
            return i;               // The matching value is then returned to i
        }
    }
    return 0;           // Returns a value at the end of the function to avoid errors, as it isn't void
}