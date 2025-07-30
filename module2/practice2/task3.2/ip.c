#include "ip.h"  

int inet_pton_and_ntohl(char* str, uint32_t* int32)
{
    if (inet_pton(AF_INET, str, int32) != 1) return 1;
    *int32 = ntohl(*int32);

    return 0;
}

void rand_ip(uint32_t* random_ip, char* random_ip_str)
{
    *random_ip = (rand() % 256) << 24 | (rand() % 256) << 16 | (rand() % 256) << 8 | (rand() % 256);

    struct in_addr addr;
    addr.s_addr = htonl(*random_ip);
    inet_ntop(AF_INET, &addr, random_ip_str, INET_ADDRSTRLEN);

}

uint32_t ip_and_mask(uint32_t ip, uint32_t mask)
{
    return ip & mask;
}


