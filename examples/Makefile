SRC_FILES= $(wildcard *.c)
OBJ_FILES= $(SRC_FILES:.c=.o)

EXAMPLES = src-tcpss-ex inoutdemo debits rg-its rg-draw hdlc-demo example-1 example-2 example-3 testTCP_ADSL test_HTTP Tests_RNG

.PHONY: clean 

all : $(EXAMPLES)

inoutdemo : inoutdemo.o ../$(SRC_DIR)/libndes.a
	$(CC) inoutdemo.o -o inoutdemo $(LDFLAGS)

src-tcpss-ex : src-tcpss-ex.o ../$(SRC_DIR)/libndes.a
	$(CC) src-tcpss-ex.o -o src-tcpss-ex $(LDFLAGS)

debits : debits.o ../$(SRC_DIR)/libndes.a
	$(CC) debits.o -o debits $(LDFLAGS)

hdlc-demo : hdlc-demo.o ../$(SRC_DIR)/libndes.a
	$(CC) hdlc-demo.o -o hdlc-demo $(LDFLAGS)

rg-its : rg-its.o ../$(SRC_DIR)/libndes.a
	$(CC) rg-its.o -o rg-its $(LDFLAGS)

rg-draw : rg-draw.o ../$(SRC_DIR)/libndes.a
	$(CC) rg-draw.o -o rg-draw $(LDFLAGS)

example-1 : example-1.o ../$(SRC_DIR)/libndes.a
	$(CC) example-1.o -o example-1 $(LDFLAGS)

example-2 : example-2.o ../$(SRC_DIR)/libndes.a
	$(CC) example-2.o -o example-2 $(LDFLAGS)

example-3 : example-3.o ../$(SRC_DIR)/libndes.a
	$(CC) example-3.o -o example-3 $(LDFLAGS)

testTCP_ADSL : testTCP_ADSL.o ../$(SRC_DIR)/libndes.a
	$(CC) testTCP_ADSL.o -o testTCP_ADSL $(LDFLAGS)

test_HTTP : test_HTTP.o ../$(SRC_DIR)/libndes.a
	$(CC) test_HTTP.o -o test_HTTP $(LDFLAGS)

Tests_RNG : Tests_RNG.o ../$(SRC_DIR)/libndes.a
	$(CC) Tests_RNG.o -o Tests_RNG $(LDFLAGS)


clean :
	\rm -f $(OBJ_FILES) $(EXAMPLES) *~ 
	(cd tuto-prog-1 ; make clean)
	(cd tutorial-1 ; make clean)
	(cd tutorial-2 ; make clean)

.c.o :
	$(CC) $(CFLAGS) -I../$(INCL_DIR) $< -c

