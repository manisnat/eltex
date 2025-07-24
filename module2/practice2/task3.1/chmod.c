#include "chmod.h"

int valid_letters(const char* letters)
{
    int flag = 0;
    if (strlen(letters) != 9) flag = 1;

    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0 && letters[i] != 'r' && letters[i] != '-') flag = 1;
        if (i % 3 == 1 && letters[i] != 'w' && letters[i] != '-') flag = 1;
        if (i % 3 == 2 && letters[i] != 'x' && letters[i] != '-') flag = 1;
    }
    return flag;
}

int letters_in_octal(char* letters)
{
    int octal = 0;
    if (!valid_letters(letters)) 
    {
        if (letters[0] == 'r') octal |= S_IRUSR;
        if (letters[1] == 'w') octal |= S_IWUSR;
        if (letters[2] == 'x') octal |= S_IXUSR;

        if (letters[3] == 'r') octal |= S_IRGRP;
        if (letters[4] == 'w') octal |= S_IWGRP;
        if (letters[5] == 'x') octal |= S_IXGRP;

        if (letters[6] == 'r') octal |= S_IROTH;
        if (letters[7] == 'w') octal |= S_IWOTH;
        if (letters[8] == 'x') octal |= S_IXOTH;
    } else octal = -1;

    return octal;
}

int octal_in_letters(int octal, char* letters)
{
    int flag = 1;
    if (octal >= 0 && octal <= 0777)
    {
        flag = 0;
        letters[0] = (octal & S_IRUSR) ? 'r' : '-';
        letters[1] = (octal & S_IWUSR) ? 'w' : '-';
        letters[2] = (octal & S_IXUSR) ? 'x' : '-';

        letters[3] = (octal & S_IRGRP) ? 'r' : '-';
        letters[4] = (octal & S_IWGRP) ? 'w' : '-';
        letters[5] = (octal & S_IXGRP) ? 'x' : '-';

        letters[6] = (octal & S_IROTH) ? 'r' : '-';
        letters[7] = (octal & S_IWOTH) ? 'w' : '-';
        letters[8] = (octal & S_IXOTH) ? 'x' : '-';

        letters[9] = '\0';
    }

    return flag;
}

void print_binary(int octal)
{
    printf("Бинарный вид: ");
    printf("%c", (octal & S_IRUSR) ? '1' : '0');
    printf("%c", (octal & S_IWUSR) ? '1' : '0');
    printf("%c", (octal & S_IXUSR) ? '1' : '0');

    printf("%c", (octal & S_IRGRP) ? '1' : '0');
    printf("%c", (octal & S_IWGRP) ? '1' : '0');
    printf("%c", (octal & S_IXGRP) ? '1' : '0');

    printf("%c", (octal & S_IROTH) ? '1' : '0');
    printf("%c", (octal & S_IWOTH) ? '1' : '0');
    printf("%c\n", (octal & S_IXOTH) ? '1' : '0');

}

int stat_file(char* name, int* octal)
{
    int flag = 0;
    struct stat file;
    if (stat(name, &file) == 0) {
        *octal = file.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
    } else flag = 1;

    return flag;
}

int edit_right(char *buffer, int* octal)
{
    int who = 0, right = 0;
    while (*buffer != '-' && *buffer != '+' && *buffer != '=')
    {
        switch(*buffer)
        {
            case 'u': who |= S_IRWXU; break;
            case 'g': who |= S_IRWXG; break;
            case 'o': who |= S_IRWXO; break;
            case 'a': who |= (S_IRWXU | S_IRWXG | S_IRWXO); break;
            default: return 1;
        }
        buffer++;

    }

    if (who == 0) who |= (S_IRWXU | S_IRWXG | S_IRWXO);
    if (*buffer == '\0') return 1;
    char sign = *buffer;
    buffer++;
    if (*buffer == '\0') return 1;

    while (*buffer != '\0')
    {
        switch(*buffer)
        {
            case 'r': right |= (S_IRUSR | S_IRGRP | S_IROTH); break;
            case 'w': right |= (S_IWUSR | S_IWGRP | S_IWOTH); break;
            case 'x': right |= (S_IXUSR | S_IXGRP | S_IXOTH); break;
            default: return 1;
        }
        buffer++;
    }
    switch(sign)
    {
        case '+': *octal |= (who & right); break;
        case '-': *octal &= ~(who & right); break;
        case '=': *octal = (*octal & (~who)) | (who & right); break;
        default: return 1;
    }

    return 0;
}


