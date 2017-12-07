#include <iostream>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <assert.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;


size_t getFilesize(const char* filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

void help(){
  cout<<"Usage: ./FixFiles <InputFile> <CorrectPart> <chunkNumber>"<<endl;
}

int main(int argc, char * argv[]){
  if((argc>1 && string(argv[1])=="--h")|| argc!=4){
      help();
      return 0;
    }
  string InputFile=argv[1];
  string CorrectPart=argv[2];
  unsigned long long  chunkNumber= strtoull(argv[3],NULL,10);
  cout<<chunkNumber<<endl;
  size_t InputFileSize=getFilesize(InputFile.c_str());
  int Inputfd = open(InputFile.c_str(), O_RDWR  , 0);
  assert(Inputfd != -1);
  char* originalFile = (char*)mmap(NULL, InputFileSize, PROT_WRITE|PROT_READ, MAP_SHARED , Inputfd, 0);
  assert(originalFile != MAP_FAILED);

  size_t CorrectPartSize=getFilesize(CorrectPart.c_str());
  unsigned long long chunkSize=CorrectPartSize;
  int Correctfd = open(CorrectPart.c_str(), O_RDWR , 0);
  assert(Correctfd != -1);
  char* correctFile = (char*)mmap(NULL, CorrectPartSize, PROT_WRITE|PROT_READ, MAP_SHARED , Correctfd, 0);
  assert(correctFile != MAP_FAILED);


  size_t changeStartPos=chunkSize*(chunkNumber-1);
  
  copy(correctFile,correctFile+chunkSize,originalFile+changeStartPos);
  
  return 0;
}
