/***********************************************************************
 * consultant.c
 * A program to read and update patient details
 * Simon Sorensen
 * 21/11/19
 * Version a
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

/* Display functions */

/* Data input */
char *input(char *validation);
char *getBirthday(void);
int getNumber(int min, int max);

int main(void)
{
    /* Prompt for login */
    /* Authenticate and greet consultant */
    /* Show menu options */
    /* OPTION 1 */
    /* Show list of patients */
    /*  */

    return 0;
}