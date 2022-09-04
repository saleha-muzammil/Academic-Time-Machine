#include <stdio.h>

void addRecord(FILE* fp){
    
    char name[40];
    char rollNum[10];
    char email[50];

    printf("Enter Name: ");
    scanf("%39s", name);
    printf("Enter Roll Number: ");
    scanf("%9s", rollNum);
    printf("Enter Email: ");
    scanf("%49s", email);

    fputs("<New Entry>\n", fp);
    fputs(name, fp);
    fputs(rollNum, fp);
    fputs(email, fp);

}
void readRecord(FILE* fp){

}
void deleteRecord(FILE* fp){

}

int main(){
    FILE *fp;
    fp=fopen("StudentRecord.txt", "r");
    
    char mode = 'x';
    while (1){
        printf("Press A to add student to record\nPress R to read student records\nPress D to to delete student record\nPress S to stop program");
        scanf("%c", &mode);
        if (mode == 'A'){
            addRecord(fp);
        }
        else if (mode == 'R'){
            readRecord(fp);
        }
        else if (mode == 'D'){
            deleteRecord(fp);
        }
        else if (mode == 'S'){
            break;
        }
        else {
            printf("Invalid input. Try Again\n");
        }    
    }
    fclose(fp);
    return 0;
}