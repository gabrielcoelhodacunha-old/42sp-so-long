#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct	s_imap
{
	size_t	rows;
	size_t	columns;
	char	**values;
}	t_imap;

typedef struct	s_error
{
	char	*message;
	t_imap	*imap;
}	t_error;

#endif
