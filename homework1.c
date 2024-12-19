// I am Vedant Sahu, owner of this program, got it?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, count_b = 0, count_g = 0;
    float total_per_all = 0, total_per_boy = 0, total_per_girl = 0;

    printf("how many student are there in the class : ");
    scanf("%d", &n);

    struct std
    {
        char name[20], gender[7];
        int math, c, fcs, eng, de;
        float percentage;
    };

    // declaration of different structure arrays based on gender
    struct std info[n];
    struct std boys[n];
    struct std girls[n];

    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("\nEnter name of student %d : ", i + 1);
        gets(info[i].name);
        printf("\nEnter gender of student %d (male/female) : ", i + 1);
        gets(info[i].gender);

        // take marks at once
        printf("Enter marks of 5 subjects respectively : (out of 100)\n");
        scanf("%d%d%d%d%d", &info[i].math, &info[i].c, &info[i].fcs, &info[i].eng, &info[i].de);

        // optional*  un-comment this part if u wanna take marks one by one of each subject (it'll be time consuming)
        // printf("\nEnter marks in maths of student %d : ", i + 1);
        // scanf("%d", &info[i].math);
        // printf("\nEnter marks in c programming of student %d : ", i + 1);
        // scanf("%d", &info[i].c);
        // printf("\nEnter marks in fcs of student %d : ", i + 1);
        // scanf("%d", &info[i].fcs);
        // printf("\nEnter marks in communication skill of student %d : ", i + 1);
        // scanf("%d", &info[i].eng);
        // printf("\nEnter marks in electronics of student %d : ", i + 1);
        // scanf("%d", &info[i].de);

        info[i].percentage = (info[i].math + info[i].c + info[i].fcs + info[i].eng + info[i].de) / 5.0;
        total_per_all += info[i].percentage;
        printf("percentage of %s is %.2f \n", info[i].name, info[i].percentage);

        if (strcmp(info[i].gender, "male") == 0)
        {
            boys[count_b] = info[i];
            boys[count_b].percentage = (boys[count_b].math + boys[count_b].c + boys[count_b].fcs + boys[count_b].eng + boys[count_b].de) / 5.0;
            total_per_boy += boys[count_b].percentage;
            count_b++;
        }
        else if (strcmp(info[i].gender, "female") == 0)
        {
            girls[count_g] = info[i];
            girls[count_g].percentage = (girls[count_g].math + girls[count_g].c + girls[count_g].fcs + girls[count_g].eng + girls[count_g].de) / 5.0;
            total_per_girl += girls[count_g].percentage;
            count_g++;
        }
        else
        {
            // nothing
        }
    }

    printf("\nThe total no. of student is %d\n", n);
    printf("The no. of Boys in the class are : %d\n", count_b);
    printf("The no. of Girls in the class are : %d\n", count_g);

    printf("\naverage percentage of whole class is : %.3f\n", total_per_all / n);
    printf("average percentage of boys is : %.3f\n", total_per_boy / count_b);
    printf("average percentage of girls is : %.3f\n", total_per_girl / count_g);

    // this is to print boys information
    printf("Boys are : ");
    for (int i = 0; i < count_b; i++)
    {
        puts(boys[i].name);
    }

    // this is to print girls information
    printf("Girls are : ");
    for (int i = 0; i < count_g; i++)
    {
        puts(girls[i].name);
    }

    return 0;
}

// © all rights reserved 2024