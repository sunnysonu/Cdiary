#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
void dairy(char *id);
void lfunction();
void signup();
void copycontents();
void getdate();
struct given
{
    int gday;
    int gmonth;
    int gyear;
}read;
struct present
{
    int pday;
    int pmonth;
    int pyear;
}get;
FILE *fp;
char login[1000],name[30],ch,current[20];
int setday,setmonth,setyear;
int main()
{
    int option;
    printf("\t\t\t\t1-->login\n\n\t\t\t\t2-->signup");
    scanf("%d",&option);
    if(option==1)
    {
        system("cls");
        lfunction();
    }
    else
    {
        system("cls");
        signup();
    }
    return 0;
}
void lfunction()
{
    int i=1,j,repeat=1;
    char id[20];
    copycontents();
    name[0]=',';
    while(repeat)
    {
        printf("\n\n\t\t\t\tEnter the name:");
        while((ch=getche())!='\r')
        {
            name[i++]=ch;
        }
        name[i++]='-';
        for(j=0;name[j]!='-';j++)
            id[j]=name[j+1];
        id[j-1]='\0';
        printf("\n\n\t\t\t\tEnter the password");
        while((ch=getch())!='\r')
        {
            name[i++]=ch;
            printf("*");
        }
        name[i]=',';
        name[i+1]='\0';
        if(strstr(login,name)!=NULL&&strcmp(strstr(login,strstr(login,name)),strstr(login,name))==0)
        {
            printf("\n\n\t\t\t\tYour account exist");
            printf("\n\n\t\t\t\tPRESS ENTER TO CONTINUE:");
            getch();
            printf("\n\n\t\t\t\tENTER THE DATE");
            scanf("%d%d%d",&read.gday,&read.gmonth,&read.gyear);
            system("cls");
            getdate();
            dairy(id);
            repeat=0;
        }else
        {
            printf("\n\n\t\t\t\tOops something went wrong in username or password");
            getch();
            system("cls");
        }
    }
}
void signup()
{
    int i,repeat=1,repeat1=1,j;
    char id[30],pass1[20],pass2[20],id1[20];
    while(repeat1)
    {
        printf("\n\n\t\t\t\tEnter the username\n\n\t\t\t\t");
        id[0]=',';
        i=1;
        while((ch=getche())!='\r')
        {
            id[i++]=ch;
        }
        id[i++]='-';
        id[i]='\0';
        for(j=0;id[j]!='-';j++)
            id1[j]=id[j+1];
        id1[j-1]='\0';
        i=0;
        copycontents();
        if(strstr(login,id)!=NULL&&strcmp(strstr(login,strstr(login,id)),strstr(login,id))==0)
        {
            printf("\n\n\t\t\t\tUser name already exist");
            getch();
            system("cls");
        }
        else
        {
            repeat1=0;
        }
    }
    while(repeat)
    {
        printf("\n\n\t\t\t\tplease enter the password");
        while((ch=getch())!='\r')
        {
            pass1[i++]=ch;
            printf("*");
        }
        pass1[i]=',';
        pass1[i+1]='\0';
        i=0;
        printf("\n\n\t\t\t\treenter the password");
        while((ch=getch())!='\r')
        {
            pass2[i++]=ch;
            printf("*");
        }
        pass2[i]=',';
        pass2[i+1]='\0';
        if(strcmp(pass1,pass2)==0)
        {
            repeat=0;
            strcat(id,pass1);
            printf("\n\n\t\t\t\tYOUR ACOUNT CREATED SUCCESSFULLY");
        }
    }
    fp=fopen("loginpage.txt","a");
    i=0;
    while(id[i]!='\0')
    {
        fputc(id[i],fp);
        i++;
    }
    fputc(',',fp);
    fclose(fp);
    printf("\n\n\t\t\t\tPRESS ENTER TO CONTINUE:");
    getch();
    printf("\n\n\t\t\t\tENTER THE DATE");
    scanf("%d%d%d",&read.gday,&read.gmonth,&read.gyear);
    getch();
    getdate();
    dairy(id1);
}
void copycontents()
{
    int i=0;
    fp=fopen("loginpage.txt","r");
    do
    {
        ch=fgetc(fp);
        login[i]=ch;
        i++;
    }while(ch!=EOF);
    login[i]='\0';
    fclose(fp);
}
void getdate()
{
    SYSTEMTIME start;
    GetSystemTime(&start);
    struct time
    {
        char day[20];
        char month[5];
        char year[10];
    }d1;
    int r,i=0;
    setday=read.gday;
    while(read.gday!=0)
    {
        r=read.gday%10;
        d1.day[i]=(char)(r+48);
        read.gday=read.gday/10;
        i++;
    }
    d1.day[i]='\0';
    strrev(d1.day);
    i=0;
    setmonth=read.gmonth;
    while(read.gmonth!=0)
    {
        r=read.gmonth%10;
        d1.month[i]=(char)(r+48);
        read.gmonth=read.gmonth/10;
        i++;
    }
    d1.month[i]='\0';
    strrev(d1.month);
    i=0;
    setyear=read.gyear;
    while(read.gyear!=0)
    {
        r=read.gyear%10;
        d1.year[i]=(char)(r+48);
        read.gyear=read.gyear/10;
        i++;
    }
    d1.year[i]='\0';
    strrev(d1.year);
    strcat(d1.day,strcat(d1.month,d1.year));
    strcpy(current,d1.day);
}
void dairy(char *id)
{
    char filename[30],temp[30];
    strcpy(temp,id);
    strcat(id,current);
    strcpy(filename,id);
    strcat(filename,".txt");
    int option,flag=1;
    FILE *text;
    SYSTEMTIME start;
    GetSystemTime(&start);
    get.pday=start.wDay;
    get.pmonth=start.wMonth;
    get.pyear=start.wYear;
    if((setday<=get.pday&&setmonth<=get.pmonth&&setyear<=get.pyear))
    {
       option=menu();
       if(option==1)
       {
           printf("\n\n\t\t\t\tEnter the text:\n\n\n\n");
           text=fopen(filename,"r");
           while((ch=fgetc(text))!=EOF)
            {
                printf("%c",ch);
            }
            fclose(text);
            printf("\n\n-----------------------------------------------------------------------\n\n");
           text=fopen(filename,"a");
           while((ch=getche())!='\r')
           {
               fputc(ch,fp);
           }
           fclose(text);
       }
       else
       {
           text=fopen(filename,"r");
            while((ch=fgetc(text))!=EOF)
            {
                printf("%c",ch);
                flag=0;
            }
            fclose(text);
            if(flag)
            {
                printf("\n\n\t\t\t\tThis page is Empty");
                printf("\n\n\t\t\t\t do you want to continue(y/n)");
                ch=getch();
                system("cls");
                if(ch=='y'||ch=='Y')
                {
                    printf("\n\n\t\t\t\tEnter the date:");
                    scanf("%d%d%d",&read.gday,&read.gmonth,&read.gyear);
                    dairy(temp);
                }
            }
        }
    }
    else
    {
            printf("Entered date contents are not present");
    }
}
int menu()
{
    int i;
    printf("\n\n\t\t\t\t1->To write text dairy");
    printf("\n\n\t\t\t\t2-?To read the text from the dairy");
    scanf("%d",&i);
    system("cls");
    return(i);
}


