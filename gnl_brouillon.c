#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
//#include "get_next_line.h"
// erase this
#include <stdio.h>
#include <fcntl.h>
// erase this

char *ft_substr(char *s, int start, int len)
{
    int i;

    i = 0;
    char *temp = malloc(sizeof(*s) * (len + 1));
    if (!temp)
        return (NULL);
    while (i < len && s[start + i])   
    {
        temp[i] = s[start + i];
        i++;
    }
    temp[i] = '\0';
    return (temp);
}

char *ft_strcpy(char *dst, char *src)
{
    unsigned int i;

    i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    return (dst);
}

int ft_strchr(char *s, int c)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == (char)c)
            return (i);
        i++;
    }
        if (s[i] == 0 && (char)c == 0)
                return (i);
        return (-1);
}

/*
char	*get_next_line(int fd, char *c)
{
static int i;
int j;
char *line;
char *rd_buf;

rd_buf= malloc(sizeof(char) * (2));

j = i;
if (rd_buf[j] == '\0' && rd_buf[i] == '\0')
{
    return (NULL);
}
 while (rd_buf[j] != '\n' && rd_buf[j])
{
    my_read(c, rd_buf, 2); 
    
    j++;
}

    my_read(c, rd_buf, 2); 

 while (j < 2)
{
    if (rd_buf[j] == '\n')
    {
        rd_buf[j] = '\0';
        return (rd_buf);
    }
    j++;
}
malloc(sizeof(char) * (rd_buf + 2));


line = ft_substr(rd_buf, i, j - i);
i = j;
if (rd_buf[j] == '\n')
    i++;
return (line);
}

char *get_one_line(char *c)
{
    char *result;
    char *tmp;
    unsigned int block_size;
    unsigned int i;
    int ret;
    int finish;

    i = 1;
    block_size = 3;
    finish = 0;
    result = NULL;

    while (finish == 0)
    {
        tmp = result;
        result = malloc(sizeof(char) * (block_size * i) + 1);
        if (!result)
            return (NULL);

        if (tmp != NULL)
            ft_strcpy(result, tmp);
        ret = my_read(c + block_size * (i - 1), result + block_size * (i - 1), block_size);
        result[ret + block_size * (i - 1)] = '\0';

        if (ft_strchr(result, '\n') != -1)
        {
            finish = 1;
            ret = ft_strchr(result, '\n');
            result[ret] = '\0';
        }

        i++;
    }
    return (result);
}
*/

size_t  ft_strlen(const char *str)
{
        size_t  i;

        i = 0;
        while (str[i] != '\0')
        {
                i++;
        }
        return (i);
}


char *get_one_line_fd(int fd)
{
    char            *line;
    char            *tmp;
    static char     *save;
    unsigned int    i;
    int             ind;
    int             ret;
    int             finish;

    i = 1;
    finish = 0;
    line = NULL;

    while (finish == 0)
    {
        tmp = line;
            // a chaque tour de boucle a l endroit ou 
            // j'assigne line a tmp je cree un leak 
        line = malloc(sizeof(char) * (BUFFER_SIZE * i) + sizeof(char));
        //au lieu de +1 pour le \0
        if (!line)
            return (NULL);
        if (tmp != NULL)
            ft_strcpy(line, tmp);
        ret = read(fd, line + BUFFER_SIZE * (i - 1), BUFFER_SIZE);
        line[ret + BUFFER_SIZE * (i - 1)] = '\0';
        if (ret == 0)
            return (NULL); 
        if (ft_strchr(line, '\n') != -1)
        {
            finish = 1;
            ret = ft_strchr(line, '\n');
            //test test test 
            if (line[ret] != '\n')
            {
                ind = line[ret + 1];
                while (line[ind])
                {
                    ft_strlen(line[ind]);
                    ind ++;
                }
                save = ft_substr(line, ret + 1, ind);
            }
            // a partir de line[ret + 1] je veux
            // trouver un moyen d extraire ce qui est lu mais
            //que je ne veux pas dans line pour la save dans la static 
            // hypothese : substr avec ret en start + un index 
            //que je recupere avec strlen.
            
            line[ret] = '\0';
        }
        i++;
    }
    return (line);
}

int main()
{
	int fd;
	char *line;
	fd = open("fichier.txt", O_RDWR);
        while (1) {
    	line = get_one_line_fd(fd);
	    printf("%s\n", line);
		free(line);
    if (line == NULL)
       break;
   }
}
