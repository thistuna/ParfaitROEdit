#include <stdio.h>
#include <stdlib.h>

// https://ameblo.jp/yu-xpe5995/entry-12472220339.html

int main(int argc, char** argv){
	if(argc<2) {
		puts("Parfait.exeを指定してください");
		system("pause");
		return -1;
	}

	FILE* fp;

	fp = fopen(argv[1],"rb+");
	if(!fp){
		puts("ファイルを開けません");
		system("pause");
		return -1;
	}

	fseek(fp,0x0001111F,SEEK_SET);
	if(getc(fp)!=0x0F){
		puts("指定したファイルが違います");
		system("pause");
		return -1;
	}

	if(getc(fp)!=0x85){
		puts("指定したファイルが違います");
		system("pause");
		return -1;
	}

	fseek(fp,0x0001111F,SEEK_SET);{
		putc(0x90,fp);
		putc(0xE9,fp);
	}

	fclose(fp);

	puts("success");
	system("pause");

	return 0;
}
