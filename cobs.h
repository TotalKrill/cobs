/**
 * @file cobs.h
 * @brief  header for wikipedia cobs
 * @author Kristoffer Ödmark
 * @version 1.0
 * @date 2016-08-10
 */
#ifndef COBS_H
#define COBS_H
#include "stdint.h"

#define FinishBlock(X) (*code_ptr = (X), code_ptr = dst++, code = 0x01)

/*
 * cobsEncode byte stuffs "length" bytes of
 * data at the location pointed to by "ptr",
 * writing the output to the location pointed
 * to by "dst".
 */
void cobsEncode(const unsigned char *ptr,
unsigned long length, unsigned char *dst);

/*
 * cobsDecode decodes "length" bytes of
 * data at the location pointed to by "ptr",
 * writing the output to the location pointed
 * to by "dst".
 */
int32_t cobsDecode(const unsigned char *ptr,
unsigned long length, unsigned char *dst);

#endif /* COBS_H */
