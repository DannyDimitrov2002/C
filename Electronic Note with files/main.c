#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define maxbrp 30

typedef struct
{
    char nickname[80];
    char password[80];
    char conpass[80];
}tuser;
typedef struct
{
    int num;
    char name[80];
    int marks[maxbrp];
    float avr;
}tstudent;
char filename[80]={"newuser"};
char admin[80]={"b.basheva"};
char pass[80]={"tues2021"};
char choise[80]={"9"};
int main()
{
    int alog=0,z=0,i=0,a;
    while(1)
    {
    int ok=0,okpass=0,t;
    char us[80];
    char uspass[80];
    do
    {
        system("cls");
        if(i==0) printf(">SIGN UP");
            else printf(" SIGN UP");
        if(i==1) printf("\n>LOG IN");
            else printf("\n LOG IN");
        if(i==2) printf("\n>ADMIN LOG IN");
            else printf("\n ADMIN LOG IN");
        if(i==3) printf("\n>EXIT");
            else printf("\n EXIT");
        a=getch();
       if(a==224 || a==0) a=getch();
       if(a==80) i = i + 1;
       if(a==72) i = i - 1;
       if(i==4 ) i=0;
       if(i==-1) i=3;
    }while(a!=13);
    system("cls");
    if(i==0) mysign(filename);
    if(i==1)
    {
        mylog(filename);
        break;
    }
    if(i==2 && ok<3)
    {
        printf("ADMIN NICKNAME: ");
        gets(us);
        while(strcmp(us,admin)!=0)
        {
            if(ok==3)
            {
                printf("TOO MANY WRONG TRYES\nPRESS ANY KEY TO RETURN");
                getch();
                break;
            }
            t=3-ok;
            printf("WRONG ADMIN NICK\n%d MORE TRYES: ", t);
            gets(us);
            if(strcmp(us,admin)==0)break;
                else ok++;
        }
        if(ok!=3)
        {
            printf("ADMIN PASSWORD: ");
            gets(uspass);
            if(strcmp(uspass,pass)==0)alog=1;
        }
        while(strcmp(uspass,pass)!=0)
        {
            if(ok==3)break;
            if(okpass==3)
            {
                printf("TOO MANY WRONG TRYES\nPRESS ANY KEY TO RETURN");
                getch();
                break;
            }
            t=3-okpass;
            printf("WRONG ADMIN PASSWORD\n%d MORE TRYES: ", t);
            gets(uspass);
            if(strcmp(uspass,pass)==0)
            {
                alog=1;
                break;
            }else okpass++;
        }




    }
    if(i==3) break;
    if(alog) break;
    }
    if(alog)
    {
        i=0;
    while(1)
    {
        do
    {
        system("cls");
        if(i==0) printf(">9A");
            else printf(" 9A");
        if(i==1) printf("\n>9B");
            else printf("\n 9B");
        if(i==2) printf("\n>9V");
            else printf("\n 9V");
        if(i==3) printf("\n>9G");
            else printf("\n 9G");
        if(i==4) printf("\n>EXIT");
            else printf("\n EXIT");
        a=getch();
       if(a==224 || a==0) a=getch();
       if(a==80) i = i + 1;
       if(a==72) i = i - 1;
       if(i==5 ) i=0;
       if(i==-1) i=4;
    }while(a!=13);
    system("cls");
    if(i==0)
    {
        choise[1]='a';
        myedit(choise);
        getch();
        break;
    }
    if(i==1)
    {
        choise[1]='b';
        myedit(choise);
        getch();
        break;

    }
    if(i==2)
    {
        choise[1]='v';
        myedit(choise);
        getch();
        break;
    }
    if(i==3)
    {
        choise[1]='g';
        myedit(choise);
        getch();
        break;
    }
    if(i==4)break;
    }
    }else
    {


        i=0;
        while(1)
    {
        do
    {
        system("cls");
        if(i==0) printf(">9A");
            else printf(" 9A");
        if(i==1) printf("\n>9B");
            else printf("\n 9B");
        if(i==2) printf("\n>9V");
            else printf("\n 9V");
        if(i==3) printf("\n>9G");
            else printf("\n 9G");
        if(i==4) printf("\n>EXIT");
            else printf("\n EXIT");
        a=getch();
       if(a==224 || a==0) a=getch();
       if(a==80) i = i + 1;
       if(a==72) i = i - 1;
       if(i==5 ) i=0;
       if(i==-1) i=4;
    }while(a!=13);
    system("cls");
    if(i==0)
    {
        choise[1]='a';
        myread();
        getch();

    }
    if(i==1)
    {
        choise[1]='b';
        myread();
        getch();

    }
    if(i==2)
    {
        choise[1]='v';
        myread();
        getch();

    }
    if(i==3)
    {
        choise[1]='g';
        myread();
        getch();

    }
    if(i==4)break;
    }
    }
    return 0;
}
void mysign(char *filename)
{
    FILE *f;
    int i=0;
    tuser s;
    if(f=fopen(filename,"rb+"))
    {
        while(!feof(f))
        {
            if(fread(&s,sizeof(s),1,f))
            {

            }
        }
            printf("NICKNAME: ");
            gets(s.nickname);
            printf("PASSWORD: ");
            gets(s.password);
            printf("CONFURM PASSWORD: ");
            gets(s.conpass);
            while(strcmp(s.conpass,s.password)!=0)
            {
                printf("PASSWORDS DOES NOT MATCH\nTRY AGAIN: ");
                gets(s.conpass);
            }
            fwrite(&s,sizeof(s),1,f);
            i=0;
        fclose(f);
    }
    else printf("ne");
}
void mylog(char *filename)
{
    FILE *f;
    tuser s;
    char logger[80];
    char passer[80];
    int ok=0;
    printf("NICKNAME: ");
    gets(logger);

    if(f=fopen(filename,"rb"))
    {
        while(!feof(f))
        {
            if(fread(&s,sizeof(s),1,f))
            {
                if(strcmp(logger,s.nickname)==0)
                {
                    printf("PASSWORD: ");
                    gets(passer);
                    while(strcmp(passer,s.password)!=0)
                    {
                        printf("WORNG PASSWORD\nTRY AGAIN ");
                        gets(passer);
                        if(strcmp(passer,s.password)!=0);
                    }
                }
            }

        }
    }
    fclose(f);
}
void myread()
{
    FILE *f;
    int i=0,z=0;
    tstudent s;
    if(f=fopen(choise,"rb"))
    {
        while(!feof(f))
        {
            if(fread(&s,sizeof(s),1,f))
            {
            if(z==0)
            {
                printf("%2d %-41s",s.num,s.name);
                z=1;
            }
            else printf("\n%2d %-41s",s.num,s.name);
            while(s.marks[i]!=0)
            {
                printf("%3d",s.marks[i]);
                i++;
            }
                    i=0;
            printf("%6.2f",s.avr);
            }
        }
        fclose(f);
    }
    else printf("Faila Ne moja da se otvori ");
}
void myedit(char *choise)
{
    FILE *f;
    tstudent s;
    int nomer,i=1,k=0,j,z=0, change;
    unsigned char a;
    if(f=fopen(choise,"r+b"))
    {
        printf("WHICH STUDENT NUMBER WILL YOU CHANGE ? ");
        scanf("%d", &nomer);
        do
        {
            system("cls");
            if(i==1) printf(">CHANGE NAME");
            else printf(" CHANGE NAME");
            if(i==2) printf("\n>CHANGE MARKS");
            else printf("\n CHANGE MARKS");
             a=getch();
            if(a==224 || a==0) a=getch();
            if(a==80) i = i + 1;
            if(a==72) i = i - 1;
            if(i==3 ) i=0;
            if(i==-1) i=1;
        }while(a!=13);
        system("cls");
        switch(i)
        {
            case 1: change=1; break;
            case 2: change=2; break;
        }
        while (fread(&s, sizeof(s), 1,f)!=NULL)
        {
            if(s.num==nomer)
            {
                fseek(f, -sizeof(s), SEEK_CUR);
                switch(change)
                {
                case 1:printf("WRITE A NEW NAME OF THE STUDENT ");
                        getchar();
                    gets(s.name);break;
                case 2:
                        s.avr=0;
                    while(1)
                    {
                        printf("WRITE MARK &d OF THE STUDENT (pri 0 izlizame) ");
                        scanf("%d", &s.marks[z]);
                        if(s.marks[z]==0)break;
                        else
                        {
                            while (s.marks[z]<2 || s.marks[z]>6)
                            {
                                printf("WRONG MARK!!! TRY AGAIN ");
                                scanf("%d",&s.marks[z]);
                            }
                            s.avr=s.avr+s.marks[z];
                        }
                        z++;
                        printf("\n");
                    }
                    s.avr=s.avr/z;
                    break;
                }
                }
                fwrite(&s, sizeof(s),1,f);
                break;
            }
        }else("WRONG FILE NAME");
        getch();
        fclose(f);
    }
