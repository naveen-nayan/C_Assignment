#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<stdlib.h>

bool validate_phoneNo(char *phoneNo){
    if(strlen(phoneNo)!=11) return false;
    for(int i=0; i<10; i++){
        if(isdigit(phoneNo[i])) continue;
        else return false;
    }
    return true;
}

bool validate_noOfPeople(char *noOfPeople){
    // printf("%d", strlen(noOfPeople));
    if(strlen(noOfPeople)==1) {
        printf("\nblank Input not allowed");
        return false;
    }
    else
    {
        for(int i=0; i<strlen(noOfPeople)-1; i++)
        {
        if(isdigit(noOfPeople[i])) continue;
        else return false;
        }
    }
    int k;
    sscanf(noOfPeople,"%d",&k);
    if(k<1) {
        printf("\nMinimum No of Entry Must be 1");
        return false;
        }
    return true;
}

bool validate_empty(char *str){
    if(strlen(str)==1) {
        printf("\nblank Input not allowed ");
        return false;
    }
    else
    {
       return true;
    }
}

int main(){

    char *filename = "personal_info.csv";
    FILE *fp;

    printf("\nThis Program is used to create personal csv info file");
    printf("\nInput Paremeter:\n1. No of People:\n2. Name\n3. Phone Number\n4. Mail address\n5. Notes");

    fp=fopen(filename,"w+");
    fprintf(fp,"Id,Name,Phone number,Mail address,Notes\n");

    char no_of_people[10]={'\0'};
    label_no_of_people: printf("\nPlease Enter Number of People: ");
    fgets (no_of_people, 100, stdin);

    bool no_of_people_flag = validate_noOfPeople(no_of_people);
    if(no_of_people_flag)
    {

        int k;
        sscanf(no_of_people,"%d",&k);
        for(int j=1; j<= k; j++)
        {
            printf("\n%d Entry\n", j);
            label_enter_name:printf("Enter Name: ");
            char name[100]= "\0";
            fgets (name, 100, stdin);
            bool name_flag = validate_empty(name);
             if (!name_flag)
            {
                printf("Name Must not be Empty\n");
                goto label_enter_name;
            }
            name[strlen(name)-1]='\0';

            label_enter_phone:printf("Enter Phone Number: ");
            char phoneNo[100]  = "\0";
            fgets (phoneNo, 100, stdin);
            bool phoneNo_flag = validate_phoneNo(phoneNo);
            if (!phoneNo_flag)
            {
                printf("Phone Number Must be digit and 10 character\n");
                goto label_enter_phone;
            }
            phoneNo[strlen(phoneNo)-1]='\0';

            label_enter_email:printf("Enter Mail Address: ");
            char email[100]= "\0";
            fgets (email, 100, stdin);
            bool email_flag = validate_empty(email);
            if(!email_flag){
                printf("Email Must not be Empty\n");
                goto label_enter_email;
            }
            email[strlen(email)-1]='\0';

            printf("Enter Any Notes: ");
            char notes[100]= "\0";
            fgets (notes, 100, stdin);
            notes[strlen(notes)-1]='\0';

            fprintf(fp, "%d,%s,+91%s,%s,%s\n", j, name, phoneNo,  email, notes);
        }
        fclose(fp);
    }
    else
    {
        printf("\nInvalid Input");
        goto label_no_of_people;
    }

    return 0;

}