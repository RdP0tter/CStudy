all:
	gcc hook.c -o hook
	gcc hooklib.c -o hooklib.so -fPIC -shared -D_GNU_SOURCE -ldl

clean:
	rm -f hooklib.so hook
