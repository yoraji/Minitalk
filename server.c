#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	handle_signal(int pid)
{
	static int count = 0;
	static unsigned char character = 0;

	if (pid == SIGUSR1)
		character = (character << 1) | 1;
	else if (pid == SIGUSR2)
		character = (character << 1);
	count++;
	if (count == 8)
	{
		if(character == '\0'){
			write(1,"\n",1);
		}else{
			write(1,&character,1);
		}
		count = 0;
		character = 0;//rest_for_the_next_character
	}
}

int main(void)
{
	printf("Server PID: %d\n",getpid());
	// Register signal andler
	signal(SIGUSR1,handle_signal);
	signal(SIGUSR2,handle_signal);
	while(1)
		pause();
	return 0;
}
