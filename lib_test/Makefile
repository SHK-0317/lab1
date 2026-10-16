CC      = gcc
CFLAGS  = -Wall -g
LIBDIR  = lib

all: main_static main_shared main_dl

$(LIBDIR)/calc.o: $(LIBDIR)/calc.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR)/libcalc.a: $(LIBDIR)/calc.o
	ar rcs $@ $<

main_static: main.c $(LIBDIR)/libcalc.a
	$(CC) $(CFLAGS) main.c $(LIBDIR)/libcalc.a -o $@

$(LIBDIR)/calc_pic.o: $(LIBDIR)/calc.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(LIBDIR)/libcalc.so: $(LIBDIR)/calc_pic.o
	$(CC) -shared -o $@ $<

main_shared: main.c $(LIBDIR)/libcalc.so
	$(CC) $(CFLAGS) main.c -L$(LIBDIR) -lcalc -Wl,-rpath,'$$ORIGIN/$(LIBDIR)' -o $@

main_dl: main_dl.c $(LIBDIR)/libcalc.so
	$(CC) $(CFLAGS) main_dl.c -ldl -o $@

run: all
	@echo "static"; ./main_static
	@echo "shared"; ./main_shared
	@echo "dynamic"; ./main_dl

clean:
	rm -f $(LIBDIR)/*.o $(LIBDIR)/*.a $(LIBDIR)/*.so main_static main_shared main_dl

.PHONY: all run clean
