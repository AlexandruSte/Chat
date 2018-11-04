    #include <stdio.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>

    #define FIFO_NAME "Chat_User1"
    #define FIFO_NAME2 "Chat_User2"

    main()
    {
        char s[300];
        int num, fd;

        mknod(FIFO_NAME, S_IFIFO | 0777, 0);
	   mknod(FIFO_NAME2, S_IFIFO | 0777, 0);
        printf("Astept sa scrie cineva...\n");
        printf("A venit cineva:\n");
	pid_t pid = fork();
	while(1==1)
	{
		if(pid!=0)
		{
			fd=open(FIFO_NAME, O_RDONLY);
        		do {
           			 if ((num = read(fd, s, 300)) == -1)
                			perror("Eroare la citirea din FIFO!");
            			else {
                			s[num] = '\0';
                			printf("User: \"%s\"\n", s);
           		 	}
        		} while (num > 0); 
			close(fd);
		}
		else
		{
			fd = open(FIFO_NAME2, O_WRONLY);
			gets(s);
           		if ((num = write(fd, s, strlen(s))) == -1)
               			perror("Problema la scriere in FIFO!");
			close(fd);
		}
	}
    }
