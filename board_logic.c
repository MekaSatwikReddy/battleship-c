#include <stdio.h>
typedef struct{
    char name[50];
        
}ship;

void init_board(char arr[10][10][2])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j][0] = '~';
            arr[i][j][1] = '~';
        }
    }
}
int max(int x, int y)
{
    if (x >= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int min(int x, int y)
{
    if (x <= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int place_ship(int n, char arr[10][10][2])
{
    int status = 0;
    int z1, z2;
    char x1, x2;
    int y1, y2;
    int a1, a2;
    int b1, b2;
    char check;
    int k = 0;
    int i;
    while (!status)

    {
        printf("DEPLOY SHIP OF LENGTH %d\n", n);
        printf("ENTER FIRST COORDINATE: ");
        i = 0;
        scanf(" %c %d", &x1, &y1);
        scanf("%c", &check);
        while (check != '\n')
        {
            scanf("%c", &check);
            i++;
            k = 1;
        }
        if (k == 1)
        {
            printf("INVALID SHIP PLACEMENT\n");
            k = 0;
            continue;
        }

        printf("ENTER SECOND COORDINATE: ");
        scanf(" %c %d", &x2, &y2);
        scanf("%c", &check);
        while (check != '\n')
        {
            scanf("%c", &check);
            i++;
            k = 1;
        }
        if (k == 1)
        {
            printf("INVALID SHIP PLACEMENT\n");
            k = 0;
            continue;
        }

        y1 = y1 - 1;
        y2 = y2 - 1;
        z1 = (int)x1 - 65;
        z2 = (int)x2 - 65;

        if (z1 < 0 || z1 > 9 || z2 < 0 || z2 > 9 || y1 < 0 || y1 > 9 || y2 < 0 || y2 > 9)
        {
            printf("INVALID SHIP PLACEMENT\n");
            status = 0;
            continue;
        }
        if (z1 == z2)
        {
            if (y1 - y2 == (n - 1) || y1 - y2 == (1 - n))
            {
                status = 1;
            }
            else
            {
                printf("INVALID SHIP PLACEMENT\n");
                status = 0;
                continue;
            }
        }
        else if (y1 == y2)
        {
            if (z1 - z2 == (n - 1) || z1 - z2 == (1 - n))
            {
                status = 1;
            }
            else
            {
                printf("INVALID SHIP PLACEMENT\n");
                status = 0;
                continue;
            }
        }
        else
        {
            printf("INVALID SHIP PLACEMENT\n");
            status = 0;
            continue;
        }

        a1 = min(z1, z2);
        a2 = max(z1, z2);
        b1 = min(y1, y2);
        b2 = max(y1, y2);
        for (int i = a1; i <= a2; i++)
        {
            for (int j = b1; j <= b2; j++)
            {
                if (arr[i][j][0] == 'S')
                {
                    printf("INVALID PLACEMENT\n");
                    status = 0;
                    i = a2 + 1;
                    break;
                }
            }
        }
    }
    for (int i = a1; i <= a2; i++)
    {
        for (int j = b1; j <= b2; j++)
        {
            arr[i][j][0] = 'S';
        }
    }
    return 1;
}
int register_hit(char arr[10][10][2])
{
    int status = 0;
    int k=0;
    int i=0;
    char check;
    while (!status)
    {
        printf("ENTER CO-ORDINATES TO HIT\n");
        char x1;

        int y1;
        scanf(" %c %d", &x1, &y1);
         scanf("%c", &check);
        while (check != '\n')
        {
            scanf("%c", &check);
            i++;
            k = 1;
        }
        if (k == 1)
        {
            printf("INVALID SHIP PLACEMENT\n");
            k = 0;
            continue;
        }

        y1 = y1 - 1;
        int z1;
        z1 = (int)x1 - 65;

        if (z1 < 0 || z1 > 9 || y1 < 0 || y1 > 9)
        {
            printf("INVALID HIT\n");
            continue;
            status = 0;
        }
        else if (arr[z1][y1][0] == '~')
        {
            status = 1;
            arr[z1][y1][0] = 'X';
            arr[z1][y1][1] = 'X';
            return 1;
        }
        else if (arr[z1][y1][0] == 'S')
        {
            arr[z1][y1][0] = 'H';
            arr[z1][y1][1] = 'S';
            status = 1;
            return 2;
        }
        else if (arr[z1][y1][0] == 'H')
        {
            printf("ALREADY HIT.INVALID CHOICE.\n");
            continue;
            status = 0;
        }
        else if (arr[z1][y1][0] == 'X')
        {
            printf("INVALID CHOICE.\n");
            printf("ALREADY TRIED THAT CO-ORDINATES.\n");
            continue;
            status = 0;
        }
    }
    return status;
}