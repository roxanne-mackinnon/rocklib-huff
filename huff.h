/*
 * huff.h - Implementation of huffman's variable length compression
 * Copyright (C) 2021   Roxanne MacKinnon
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * <rdm3@williams.edu> Roxanne MacKinnon
 */
#ifndef __HUFF_H__
#define __HUFF_H__

/* struct representing a single huffman character encoding */
typedef struct HuffChar {
  uint64_t character; /* bits representing a character */
  unsigned num_bits; /* num of significant bits in this encoding */
} HuffChar;

/* struct representing mapping from chars to compressed encodings*/
typedef struct HuffTable{
  HuffChar table[256];
} HuffTable;

/* struct representing compressed string and translation table */
typedef struct HuffEncoding {
  char * compressed_string; /* compressed version of original string */
  HuffTable table; /* map from chars to var. length huff chars */
} HuffEncoding;

/**
 * Compress the given string using huffman scheme
 * Returns a HuffEncoding struct that can be used for decompression.
 * Result is dynamically allocated and must be freed after use.
 */
HuffEncoding * huff_compress_string(char * str);

/**
 * Decompress the given huffman encoding and return the original string.
 * Result is dynamically allocated and must be freed after use.
 */
char * huff_decompress_string (HuffEncoding * encoding);

#endif
