#include <sys/vfs.h>
#include <stdio.h>

int main(void)
{
struct statfs diskInfo;  
statfs("/", &diskInfo);  
unsigned long long totalBlocks = diskInfo.f_bsize;  
unsigned long long totalSize = totalBlocks * diskInfo.f_blocks;  
size_t mbTotalsize = totalSize>>20;  
unsigned long long freeDisk = diskInfo.f_bfree*totalBlocks;  
size_t mbFreedisk = freeDisk>>20;  
printf ("/  total=%dMB, free=%dMB\n", mbTotalsize, mbFreedisk);  
  
statfs("/boot", &diskInfo);  
totalBlocks = diskInfo.f_bsize;  
totalSize = totalBlocks * diskInfo.f_blocks;  
mbTotalsize = totalSize>>20;  
freeDisk = diskInfo.f_bfree*totalBlocks;  
mbFreedisk = freeDisk>>20;  
printf ("/boot  total=%dMB, free=%dMB\n", mbTotalsize, mbFreedisk);  
  
statfs("/dev/shm", &diskInfo);  
totalBlocks = diskInfo.f_bsize;  
totalSize = totalBlocks * diskInfo.f_blocks;  
mbTotalsize = totalSize>>20;  
freeDisk = diskInfo.f_bfree*totalBlocks;  
mbFreedisk = freeDisk>>20;  
printf ("/dev/shm  total=%dMB, free=%dMB\n", mbTotalsize, mbFreedisk); 

struct statfs diskInfo1;  
statfs("/media/B493-4423", &diskInfo1);  
unsigned long long totalBlocks1 = diskInfo1.f_bsize;  
unsigned long long totalSize1 = totalBlocks1 * diskInfo1.f_blocks;  
size_t mbTotalsize1 = totalSize1>>20;  
unsigned long long freeDisk1 = diskInfo1.f_bfree*totalBlocks1;  
size_t mbFreedisk1 = freeDisk1>>20;  
printf ("/media/B493-4423  total=%dMB, free=%dMB\n", mbTotalsize1, mbFreedisk1);  
}
 
