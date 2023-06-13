#include <stdio.h>
#include <string.h>

#define OK       0
#define NO_INPUT 1
#define TOO_LONG 2

static int getLine (char *prmpt, char *buff, size_t sz) {
    int ch, extra;

    // Get line with buffer overrun protection.
    if (prmpt != NULL) {
        printf ("%s", prmpt);
        fflush (stdout);
    }
    if (fgets (buff, sz, stdin) == NULL)
        return NO_INPUT;

    // If it was too long, there'll be no newline. In that case, we flush
    // to end of line so that excess doesn't affect the next call.
    if (buff[strlen(buff)-1] != '\n') {
        extra = 0;
        while (((ch = getchar()) != '\n') && (ch != EOF))
            extra = 1;
        return (extra == 1) ? TOO_LONG : OK;
    }

    // Otherwise remove newline and give string back to caller.
    buff[strlen(buff)-1] = '\0';
    return OK;
}

void addRecord(const char* filename){

    char name[64]="";
    char rollNum[32]="";
    char email[64]="";

    int rc;
    while ((getchar()) != '\n');

    rc = getLine("Enter Name: ", name, sizeof(name));
    if (rc == NO_INPUT) {
    // Extra NL since my system doesn't output that on EOF.
        printf ("\nNo input\n");
        return;
    }
    if (rc == TOO_LONG) {
        printf ("Input too long [%s]\n", name);
        return;
    }
    rc = getLine("Enter Roll Number: ", rollNum, sizeof(rollNum));
    if (rc == NO_INPUT) {
    // Extra NL since my system doesn't output that on EOF.
        printf ("\nNo input\n");
        return;
    }

    if (rc == TOO_LONG) {
        printf ("Input too long [%s]\n", rollNum);
        return;
    }

    rc = getLine ("Enter Email: ", email, sizeof(email));
    if (rc == NO_INPUT) {
    // Extra NL since my system doesn't output that on EOF.
        printf ("\nNo input\n");
        return;
    }

    if (rc == TOO_LONG) {
        printf ("Input too long [%s]\n", email);
        return;
    }

    FILE *fp=fopen(filename, "a");
    fputs("<New Entry>\n", fp);
    fputs(name, fp);
    fputc('\n', fp);
    fputs(rollNum, fp);
    fputc('\n', fp);
    fputs(email, fp);
    fputc('\n', fp);
    fclose(fp);

}
void readRecord(const char* filename){
    int num=0;
    int count=0;
    char curStr[64];

    printf("Input number of record to read.\n");

    scanf("%d", &num);

    FILE *fp= fopen(filename, "r");
    while (fgets(curStr, 63, fp)!=NULL){
        if (strcmp(curStr,"<New Entry>\n")==0){
            count++;
        }
        if (count==num + 1){
            fgets(curStr, 63, fp);
            printf("Name: %s", curStr);
            fgets(curStr, 63, fp);
            printf("Roll Number: %s", curStr);
            fgets(curStr, 63, fp);
            printf("Email: %s", curStr);
            printf("%c", '\n');

            break;
        }
    }
    fclose(fp);

}
void deleteRecord(const char* filename){
    char curStr[64];
    char temp[]="temp.txt";
    int num=0;
    int count=0;

    printf("Input number of record to delete.\n");
    scanf("%d", &num);

    FILE *fp1, *fp2;
    fp1=fopen(filename, "r");
    fp2 = fopen(temp, "w"); 

    while (fgets(curStr, 63, fp1)!=NULL){
        if (strcmp(curStr,"<New Entry>\n")==0){
            count++;
        }
        if (count==num + 1){
            fgets(curStr, 63, fp1);
            fgets(curStr, 63, fp1);
            fgets(curStr, 63, fp1);
        }
        else {
            fprintf(fp2, "%s", curStr);
        }
    }

    fclose(fp1);
    fclose(fp2);
    remove(filename);  		// remove the original file 
    rename(temp, filename); 	// rename the temporary file to original name

}

int main(){
    const char* filename="StudentRecord.txt";
    
    char mode;
    while (1){
        printf("Press A to add student to record\nPress R to read student records\nPress D to to delete student record\nPress S to stop program\n");
        scanf(" %c", &mode);

        if (mode == 'A'){
            addRecord(filename);
        }
        else if (mode == 'R'){
            readRecord(filename);
        }
        else if (mode == 'D'){
            deleteRecord(filename);
        }
        else if (mode == 'S'){
            break;
        }
        else {
            printf("Invalid input. Try Again\n");
        }    
    }
    return 0;
}