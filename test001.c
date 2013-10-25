#include "src/apue.h"
#include "src/apue_db.h"
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/uio.h>
#include "src/db.c"
#include "src/error.c"

int main(int argc, char* argv[]){
	DBHANDLE	db;

	if ((db = db_open("data/db4", O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) == NULL)
		err_sys("db_open error");

	printf("%p\n", db);

	db_close(db);

	exit(0);
}