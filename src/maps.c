#include "so_long.h"

char	*open_maps(char *ber)
{
  int  fd;
  char *maps;
  char	*mappers;
  char *tmp;
  
  maps = ft_strdup("");
  fd = open(ber, O_RDONLY);
  while (1)
    {
      mappers = get_next_line(fd);
      if (!mappers)
        break ;
      tmp = ft_strdup(maps);
      free(map);
      maps = ft_strjoin((char const *)tmp,(char const *)mappers);
      free(tmp);
      free(mappers);
    }
  free(mappers);
  close(fd);
  return (maps);
}