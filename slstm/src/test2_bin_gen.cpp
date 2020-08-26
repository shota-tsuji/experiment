#include <cstdio>
#include <cstdint>
#include <unistd.h>
#include <fcntl.h>
#include "word.hpp"

int main(int argc, char *argv[]){
    
    if(argc != 2){
        fprintf(stderr, "You need specify output filename\n");
        return -1;
    }
    
    /*
     * main(){
     *     print(0xAA);
     * }
     * */
    Word TEST_BIN[] = {
        INS_ENTRY, 0x00,
        INS_PUSH, 0xAA, //n1
        INS_PRINT, 0x00,
        INS_POP, 0x00,
        INS_END, 0x00,
    };
    
    slbin_header header = {sizeof(TEST_BIN)};
    
	// バイナリとして，順番に書き出している
	int fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(fd, &header, sizeof(slbin_header));
    write(fd, TEST_BIN, sizeof(TEST_BIN));
    close(fd);
    
    return 0;
}
