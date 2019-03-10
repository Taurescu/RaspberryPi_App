LIBS = lib/
INCLUDE_PATH= lib/
CLIENT=daytimetcpcli
SERVER=daytimetcpsrv
cli_exec: libraries
	gcc Intro/$(SERVER).c $(wildcard libraries/*) -I$(INCLUDE_PATH) -o srv_exec
	gcc Intro/$(CLIENT).c $(wildcard libraries/*) -I$(INCLUDE_PATH) -o cli_exec

libraries:
	mkdir libraries/
	for dir in $(LIBS); do\
		cd $$dir; \
		gcc -c *.c -I../; \
		mv *.o ../libraries; \
		cd -; \
	done

clean:
	rm -rf libraries 
	rm srv_exec
	rm cli_exec
