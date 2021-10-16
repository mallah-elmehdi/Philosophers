#include "util.h"

int	isnum(char element)
{
	if (element >= 48 && element <= 57)
		return (SUCCESS);
    return (ERROR);
}