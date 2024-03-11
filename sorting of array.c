#include <stdio.h>

int main()
{
    int i, j, temp;
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Printing Sorted Element List in descending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}
