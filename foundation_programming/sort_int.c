void displayArray(int numbers[], int count);

int main(void)
{
    int numbers[] = {25, 45, 12, 4, 52, 22, 125, 1, 5, 3, 94, 1, 1,1, 1,1, 1, 99999999, 454684415,4564,56465 ,465,465,465,4654,65,465,465 ,46};
    displayArray(numbers, sizeof(numbers) / sizeof(int));

    _Bool hasChanged = 1;
    while(hasChanged == 1)
    {
        hasChanged = 0;        

        for(int i = 0; i < sizeof(numbers) / sizeof(int); i++)
        {
            if(i == 0)
            {
                continue;
            } else {
                if(numbers[i-1] > numbers[i])
                {
                    int tmp = numbers[i-1];
                    numbers[i-1] = numbers[i];
                    numbers[i] = tmp;
                    hasChanged = 1;
                }
            }
        }
    }

    printf("\nbecomes:\n\n");
    displayArray(numbers, sizeof(numbers) / sizeof(int));
}

void displayArray(int numbers[], int count)
{
    for(int i = 0; i < count; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");
}