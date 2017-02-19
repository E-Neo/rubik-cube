rubik.so: src/lua_rubik.c src/cube/cube.c
	gcc -Wall -O2 -shared -fPIC -o $@ $^

.PHONY: clean

clean:
	rm rubik.so
