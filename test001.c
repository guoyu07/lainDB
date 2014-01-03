#include "src/apue.h"
#include "src/apue_db.h"
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/uio.h>
#include "src/db.c"

int main(int argc, char* argv[]){
	DBHANDLE	db;
	char *tmp_val;

	if ((db = db_open("data/db1", O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) == NULL)
		err_sys("db_open error");

	//printf("%p\n", db);
	
	if (db_store(db, "key_1", "value_1", DB_INSERT) != 0)
		err_quit("db_store error for key_1");
	
	if (db_store(db, "key_2", "value_2", DB_INSERT) != 0)
		err_quit("db_store error for key_2");
	if (db_store(db, "key_3", "value_3", DB_INSERT) != 0)
		err_quit("db_store error for key_3");

	tmp_val = db_fetch(db,"key_1");
	
	printf("%s\n",tmp_val);
	
	if (db_delete(db, "key_1") != 0){
		err_quit("db_delete error");
	}

	if (db_store(db, "key_2", "value_2_2", DB_REPLACE) != 0)
		err_quit("db_store error for key_1");

	tmp_val = db_fetch(db,"key_2");
	
	printf("%s\n",tmp_val);
	
	db_close(db);

	exit(0);
}
