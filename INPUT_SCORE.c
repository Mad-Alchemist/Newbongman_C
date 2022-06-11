#include <stdio.h>


int main(void)
{
    printf("\n <문제.1> \n");
	printf("\t 5명 이상의 학생 이름과 성적 3개를 입력 받아서 파일에 저장하시오.\n\n");

    char dty[100];
    printf("Please type the route which you want to save file.\n");
    scanf("%s",&dty);
    FILE* input = fopen(dty);

    char name[10];
    int sbj1,sbj2,sbj3;
    
    if(input==NULL)
    {
        printf("Failed to open the file.\n");
    }
    else
    {
        printf("Openning file is success.\n");
        for(int i = 0; i < 5; i++)
        {
            printf("Please type the name of the student.\n");
            scanf("%s",&name);
            printf("Please type the score. (subject1, subject2, subject3)\n");
            scanf("%d %d %d",&sbj1,&sbj2,&sbj3);
            fprintf(input,"%s %d %d %d\n",name,sbj1,sbj2,sbj3);
        }
        printf("Finished.");
    }
    fclose(input);
    return 0;

}