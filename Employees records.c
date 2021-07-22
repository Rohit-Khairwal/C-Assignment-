#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct std{
	char name[50];
	int age;
	char department[50];
	int n;
	int salary;
	int DOB;
};
struct std e;


long int size = sizeof(e);




FILE *fp, *ft;


void addrecord()
{
	printf("\n\n");
	fseek(fp, 0, SEEK_END);
	char another = 'y';

	while (another == 'y')
    {
		printf("\nEnter Name : ");
		scanf("%s", &e.name);
        fflush(stdin);
		printf("\nEnter age : ");
		scanf("%d", &e.age);
		fflush(stdin);
		printf("\nName of department : ");
		scanf("%s",&e.department);
		fflush(stdin);
        printf("\nEnter DOB : ");
		scanf("%d", &e.DOB);
		fflush(stdin);
		printf("\nEnter Salary : ");
		scanf("%d", &e.salary);
		fwrite(&e, size, 1, fp);
		printf("\nWant to add another"
			" record (y/n) : ");
		fflush(stdin);

		scanf("%c", &another);

		}




	}



void deleterecord()
{
	printf("\n\n");
	char stname[50];
	char another = 'y';

	while (another == 'y') {
		printf("\nEnter Name "
			"name to delete : ");
		scanf("%s", stname);

		ft = fopen("temp.txt", "wb");
		rewind(fp);

		while (fread(&e, size,
					1, fp)
			== 1) {
			if (strcmp(e.name,
					stname)
				!= 0)
				fwrite(&e, size, 1, ft);
		}

		fclose(fp);
		fclose(ft);
		remove("data.txt");
		rename("temp.txt", "data.txt");
		fp = fopen("data.txt", "rb+");

		printf("\nWant to delete another"
			" record (y/n) :");
		fflush(stdin);
		another = getche();
	}
	printf("\n\n");
}


void displayrecord()
{
    printf("\n\n");


    rewind(fp);



    while (fread(&e, size, 1, fp) == 1){
       printf("\n\nNAME: ");
		printf("%s" ,e.name);
		printf("\n Age: ");
		printf("%d" ,e.age);
		printf("\n Department : ");
		printf("%s" ,e.department);
        printf("\n DOB: ");
		printf("%d" ,e.DOB);
		printf("\n Salary: ");
		printf("%d" ,e.salary);

		}

    }
void update()
{
    system("cls");
    char name[50];
    char another = 'y';

    while (another == 'y') {
        printf("\nEnter employee name"
               " to modify : ");
        scanf("%s", name);

        rewind(fp);

        // While File is open
        while (fread(&e, size, 1, fp) == 1) {
            // Compare the employee name
            // with ename
            if (strcmp(e.name, name) == 0) {
                printf("\nEnter new name:");
                scanf("%s", e.name);
                printf("\nEnter new age :");
                scanf("%d", &e.age);
                printf("\nEnter new department :");
                scanf("%s", &e.department);
                printf("\nEnter new salary :");
                scanf("%d", &e.salary);
                printf("\nEnter new DOB :");
                scanf("%d", &e.DOB);

                fseek(fp, -size, SEEK_CUR);
                fwrite(&e, size, 1, fp);
                break;
            }
        }

        // Ask for modifying another record
        printf("\nWant to modify another"
               " record (Y/N) :");
        fflush(stdin);
        scanf("%c", &another);
    }
}

int main()
{
	int choice;


	fp = fopen("data.txt", "rb+");


	if (fp == NULL) {
		fp = fopen("data.txt", "wb+");
		if (fp == NULL) {
			printf("\nCannot open file...");
			exit(1);
		}
	}




	while (1) {



		printf("\n1. ADD RECORD\n");

		printf("\n2. DELETE RECORD\n");

		printf("\n3. DISPLAY RECORDS\n");

		printf("\n4. UPDATE RECORDS\n");



		printf("\n5. EXIT\n");

		printf("\nENTER YOUR CHOICE\n");
		fflush(stdin);
		scanf("%d", &choice);


		switch (choice) {
		case 1:


			addrecord();
			break;

		case 2:


			deleterecord();
			break;

		case 3:


			displayrecord();
			break;


        case 4:


			update();
			break;
       case 5:
			fclose(fp);
			exit(0);
			break;

		default:
			printf("\nINVALID CHOICE \n");
		}
	}

	return 0;
}

