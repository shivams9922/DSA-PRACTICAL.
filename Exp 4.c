#include <stdio.h>
#include <string.h>

struct student
{
    char name[20];
    int roll_num;
} s[100];

void create(int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nEnter name: ");
        scanf("%s", s[i].name);

        printf("Enter roll no.: ");
        scanf("%d", &s[i].roll_num);
    }
}

void display(int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("\nName: %s", s[i].name);
        printf("\nRoll No.: %d\n", s[i].roll_num);
    }
}

void modify(int n)
{
    int roll, i;

    printf("\nEnter roll no. to modify: ");
    scanf("%d", &roll);

    for(i = 0; i < n; i++)
    {
        if(s[i].roll_num == roll)
        {
            printf("Enter new name: ");
            scanf("%s", s[i].name);

            printf("Enter new roll no.: ");
            scanf("%d", &s[i].roll_num);

            printf("Record modified successfully.\n");
            return;
        }
    }

    printf("Record not found.\n");
}

void search(int n)
{
    int roll, i;

    printf("\nEnter roll no. to search: ");
    scanf("%d", &roll);

    for(i = 0; i < n; i++)
    {
        if(s[i].roll_num == roll)
        {
            printf("\nRecord found!");
            printf("\nName: %s", s[i].name);
            printf("\nRoll No.: %d\n", s[i].roll_num);
            return;
        }
    }

    printf("\nRecord not found.\n");
}

void sort(int n)
{
    int i, j;
    struct student temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(s[i].roll_num > s[j].roll_num)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    printf("\nRecords sorted successfully.\n");
}

int main()
{
    int n, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    do
    {
        printf("\n\n1. Create");
        printf("\n2. Display");
        printf("\n3. Modify");
        printf("\n4. Search");
        printf("\n5. Sort");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create(n);
                break;

            case 2:
                display(n);
                break;

            case 3:
                modify(n);
                break;

            case 4:
                search(n);
                break;

            case 5:
                sort(n);
                break;

            case 6:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while(choice != 6);

    return 0;
}
