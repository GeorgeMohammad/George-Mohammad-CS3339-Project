#gcc printfTest.s -fno-pie -no-pie
#this code was translated from asm x86 code on the
#tutorialspoint website.

message:
	.ascii "hello world111111"
str:
	.ascii "test4"
file:
	.ascii "test2.txt"

#	.long 'test2.txt', 0
.lcomm fd_out, 1
.lcomm fd_in, 1
.lcomm info, 5
.global main
.text

main:
mov $1, %rax
mov $1, %rdi
mov $message, %rsi
mov $13, %rdx
#syscall

#create the file
mov $8, %eax
mov $str, %ebx
mov $0777, %ecx
int $0x80
mov %eax, (fd_out)

#writing to file
#mov $11, %edx
#mov $message, %ecx
#mov (fd_out), %ebx
#mov $4, %eax
#int $0x80

#close file
mov $6, %eaX
mov (fd_out), %ebx

#open file for reading/?writing?
mov $5, %eax
mov $file, %ebx
#mov $0, %ecx
mov $2, %ecx
mov $0777, %edx
int $0x80
mov %eax, (fd_in)



#read from the file
mov $3, %eax
mov (fd_in), %ebx
##changed, 5/12/2019
mov info, %ecx
mov $5, %edx
int $0x80

###
#writing to file
mov $11, %edx
mov info, %ecx
mov (fd_out), %ebx
mov $4, %eax
int $0x80
###

#close the file
mov $6, %eax
mov (fd_in), %ebx
int $0x80


#printing the info
mov $4, %eax
mov $1, %ebx
#mov (info), %ecx
mov $str, %ecx
mov $5, %edx
int $0x80
#syscall
mov $1, %eax
int $0x80
push %rdi
mov $str, %rdi
call printf
pop %rdi
ret



