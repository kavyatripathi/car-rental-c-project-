#include <stdio.h>
//#include <stdlib.h>
#include<string.h>
struct car
{
    char nmcust[50];
    char custid[13];
    char crented[20];
    int n,rent,days;
    int dr,mr,yr,dret,mret,yret;
};
char cbrand[10][20]={"HYUNDAI","MARUTI_SUZUKI","HONDA","TOYOTA","FORD","TATA","MERCEDES","AUDI","MAHINDRA"};
char model[10][20]={"Accent","Swift","City","Innova","Figo","Indica","C_Class","SQ7","XUV"};
int seat[10]={4,4,4,8,4,4,4,8,8,0};
int rentpd[10]={70,65,80,100,60,60,200,250,150,0};
int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int z=0,u=0;
struct car c,ca[10],cr[10],cn={0};
void car_rent()
{
    int i,f;
    int t,days1=0,days2=0,days3=0;
    char ch;
    int j,x;
    printf("Welcome dear customer!!! \n");
    display();
    printf("ENTER THE BRAND OF CAR YOU WANT TO RENT: ");
    scanf("%s",c.crented);
    printf("ENTER DATE ON WHICH YOU WILL TAKE THE CAR(dd mm yyyy): ");
    scanf("%d%d%d",&c.dr,&c.mr,&c.yr);
    printf("ENTER THE DATE ON WHICH YOU WILL RETURN THE CAR(dd mm yyyy): ");
    scanf("%d%d%d",&c.dret,&c.mret,&c.yret);
    printf("LETS CHECK WHETHER THE CAR IS AVAILABLE OR NOT\n");
    //FILE *ptr;
    //ptr=fopen("Car_rent.txt","r");
    //fread(ca,sizeof(ca),1,ptr);
       for(i=0;i<10;i++)
       {
        if(strcmp(ca[i].crented,c.crented)==0)
        {
            for(t=0;t<=ca[i].mr;t++)
                days1+=mon[t];
            for(t=0;t<=ca[i].mret;t++)
                days2+=mon[t];
            for(t=0;t<=c.mr;t++)
                days3+=mon[t];
            days1+=ca[i].dr;
            days2+=ca[i].dret;
            days3+=c.dr;
            if((days3-days1)*(days2-days3)>=0)
                f=1;
            else
            f=0;
               if(f==1)
               {
                 printf("Car not available.Are you interested in trying another car?\nIf yes enter Y else enter N\n");
                 getchar();
                 scanf("%c",&ch);
                 //fclose(ptr);
                 if(ch=='y'||ch=='Y')
                    car_rent();
                 else
                 {
                     printf("THANKS FOR COMING!!PLEASE VISIT AGAIN \n\n\n");
                     //fclose(ptr);
                     break;
                 }
               }
        }
        else if(strcmp(ca[i].crented,c.crented)!=0 ||f==0)
        {
            printf("CAR AVAILABLE!! \n");
            FILE *fp;
            fp=fopen("Car_rent","a");
            strcpy(ca[u].crented,c.crented);
            ca[u].dr=c.dr;
            ca[u].mr=c.mr;
            ca[u].yr=c.yr;
            ca[u].dret=c.dret;
            ca[u].mret=c.mret;
            ca[u].yret=c.yret;
            //u++;
            fwrite(&ca,sizeof(ca),1,fp);
            fclose(fp);
            printf("ENTER YOUR NAME: ");
            scanf("%s",c.nmcust);
            printf("ENTER YOUR AADHAR NUMBER: ");
            scanf("%s",c.custid);
            c.n=date(c.yr,c.yret,c.mr,c.mret,c.dr,c.dret);
            for(j=0;j<10;j++)
            {
                x=strcmp(c.crented,cbrand[j]);
                if(x==0)
                    break;
            }
            c.rent=c.n*rentpd[j];
            printf("WARNING: If any damage is done to the car then you are entirely responsible. The car has to be returned in its initial condition.\n");
            printf("Details:\n");
            printf("NAME:\t%s\nID:\t%s\nCAR RENTED:\t%s\nNUMBER OF DAYS:\t%d\nRENT:\t%d\n",c.nmcust,c.custid,c.crented,c.n,c.rent);
            //fclose(ptr);
            strcpy(cr[z].nmcust,c.nmcust);
            strcpy(cr[z].custid,c.custid);
            strcpy(cr[z].crented,c.crented);
            cr[z].n=c.n;
            cr[z].rent=c.rent;
            //z++;
            FILE *fptr;
            fptr=fopen("Car_rent.txt","a+");
            fwrite(&cr,sizeof(cr),1,fptr);
            fclose(fptr);
            break;
        }
    }
}
int date(int y1,int y2,int m1,int m2,int d1,int d2)
{
    int i,days1=0,days2=0,days3=0 ;
        for(i=0;i<=m1;i++)
            days1+=mon[i];
        for(i=0;i<=m2;i++)
            days2+=mon[i];
        days1+=d1;
        days2+=d2;
        return(days2-days1);
}
void car_return()
{
    //FILE *fptr,*nptr;
    char id[13];
    int dd,mm,yy,d,m,y,flag=0,i,j;
    printf("Welcome back dear customer \n");
    printf("Please enter your id\n");
    scanf("%s",id);
    //fptr=fopen("Car_rent","r");
    //fread(cr,sizeof(struct car),1,fptr);
    for(i=0;i<10;i++)
    {
        if(strcmp(cr[i].custid,id)==0)
        {
            flag=1;
            printf("HELLO %s\n",cr[i].nmcust);
            printf("For confirmation please enter the date on which you took the car and the date on which you are returning the date in(dd mm yyyy)format.\n");
            scanf("%d%d%d",&dd,&mm,&yy);
            scanf("%d%d%d",&d,&m,&y);
            cr[i].days=date(yy,y,mm,m,dd,d);
            if(cr[i].days>cr[i].n)
            {
                    cr[i].rent+=50*(cr[i].days-cr[i].n);
            }
            printf("FINAL AMOUNT:%d \n",cr[i].rent);
            printf("\n\n");
            break;
        }
    }
    if(flag==0)
           {
             printf("Customer not found\n");
            //fclose(fptr);
           }
        else
        {
            //nptr=fopen("Car_rent","w+");
            //fread(cr,sizeof(cr),1,nptr);
            for(j=0;j<10;j++)
            {
                if(j==i)
                    memset(&cr[j].crented[0],0,sizeof(cr[j].crented[0]));
            }
            //fclose(fptr);
            //remove("Car_rent");
            //rename("Car_temp","Car_rent");
           // fclose(nptr);
        }
}
void display()
{
    printf("------------------------------------------------ \n");
    printf("|    CAR BRAND   |  MODEL  | RENT PER DAY(Rs.) | \n");
    printf("------------------------------------------------ \n");
    printf("|     HYUNDAI    |  ACCENT |      70           | \n");
    printf("|  MARUTI_SUZUKI |  SWIFT  |      65           | \n");
    printf("|      HONDA     |  CITY   |      80           | \n");
    printf("|     TOYOTA     |  INNOVA |      100          | \n");
    printf("|      FORD      |  FIGO   |      60           | \n");
    printf("|      TATA      |  INDICA |      60           | \n");
    printf("|    MERCEDES    |  C_CLASS|      200          | \n");
    printf("|      AUDI      |  SQ7    |      250          | \n");
    printf("|    MAHINDRA    |  XUV    |      150          | \n");
    printf("------------------------------------------------ \n");
}
int main()
{
    int q,p=0,g,h;
    for(g=1;g<=365;g++)
    {
        for(h=1;h<=10;h++)
        {
            printf("\nIS THERE A NEW CUSTOMER NOW??\nENTER 1 FOR YES AND 0 FOR NO\n");
            scanf("%d",&p);
            if(p==1)
            {
                label:
                printf("\aHI!! ARE YOU HERE TO TAKE THE CAR SERVICE OR RETURN BACK THE CAR? \n 1.WANT TO RENT A CAR.\n 2.WANT TO RETURN THE CAR.\n");
                scanf("%d",&q);
                switch(q)
                {
                    case 1:{car_rent();u++;z++;
                    break;}
                    case 2:car_return();
                    break;
                    default:{printf("Wrong choice!! Try again.\n");
                    goto label;}
                }
            }
        }
        printf("\n\n\nBYE!!Today's work is over\a\n\n\n");
    }
}
