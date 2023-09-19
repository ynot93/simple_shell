#include "main.h"
#include "env.h"
/**
 * _getenv - Get the value of an environment variable.
 * @var_name: The name of the environment variable to retrieve.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *_getenv(const char *var_name)
{
	char *input_name = str_tolower(var_name);
	char *env_var = NULL;
	char **env;

	if (var_name == NULL || !var_name[0] || environ == NULL)
	{
		free(input_name);
		return (NULL);
	}
	for (env = environ; *env; ++env)
	{
		env_var = str_tolower(*env);

		if (_strncmp(env_var, input_name, _strlen(input_name)) == 0 && env_var[_strlen(input_name)] == '=')
		{
			env_var = _strdup(*env + _strlen(input_name) + 1);
			break;
		}
		free(env_var);
		env_var = NULL;
	}
	free(input_name);
	return (env_var);
}

/**
 * str_tolower - Converts a string to lowercase.
 * @str: The string to be converted.
 *
 * Return: A new string in lowercase.
 */
char *str_tolower(const char *str)
{
	char *new_str = _strdup(str);
	int i = 0;

	while (new_str[i])
	{
		new_str[i] = tolower(new_str[i]);
		i++;
	}
	return (new_str);
}
