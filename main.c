#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct detail
{
    char name[30];
    char email[30];
    char address[50];
    char gender;
    int room, age;
    char phone[15];
} x[200];

struct staff
{
    char name[25];
    char qual[25];
    char post[25];
    char ID[25];
} member[7];

int n, i, j = 0, a = 0 ,g;
int flag,num, guest = 0;
int read();
int write();
void add();
void list();
void edit();
void deletee();
void staff();
void expense();

int read()
{
    FILE *fp = fopen("details.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("details.txt", "w");
        fclose(fp);
        printf("\tNo file found!! Creating new...\n\n");
        return 0;
    }

    num = fread(x, sizeof(struct detail), 100, fp);
    fclose(fp);
}
int write()
{
    FILE *fp = fopen("details.txt", "w");
    if (fp == NULL)
    {
        printf("\t**error**");
        exit(1);
    }
    fwrite(x, sizeof(struct detail), num, fp);

    fclose(fp);
}


int main()
{
    read();
    int c;
    char pw[30];
    char us[30];
    system("cls");
    printf("--------------------------------------------------\n");
    printf("             Hotel Management System              \n");
    printf("--------------------------------------------------\n");
    printf("\n\n");
    printf("\n\n\t done by group19 , SECTION-C");

    printf("\n\t enter username: ");
    gets(us);
    int res1 = strcmp(us, "project");
    while(res1 != 0)
    {
        system("cls");
        printf("\n\t incorrect username..");
        printf("\n\t try again..");
        gets(us);
        res1 = strcmp(us, "project");
    }

        printf("\n\n\tEnter Password: ");
        gets(pw);
        int res=strcmp(pw,"group19");
        while(res != 0)
        {
        system("cls");
        printf("\n\tWrong Password, Try again : ");
        gets(pw);
        res=strcmp(pw,"group19");
        }

    system("cls");
    printf("\n\n----------- main menu --------");
    while (c != 8)
    {

        printf("\n\n\t1. reserve room: ");
        printf("\n\t2. Customer profiles:");
        printf("\n\t3. Edit: ");
        printf("\n\t4. Delete: ");
        printf("\n\t5. Staff Information: ");
        printf("\n\t6. Expense: ");
        printf("\n\t7. Save & Exit: ");
        printf("\n\t");

        scanf("%d", &c);
        fflush(stdin);
        if (c == 1)
        {
            system("cls");
            add();
        }
        else if (c == 2)
        {
            system("cls");
            list();
        }
        else if (c == 3)
        {
            system("cls");
            edit();
        }
        else if (c == 4)
        {
            system("cls");
            deletee();
        }
        else if (c == 5)
        {
            system("cls");
            staff();
        }
        else if (c == 6)
        {
            system("cls");
            expense();
        }
        else if (c == 7)
        {
            write();
            return 0;
        }
        else
        {
            system("cls");
            printf("\n\n\tInvalid input , try again!!");
        }
        printf("\n\n");
    }
}
void add()
{
    printf("\n\n\tHow many rooms do you want to reserve : ");
    scanf("%d", &n);
    guest = n + num;

    for (i = num, j = 0; i < guest; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("\tEnter Room No. : ");
        scanf("%d", &x[i].room);
        fflush(stdin);
        printf("\tEnter Name : ");
        gets(x[i].name);
        fflush(stdin);
        printf("\tEnter email : ");
        gets(x[i].email);
        fflush(stdin);
        printf("\tEnter the gender (M/F/N) : ");
        scanf("%c", &x[i].gender);
        fflush(stdin);
        printf("\tEnter Address : ");
        gets(x[i].address);
        fflush(stdin);
        printf("\tEnter phone number : ");
        gets(x[i].phone);
        fflush(stdin);
        printf("\n\t successfully reserved your room!!");
        printf("\n");
        j++;
        a++;
        num++;
    }
}

void list()
{
    for (i=0;i<num;i++)
    {
        printf("\n\t S.NO : %d", i);
        printf("\t Room no : %d", x[i].room);
        printf("\t Name : ");
        puts(x[i].name);
        printf("\t email : ");
        puts(x[i].email);
        printf("\t Address : ");
        puts(x[i].address);
        printf("\t Phone number : %s", x[i].phone);
        printf("\t Gender : %c", x[i].gender);
        printf("\n\n\n");
    }
}


void edit()
{
    int p;
    int z;
    fflush(stdin);
    printf("\n\t edit: ");
    printf("\n\t1. Name");
    printf("\n\t2. Address");
    printf("\n\t3. email");
    printf("\n\t4. Room No. ");
    printf("\n\t5. Phone no.");
    scanf("%d", &z);
    if (z <= 5)
    {
        printf("\tEnter the serial no of that guest");
        scanf("%d", &p); //serial number
        if (z<num)
        {
            if (z==1)
            {
                fflush(stdin);
                printf("\tEnter the new Name : ");
                gets(x[p].name);
            }
            else if (z==2)
            {
                fflush(stdin);
                printf("\tEnter the new Address : ");
                gets(x[p].address);
            }
            else if (z==3)
            {
                fflush(stdin);
                printf("\tEnter the new email : ");
                gets(x[p].email);
            }

            else if (z==4)
            {
                fflush(stdin);
                printf("\tEnter the new Room no : ");
                scanf("%d", &x[p].room);
            }

            else if (z==5)
            {
                fflush(stdin);
                printf("\tEnter the new Phone no : ");
                gets(x[p].phone);
            }
            else
            {
                printf("\n\n\tInvalid Option \nTry Again !!\n\n");
            }
        }
        else
        {
            printf("\n\n\tThe record you are searching doesn't exist!!\n\n");
        }
    }
}

void deletee()
{
    int f, h=0;
    printf("\n\t enter the guest record u want to deletee: ");
    scanf("%d", &f);
    if (f < num)
    {
        printf("\n\t chose the option u want to delete..");
        printf("\n\t1. guest record");
        printf("\n\t2. Name");
        printf("\n\t3. email");
        printf("\n\t4. Room No.");
        printf("\n\t5. phone number");
        printf("\n\t6. Gender");
        printf("\n\t7. Address");
        printf("\n\t");

        scanf("%d", &g);
        if (h == 1)
        {
            while (f < num)
            {
                strcpy(x[f].name, x[f + 1].name);
                strcpy(x[f].email, x[f + 1].email);
                strcpy(x[f].address, x[f + 1].address);
                x[f].gender = x[f + 1].gender;
                x[f].room = x[f + 1].room;
                strcpy(x[f].phone, x[f + 1].phone);
                f++;
            }
            num--;
        }
        else if (h == 2)
        {
            strcpy(x[f].name, "Removed");
        }
        else if (h == 3)
        {
            strcpy(x[f].email, "Removed");
        }
        else if (h == 4)
        {
            x[f].room = 0;
        }
        else if (h == 5)
        {
            strcpy(x[f].phone, "removed");
        }
        else if (h == 6)
        {
            x[f].gender = 'O';
        }
        else if (h == 7)
        {
            strcpy(x[f].address, "Removed");
        }
    }
    else
        printf("\n\n\tThe record you are searching doesn't exist!!\n");
}


void staff()
{

    strcpy(member[0].name, "Deepak .M");
    strcpy(member[0].qual, "BBA");
    strcpy(member[0].post, "manegar");
    strcpy(member[0].ID, "22187");

    strcpy(member[1].name, "Kalyani .K");
    strcpy(member[1].qual, "12th pass");
    strcpy(member[1].post, "Clerk");
    strcpy(member[1].ID, "22188");

    strcpy(member[2].name, "Yeswanth .p");
    strcpy(member[2].qual, "Hotel management course");
    strcpy(member[2].post, "Kitchen manager");
    strcpy(member[2].ID, "22189");

    strcpy(member[3].name, "Ramya .H");
    strcpy(member[3].qual, "Hotel management course");
    strcpy(member[3].post, "House keeping manager");
    strcpy(member[3].ID, "22226");

    strcpy(member[4].name, "Ramesh .A");
    strcpy(member[4].qual, "BBa");
    strcpy(member[4].post, "Front desk supervisor");
    strcpy(member[4].ID, "22886");

    strcpy(member[5].name, "Mahesh .G");
    strcpy(member[5].qual, "12th pass");
    strcpy(member[5].post, "Supervisor of Guest service");
    strcpy(member[5].ID, "22689");

    strcpy(member[6].name, "Kalyan .B");
    strcpy(member[6].qual, "12th pass");
    strcpy(member[6].post, "Waiter");
    strcpy(member[6].ID, "226567");

    for (int i=0;i<7;i++)
    {
        printf("\tworker Name    : %s\n", member[i].name);
        printf("\tQualification  : %s\n", member[i].qual);
        printf("\tworking as     : %s\n", member[i].post);
        printf("\tID number      : %s\n", member[i].ID);
        printf("\n\n");
    }
}


void expense()
{
    int days;
    float rr, food, tr, total, tax, amount;
    printf("\tEnter the number of days : ");
    scanf("%d", &days);
    printf("\tEnter the rent of room per day : ");
    scanf("%f", &rr);
    printf("\tEnter the total cost of food : ");
    scanf("%f", &food);
    tr = days * rr;
    total = tr + food;
    tax = 0.15 * total;
    amount = total + tax;
    printf("\tTotal Rent                  = %.5f\n", tr);
    printf("\tTotal Cost of all expenses  = %.5f\n", total);
    printf("\tTax on total                = %.5f\n", tax);
    printf("\tFinal Total incl. tax       = %.5f\n", amount);
    printf("\n\n");
}
