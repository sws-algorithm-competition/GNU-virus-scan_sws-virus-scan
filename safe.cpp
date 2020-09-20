#include<iostream>
#include<string>
#include<io.h>
#include<fstream>
#include<windows.h>
#include <stdlib.h>  
#include <pthread.h>
#include "shlobj.h" 
#include<winbase.h>
using namespace std;
string  getDesktopPath()
{
    LPITEMIDLIST pidl;
    LPMALLOC pShellMalloc;
    char szDir[200];
    if (SUCCEEDED(SHGetMalloc(&pShellMalloc)))
    {
        if (SUCCEEDED(SHGetSpecialFolderLocation(NULL, CSIDL_DESKTOP, &pidl))) {
            // 如果成功返回true  
            SHGetPathFromIDListA(pidl, szDir);
            pShellMalloc->Free(pidl);
        }
        pShellMalloc->Release();
    }

    return string(szDir);
}
//#define sws "D:\\" 
bool fi(string a,string b){
	bool find;
	for(int i=0;a[i]!='\0';i++){
		for(int q=0;b[q]!='\0';q++){
			if(a[i]==b[q])find=true;
			find=false;
		}
	}
	return find;
}
int remover(string h){
	if(remove(h.c_str())==0)return 0;
	if(MoveFileExA(h.c_str(),NULL,MOVEFILE_COPY_ALLOWED)==0){
		if(MoveFileExA(h.c_str(),NULL,MOVEFILE_WRITE_THROUGH)==0){
			MessageBox(NULL,"文件将在您重启后删除","提示-sws安全助手",MB_OK);
			MoveFileExA(h.c_str(),NULL,MOVEFILE_DELAY_UNTIL_REBOOT); 
			return -1;
		} 
	}
	return 0;
}
int removeDir(string dirPath)
{
	struct _finddata_t fb;   //find the storage structure of the same properties file.
	string path;
	long    handle;
	int  resultone;
	int   noFile;            // the tag for the system's hidden files

	noFile = 0;
	handle = 0;

	path = dirPath + "/*";

	handle = _findfirst(path.c_str(), &fb); 

	//find the first matching file
	if (handle != -1)
	{
		//find next matching file
		while (0 == _findnext(handle, &fb))
		{
			// "." and ".." are not processed
			noFile = strcmp(fb.name, "..");

			if (0 != noFile)
			{
				path.clear();
				path = dirPath + "/" + fb.name;
				
				//fb.attrib == 16 means folder
				if (fb.attrib == 16)
				{
					removeDir(path);
				}
				else
				{
					//not folder, delete it. if empty folder, using _rmdir istead.
					if(path.find("病毒")!=path.npos){
						string j="检测到一个病毒文件(危险等级 未知)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							
							remover(path.c_str());
						}
					}
					if(path.find(".68235483526485238qtr8347rht348rh6t4387r6")!=path.npos){
						remove(path.c_str());
					}
					if(path.find("ludashi")!=path.npos){
						string j="检测到一个含有欺诈用户行为的流氓程序(危险等级 极高)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remover(path.c_str());
						}
					}if(path.find("鲁大师")!=path.npos){
						string j="检测到一个含有欺诈用户行为的流氓程序(危险等级 极高)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remover(path.c_str());
						}
					}if(path.find("LDSLite")!=path.npos){
						string j="检测到一个含有欺诈用户行为的流氓程序(危险等级 极高)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remover(path.c_str());
						}
					}if(path.find("ComputerZLock")!=path.npos){
						string j="检测到一个含有欺诈用户行为的流氓程序(危险等级 极高)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remover(path.c_str());
						}
					}if(path.find("ComputerZ12")!=path.npos){
						string j="检测到一个含有欺诈用户行为的流氓程序(危险等级 极高)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remover(path.c_str());
						}
					}
					}if(path.find("virus")!=path.npos){
						string j="检测到一个病毒文件(危险等级 未知)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remover(path.c_str());
						}
					}if(path.find("filekiller")!=path.npos){
						string j="检测到一个病毒文件(危险等级 极高)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remover(path.c_str());
						}
					}
					}if(path.find(".vbs")!=path.npos){
						char buffer[1000];
      				  	ifstream in(path.c_str());
        			 	if (! in.is_open()){ 
						}else{
 		       				while (!in.eof() ) {
        	    			 	in.getline (buffer,100);
        	    				string bu=buffer;
            				 	if(bu.find("shutdown")!=path.npos){
									string j="检测到一个病毒文件(危险等级 中)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remover(path.c_str());
									}
								}
								if(bu.find("kill")!=path.npos){
									string j="检测到一个病毒文件(危险等级 高)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remover(path.c_str());
									}
								}
								if(bu.find("rename")!=path.npos){
									string j="检测到一个病毒文件(危险等级 中)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remover(path.c_str());
									}
								}
								if(bu.find("name")!=path.npos){
									string j="检测到一个病毒文件(危险等级 低)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remover(path.c_str());
									}
								}
								if(bu.find("shell")!=path.npos){
									string j="检测到一个病毒文件(危险等级 低)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remover(path.c_str());
									}
								}
					}if(path.find(".bat")!=path.npos){
						char buffer[1000];
      				  	ifstream in(path.c_str());
        			 	if (! in.is_open()){ 
						}else{
 		       				while (!in.eof() ) {
        	    			 	in.getline (buffer,100);
        	    				string bu=buffer;
            				 	if(bu.find("shutdown")!=path.npos){
									string j="检测到一个病毒文件(危险等级 中)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remover(path.c_str());
									}
								}
								if(bu.find("copy")!=path.npos){
									string j="检测到一个病毒文件(危险等级 低)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remover(path.c_str());
									}
								}
								if(bu.find("kill")!=path.npos){
									string j="检测到一个病毒文件(危险等级 低)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remover(path.c_str());
									}
								}
								if(bu.find("del")!=path.npos){
									string j="检测到一个病毒文件(危险等级 中)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remover(path.c_str());
									}
								}
								if(bu.find("rd")!=path.npos){
									string j="检测到一个病毒文件(危险等级 高)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remover(path.c_str());
									}
								}
            				}
						}
					}
				}
			}
		}
		// close the folder and delete it only if it is closed. For standard c, using closedir instead(findclose -> closedir).
		// when Handle is created, it should be closed at last.  
		_findclose(handle);
	}
	return 0;
}
bool check(const std::string& dirName_in)  
{  
    DWORD ftyp = GetFileAttributesA(dirName_in.c_str());  
    if (ftyp == INVALID_FILE_ATTRIBUTES)  
        return false;  //something is wrong with your path!  
  
    if (ftyp & FILE_ATTRIBUTE_DIRECTORY)  
        return true;   // this is a directory!  
  
    return false;    // this is not a directory!  
}  
void *killer(void *){
	if(check("A:\\")==true){
		removeDir("A:\\");
	}
	if(check("B:\\")==true){
		removeDir("B:\\");
	}
	if(check("C:\\")==true){
		removeDir("C:\\");
	}
}
void *killer1(void *){
	if(check("E:\\")==true){
		removeDir("E:\\");
	}
	if(check("F:\\")==true){
		removeDir("F:\\");
	}
	if(check("G:\\")==true){
		removeDir("G:\\");
	}
	if(check("H:\\")==true){
		removeDir("H:\\");
	}
	if(check("I:\\")==true){
		removeDir("I:\\");
	}
	if(check("J:\\")==true){
		removeDir("J:\\");
	}
}
void *killer3(void *){
	if(check("D:\\")==true){
		removeDir("D:\\");
	}
}
void *killer4(void *){
	if(check(getDesktopPath())==true){
		removeDir(getDesktopPath());
	}
}
int main() {
	HWND hWnd= GetForegroundWindow();
	ShowWindow(hWnd, SW_HIDE);
	pthread_t ttt;
	pthread_t pdd;
	pthread_t pddf;
	pthread_t pddfw;
	pthread_create(&pdd, NULL, killer, NULL);
	pthread_create(&ttt, NULL, killer1, NULL);
	pthread_create(&pddf, NULL, killer3, NULL);
	pthread_create(&pddfw, NULL, killer4, NULL);
	pthread_exit(NULL);
	if(check("D:\\sre")!=true&&check("C:\\sre")!=true){
		system("donewi.exe");
		exit(0); 
	}
}

	handle = _findfirst(path.c_str(), &fb);

	//find the first matching file
	if (handle != -1)
	{
		//find next matching file
		while (0 == _findnext(handle, &fb))
		{
			// "." and ".." are not processed
			noFile = strcmp(fb.name, "..");

			if (0 != noFile)
			{
				path.clear();
				path = dirPath + "/" + fb.name;
				
				//fb.attrib == 16 means folder
				if (fb.attrib == 16)
				{
					removeDir(path);
				}
				else
				{
					//not folder, delete it. if empty folder, using _rmdir istead.
					if(path.find("病毒")!=path.npos){
						string j="检测到一个病毒文件(危险等级 未知)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remove(path.c_str());
						}
					}
					if(path.find("360")!=path.npos&&(path.find(".exe")!=path.npos||path.find(".dll")!=path.npos||path.find(".dat")!=path.npos||path.find(".sys")!=path.npos||path.find(".bin")!=path.npos)){
						string j="检测到一个含有欺诈用户行为的程序(危险等级 低)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remove(path.c_str());
						}
					}
					if(path.find("ludashi")!=path.npos){
						string j="检测到一个含有欺诈用户行为的流氓程序(危险等级 极高)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remove(path.c_str());
						}
					}if(path.find("鲁大师")!=path.npos){
						string j="检测到一个含有欺诈用户行为的流氓程序(危险等级 极高)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remove(path.c_str());
						}
					}if(path.find("LDSLite")!=path.npos){
						string j="检测到一个含有欺诈用户行为的流氓程序(危险等级 极高)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remove(path.c_str());
						}
					}if(path.find("ComputerZLock")!=path.npos){
						string j="检测到一个含有欺诈用户行为的流氓程序(危险等级 极高)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remove(path.c_str());
						}
					}if(path.find("ComputerZ12")!=path.npos){
						string j="检测到一个含有欺诈用户行为的流氓程序(危险等级 极高)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remove(path.c_str());
						}
					}
					}if(path.find("virus")!=path.npos){
						string j="检测到一个病毒文件(危险等级 未知)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remove(path.c_str());
						}
					}if(path.find("filekiller")!=path.npos){
						string j="检测到一个病毒文件(危险等级 极高)，路径为"+path+"是否删除？";
						int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
						if(ret == IDYES){
							remove(path.c_str());
						}
					}
					}if(path.find(".vbs")!=path.npos){
						char buffer[1000];
      				  	ifstream in(path.c_str());
        			 	if (! in.is_open()){ 
						}else{
 		       				while (!in.eof() ) {
        	    			 	in.getline (buffer,100);
        	    				string bu=buffer;
            				 	if(bu.find("shutdown")!=path.npos){
									string j="检测到一个病毒文件(危险等级 中)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remove(path.c_str());
									}
								}
								if(bu.find("kill")!=path.npos){
									string j="检测到一个病毒文件(危险等级 高)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remove(path.c_str());
									}
								}
								if(bu.find("rename")!=path.npos){
									string j="检测到一个病毒文件(危险等级 中)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remove(path.c_str());
									}
								}
								if(bu.find("name")!=path.npos){
									string j="检测到一个病毒文件(危险等级 低)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remove(path.c_str());
									}
								}
								if(bu.find("shell")!=path.npos){
									string j="检测到一个病毒文件(危险等级 低)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remove(path.c_str());
									}
								}
					}if(path.find(".bat")!=path.npos){
						char buffer[1000];
      				  	ifstream in(path.c_str());
        			 	if (! in.is_open()){ 
						}else{
 		       				while (!in.eof() ) {
        	    			 	in.getline (buffer,100);
        	    				string bu=buffer;
            				 	if(bu.find("shutdown")!=path.npos){
									string j="检测到一个病毒文件(危险等级 中)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remove(path.c_str());
									}
								}
								if(bu.find("copy")!=path.npos){
									string j="检测到一个病毒文件(危险等级 低)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remove(path.c_str());
									}
								}
								if(bu.find("kill")!=path.npos){
									string j="检测到一个病毒文件(危险等级 低)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remove(path.c_str());
									}
								}
								if(bu.find("del")!=path.npos){
									string j="检测到一个病毒文件(危险等级 中)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remove(path.c_str());
									}
								}
								if(bu.find("rd")!=path.npos){
									string j="检测到一个病毒文件(危险等级 高)，路径为"+path+"是否删除？";
									int ret = MessageBox(NULL,j.c_str(),"询问-SWS安全助手",MB_YESNO);
									if(ret == IDYES){
										remove(path.c_str());
									}
								}
            				}
						}
					}
				}
			}
		}
		// close the folder and delete it only if it is closed. For standard c, using closedir instead(findclose -> closedir).
		// when Handle is created, it should be closed at last.  
		_findclose(handle);
	}
	return 0;
}
bool check(const std::string& dirName_in)  
{  
    DWORD ftyp = GetFileAttributesA(dirName_in.c_str());  
    if (ftyp == INVALID_FILE_ATTRIBUTES)  
        return false;  //something is wrong with your path!  
  
    if (ftyp & FILE_ATTRIBUTE_DIRECTORY)  
        return true;   // this is a directory!  
  
    return false;    // this is not a directory!  
}  
void *killer(void *){
	if(check("A:\\")==true){
		removeDir("A:\\");
	}
	if(check("B:\\")==true){
		removeDir("B:\\");
	}
	if(check("C:\\")==true){
		removeDir("C:\\");
	}
}
void *killer1(void *){
	if(check("E:\\")==true){
		removeDir("E:\\");
	}
	if(check("F:\\")==true){
		removeDir("F:\\");
	}
	if(check("G:\\")==true){
		removeDir("G:\\");
	}
	if(check("H:\\")==true){
		removeDir("H:\\");
	}
	if(check("I:\\")==true){
		removeDir("I:\\");
	}
	if(check("J:\\")==true){
		removeDir("J:\\");
	}
}
void *killer3(void *){
	if(check("D:\\")==true){
		removeDir("D:\\");
	}
}
void *killer4(void *){
	if(check(getDesktopPath())==true){
		removeDir(getDesktopPath());
	}
}
int main() {
	HWND hWnd= GetForegroundWindow();
	ShowWindow(hWnd, SW_HIDE);
	pthread_t ttt;
	pthread_t pdd;
	pthread_t pddf;
	pthread_t pddfw;
	pthread_create(&pdd, NULL, killer, NULL);
	pthread_create(&ttt, NULL, killer1, NULL);
	pthread_create(&pddf, NULL, killer3, NULL);
	pthread_create(&pddfw, NULL, killer4, NULL);
	pthread_exit(NULL);
	if(check("D:\\sre")!=true&&check("C:\\sre")!=true){
		system("donewi.exe");
		exit(0); 
	}
}
