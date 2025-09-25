#include "test.h"
#include "get_next_line.h"

static void check_arguments(t_data *data, int i)
{
    if (data->rules[0] == '0' && i == 0)
    {
        data->disolvant = 1;
        free(data->rules);
        data->rules = NULL;
    }
    if (data->rules && i == 1)
    {
        printf("%s\n", data->rules);
        free(data->rules);
        data->rules = NULL;
    }
}

static int  check_rules(t_data *data, char *line, int *iteration)
{
    int     i;
    size_t  len;

    len = getlen(line);
    i = *iteration;
    if (len >= 32)
        return (merrors(1), 1);
    data->rules = ft_strdup(line);
    if (!data->rules)
        return (merrors(8), 0);
    check_arguments(data, i);
    free(data->rules);
    *iteration += 1;
    mrules(((i) + 4));
    if (i > 7 || len == 1)
        return (0);
    return (1);
}

static int    intro(t_data *data)
{
    int     i;
    int     state;
    char    *line;

    i = 0;
    state = 0;
    line = NULL;
    mrules(1);
    while (1)
    {
        if (i == 1)
            state = 1;
        line = get_next_line(0, state);
        if (line)
        {
            if (!check_rules(data, line, &i))
                return (mrules(2), free(line), i);
            if (ft_strlen(line) != 0)
                mrules(3);
            free(line);
        }
        if (i >= 2)
            break ;
    }
    return (mrules(2), i);
}

int	main()
{
    t_data  data;

    data.rules = NULL;
    data.disolvant = 0;
	intro(&data);
	return (1);
}
