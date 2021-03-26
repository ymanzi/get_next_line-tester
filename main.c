#include "gnl_test.h"

int	n_test = 0;

void handler(int num)
{
	exit(0);
}

static int	fct_error(int i)
{
	perror(strerror(errno));
	return (i);
}

void	verif(int i)
{

	printf("%d", ++n_test);
	if (i)
		printf("" GREEN "[O.K]" RESET "");
	else
		printf("" RED "[K.O]" RESET "");
}

void readAll(int fd)
{
	char * s;
	while (get_next_line(fd, &s) > 0)
		free(s);
	free(s);
}

int main(void)
{
	int		fd[6];
	int		ret;
	char	*line;

	line = 0;
	if ((fd[0] = open("files/empty", O_RDWR)) == -1 
		|| (fd[1] = open("files/nl", O_RDWR)) == -1
		|| (fd[2] = open("files/simple_line", O_RDWR)) == -1
		|| (fd[3] = open("files/simple_line_w_nl", O_RDWR)) == -1
		|| (fd[4] = open("files/long", O_RDWR)) == -1
		|| (fd[5] = open("files/long_w_nl", O_RDWR)) == -1)
		return (fct_error(1));
printf("\n------------------   BUFFER_SIZE = %d   --------------\n", BUFFER_SIZE);
printf("ERROR CHECK :");
/*1*/	line = (char*)42; ret = get_next_line(42, &line); verif(ret == -1);
/*2*/	line = (char*)42; ret = get_next_line(-1, &line); verif(ret == -1);
/*3*/	line = (char*)42; ret = get_next_line((int)426256465456454, &line); verif(ret == -1);
printf("\n");
printf("Empty File : ");
/*4*/	line = 0; ret = get_next_line(fd[0], &line); verif(ret == 0);
	free(line);
printf("\nNl File : ");
/*5*/	ret = get_next_line(fd[1], &line); verif(!strcmp(line, "") && ret == 1);
	free(line);
printf("\nSimple Line w/o NL: ");
/*6*/	line = (char*)42; ret = get_next_line(fd[2], &line); verif(!strcmp(line, "123456789123456789123456789") && ret == 0);
	free(line);
printf("\nSimple Line w NL: ");
/*7*/	line = (char*)42; ret = get_next_line(fd[3], &line); verif(!strcmp(line, "123456789123456789123456789") && ret == 1);
	free(line);
printf("\nLong w/o NL: ");
/*8*/	line = (char*)42; ret = get_next_line(fd[4], &line); verif(!strcmp(line, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie, enim est eleifend mi, non fermentum diam nisl sit amet erat. Duis semper. Duis arcu massa, scelerisque vitae, consequat in, pretium a, enim. Pellentesque congue. Ut in risus volutpat libero pharetra tempor. Cras vestibulum bibendum augue. Praesent egestas leo in pede. Praesent blandit odio eu enim. Pellentesque sed dui ut augue blandit sodales. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aliquam nibh. Mauris ac mauris sed pede pellentesque fermentum. Maecenas adipiscing ante non diam sodales hendrerit.")
	 && ret == 1);
	free(line);
/*9*/	line = (char*)42; ret = get_next_line(fd[4], &line); verif(!strcmp(line, "Ut velit mauris, egestas sed, gravida nec, ornare ut, mi. Aenean ut orci vel massa suscipit pulvinar. Nulla sollicitudin. Fusce varius, ligula non tempus aliquam, nunc turpis ullamcorper nibh, in tempus sapien eros vitae ligula. Pellentesque rhoncus nunc et augue. Integer id felis. Curabitur aliquet pellentesque diam. Integer quis metus vitae elit lobortis egestas. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Morbi vel erat non mauris convallis vehicula. Nulla et sapien. Integer tortor tellus, aliquam faucibus, convallis id, congue eu, quam. Mauris ullamcorper felis vitae erat. Proin feugiat, augue non elementum posuere, metus purus iaculis lectus, et tristique ligula justo vitae magna.")
	 && ret == 1);
	free(line);
/*10*/	line = (char*)42; ret = get_next_line(fd[4], &line); verif(!strcmp(line, "")
	 && ret == 1);
	free(line);
/*11*/	line = (char*)42; ret = get_next_line(fd[4], &line); verif(!strcmp(line, "Aliquam convallis sollicitudin purus. Praesent aliquam, enim at fermentum mollis, ligula massa adipiscing nisl, ac euismod nibh nisl eu lectus. Fusce vulputate sem at sapien. Vivamus leo. Aliquam euismod libero eu enim. Nulla nec felis sed leo placerat imperdiet. Aenean suscipit nulla in justo. Suspendisse cursus rutrum augue. Nulla tincidunt tincidunt mi. Curabitur iaculis, lorem vel rhoncus faucibus, felis magna fermentum augue, et ultricies lacus lorem varius purus. Curabitur eu amet.")
	 && ret == 0);
	free(line);
printf("\nLong w NL: ");
/*12*/	line = (char*)42; ret = get_next_line(fd[5], &line); verif(!strcmp(line, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie, enim est eleifend mi, non fermentum diam nisl sit amet erat. Duis semper. Duis arcu massa, scelerisque vitae, consequat in, pretium a, enim. Pellentesque congue. Ut in risus volutpat libero pharetra tempor. Cras vestibulum bibendum augue. Praesent egestas leo in pede. Praesent blandit odio eu enim. Pellentesque sed dui ut augue blandit sodales. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aliquam nibh. Mauris ac mauris sed pede pellentesque fermentum. Maecenas adipiscing ante non diam sodales hendrerit.")
	 && ret == 1);
	free(line);
/*13*/	line = (char*)42; ret = get_next_line(fd[5], &line); verif(!strcmp(line, "Ut velit mauris, egestas sed, gravida nec, ornare ut, mi. Aenean ut orci vel massa suscipit pulvinar. Nulla sollicitudin. Fusce varius, ligula non tempus aliquam, nunc turpis ullamcorper nibh, in tempus sapien eros vitae ligula. Pellentesque rhoncus nunc et augue. Integer id felis. Curabitur aliquet pellentesque diam. Integer quis metus vitae elit lobortis egestas. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Morbi vel erat non mauris convallis vehicula. Nulla et sapien. Integer tortor tellus, aliquam faucibus, convallis id, congue eu, quam. Mauris ullamcorper felis vitae erat. Proin feugiat, augue non elementum posuere, metus purus iaculis lectus, et tristique ligula justo vitae magna.")
	 && ret == 1);
	free(line);
/*14*/	line = (char*)42; ret = get_next_line(fd[5], &line); verif(!strcmp(line, "")
	 && ret == 1);
	free(line);
/*15*/	line = (char*)42; ret = get_next_line(fd[5], &line); verif(!strcmp(line, "Aliquam convallis sollicitudin purus. Praesent aliquam, enim at fermentum mollis, ligula massa adipiscing nisl, ac euismod nibh nisl eu lectus. Fusce vulputate sem at sapien. Vivamus leo. Aliquam euismod libero eu enim. Nulla nec felis sed leo placerat imperdiet. Aenean suscipit nulla in justo. Suspendisse cursus rutrum augue. Nulla tincidunt tincidunt mi. Curabitur iaculis, lorem vel rhoncus faucibus, felis magna fermentum augue, et ultricies lacus lorem varius purus. Curabitur eu amet.")
	 && ret == 1);
	free(line);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	close(fd[4]);
	close(fd[5]);
	return (0);
}