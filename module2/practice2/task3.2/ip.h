#ifndef IP_H
#define IP_H

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <time.h>

int inet_pton_and_ntohl(char* str, uint32_t* int32);
void rand_ip(uint32_t* random_ip, char* random_ip_str);
uint32_t ip_and_mask(uint32_t ip, uint32_t mask);

#endif