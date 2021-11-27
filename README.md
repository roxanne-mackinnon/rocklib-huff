### huff.h
#### Huffman's variable length compression

Huffman compression is an algorithm which assigns variable-length codes to 8-bit character values, giving shorter codes to characters which occur more frequently in a given data source.

Huffman compression is applicable not just to text - good lossless image compression can be achieved by instead encoding a translated image wherein each column is the corresponding original column of pixels, minus the column to the left of it, save for the leftmost column which is unchanged. This results in an image that is mostly black pixels, due to adjacent colours being close in value.