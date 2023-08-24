/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:27:35 by rgiraud           #+#    #+#             */
/*   Updated: 2023/08/20 23:29:33 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ====================================================
// Structure
// ====================================================

typedef struct counter
{
	int				word;
	int				iteration;
	int				keyword;
}					counter;

typedef struct dictionary
{
	char			*key;
	char			*value;
}					dictionary;

typedef struct search_dictionary
{
	int				is_found;
	char			*value;
}					search_dictionary;

typedef struct array_container
{
	char			*str;
	char			**result;
	int				index_result;
	char			*comma;
	char			*dash;
	char			*and;
	char			*temp;
}					array_container;

typedef struct param_input
{
	char			*path;
	char			*number;
	int				is_correct;
}					params_input;


// ====================================================
// Usefull Functions
// ====================================================

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	skip_space(char *buffer, int *i)
{
	int	stop_skip;

	stop_skip = 1;
	while (buffer[*i] && (buffer[*i] == ' ' || (buffer[*i] == ':'
				&& stop_skip)))
	{
		if (buffer[*i] == ':')
			stop_skip = 0;
		(*i)++;
	}
}

int	is_space(char c)
{
	if (c == ' ' || c == ':' || c == '\n')
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

// ======================================
// join
// ======================================

int	ft_strlens(char **strs, int size)
{
	int	i;
	int	j;
	int	len_strs;

	len_strs = 0;
	j = 0;
	i = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			len_strs++;
			j++;
		}
		j = 0;
		i++;
	}
	return (len_strs);
}

void	ft_add_sep(char *result, char *sep, int *k)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		result[*k] = sep[i];
		(*k)++;
		i++;
	}
}

char	*ft_fill_result_join(char **strs, char *result, int size, char *sep)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	k = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			result[k] = strs[i][j];
			j++;
			k++;
		}
		if (i < size - 1)
			ft_add_sep(result, sep, &k);
		j = 0;
		i++;
	}
	result[k] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len_strs;
	char	*empty_string;
	char	*result;
	int		len_sep;

	if (size == 0)
	{
		empty_string = malloc(1);
		empty_string[0] = '\0';
		return (empty_string);
	}
	len_sep = ft_strlen(sep);
	len_strs = ft_strlens(strs, size) + (len_sep * (size - 1) + 1);
	result = malloc(len_strs * sizeof(char));
	if (!result)
		return (NULL);
	ft_fill_result_join(strs, result, size, sep);
	return (result);
}

// ======================================
// split
// ======================================

int	is_separator(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

int	ft_count_word(char *str, char *charset, int count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		if (str[i] && !is_separator(str[i], charset))
		{
			count++;
			while (str[i] && !is_separator(str[i], charset))
				i++;
		}
	}
	return (count);
}

void	ft_add_word_to_result(char *start, char **result, int *count, char *str)
{
	int		len_word;
	int		index;
	char	*word;

	index = 0;
	len_word = str - start;
	if (len_word == 0)
	{
		(*count)--;
		return ;
	}
	word = malloc((len_word + 1) * sizeof(char));
	if (!word)
		return ;
	result[*count] = word;
	while (index < len_word)
	{
		result[*count][index] = *start;
		start++;
		index++;
	}
	result[*count][index] = '\0';
}

void	ft_fill_result_split(char **result, char *str, char *charset, int count)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], charset))
			i++;
		if (str[i] && !is_separator(str[i], charset))
		{
			j = i;
			while (str[j] && !is_separator(str[j], charset))
				j++;
			ft_add_word_to_result(&str[i], result, &count, &str[j]);
			count++;
			i = j;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	int		nb_word;
	int		count;
	int		i;
	char	**result;

	count = 0;
	i = 0;
	nb_word = ft_count_word(str, charset, count);
	result = malloc((nb_word + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	ft_fill_result_split(result, str, charset, count);
	result[nb_word] = 0;
	return (result);
}

char	*ft_split_join(char *chaine)
{
	char	**result_split;
	char	*result_final;
	int		len;

	len = 0;
	result_split = ft_split(chaine, " ");
	while (result_split[len])
		len++;
	result_final = ft_strjoin(len, result_split, " ");
	return (result_final);
}

// ====================================================
// Intialize Dictionnary with tab of Struct dictionary
// ====================================================

void	ft_free_dict(dictionary *dict, int *count_entries)
{
	while (*count_entries >= 0)
	{
		free(dict[*count_entries].value);
		free(dict[*count_entries].key);
		(*count_entries)--;
	}
	free(dict);
}

// fonction qui ajoute la valeur du dico dans le tab
void	ft_add_value_to_dict(char *buffer, dictionary *dict, int *i, int *j,
		int *count_entries)
{
	int	index_dict;

	index_dict = 0;
	while (buffer[*j] && /*!is_space(buffer[*j])*/ buffer[*j] != '\n')
		(*j)++;
	dict[*count_entries].value = malloc((*j - *i + 1) * sizeof(char));
	if (!dict[*count_entries].value)
		ft_free_dict(dict, count_entries);
	while (*i < *j)
	{
		dict[*count_entries].value[index_dict] = buffer[*i];
		(*i)++;
		index_dict++;
	}
	dict[*count_entries].value[index_dict] = '\0';
	dict[*count_entries].value = ft_split_join(dict[*count_entries].value);
}

// fonction qui ajoute la cle du dico dans le tab
void	ft_add_key_to_dict(char *buffer, dictionary *dict, int *i, int *j,
		int *count_entries)
{
	int	index_dict;

	index_dict = 0;
	while (buffer[*j] && !is_space(buffer[*j]))
		(*j)++;
	dict[*count_entries].key = malloc((*j - *i + 1) * sizeof(char));
	if (!dict[*count_entries].key)
		ft_free_dict(dict, count_entries);
	while (*i < *j)
	{
		dict[*count_entries].key[index_dict] = buffer[*i];
		(*i)++;
		index_dict++;
	}
	dict[*count_entries].key[index_dict] = '\0';
	skip_space(buffer, i);
	*j = *i;
	ft_add_value_to_dict(buffer, dict, i, j, count_entries);
}

int	malloc_dict(dictionary **dict, int count_entries)
{
	*dict = malloc((count_entries + 1) * sizeof(dictionary));
	if (!dict)
	{
		free(dict);
		return (0);
	}
	return (1);
}

// rempli les structure avec la cle et la valeur
int	fill_dict(char *buffer, dictionary **dict)
{
	int	count_entries;
	int	i;
	int	j;

	count_entries = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count_entries++;
		i++;
	}
	i = 0;
	if (!malloc_dict(dict, count_entries))
		return (0);
	dict[count_entries] = NULL;
	count_entries = 0;
	while (buffer[i])
	{
		j = i;
		ft_add_key_to_dict(buffer, *dict, &i, &j, &count_entries);
		count_entries++;
		i++;
	}
	return (1);
}

// fonction principale de l'initialisation du dictionnaire
int	make_dict(dictionary **dict, char *path)
{
	unsigned int	status;
	char			buffer[4096];
	unsigned int	bytesread;

	status = open(path, O_RDONLY);
	if (status == (unsigned int)-1)
		return (0);
	bytesread = read(status, buffer, sizeof(buffer) - 1);
	if (bytesread == (unsigned int)-1)
		return (0);
	buffer[bytesread] = '\0';
	fill_dict(buffer, dict);
	return (1);
}


// ====================================================
// Part count size of char *result for the malloc
// ====================================================

search_dictionary	ft_search_word_dico(char *str, dictionary *dict)
{
	int					i;
	search_dictionary	struct_search;

	i = -1;
	while (dict[++i].key)
	{
		if (ft_strcmp(dict[i].key, str) == 0)
		{
			struct_search.is_found = 1;
			struct_search.value = dict[i].value;
			return (struct_search);
		}
	}
	struct_search.is_found = 0;
	struct_search.value = NULL;
	return (struct_search);
}

// functions cut str from start to end (ex: bonjour, 2, 4 => njo)
char	*ft_cut_str(char *str, int start_split, int end_split)
{
	char	*result;
	int		len;
	int		index;

	index = 0;
	len = end_split - start_split + 1;
	result = malloc((len + 1) * sizeof(char));
	result[len] = '\0';
	if (!result)
	{
		free(result);
		return (NULL);
	}
	while (index < len)
	{
		result[index] = str[start_split];
		start_split++;
		index++;
	}
	return (result);
}

// function count of word for group of one or two char of digit (ex: 24 =>
// 3 ("tweenty","-", "two"))
void	count_beginning(char *str, counter *count, int *index, dictionary *dict)
{
	int		len;
	char	*word_search;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (len % 3 == 1)
	{
		count->word++;
		(*index)++;
	}
	else
	{
		if (!(word_search = ft_cut_str(str, *index, *index + 1)))
			return ;
		if (ft_search_word_dico(word_search, dict).is_found)
			count->word++;
		else
			count->word += 3;
		(*index) += 2;
	}
	count->iteration++;
	if (len > 3)
		count->keyword++;
}

int	add_number(array_container *all_arrays, int index, int end,
		dictionary *dict)
{
	char	*word_search;

	if (all_arrays->temp)
		word_search = ft_search_word_dico(all_arrays->temp, dict).value;
	else
		word_search = ft_search_word_dico(ft_cut_str(all_arrays->str, index,
				end), dict).value;
	all_arrays->temp = NULL;
	if (!word_search)
		return (0);
	all_arrays->result[all_arrays->index_result] = word_search;
	all_arrays->index_result++;
	return (1);
}
char	*ft_create_temp(char c, int size) // free !!
{
	char *temp;
	int j;

	j = 0;
	temp = malloc(sizeof(char) * size + 1);
	temp[size] = '\0';
	temp[j] = c;
	while (++j < size)
		temp[j] = '0';
	return (temp);
}
int	add_keyword(array_container *all_arrays, int size, dictionary *dict)
{
	char	*temp;
	char	*word_search;
	int		j;

	temp = ft_create_temp('1', size);
	word_search = ft_search_word_dico(temp, dict).value;
	if (!word_search)
		return (0); // dict error
	all_arrays->result[all_arrays->index_result] = word_search;
	all_arrays->index_result++;
	return (1);
}
void	parse_beginning(array_container *all_arrays, counter *count, int *index,
		dictionary *dict)
{
	int		len;
	char	*word_search;

	len = ft_strlen(all_arrays->str);
	if (len % 3 == 1 && add_number(all_arrays, *index, *index, dict)
		&& len > 3)
	;
	else if (len % 3 == 2 || len > 3)
	{
		if (!add_number(all_arrays, *index, *index + 1, dict))
		{
			all_arrays->temp = ft_create_temp(all_arrays->str[*index], 2);
			if (add_number(all_arrays, *index, *index, dict))
			{
				all_arrays->result[all_arrays->index_result++] = all_arrays->dash;
				add_number(all_arrays, *index + 1, *index + 1, dict);// error
			}
		}
	}
	if (len % 3 == 1)
		(*index)++;
	else
		(*index) += 2;
	if (len > 3)
			{
			add_keyword(all_arrays, len - (*index - 1), dict);
			all_arrays->result[all_arrays->index_result] = all_arrays->comma;
			all_arrays->index_result++;
			}
}

// fonction qui verifie si on est au debut d'un segment,
// et si c'est le cas on verifie que c'est pas que des 0
int	seg_is_zero(int *index, char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	if ((len - *index) % 3 == 0)
	{
		while (str[*index + i] && i < 3)
		{
			if (str[*index + i] != '0')
				return (0);
			i++;
		}
		*index += 3;
		return (1);
	}
	else
	{
		return (0);
	}
}

void	parsing(array_container *all_arrays, counter *count, int *index,
		dictionary *dict)
{
	int		len;
	char	*word_search;

	len = ft_strlen(all_arrays->str);
	while (all_arrays->str[*index])
	{
		while (all_arrays->str[*index] && seg_is_zero(index, all_arrays->str))
			;
		if (!all_arrays->str[*index])
			break ;
		if (all_arrays->str[(*index)] != '0' && add_number(all_arrays, *index, *index, dict))
			add_keyword(all_arrays, 3, dict);
		if (all_arrays->str[(*index) + 1] != '0')
		{
			all_arrays->result[all_arrays->index_result] = all_arrays->and;
			all_arrays->index_result++;
			if (!add_number(all_arrays, *index + 1, *index + 2, dict))
			{
				all_arrays->temp = ft_create_temp(all_arrays->str[*index + 1], 2);
				if (add_number(all_arrays, *index + 1, *index + 1, dict))
				{
					all_arrays->result[all_arrays->index_result++] = all_arrays->dash;
					add_number(all_arrays, *index + 2, *index + 2, dict);
					// error
				}
			}
		}
		else if (all_arrays->str[(*index) + 2] != '0')
			add_number(all_arrays, *index + 2, *index + 2, dict);
		if (*index + 2 < len - 3)
			{
				add_keyword(all_arrays, len - (*index + 2) , dict);
				all_arrays->result[all_arrays->index_result] = all_arrays->comma;
				all_arrays->index_result++;
			}
		*index += 3;
	}
}


int	is_and(char *str, counter *count)
{
	if (!(str[0] == '0' && str[1] == '0'))
		count->word++;
	return (1);
}

void	is_and_end(char *str, counter *count)
{
	int	len;
	int	index;

	len = ft_strlen(str);
	index = len - 3;
	if (!seg_is_zero(&index, str))
		count->keyword--;
	if (len > 3)
	{
		str = ft_cut_str(str, len - 3, len - 1);
		if (str[0] == '0' && !(str[1] == '0' && str[2] == '0'))
			count->word++;
	}
}

void	count_parsing(char *str, counter *count, int *index, dictionary *dict)
{
	char	*word_search;

	while (str[*index])
	{
		while (str[*index] && seg_is_zero(index, str))
			count->iteration++;
		if (!str[*index])
			break ;
		if (str[(*index)++] != '0' && is_and(ft_cut_str(str, *index, (*index)
					+ 1), count))
			count->word += 2;
		if (str[(*index)++] != '0')
		{
			if (!(word_search = ft_cut_str(str, *index - 1, *index)))
				return ;
			if (ft_search_word_dico(word_search, dict).is_found)
				count->word += 1;
			else
				count->word += 3;
			(*index)++;
		}
		else if (str[(*index)++] != '0')
			count->word += 1;
		count->iteration++;
		count->keyword++;
	}
}
// ====================================================
// Gestion des inputs
// ====================================================

void	ft_skip_blank(char *str, int *i)
{
	while (str[*i] && str[*i] == ' ')
		(*i)++;
}
int	is_str_blank(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
	{
		return (1);
	}
	while (str[i])
	{
		if (str[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_easy_atoi(char *str)
{
	int	i;

	if (is_str_blank(str))
		return (0);
	i = 0;
	ft_skip_blank(str, &i);
	while (str[i] && str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] && (str[i] < '0' || str[i] > '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_trim_input_number(char *str, char **output)
{
	int		i;
	char	*result;
	int		len;
	int		j;

	j = 0;
	len = ft_strlen(str);
	i = 0;
	ft_skip_blank(str, &i);
	while (str[i] && (str[i] == '+' || (str[i] == '0' && str[i + 1] != '\0')))
		i++;
	result = malloc((len - i + 2) * sizeof(char));
	if (!result)
		return (0);
	while (str[i])
	{
		result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	*output = result;
	return (1);
}

void	ft_init_struct_params(int argc, char **argv, params_input *params)
{
	params->is_correct = 1;
	params->path = argv[1];
	if (!ft_trim_input_number(argv[2], &(params->number)))
		params->is_correct = 0;
}

void	ft_init_struct_params_default(int argc, char **argv,
		params_input *params)
{
	params->is_correct = 1;
	params->path = "./numbers.dict";
	if (!ft_trim_input_number(argv[1], &(params->number)))
		params->is_correct = 0;
}

params_input	ft_check_params(int argc, char *argv[])
{
	params_input	params;

	params.is_correct = 0;
	params.number = NULL;
	params.path = NULL;
	if (argc == 3)
	{
		if (ft_easy_atoi(argv[2]))
			ft_init_struct_params(argc, argv, &params);
	}
	// si argc == 1, stdinput
	else if (argc == 2)
	{
		if (ft_easy_atoi(argv[1]))
			ft_init_struct_params_default(argc, argv, &params);
	}
	return (params);
}

void	ft_error_basic(void)
{
	write(1, "Error\n", 6);
}

void ft_putstr(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}

void ft_display(char **result)
{
    int i = 0;

    while (result[i])
    {
        ft_putstr(result[i]);

        if (result[i + 1])
        {
            if (result[i][0] != ',' && result[i][0] != '-' && result[i + 1][0] != '-' && result[i + 1][0] != ',')
            {
                ft_putstr(" ");
            }
            else if (result[i][0] == ',' && result[i + 1][0] != '-')
            {
                ft_putstr(" ");
            }
        }
        i++;
    }
    ft_putstr("\n");
}


int	main(int argc, char *argv[])
{
	counter			count;
	dictionary		*dict;
	array_container	all_arrays;
	params_input	params;
	char			*str;
	char			**result;
	char			*path;
	int				index;
	int				len;
	int				i;
	
	params = ft_check_params(argc, argv);
	if (!params.is_correct)
	{
		ft_error_basic();
		return (0);
	}
	str = params.number;
	path = params.path;
	len = ft_strlen(str);
	index = 0;
	count.word = 0;
	count.iteration = 0;
	count.keyword = 0;
	make_dict(&dict, path);
	if (len % 3)
		count_beginning(str, &count, &index, dict);
	count_parsing(str, &count, &index, dict);
	is_and_end(str, &count);
	all_arrays.result = malloc(sizeof(char *) * (count.word + (count.keyword* 2) + 1));
	all_arrays.result[count.word + count.keyword * 2] = NULL;
	all_arrays.str = str;
	all_arrays.comma = ",";
	all_arrays.and = "and";
	all_arrays.dash = "-";
	all_arrays.index_result = 0;
	index = 0;
	if (len % 3)
		parse_beginning(&all_arrays, &count, &index, dict);
	parsing(&all_arrays, &count, &index, dict);
	ft_display(all_arrays.result);
}
