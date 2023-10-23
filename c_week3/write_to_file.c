#include <stdio.h>

int main()
{
    char *filename = "data.txt";
    int number;
    int num_lines, total , mean;

    printf("how many numbers do you want to type in?\n");
    scanf("%d", &num_lines);
    printf("Type %d numbers: \n", num_lines);

    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

   
    
    for (int i = 0; i < num_lines; i++)
    {
        scanf("%d", &number);
        fprintf(file, "%d\n", number);
        total += number;
    }

    mean = total / num_lines;
    fprintf("the total of %d numbers was %d and the mean is %d", total, num_lines, mean);

    fclose(file);
    return 0;
}