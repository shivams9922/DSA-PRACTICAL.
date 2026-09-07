#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], copy[100], rev[100], sub[100];
    int choice, i, j, len, pos, flag;

    printf("Enter a string: ");
    scanf("%s", str);

    do
    {
        printf("\n\n--- STRING OPERATIONS ---");
        printf("\n1. Copy");
        printf("\n2. Palindrome");
        printf("\n3. Reverse");
        printf("\n4. Substring");
        printf("\n5. Compare");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        len = strlen(str);

        switch(choice)
        {
            case 1:
                strcpy(copy, str);
                printf("Copied string: %s", copy);
                break;

            case 2:
                flag = 1;

                for(i = 0, j = len - 1; i < j; i++, j++)
                {
                    if(str[i] != str[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag)
                    printf("The given string is a Palindrome");
                else
                    printf("The given string is not a Palindrome");

                break;

            case 3:
                for(i = 0; i < len; i++)
                    rev[i] = str[len - 1 - i];

                rev[len] = '\0';

                printf("Reversed string: %s", rev);
                break;

            case 4:
                printf("Enter starting position: ");
                scanf("%d", &pos);

                if(pos >= 0 && pos < len)
                {
                    j = 0;

                    for(i = pos; i < len; i++)
                        sub[j++] = str[i];

                    sub[j] = '\0';

                    printf("Substring: %s", sub);
                }
                else
                {
                    printf("Position out of range");
                }

                break;

            case 5:
                {
                    char str2[100];

                    printf("Enter another string: ");
                    scanf("%s", str2);

                    if(strcmp(str, str2) == 0)
                        printf("Both strings are equal");
                    else if(strcmp(str, str2) < 0)
                        printf("%s comes before %s", str, str2);
                    else
                        printf("%s comes after %s", str, str2);

                    break;
                }

            case 6:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice!");
        }

    } while(choice != 6);

    return 0;
}
