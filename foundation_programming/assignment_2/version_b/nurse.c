/***********************************************************************
 * nurse.c
 * A program to enter patient details to be saved and read later
 * Simon Sorensen
 * 21/11/19
 * Version b
 * ********************************************************************/

/* Structures */
struct nurse {
    char name[50];
    char id[9];
    char password[9];
};

struct patient {
    char first_name[50];
    char last_name[50];
    char birthday[12];
    int height;
    int waist;
    int weight;
    char comment[2000];
};

/* Main functions */
void loadAuth(char *dest);
int validateCredentials(char *id, char *password, struct nurse nurses[]);
void savePatient(struct patient);

/* Encryption */
void encrypt(char *input);
void decrypt(char *output);

/* Data input */
char *input(char *validation);
char *getBirthday(void);
int getNumber(int min, int max);

int main(void)
{
    char tmp[255];
    printf("Username: ");
    scanf("%s", &tmp);
    getchar();
    printf("\nPassword: ");
    scanf("%s", &tmp);
    getchar();
    puts("\n\nWelcome!\n");

    printf("\nFirst name: ");
    scanf("%s", &tmp);
    getchar();
    printf("\nLast name: ");
    scanf("%s", &tmp);
    getchar();
    printf("\nBirthday: ");
    scanf("%s", &tmp);
    getchar();
    printf("\nHeight: ");
    scanf("%s", &tmp);
    getchar();
    printf("\nWaist: ");
    scanf("%s", &tmp);
    getchar();
    printf("\nHeight: ");
    scanf("%s", &tmp);
    getchar();

    puts("\n\nPatient file saved!");

    return 0;
}