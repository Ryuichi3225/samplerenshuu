
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<locale.h>

int PrintDirsAndFiles(coonst wchar_t * dirpath,const wchar_t * filename);

int main(void){
  //Unicode local  japanese
  setlocale(LC_ALL,"japanese");
  
  //present
  //please input first your search directory
  //please input second your search file name
  PrintDirsAndFiles("L"C:\\",L"xxx.c");
  
  
}

int PrintDirsAndFiles(const wchar_t * dirpath,const wchar_t * filename)
{
  HANDLE hFind;
  WIN32_FIND_DATA win32fd;
  
  wchar_t dirwildpath[1024];
  wcscpy(dirwildpath,dirpath);
  wcscat(dirwildpath, L"*");  
  
   hFind = FindFirstFile(dirwildpath, &win32fd);
   if (hFind == INVALID_HANDLE_VALUE) { 
     FindClose(hFind);
     return;
   }
   do{
   if ((wcscmp(win32fd.cFileName, L".") == 0)||(wcscmp(win32fd.cFileName,L"..")){
    //do nothing
   }
   else if(win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
   {
    wchar_t dir_buf[1024];
    wcscpy(dir_buf,dirpath);
    wcscat(dir_buf,win32fd.cFileName);
    wprintf(L"(Dir)-%ls\n",dirname);
    
    PrintDirsAndFiles(dir_buf,filename);
    
   }
   else {
    if(wcscmp(win32fd.cFileName,filename)==0){
      wprintf(L"(File)-%ls\n",win32fd.cFileName);
      
    }
    while(FindNextFile(hFind,&win32fd));
    
    FindClose(hFind);
   }
   
  
}
