#include "so_long.h"

void destroy_imap(t_imap *m)
{
	if (!m)
		return ;
	m->rows = 0;
	m->columns = 0;
	if (!m->values)
		return ;
	ft_lstclear(&(m->values), free);
}
