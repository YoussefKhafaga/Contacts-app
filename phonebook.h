FILE *f1;
int count,edited=0,added=0,deleted=0;
typedef struct
{
    int day;
    int month;
    int year;
} date;
typedef struct
{
    char lname[100];
    char fname[100];
    date dob;
    char address[100];
    char  email[100];
    char num[100];
} contact;
contact arr[100];
void load()
{
    FILE *f1;
    f1=fopen("phonebook.txt","r");
    while(!feof(f1))
    {
        fscanf(f1,"%[^,],",arr[count].lname);
        fscanf(f1,"%[^,],",arr[count].fname);
        fscanf(f1,"%d-%d-%d,",&arr[count].dob.day,&arr[count].dob.month,&arr[count].dob.year);
        fscanf(f1,"%[^,],",arr[count].address);
        fscanf(f1,"%[^,],",arr[count].email);
        fscanf(f1,"%s\n",arr[count].num);
        count++;
    }
    fclose(f1);
    phonebook();
}
void save()
{
    system("cls");

    int j;
    int i=0;
    f1=fopen("phonebook.txt","w");
    for(j=0; j<count; j++)
    {
        fprintf(f1,"%s,",arr[j].lname);
        fprintf(f1,"%s,",arr[j].fname);
        fprintf(f1,"%d-%d-%d,",arr[j].dob.day,arr[j].dob.month,arr[j].dob.year);
        fputs(arr[j].address,f1);
        fprintf(f1,",");
        fputs(arr[j].email,f1);
        fprintf(f1,",");
        fputs(arr[j].num,f1);
    fprintf(f1,"\n");
    }
    fclose(f1);
    edited=0;
    added=0;
    deleted=0;
}
void query ()
{
    system("cls");
    int x;
    int i=0;
    printf("\t\t\t\t\tselect type of search \n");
    printf("\t\t1. by last name\t");
    printf("2. by first name\t");
    printf("3. by date of birth\t\n");
    printf("\t\t4. by address\t");
    printf("5. by email\t\t");
    printf("6. by number\t\n");
    scanf("%d",&x);
    switch (x)
    {
    case 1:
    {
        searchbylname();
        break;
    }
    case 2:
    {
        searchbyfirst();
        break;
    }
    case 3:
    {
        searchbydate();
        break;
    }
    case 4:
    {
        searchbyaddress();
        break;
    }
    case 5:
    {
        searchbymail();
        break;
    }
    case 6:
    {
        searchbynum();
        break;
    }
    default:
    {
        printf("YOU ENTERED A WRONG NUMBER\n");
        query();
    }

    }
}
void searchbylname ()
{
    int i,z=1;
    char name[100];
    printf("enter last name : ");
    scanf("%s",name);

    for(i=0; i<count; i++)
    {
        if (stricmp(arr[i].lname,name)==0)
        {
            printf("\n\t\t contact #%d",i+1);
            printf("\nFirst name: %s",arr[i].fname);
            printf("\nBirth date: %d-%d-%d",arr[i].dob.day,arr[i].dob.month,arr[i].dob.year);
            printf("\nAddress: %s",arr[i].address);
            printf("\nEmail: %s",arr[i].email);
            printf("\nPhone number: %s\n",arr[i].num);
            z++;
        }
    }
    if(z==1)
        printf("you entered an invalid last name\n");

}
void searchbyfirst ()
{
    int i=0,z=1;
    char name[100];
    printf("enter first name to search it : ");
    scanf("%s",name);

    for(i=0; i<count; i++)
    {
        if (stricmp(arr[i].fname,name)==0)
        {
            printf("\n\t\t contact #%d",i+1);
            printf("\nLast name: %s",arr[i].lname);
            printf("\nBirth date: %d-%d-%d",arr[i].dob.day,arr[i].dob.month,arr[i].dob.year);
            printf("\nAddress: %s",arr[i].address);
            printf("\nEmail: %s",arr[i].email);
            printf("\nPhone number: %s\n",arr[i].num);
            z++;
        }
    }
    if(z==1)
        printf("you entered an invalid first name");
}
void searchbydate ()
{


    int i=0,z=1,day,month,year;
    printf("\nenter day of birth: ");
    scanf("%d",&day);
    printf("\nenter month of birth: ");
    scanf("%d",&month);
    printf("\nenter year of birth: ");
    scanf("%d",&year);
    for(i=0; i<count; i++)
    {
        if (day==arr[i].dob.day && month==arr[i].dob.month && year==arr[i].dob.year)
        {
            printf("\n\t\t contact #%d",i+1);
            printf("\nLast name: %s",arr[i].lname);
            printf("\nFirst name: %s",arr[i].fname);
            printf("\nAddress: %s",arr[i].address);
            printf("\nEmail: %s",arr[i].email);
            printf("\nPhone number: %s",arr[i].num);
            z++;
        }
    }
    if(z==1)
        printf("you entered an invalid date of birth");



}
void searchbyaddress()
{
    int i=0,z=1;
    char addrss[100];
    printf("enter address to search it : ");
    getchar();
    gets(addrss);
    for(i=0; i<count; i++)
    {
        if (stricmp(arr[i].address,addrss)==0)
        {
            printf("\n\t\t contact #%d",i+1);
            printf("\nLast name: %s",arr[i].lname);
            printf("\nFirst name: %s",arr[i].fname);
            printf("\nBirth date: %d-%d-%d",arr[i].dob.day,arr[i].dob.month,arr[i].dob.year);
            printf("\nEmail: %s",arr[i].email);
            printf("\nPhone number: %s\n",arr[i].num);
            z++;
        }
    }
    if(z==1)
        printf("you entered an invalid address");
}
void searchbymail ()
{
    int i=0,z=1;
    char mail[100];
    printf("enter email to search it : ");
    getchar();
    gets(mail);
    for(i=0; i<count; i++)
    {
        if (stricmp(arr[i].email,mail)==0)
        {
            printf("\n\t\t contact #%d",i+1);
            printf("\nLast name: %s",arr[i].lname);
            printf("\nFirst name: %s",arr[i].fname);
            printf("\nBirth date: %d-%d-%d",arr[i].dob.day,arr[i].dob.month,arr[i].dob.year);
            printf("\nAddress: %s",arr[i].address);
            printf("\nPhone number: %s\n",arr[i].num);
            z++;
        }
    }
    if(z==1)
        printf("you entered an invalid email");
}
void searchbynum()
{
    int i=0,z=1;
    char number[100];
    printf("enter number to search it : ");
    getchar();
    gets(number);
    for(i=0; i<count; i++)
    {
        if (strcmp(arr[i].num,number)==0)
        {
            printf("\n\t\t contact #%d",i+1);
            printf("\nLast name %s",arr[i].lname);
            printf("\nFirst name: %s",arr[i].fname);
            printf("\nBirth date: %d-%d-%d",arr[i].dob.day,arr[i].dob.month,arr[i].dob.year);
            printf("\nAddress: %s",arr[i].address);
            printf("\nEmail: %s",arr[i].email);
            z++;
        }
    }
    if(z==1)
        printf("you entered an invalid phone number");
}
void modify()
{
   // system("cls");
    int i,z=1,m;
    int x;
    char a2[100];
    int num;
    int r;
    char name[100];
    printf("enter last name : ");
    scanf("%s",name);

    for(i=0; i<count; i++)
    {
        if (stricmp(arr[i].lname,name)==0)
        {
            printf("\n\t\t contact #%d",i+1);
            printf("\nFirst name: %s",arr[i].fname);
            printf("\nBirth date: %d-%d-%d",arr[i].dob.day,arr[i].dob.month,arr[i].dob.year);
            printf("\nAddress: %s",arr[i].address);
            printf("\nEmail: %s",arr[i].email);
            printf("\nPhone number: %s\n",arr[i].num);
            z++;
        }
    }
  if (z==1) { printf("you entered an invalid last name\nTRY AGAIN\n");
        modify();}
        else if (z!=1)
        {
            printf("\nEnter number of wanted contact to be modified: ");
    scanf("%d",&m);
    m--;

    printf("1-if you want to modify one field \n2-if you want to modify all the data of contact \n:");
    scanf("%d",&r);
    if (r==1)
    {
        printf("\t\t\t\t\tselect what to be modified\n");
        printf("\t\t1.last name\t\t");
        printf("2.first name\t\t");
        printf("3.day\t\n");
        printf("\t\t4.month\t\t\t");
        printf("5.year\t\t\t");
        printf("6.address\t\t\n");
        printf("\t\t\t7.email\t\t\t\t");
        printf("8.number\t\t\n");
        scanf("%d",&x);
        switch (x)
        {
        case 1:
        {
            printf("\nenter new last name: ");
            scanf("%s",a2);
            strcpy(arr[m].lname,a2);
            break;
        }
        case 2:
        {
            printf("\nenter new first name: ");
            scanf("%s",a2);
            strcpy(arr[m].fname,a2);
            break;
        }
        case 3:
        {
            printf("\nenter new day of birth: ");
            scanf("%d",&num);
            arr[m].dob.day=num;
            break;
        }
        case 4:
        {
            printf("\nenter new month of birth: ");
            scanf("%d",&num);
            arr[m].dob.month=num;
            break;
        }
        case 5:
        {
            printf("\nenter new year of birth: ");
            scanf("%d",&num);
            fgets(a2,100,stdin);
            arr[m].dob.year=num;
            break;
        }
        case 6:
        {
            printf("\nenter new address: ");
            getchar();
            fgets(a2,100,stdin);
            a2[strlen(a2)-1]=',';
            strcpy(arr[m].address,a2);
            break;
        }
        case 7:
        {
            printf("\nenter new e-mail: ");
            getchar();
            fgets(a2,100,stdin);
            a2[strlen(a2)-1]=',';
            strcpy(arr[m].email,a2);
            break;
        }
        case 8:
        {
            printf("\nenter new phone number:");
            getchar();
            fgets(a2,100,stdin);
            strcpy(arr[m].num,a2);
            break;
        }
        }
    }
    edited+=1;
    if (r==2)
    {
        printf("\nenter new last name: ");
        scanf("%s",a2);
        strcpy(arr[m].lname,a2);
        printf("\nenter new first name: ");
        scanf("%s",a2);
        strcpy(arr[m].fname,a2);
        printf("\nenter new day of birth: ");
        scanf("%d",&num);
        arr[m].dob.day=num;
        printf("\nenter new month of birth: ");
        scanf("%d",&num);
        arr[m].dob.month=num;
        printf("\nenter new year of birth: ");
        scanf("%d",&num);
        fgets(a2,100,stdin);
        arr[m].dob.year=num;
        printf("\nenter new address: ");
        fgets(a2,100,stdin);
        a2[strlen(a2)-1]=',';
        strcpy(arr[m].address,a2);
        printf("\nenter new e-mail: ");
        fgets(a2,100,stdin);
        a2[strlen(a2)-1]=',';
        strcpy(arr[m].email,a2);
        printf("\nenter new phone number:");
        fgets(a2,100,stdin);
        strcpy(arr[m].num,a2);
        edited=1;
    }


    }}
void Delete()
{
    system("cls");
    int num;
    char arr2[100];
    char lastname[100];
    char firstname[100];
    int i,x,z=count;
    printf("Enter the last name of contact to be deleted\n");
    scanf("%s",lastname);
    printf("Enter the first name of contact to be deleted\n");
    scanf("%s",firstname);
    for (i=0; i<count; i++)
    {
        if ((stricmp(arr[i].lname,lastname)==0)&&(stricmp(arr[i].fname,firstname)==0))
        {
            for (x=i; x<count; x++)
            {
                strcpy(arr[x].lname,arr[x+1].lname);
                strcpy(arr[x].fname,arr[x+1].fname);
                arr[x].dob.day=arr[x+1].dob.day;
                arr[x].dob.month=arr[x+1].dob.month;
                arr[x].dob.year=arr[x+1].dob.year;
                strcpy(arr[x].address,arr[x+1].address);
                strcpy(arr[x].email,arr[x+1].email);
                strcpy(arr[x].num,arr[x+1].num);
            }
            count--;
            printf("deleted\n");
            deleted+=1;
            break;
        }

    }
    if(count==z)
        printf("contact not found");

}
void add()
{
    system("cls");
    contact a[100];
    char a2[100];
    int num;
    int i=count;
    printf("enter last name: ");
    scanf("%s",a2);
    strcpy(arr[i].lname,a2);
    printf("\nenter first name: ");
    scanf("%s",a2);
    strcpy(arr[i].fname,a2);
    printf("\nenter day of birth: ");
    scanf("%d",&num);
    arr[i].dob.day=num;
    printf("\nenter month of birth: ");
    scanf("%d",&num);
    arr[i].dob.month=num;
    printf("\nenter year of birth: ");
    scanf("%d",&num);
    fgets(a2,100,stdin);
    arr[i].dob.year=num;
    printf("\nenter address: ");
    fgets(a2,100,stdin);
    a2[strlen(a2)-1]='\0';
    strcpy(arr[i].address,a2);
    printf("\nenter e-mail: ");
    fgets(a2,100,stdin);
    a2[strlen(a2)-1]='\0';
    strcpy(arr[i].email,a2);
    printf("\nenter phone number:");
    fgets(a2,100,stdin);
    strcpy(arr[i].num,a2);
    added+=1;
    count++;
}
void sortbyDOB()
{
    system("cls");

    contact arr2[1];
    int i,j;
    char a[100];
    for(i=0; i<count; i++)
    {
        for(j=i+1; j<count; j++)
        {
            if(arr[j].dob.year>arr[i].dob.year)
            {
                arr2[0]=arr[j];
                arr[j]=arr[i];
                arr[i]=arr2[0];
            }
            if (arr[j].dob.year==arr[i].dob.year)
            {
                if (arr[j].dob.month>arr[i].dob.month)
                {
                    arr2[0]=arr[j];
                    arr[j]=arr[i];
                    arr[i]=arr2[0];
                }
                if (arr[i].dob.month==arr[j].dob.month)
                {
                    if (arr[j].dob.day>arr[i].dob.day)
                    {
                        arr2[0]=arr[j];
                        arr[j]=arr[i];
                        arr[i]=arr2[0];
                    }
                }
            }
        }
    }
}
void print()
{
    system("cls");
    int i=0;
    int k;
    printf("1-PRINT SORTED BY LAST NAME\n2-PRINT SORTED BY DATE OF BIRTH\n");
    scanf("%d",&k);
    if(k==1)
    {
        sortlname();
        for(i=0; i<count; i++)
        {
            printf("\n\t\t contact #%d",i+1);
            printf("\nLAST NAME: %s ",arr[i].lname);
            printf("\nFIRST NAME: %s ",arr[i].fname);
            printf("\nDATE OF BIRTH: %d-%d-%d ",arr[i].dob.day,arr[i].dob.month,arr[i].dob.year);
            printf("\nADDRESS: %s ",arr[i].address);
            printf("\nEMAIL: %s ",arr[i].email);
            printf("\nPHONE NUMBER: %s",arr[i].num);
        }
    }

    else if(k==2)
    {
        sortbyDOB();
        for(i=0; i<count; i++)
        {
            printf("\n\t\t contact #%d",i+1);
            printf("\nLAST NAME: %s ",arr[i].lname);
            printf("\nFIRST NAME: %s ",arr[i].fname);
            printf("\nDATE OF BIRTH: %d-%d-%d ",arr[i].dob.day,arr[i].dob.month,arr[i].dob.year);
            printf("\nADDRESS: %s ",arr[i].address);
            printf("\nEMAIL: %s ",arr[i].email);
            printf("\nPHONE NUMBER: %s",arr[i].num);
        }
    }
    else
    {
        printf("YOU ENTERED A WRONG NUMBER \n");
        print();
    }
}
void sortlname()
{
    system("cls");

    contact arr2[1];
    int i,j;
    char a[100];
    for(i=0; i<count; i++)
    {
        for(j=i+1; j<count; j++)
        {
            if(strcmp(arr[i].lname,arr[j].lname)>0)
            {
                arr2[0]=arr[j];
                arr[j]=arr[i];
                arr[i]=arr2[0];
            }
        }
    }
}
void check()
{
    system("cls");
    int z;
    if(edited!=0||added!=0||deleted!=0)
    {
        printf("            **warning: exiting without saving**\n" );
        printf("press 1 to save before exiting             press any button to exit without saving\n:");
        scanf("%d",&z);
        if(z==1)
            save();
        else
            exit(0);
    }
}
void phonebook()
{
     int x,y;
    printf("\n\t\t\t\t\t\t*PHONE BOOK*\n ");
    printf("\t\t\t1.QUERY\t\t\t2.ADD\t\t\t3.DELETE\n\t\t\t4.EDIT\t\t\t5.PRINT ALL\t\t6.SAVE\n\t\t\t7.EXIT\n");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        query();
        phonebook();
        break;
    case 2:
        add();
        phonebook();
        break;
    case 3:

        Delete();
        phonebook();
        break;
    case 4:
        modify();
        phonebook();
        break;
    case 5:
        print();
        phonebook();
        break;
    case 6:
        save();
        printf("EVERYTHING SAVED");
        phonebook();
        break;
    case 7:
        check();
        break;
    default:
        printf("YOU ENTERED A WRONG NUMBER");
        phonebook();

    }

}

