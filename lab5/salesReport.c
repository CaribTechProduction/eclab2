#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

void generate_sales_report(float sales_data[])
{
    char *months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Sales report
    printf("Monthly sales report for 2022:\n");
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++)
    {
        printf("%s\t$%.2f\n", months[i], sales_data[i]);
    }

    // Sales summary
    float min_sales = sales_data[0];
    float max_sales = sales_data[0];
    float total_sales = 0;
    for (int i = 0; i < MONTHS; i++)
    {
        if (sales_data[i] < min_sales)
        {
            min_sales = sales_data[i];
        }
        if (sales_data[i] > max_sales)
        {
            max_sales = sales_data[i];
        }
        total_sales += sales_data[i];
    }
    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min_sales, months[0]);
    printf("Maximum sales: $%.2f (%s)\n", max_sales, months[MONTHS - 1]);
    printf("Average sales: $%.2f\n", total_sales / MONTHS);

    // Six-month moving averages
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i < MONTHS - 5; i++)
    {
        float sum = 0;
        for (int j = i; j < i + 6; j++)
        {
            sum += sales_data[j];
        }
        printf("%s - %s $%.2f\n", months[i], months[i + 5], sum / 6);
    }

    // Sales report (Highest to Lowest)
    for (int i = 0; i < MONTHS; i++)
    {
        for (int j = i + 1; j < MONTHS; j++)
        {
            if (sales_data[i] < sales_data[j])
            {
                float temp = sales_data[i];
                sales_data[i] = sales_data[j];
                sales_data[j] = temp;
                char *temp_month = months[i];
                months[i] = months[j];
                months[j] = temp_month;
            }
        }
    }
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++)
    {
        printf("%s\t$%.2f\n", months[i], sales_data[i]);
    }
}

int main()
{
    FILE *file = fopen("input_sales.txt", "r");
    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    float sales_data[MONTHS];
    for (int i = 0; i < MONTHS && fscanf(file, "%f", &sales_data[i]) == 1; i++)
        ;

    generate_sales_report(sales_data);

    fclose(file);
    system("pause");
    return 0;
}
