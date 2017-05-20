#include "get_next_line.h"

t_list  *new_elem(int fd)
{
    t_list *temp;

    temp = (t_list*)malloc(sizeof(t_list));
    (fd >= 0) ? temp->fd = fd : 0;
    temp->str = ft_strnew(0);
    return (temp);
}

t_list *compare_fd(int fd, t_list *MAIN)
{
    t_list  *i;

    i = MAIN;
    while(i)
    {
        if(i->fd == fd)
            return (i);
        if(i->next == NULL)
            i->next = new_elem(fd);
        i = i->next;
    }
    return(i);
}

int write_in_line (t_list *i, char **line)
{
        *line = ft_strsub(i->str, 0, (ft_strchr(i->str, 10) - i->str));
        i->str += (ft_strchr(i->str, 10) - i->str);
        write(1, "Hello\n", 6);
        return(1);
}

int get_next_line   (const int fd, char **line)
{
    char buffer[BUFF_SIZE + 1];
    static t_list *MAIN = NULL;
    ssize_t symbols;
    t_list *i;


    if (fd == -1 || (!line) || (read(fd, NULL, 0) == -1) || !(ft_memset(buffer, 0, (BUFF_SIZE + 1))))
        return (-1);
    (MAIN == NULL) ? MAIN = new_elem(fd) : 0;
    i = compare_fd(fd, MAIN);
    while((symbols = read(fd, buffer, BUFF_SIZE)) >= 0)
    {
        (symbols < BUFF_SIZE) ? buffer[symbols] = '\0' : 0;
        i->str = ft_strjoin(i->str, buffer);
        i->str += (i->str[0] == '\n') ? 1 : 0;
        if (ft_strchr(i->str, 10))
            return (write_in_line(i, line));
        if(i->str[ft_strlen(i->str) - 1] != '\n' && ft_strlen(buffer) == 0)
        {
            i->str[ft_strlen(i->str)] = '\n';
            i->str[ft_strlen(i->str) + 1] = '\0';
            continue ;
        }
        if(symbols == 0)
            return (0);
    }
    return (1);
}