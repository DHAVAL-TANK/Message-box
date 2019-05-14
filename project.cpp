#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
// TODO : highlight text

/* declaration of function(start)*/
void signup (void);
int login (void);
void gotoxy(int ,int );
void msg(char []);
int modify(char []);
int rsuname(char [],char []);
int rspass(char []);
void frame1(char []);


/* declaration of global variables */
COORD coord={0,0};
using namespace std;
int counter=0;

/*body of functions(start)*/
void signup(void){

    char password[10],x,ch,space=32;
    char uname[30],tuname[30];

    int j,s,i=-1,f=0;

    FILE* fp;
    FILE* fp1;

    system("cls");
    frame1(" SIGN UP ");

    gotoxy(20,10);
    printf("ENTER USERNAME : ");
    scanf("%s",uname);

    //check whether username is already entered or not
    fp1=fopen("all_uname","r");

    if(fp1!=NULL)
    {
        while(!feof(fp1))
        {
            fscanf(fp1,"%s",&tuname);

            s=strcmp(tuname,uname);

            if(s==0)//if username is same
            {  strcat(uname,"1");
                gotoxy(20,12);
                printf("SORRY,WE HAVE ALREADY THAT USERNAME.");

                gotoxy(20,14);
                printf("YOUR NEW USERNAME IS \" %s \". ",uname);
                f=1;

            }

                   //if not then loop evaluate
        }


     fclose(fp1);
    }



    fp=fopen(uname,"w");// for storing spassword only

     if(f==1)
     {
         gotoxy(20,16);
     }
     else
     {
         gotoxy(20,11);
     }

     printf("ENTER PASSWORD : ");

      x=getch();
     while(x!=13)
    {
       printf("*");
       i++;
       password[i]=x;
       x=getch();

     }
    password[i+1]=NULL;
    fputs(password,fp);
    fclose(fp);

    fp1=fopen("all_uname","a");//for maintain all username to create conversasation file

    fputs(uname,fp1);
    putc('\n',fp1);
    fclose(fp1);

    system("cls");
    frame1(" HOME PAGE ");

    gotoxy(25,8);
    printf("YOU HAVE DONE SIGN_UP PROCEDURE SUCCESFULLY");

}


int login (void)
 { char uname[30],cpassword[30],opassword[30],tuname[30];

   FILE *fp,*fp1;

   int i=-1,x=0,k=0,m,l,f1=0,s,f=0;
start:
   system("cls");

   frame1("LOG IN PAGE");

     if (f1==1)
    {
     gotoxy(30,8);
     printf(" *** INVALID USERNAME *** " );
    }

     else if(f1==2)
     {
        gotoxy(30,8);
        printf(" *** INVALID PASSWORD *** " );
     }

     else if(f==3)
     {
         gotoxy(30,8);
         printf(" *** SELECT YOUR CHOICE PROPERLY *** ");
     }
     // ask for username
     gotoxy(20,10);
     printf("ENTER YOUR USERNAME : ");
     scanf("%s",&uname);

 /*
  fp1=fopen("all_uname","r");

       while(!feof(fp1))
        {
            fscanf(fp,"%s",&tuname);

            s=strcmp(tuname,uname);

            if(s!=0)  //if username is not in list
            {
                f1=1;

                fclose(fp1);
                goto start;
            }
            else{
                fclose(fp1);
            }
    }
    */

     // verify password

     fp=fopen(uname,"r");

     gotoxy(20,11);
     printf("ENTER YOUR PASSWORD : ");
     i=-1;

       x=getch();
         while(x!=13)
        {

          printf("*");
          i++;
          cpassword[i]=x;
          x=getch();
        }
      cpassword[i+1]=NULL;
      fscanf(fp,"%s",&opassword);
   /* fgets(opassword,'\n',fp);
     l=i-1;
     i=-1;

    while(i<=l)
    {
        x=getc(fp);
        i++;
        opassword[i]=x;

    }
*/
fclose(fp);

        if(strcmp(opassword,cpassword)==0)
        {    system("cls");
             frame1("TO DO MENU");

             gotoxy(25,8);
             printf(" YOU HAVE DONE 'LOG IN' PROCEDURE SUCCESFULLY ");

             while(x!=3)
             {

              gotoxy(40,10);
              printf("SEND MESSAGE   : PRESS 1");
              gotoxy(40,11);
              printf("MODIFY DETAILS : PRESS 2");
              gotoxy(40,12);
              printf("LOG OUT        : PRESS 3");
              gotoxy(40,14);
              printf("SELECT YOUR CHOICE : ");
              scanf("%d",&k);

                 switch(k)
                 {
                  case 1: msg(uname);  break;                                  // if user want to chat then call msg function
                  case 2: f=modify(uname);

                          if(f==0)
                          {
                            x=3;
                          }
                           break ;
                   case 3: x=3; break;                                     // if user want to modify details then call modify fucntion
                  default : f1=3;
                 }

             }

             system("cls");
             frame1(" HOME PAGE ");

             return 1;

        }

        else if(strcmp(opassword,cpassword)!=0)
        {
           f1=2;
           goto start;
        }

}


void msg(char uname[30]) //almost- change: compiler skips gets fn.
{
     char ch=1;
     char ouname[30],fname[60]={"NULL"},ms[100],tms[20],tuname[30],enter[2]={"\n"},line[30];
     int k,m,s,i,j,f=0,l=0;

   FILE* fp;
   FILE* fp1;

   /*  char* a;
     a=(char*)malloc(sizeof(char));
     char ms[a];
    */
    start1:
     system("cls");
     frame1("INBOX");
     k=0;



      // print all users
    fp=fopen("all_uname","r");

     gotoxy(40,6);
     printf("LIST OF USERS :");


        while(!feof(fp))
       {     gotoxy(35,7+k);
             printf("[%d]",++k);

           fscanf(fp,"%s",tuname);
           m=strcmp(tuname,uname);
              if(m==0)
               {
                printf("YOU,ALMIGHTY");
                char tuname[30]={NULL};
               }
             else if(m!=0)
               {
                   printf("%s",tuname);
               }

       }
       fclose(fp);
    // open username file
     if(f==1)
     {   gotoxy(20,k+9);
            printf("*PLEASE ,ENTER VALID USERNAME*");

     }


    gotoxy(20,k+10);
    printf("ENTER NAME OF USER WHOM YOU WANT SEND THE MESSAGE : ");
    scanf("%s",&ouname);


    // check username is valid or not
    fp1=fopen("all_uname","r");

        while(!feof(fp1))
        {    fscanf(fp1,"%s",&tuname);

            //fgets(tuname,'\n',fp1);

            s=strcmp(ouname,tuname);

            if(s==0)// if other username is found in the list
            {
            goto down;
            }
            else  //if other username is not in the list
            {
           f=1;
            }
        }
        goto start1;

        down:
              if(strcmp(ouname,uname)==0)//if user enters  his/her own name
                     {
                       gotoxy(20,k+12);
                       f=1;
                       fclose(fp1);
                       goto start1;
                     }
                    else if(strcmp(ouname,uname)<0)
                    {
                        strcat(fname,uname);
                        strcat(fname,ouname);
                        f=0;
                    }
                    else if(strcmp(ouname,uname)>0)
                    {
                        strcat(fname,ouname);
                        strcat(fname,uname);
                        f=0;
                    }





    fclose(fp1);
    fp=fopen(fname,"a");

    system("cls");
    frame1(" INBOX ");
    gotoxy(10,7);
    printf("DROP YOUR MSG HERE[ to %s ] :  ",ouname);

     i=0;
     ch=' ' ;
    while(ch!='\r')
    {
        ch=getch();
        ms[i]=ch;
        printf("%c",ch);
        i++;
    }
    ms[i]=NULL;
    //makind a line of length equals to username

    l=strlen(uname);
    for(i=0;i<l;i++)
    {
        line[i]='-';
    }
    line[i]=NULL;
   // append message into that file



      fprintf(fp,"%s %s %s %s","\n\n",line,"\n",uname);
      fprintf(fp,"%s %s","\n",line);
      fprintf(fp,"%s %s %s","\n","    ",ms);

    fclose(fp);

    // print all file content
    system("cls");
    gotoxy(40,5);
    printf(" ***  C O N V E R S A T I O N  *** ");
    gotoxy(6,7);
    printf(" [ %s ] -&- [ %s ] ",uname,ouname);

    i=8;
    j=10;

    gotoxy(i,j);
    fp=fopen(fname,"r");

       while(!feof(fp))
       {
         ch=getc(fp);

           if(ch=='\n')
          {
           gotoxy(i,j++);
          }
          else
          {
          printf("%c",ch);
          }
       }

    fclose(fp);
 gotoxy(i+13,j+2);
 printf(" ** PRESS ANY KEY TO GO TO MENU ** ");
 getch();

  system("cls");
  frame1("TO DO MENU");

}

 void delay(unsigned int msec)
{
    clock_t goal= msec+ clock();
    while(goal > clock());
}
void gotoxy(int x,int y)  //completed
{
    coord.X=x;
    coord.Y=y;
    HANDLE test = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(test,coord);
}

int modify(char uname[30])  //completed
{
    char nuname[30];
    int x,u=0,p=0,l=0;
    FILE *fp;

start2:
    system("cls");

    frame1(" MODIFY DETAILS ");

    if(u==1)
    {
        gotoxy(20,6);
        printf("OPPS,THERE IS SOMETHING WRONG. YOU HAVE TO SET USERNAME AGAIN");
    }
    else if(u==2)
    {
        gotoxy(30,6);
        printf("SELECT YOUR CHOICE PROPERLY.");
    }


    if(p==1)
    {
        gotoxy(20,7);
        printf("YOU HAVE TO SET YOUR PASSWORD AGAIN");

    }

    gotoxy(20,8);
    printf("RESET USERNAME : PRESS 1");
    gotoxy(20,9);
    printf("RESET PASSWORD : PRESS 2");
    gotoxy(20,10);
    printf("SELECT YOUR CHOICE: ");


    scanf("%d",&x);

    switch(x)
    {
        case 1 :

               gotoxy(20,14);
               printf("ENTER NEW USERNAME: ");
               scanf("%s",&nuname);

             u = rsuname(uname,nuname);

             if(u==1)
             { goto start2;}

             else if(u==0)
             {   system("cls");
                  frame1(" MODIFY DETAILS ");
                 gotoxy(30,6);
                 printf("  *** USERNAME HAS BEEN CHANGED ***");
                 gotoxy(35,8);
                 printf(" YOUR NEW USERNAME IS -> | %s |",nuname);
                 gotoxy(30,10);
                printf("  *** YOU HAVE TO LOGIN AGAIN *** ") ;
             }

                break;

        case 2 : p = rspass(uname);


                if(p==0)
                {


                  system("cls");
                  frame1(" MODIFY DETAILS ");
                  gotoxy(30,6);
                  printf("  ***PASSWORD CHANGED ***");
                  gotoxy(30,8);
                  printf("YOU HAVE TO LOGIN AGAIN.");
                  break;
                }

                else if(p==1)
                {
                goto start2;
                }



                break;

         default :   u=2;
                goto start2;

    }

    gotoxy(40,12);
    printf("  *** PRESS ANY KEY FOR HOMEPAGE ***");
    getch();

    system("cls");
    frame1(" HOME PAGE ");

   return 0;// if password or username is successfully changed then return 0.

}


int rspass(char uname[30])   //completed
{
    char npass[30],opass[30];
    FILE *fp;

    fp=fopen(uname,"w+");

    gotoxy(20,14);
    printf("ENTER NEW PASSWORD : ");
    scanf("%s",&npass);
    fscanf(fp,"%s",&opass);

       if(strcmp(npass,opass)==0)
       {
        gotoxy(20,6);
        printf("SOORY,THIS IS YOUR OLD PASSWORD.");
        fclose(fp);
        return 1;
       }

       else
       {
        fputs(npass,fp);
        fclose(fp);
        return 0;
       }

}

int rsuname(char uname[30],char nuname[30])   //completed
{
    char tuname[30];
    FILE* fp;
    int r=-1,l;

       if(rename(uname,nuname)!=0)
       {
        r=1;
       }

       else if(rename(uname,nuname)==0)
       {
          fp=fopen("all_uname","r+");

           while(!feof(fp))
           {
               fscanf(fp,"%s",tuname);

               if(strcmp(tuname,uname)==0)
               {  l=strlen(uname);
                  fseek(fp,-l,SEEK_CUR);
                  fputs(nuname,fp);
                  break;
               }
           }
           fclose(fp);
          r=0;
        }

       return r;

}

void frame1 (char name[15])      //change completatly
{
int i;
gotoxy(50,1);
 for(i=0;i<27;i++)
  {
      printf("-");
  }
 gotoxy(50,2);
 printf("| *** T E S E R E C T *** |");

 gotoxy(50,3);
  for(i=0;i<27;i++)
  {
      printf("-");
  }

 gotoxy(5,3);
  for(i=0;i<(strlen(name)+4);i++)
  {
      printf("-");
  }

 gotoxy(5,4);
 printf("| %s |",name);

 gotoxy(5,5);
  for(i=0;i<(strlen(name)+4);i++)
  {
      printf("-");
  }

 }



//body of function (end)

int main()
{
    long ls,x1=0,f=0;
    char x[2];
    star:

    /* if(f==1)
            {
                gotoxy(35,8);
                printf("  *** SELECT APROPIAT CHOICE ***");
                f=0;

            }
*/
  //  while(x!=3)
  //  {

        frame1("HOME PAGE");
        gotoxy(40,10);
        printf(" PRESS 1 :  SIGN UP ");
        gotoxy(40,11);
        printf(" PRESS 2 : LOG IN ");
        gotoxy(40,12);
        printf(" PRESS 3 : EXIT \n ");


        x[0]=_getch();
        x1=strtol(x,NULL,10);

        system("cls");
        switch(x1)
        {
            case 1: signup();goto star;
            case 2: login();goto star;
            case 3: exit(0);
            default:
                    gotoxy(35,8);
                   printf("  *** SELECT APROPIAT CHOICE ***");
                   goto star;
        }




    return 0;
}
