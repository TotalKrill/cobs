/**
 * @file cobs.c
 * @brief  sligthly modified cobs decode/encode from wikipedia
 * @author Kristoffer Ödmark
 * @version 1.0
 * @date 2016-08-10
 */

#include "cobs.h"

void cobsEncode(const uint8_t *ptr,
        uint32_t length, uint8_t *dst)
{
    const unsigned char *end = ptr + length;
    unsigned char *code_ptr = dst++;
    unsigned char code = 0x01;

    while (ptr < end)
    {
        if (*ptr == 0){
            FinishBlock(code);
        }
        else{
            *dst++ = *ptr;
            if (++code == 0xFF)
                FinishBlock(code);
        }
        ptr++;
    }
    *dst = 0;
    FinishBlock(code);

}


int32_t cobsDecode(const uint8_t *ptr,
        uint32_t length, uint8_t *dst)
{
    const uint8_t *end = ptr + length;
    const int32_t start = (uint32_t)dst+1;
    while (ptr < end && *ptr != 0)
    {
        int i, code = *ptr++;
        for (i=1; ptr<=end && i<code; i++){
            // check so that there is no zero in the cobsed data.
            if(*ptr == 0)
                return -1;
            *dst++ = *ptr++;
        }
        if (code < 0xFF){
            *dst++ = 0;
        }
    }
    return (int32_t)dst - start;
}

