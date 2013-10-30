#include "src/apue.h"
#include "src/apue_db.h"
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/uio.h>
#include "src/db.c"

int main(int argc, char* argv[]){
	DBHANDLE	db;

	if ((db = db_open("data/db1", O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) == NULL)
		err_sys("db_open error");

	printf("%p\n", db);

	if (db_store(db, "Alpha", "data1", DB_INSERT) != 0)
		err_quit("db_store error for alpha");

	db_close(db);

	exit(0);
}