#ifndef _SHELL_H_
#define _SHELL_H_
#include <sys/types.h>

#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* 1 used for system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

/* used for read/write buffer */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststr - links list singly
 * @num: this is the num of fields
 * @str: this is a string
 * @next:this awards point to the folowing node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct pass info-contains pseudo-arguement to pass into function,
 *allows uniformly prototype for functions pointer struct
 * @cmd_buf_type: CMD_type ||, etc
 * @readfd: reads the fd
 * @histcount: count history line numb
 * @fname: contains the prog filename
 * @env:links list of local copy of the working environment
 * @environ:custommodifiedcopyofenvironfromLLenv
 * @argv:this is an array of strings that was generated from arg
@path:this is a string path
@argc:counts arguments
@err_num:the checks if error code exists
@linecount_flag: counts line of inputs
@history:checks the history node
@status:returns status of the last exec'dcommand
@cmd_buf:pointes to cmd
@arg:generates line containing arguements
@alias:contains the alias node
@env_changed:on changed enviroments

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	_}
	char **cmd_buf; / * pointer to cmd ; chain buffer, for memory mangement 
	*/
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}
/* toem_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);


/* toem_parser.c */
int is_cmd(ino_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(ino_t *, char *, char *);

/* toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(ino_t *);
} builtin_table;


/* loophsh.c */
int loophsh(char **);

/* toem_shloop.c */
int hsh(ino_t *, char **);
int find_builtin(ino_t *);
void find_cmd(ino_t *);
void fork_cmd(ino_t *);

/*toem_getline.c */
ssize_t get_input(ino_t *);
int _getline(ino_t *, char **, size_t *);
void sigintHandler(int);



/* toem_lists1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* toem_vars.c */
int is_chain(ino_t *, char *, size_t *);
void check_chain(ino_t *, char *, size_t *, size_t, size_t);
int replace_alias(ino_t *);
int replace_vars(ino_t *);
int replace_string(char **, char *);

/* toem_environ.c */
char *_getenv(ino_t *, const char *);
int _myenv(ino_t *);
int _mysetenv(ino_t *);
int _myunsetenv(ino_t *);
int populate_env_list(ino_t *);
/* toem_history.c */
char *get_history_file(ino_t *ino);
int write_history(ino_t *ino);
int read_history(ino_t *ino);
int build_history_list(ino_t *ino, char *buf, int linecount);
int renumber_history(ino_t *ino);

/* toem_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* toem_atoi.c */
int interactive(ino_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* toem_errors1.c */
int _erratoi(char *);
void print_error(ino_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* toem_getinfo.c */
void clear_info(ino_t *);
void set_info(ino_t *, char **);
void free_info(ino_t *, int);

/* toem_getenv.c */
char **get_environ(ino_t *);
int _unsetenv(ino_t *, char *);
int _setenv(ino_t *, char *, char *);

/* toem_builtin.c */
int _myexit(ino_t *);
int _mycd(ino_t *);
int _myhelp(ino_t *);

/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);


/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_builtin1.c */
int _myhistory(ino_t *);
int _myalias(ino_t *);



/* toem_memory.c */
int bfree(void **);

/* toem_builtin1.c */
int _myhistory(ino_t *);
int _myalias(ino_t *);

#endif
