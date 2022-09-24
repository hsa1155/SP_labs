all:100.exe 4096.exe 8192.exe 16384.exe sync4096.exe

100.exe:buf100.c
	gcc -o 100.exe buf100.c apue.h error.c
	dd if=/dev/zero of=500mb_file_for_buffSize100 bs=1024 count=512000
	dd if=/dev/zero of=50mb_file_for_buffSize100 bs=1024 count=51200
	dd if=/dev/zero of=1mb_file_for_buffSize100 bs=1024 count=1024
4096.exe:buf4096.c
	gcc -o 4096.exe buf4096.c apue.h error.c
	dd if=/dev/zero of=500mb_file_for_buffSize4096 bs=1024 count=512000
	dd if=/dev/zero of=50mb_file_for_buffSize4096 bs=1024 count=51200
	dd if=/dev/zero of=1mb_file_for_buffSize4096 bs=1024 count=1024
	dd if=/dev/zero of=512mb_file1 bs=1024 count=524288
	dd if=/dev/zero of=512mb_file2 bs=1024 count=524288
8192.exe:buf8192.c
	gcc -o 8192.exe buf8192.c apue.h error.c
	dd if=/dev/zero of=500mb_file_for_buffSize8192 bs=1024 count=512000
	dd if=/dev/zero of=50mb_file_for_buffSize8192 bs=1024 count=51200
	dd if=/dev/zero of=1mb_file_for_buffSize8192 bs=1024 count=1024
16384.exe:buf16384.c
	gcc -o 16384.exe buf16384.c apue.h error.c
	dd if=/dev/zero of=500mb_file_for_buffSize16384 bs=1024 count=512000
	dd if=/dev/zero of=50mb_file_for_buffSize16384 bs=1024 count=51200
	dd if=/dev/zero of=1mb_file_for_buffSize16384 bs=1024 count=1024
sync4096.exe:sync4096.c
	gcc -o sync4096.exe sync4096.c apue.h error.c
	dd if=/dev/zero of=512mb_file3 bs=1024 count=524288
	dd if=/dev/zero of=512mb_file4 bs=1024 count=524288

clean:
	rm -f 100.exe 4096.exe 8192.exe 16384.exe 500mb_file_for_buffSize100 50mb_file_for_buffSize100 1mb_file_for_buffSize100 500mb_file_for_buffSize4096 50mb_file_for_buffSize4096 1mb_file_for_buffSize4096
	rm -f 500mb_file_for_buffSize8192 50mb_file_for_buffSize8192 1mb_file_for_buffSize8192 500mb_file_for_buffSize16384 50mb_file_for_buffSize16384 1mb_file_for_buffSize16384
	rm -f 512mb_file3 512mb_file4 512mb_file1 512mb_file2 sync4096.exe 