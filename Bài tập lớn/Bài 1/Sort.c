#include <stdlib.h>
#include <stdio.h>

// ------------------------------------- increase --------------------------------------
void selection_sort1(int k[], int n)
{
    int i, j, m, x;
    for (i = 0; i < n; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            if (k[j] < k[m])
                m = j;
        }

        if (m != i)
        {
            x = k[i];
            k[i] = k[m];
            k[m] = x;                                           
        }
    }
}


void insert_sort1(int k[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = k[i];
        j = i - 1;
        while (x < k[j] && j >= 0)
        {
            k[j + 1] = k[j];
            j = j - 1;
        }
        k[j + 1] = x;
    }
}


void bubble_sort1(int k[], int n)
{
    int i, j, x;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (k[j] < k[j - 1])
            {
                x = k[j];
                k[j] = k[j - 1];
                k[j - 1] = x;
            }
        }
    }
} 
// -------------------------------------- decrease -----------------------------------------

void insert_sort2(int k[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = k[i];
        j = i - 1;
        while (x > k[j] && j >= 0)
        {
            k[j + 1] = k[j];
            j = j - 1;
        }
        k[j + 1] = x;
    }
}

void selection_sort2(int k[], int n)
{
    int i, j, m, x;
    for (i = 0; i < n; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            if (k[j] > k[m])
                m = j;
        }

        if (m != i)
        {
            x = k[i];
            k[i] = k[m];
            k[m] = x;                                           
        }
    }
}


void bubble_sort2(int k[], int n)
{
    int i, j, x;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (k[j] > k[j - 1])
            {
                x = k[j];
                k[j] = k[j - 1];
                k[j - 1] = x;
            }
        }
    }
}

void printOut(int k[], int n){
    int i;
    for(i = 0; i<n; i++) {
        printf("%d ", k[i]);
    }
}

// --------------------------------------- main ------------------------------------

int main() {
    int n = 7;
    int a[] = {9, 11, 8, 6, 7, 5, 10};
    printOut(a, n);
    selection_sort1(a, n);
    printf("\nselection sort increase:\n");
    printOut(a, n);

    insert_sort1(a, n);
    printf("\nbubble sort increase\n");
    printOut(a, n);
    
    bubble_sort1(a, n);
    printf("\ninsert sort increase\n");
    printOut(a, n);
    

    selection_sort2(a, n);
    printf("\n\nselection sort decrease:\n");
    printOut(a, n);
    
    insert_sort2(a, n);
    printf("\ninsert sort decrease\n");
    printOut(a, n);
    
    bubble_sort2(a, n);    
    printf("\nbubble sort decrease\n");
    printOut(a, n);
}