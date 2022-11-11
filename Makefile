run: hello.nes
	fceux $^

hello.nes: $(wildcard *.c) $(wildcard *.s)
	cl65 -o $@ -t nes $^

clean:
	rm -f *.o *.nes