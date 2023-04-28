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
structpassinfo-contains pseudo-arguement to pass into function,
allows uniformly prototype for functions pointer struct
 * @cmd_buf_type: CMD_type ||, etc
 * @readfd: reads the fd
 * @histcount: count history line numb
 * @fname: contains the prog filename
 * @env:links list of local copy of the working environment
 * @environ:custommodifiedcopyofenvironfromLLenv
 * @argv:this is an array of strings that was generated from arg
@path:this is a string path
@argc:counts arguments
@line_count: error is counted
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

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}
