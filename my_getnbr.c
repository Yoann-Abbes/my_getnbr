/*
** EPITECH PROJECT, 2018
** getnbr Yoann ABBES
** File description:
** getnbr Yoann ABBES
*/

#include <unistd.h>

void my_putchar(char);
int is_neg(char const*);
int wash_int(long long int, int, int);
int my_strlen(char const*);

int get_num_pos(char const *str)
{
    int i = 0;

    while (str[i] > '9' || str[i] < '0') {
        if (str[i] == '-' || str[i] == '+')
            i = i + 1;
        else
            return (0);
    }
    if (i < my_strlen(str))
        return (i);
    else
        return (0);
}

int my_getnbr(char const *str)
{
    int i = 0;
    long long int nb = 0;
    int neg = 0;

    if (str != NULL) {
        neg = is_neg(str);
        i = get_num_pos(str);
        while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0') {
            nb = nb + (str[i] - '0');
            nb = nb * 10;
            i = i + 1;
            if (neg == 0 && (nb / 10) > 2147483647)
                return (0);
            else if (neg == 1 && (-nb / 10) < -2147483648)
                return (0);
            else
                continue;
        }
        nb = nb / 10;
    }
    return (neg == 1 ? (int)-nb : (int)nb);
}

int is_neg(char const *str)
{
    int n = 0;
    int i = 0;

    while (str[i] != '\0' && (str[i] > '9' || str[i] < '0')) {
        if (str[i] == '-')
            n = n + 1;
        i = i + 1;
    }
    return (n % 2 == 0 ? 0 : 1);
}
