#include <stdio.h>
#include <stdlib.h>
#define maxbrp 30

typedef struct
{
    int num;
    char name[80];
    int marks[maxbrp];
    float avr;
}tstudent;
char filename[80];
int main()
{
    printf("Ime na File: ");
    gets(filename);
    while(1)
    {
    int i=0,a, ok;
    do
    {
        system("cls");
        if(i==0) printf(">Write");
            else printf(" Write");
        if(i==1) printf("\n>Read");
            else printf("\n Read");
        if(i==2) printf("\n>Add");
            else printf("\n Add");
        if(i==3) printf("\n>Change file");
            else printf("\n Change file");
        if(i==4) printf("\n>Edit");
            else printf("\n Edit");
        if(i==5) printf("\n>Exit");
            else printf("\n Exit");
        a=getch();
       if(a==224 || a==0) a=getch();
       if(a==80) i = i + 1;
       if(a==72) i = i - 1;
       if(i==6 ) i=0;
       if(i==-1) i=4;
    }while(a!=13);
    system("cls");
    if(i==0) mywrite(filename);
    if(i==1)
    {
        myread(filename);
        printf("\nPress any key to return ");
        ok=getch();
    }
    if(i==2) myadd(filename);
    if(i==3) mychange(filename);
    if(i==4)
    {
        myedit(filename);
        printf("\nPress any key to return ");
        ok=getch();
    }
    if(i==5) break;
    }
    return 0;
}
void mywrite(char *filename)
{
    FILE *f;
    int i=0,y=1,d=0,m;
    tstudent s;
    if(f=fopen(filename,"rb")){
        do{
        printf("Sustestvuva fail. Da prezapisha li? ");
        if(d==0) printf("\n>Da" );
            else printf("\n Da ");
        if(d==1) printf("\n>Ne ");
            else printf("\n Ne");
        m=getch();
       if(m==224 || m==0) m=getch();
       if(m==80) d = d + 1;
       if(m==72) d = d - 1;
       if(d==2 ) d=0;
       if(d==-1) d=1;
        system("cls");
    }while(m!=13);
    fclose(f);
    }
    if(d==0){
        if(f=fopen(filename,"wb"))
        {
            while(1)
            {
                s.avr=0;
                printf("Nomer na Uchenik %d(Ako e 0 izlizame) ",y);
                scanf("%d",&s.num);
                if(s.num==0)
                    break;
                getchar();
                printf("Ime na uchenik: ");
                gets(s.name);
                while(1)
                {
                    do{
                    printf("ocenka %d: ",i+1);
                    scanf("%d",&s.marks[i]);
                    if(s.marks[i]==0) break;
                    }while (s.marks[i]<2 || s.marks[i]>6);
                    if(s.marks[i]==0) break;
                    s.avr=s.avr + s.marks[i];
                    i++;
                }
                s.avr=s.avr/i;
                fwrite(&s,sizeof(s),1,f);
                y++;
                i=0;
            }
            fclose(f);
        }else printf("Faila Ne moja da se otvorui");
    }
}
void myread(char *filename)
{
    FILE *f;
    int i=0,z=0;
    tstudent s;
    if(f=fopen(filename,"rb"))
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
void myadd(char *filename)
{
    FILE *f;
    int i=0;
    tstudent s;
    if(f=fopen(filename,"rb+"))
    {
        while(!feof(f))
        {
            if(fread(&s,sizeof(s),1,f))
            {
            while(s.marks[i]!=0)
            {
                i++;
            }
                    i=0;
            }
        }
     while(1)
        {
            s.avr=0;
            printf("Nomer na Uchenik dobaveniq uchenic (Ako e 0 izlizame) ");
            scanf("%d",&s.num);
            if(s.num==0)
                break;
            getchar();
            printf("ime na uchenik: ");
            gets(s.name);
            while(1)
            {
                do{
                printf("ocenka %d: ",i+1);
                scanf("%d",&s.marks[i]);
                if(s.marks[i]==0) break;
                }while (s.marks[i]<2 || s.marks[i]>6);
                if(s.marks[i]==0) break;
                s.avr=s.avr + s.marks[i];
                i++;
            }
            s.avr=s.avr/i;
            fwrite(&s,sizeof(s),1,f);
            i=0;
        }
        fclose(f);
    }
    else printf("ne");
}
void mychange(char *filename)
{
    printf("What will be the new file name? ");
    gets(filename);
}
void myedit(char *filename)
{
    FILE *f;
    FILE *c;
    tstudent s;
    int nomer,i=0,a,k=0,j;
    if(f=fopen(filename,"rb"))
    {
        if(c=fopen("pomosht","wb"))
        {
        printf("WHICH STUDENT NUMBER WILL YOU CHANGE ? ");
        scanf("%d", &nomer);
        do
        {
            system("cls");
            if(i==0) printf(">CHANGE NAME");
            else printf(" CHANGE NAME");
            if(i==1) printf("\n>CHANGE MARKS");
            else printf("\n CHANGE MARKS");
             a=getch();
            if(a==224 || a==0) a=getch();
            if(a==80) i = i + 1;
            if(a==72) i = i - 1;
            if(i==2 ) i=0;
            if(i==-1) i=1;
        }while(a!=13);
        system("cls");
        while(!feof(f))
        {
        if(fread(&s,sizeof(s),1,f))
        {
            if(s.num==nomer)
            {
                if(i==0)
                {
                    printf("WRITE THE NEW NAME ");
                    gets(s.name);
                    break;
                }
                if(i==1)
                {
                    printf("WRITE THE NEW MARKS (pri 0 izlizame) ");
                    while(1)
                {
                    do{
                    printf("ocenka %d: ",k+1);
                    scanf("%d",&s.marks[k]);
                    if(s.marks[k]==0) break;
                    }while (s.marks[k]<2 || s.marks[k]>6);
                    if(s.marks[k]==0) break;
                    s.avr=s.avr + s.marks[k];
                    k++;
                }
                s.avr=s.avr/k;

                }
            }
        }
        fwrite(&c,sizeof(s),1,c);
        }
        }
    }else("WRONG FILE NAME");
        fclose(f);

    }
