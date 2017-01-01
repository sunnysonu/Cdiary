#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int main_menu();
int Diary_options();
void dairy(char *id);
void login();
void signup();
void copycontents();
void date_converter();
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
char username[1000],name[30],ch,current[20];
int setday,setmonth,setyear;
int main()
{
    int option;
    option=main_menu();
    if(option==1)
    {
        system("cls");
        login();
    }
    else
    {
        system("cls");
        signup();
    }
    return 0;
}
/* This function takes the user name and password checks whether the account is already exist or not, if exist then user can able to go for further
or else Displays Your account does not exist"*/
void login()
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
        if(strstr(username,name)!=NULL&&strcmp(strstr(username,strstr(username,name)),strstr(username,name))==0)
        {
            printf("\n\n\t\t\t\tYour account exist");
            printf("\n\n\t\t\t\tPRESS ENTER TO CONTINUE:");
            getch();
            system("cls");
            printf("\n\n\t\t\t\tENTER THE DATE");
            scanf("%d%d%d",&read.gday,&read.gmonth,&read.gyear);
            system("cls");
            date_converter();
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
/* This functions helps in creating the new account for the user if the account does not signed up */
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
        if(strstr(username,id)!=NULL&&strcmp(strstr(username,strstr(username,id)),strstr(username,id))==0)
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
    system("cls");
    printf("\n\n\t\t\t\tENTER THE DATE");
    scanf("%d%d%d",&read.gday,&read.gmonth,&read.gyear);
    date_converter();
    dairy(id1);
}
/*This function copy the all the user names and the passwords of all signed in users into an string to compare already existing user names and passwords*/
void copycontents()
{
    int i=0;
    fp=fopen("loginpage.txt","r");
    do
    {
        ch=fgetc(fp);
        username[i]=ch;
        i++;
    }while(ch!=EOF);
    username[i]='\0';
    fclose(fp);
}
/*This function get the integer type date given by user and converts it into char type*/
void date_converter()
{
    struct time
    {
        char day[20];
        char month[5];
        char year[10];
    }time_in_char;
    int r,i=0;
    setday=read.gday;
    while(read.gday!=0)
    {
        r=read.gday%10;
        time_in_char.day[i]=(char)(r+48);
        read.gday=read.gday/10;
        i++;
    }
    time_in_char.day[i]='\0';
    strrev(time_in_char.day);
    i=0;
    setmonth=read.gmonth;
    while(read.gmonth!=0)
    {
        r=read.gmonth%10;
        time_in_char.month[i]=(char)(r+48);
        read.gmonth=read.gmonth/10;
        i++;
    }
    time_in_char.month[i]='\0';
    strrev(time_in_char.month);
    i=0;
    setyear=read.gyear;
    while(read.gyear!=0)
    {
        r=read.gyear%10;
        time_in_char.year[i]=(char)(r+48);
        read.gyear=read.gyear/10;
        i++;
    }
    time_in_char.year[i]='\0';
    strrev(time_in_char.year);
    strcat(time_in_char.day,strcat(time_in_char.month,time_in_char.year));
    strcpy(current,time_in_char.day);
}
/*This function creates a new file or open the existing file according to the given date and user name given by the user and perform the read and write
operations*/
void dairy(char *id)
{
    char filename[30],temp[30];
    strcpy(temp,id);
    strcat(id,current);
    strcpy(filename,id);
    strcat(filename,".txt");
    int option,flag=1;
    FILE *textFile;
    SYSTEMTIME start;
    GetSystemTime(&start);
    get.pday=start.wDay;
    get.pmonth=start.wMonth;
    get.pyear=start.wYear;
    if((setday<=get.pday&&setmonth<=get.pmonth&&setyear<=get.pyear)||(setmonth<get.pmonth&&setyear<get.pyear)||(setyear<get.pyear))
    {
       option=Diary_options();
       if(option==1)
       {
           printf("\n\n\t\t\t\tEnter the text:\n\n\n\n");
           textFile=fopen(filename,"r");
           while((ch=fgetc(textFile))!=EOF)
            {
                printf("%c",ch);
            }
            fclose(textFile);
            printf("\n\n-----------------------------------------------------------------------\n\n");
           textFile=fopen(filename,"a");
           while((ch=getche())!='\r')
           {
               fputc(ch,fp);
           }
           fclose(textFile);
       }
       else
       {
           textFile=fopen(filename,"r");
            while((ch=fgetc(textFile))!=EOF)
            {
                printf("%c",ch);
                flag=0;
            }
            fclose(textFile);
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
/*This function Displays the operations that can be performed for reading and writing the the text into the diary, reads the option
and returns it*/
int Diary_options()
{
    int i;
    printf("\n\n\t\t\t\t1->To write text dairy");
    printf("\n\n\t\t\t\t2-?To read the text from the dairy");
    scanf("%d",&i);
    system("cls");
    return(i);
}
/*This function Displays the login or signup option,reads the integer which indicates the certain option provided in the function
and returns it*/
int main_menu()
{
    int option;
    printf("\t\t\t\t1-->login\n\n\t\t\t\t2-->signup");
    scanf("%d",&option);
    return(option);
}

