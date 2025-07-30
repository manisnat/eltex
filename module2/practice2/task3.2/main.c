#include "ip.h"  

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Некорректный ввод! %s <шлюз> <маска> <количество пакетов>\n", argv[0]);
        return 1;
    }

    char *gateway_ip_str = argv[1];
    char *subnet_mask_str = argv[2];
    int packet_count = atoi(argv[3]);

    uint32_t gateway_ip;
    uint32_t subnet_mask;

    if (inet_pton_and_ntohl(gateway_ip_str, &gateway_ip) == 1 || inet_pton_and_ntohl(subnet_mask_str, &subnet_mask) == 1)
    {
        printf("Ошибка: неверный IP или формат маски подсети!\n");
        return 1;
    }

    srand(time(NULL));
    int same_subnet = 0, other_subnet = 0;

    for (int i = 0; i < packet_count; i++)
    {
        uint32_t random_ip;
        char random_ip_str[INET_ADDRSTRLEN];
        
        rand_ip(&random_ip, random_ip_str);

        if (ip_and_mask(random_ip, subnet_mask) == ip_and_mask(gateway_ip, subnet_mask))
        {
            same_subnet++;
            printf("Пакет %d: %s - своя подсеть\n", i + 1, random_ip_str);
        } else {
            other_subnet++;
            printf("Пакет %d: %s - чужая подсеть\n", i + 1, random_ip_str);
        }
    }

    printf("\nСтатистика:\n");
    printf("Пакетов для своей подсети: %d (%.2f%%)\n", same_subnet, (float)same_subnet / packet_count * 100);
    printf("Пакетов для других подсетей: %d (%.2f%%)\n", other_subnet, (float)other_subnet / packet_count * 100);


    return 0;
}