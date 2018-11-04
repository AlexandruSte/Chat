        #include <stdio.h>
	#include <stdlib.h>
	#include <errno.h>
	#include <string.h>
	#include <fcntl.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <unistd.h>

    main()
    {
        char s[300];
        int num, fd;
        printf("Astept cititori...\n");
        printf("Am un cititor....introduceti ceva...\n");
	pid_t pid = fork();
	while(1==1)
	{
		if(pid!=0)
		{
			fd=open("/fenrir/studs/dana.paduraru/retele/Chat_User1", O_WRONLY);
			gets(s);
          		if ((num = write(fd, s, strlen(s))) == -1)
                		perror("Problema la scriere in FIFO!");
			close(fd);
		}
		else
		{
			fd = open("/fenrir/studs/dana.paduraru/retele/Chat_User2", O_RDONLY);
			do {
            			if ((num = read(fd, s, 300)) == -1)
                			perror("Eroare la citirea din FIFO!");
            			else {
                			s[num] = '\0';
					printf("User:  \"%s\"\n", s);
            			     }
        		} while (num > 0);
			close(fd);
		}
	}
    }

