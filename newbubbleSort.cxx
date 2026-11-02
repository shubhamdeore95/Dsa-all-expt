#include <stdio.h>

int AscSort(int a[], int n)
{   
    int temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }  
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}

int main()
{
    int i, a[100], n;
    
    printf("Enter the number of temperature readings: ");
    scanf("%d", &n);
    
    printf("Enter the temperature readings:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    printf("\nThe sorted temperatures in ascending order are:\n");
    AscSort(a, n);
   
    printf("The highest temperature is: %d\n", a[n - 1]);
    
    return 0;
}

