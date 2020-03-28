#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void usage(void)
{
	printf("Command name: searchin\n");
	printf("version: 1.0\n");
	printf("Copyright(c) 2020\n");
	printf("Written by: Aissa ben yahya\n");
	printf("Usage: ./executable <filename> <string-to-search>\n");
}

void search_in_file(char *filename, char *str)
{
	int lnum, c, i = 0;
	int find_result = 0;
	char file[1000];
	
	printf("%s\n", filename);

	FILE *fName;

	fName = fopen(filename, "r");
	if(fName == NULL)
	{
		printf(" Cannot open the file '%s'\n", filename);
		exit(0);
	}
	else
	{
		char *p = fgets(file, 1000, fName);
		if(p == NULL)
			printf("Hello NULL\n");

		while((fgets(file, 1000, fName)) != NULL)
		{
			if((strstr(file, str)) != NULL)
			{
				printf("a matched found in line: %d\n", lnum);
				printf("-------------------------------------------------\n");
				printf("%s\n", file);
				printf("-------------------------------------------------\n");
				find_result++;
			}
			++lnum;
		}
                if(find_result == 0)
                {	
			printf("We cannot find the a match word!!\n");
	       	}

	}
	fclose(fName);
}

int main(int argc, char *argv[])
{
  if(argc > 1 && argc < 3)
  {
  	if(!(strcmp("-h", argv[1])) || !(strcmp("--help", argv[1])))
  	{
  
		  usage();
		  exit(1);
  	}
	else
	{
		printf("searchin: unknown predicate '%s'\n", argv[1]);
	 	exit(0);
	}
  }
  else if(argc == 1 || argc > 3)
  {
	usage();
	exit(1);
  }

  search_in_file(argv[1], argv[2]);

  return 0;
}
