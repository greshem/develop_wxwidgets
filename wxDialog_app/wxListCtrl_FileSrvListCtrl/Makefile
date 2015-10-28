CC = gcc  -g  -Wall 
CPP = g++ -g  -Wall 
EXEC = MyApp  
MAIN_OBJS= MyApp.o  
NOMAIN_OBJS= Cmd_str_to_struct.o log.o FileSrvListCtrl.o TestDialog.o 
CFLAGS += `wx-config  --cxxflags`    -Wno-write-strings
LDFLAGS += 
LIBS += `wx-config --libs` -lX11 

all: $(EXEC)
$(EXEC): $(MAIN_OBJS)  $(NOMAIN_OBJS) 
	$(CPP) $(LDFLAGS) -o $@ $@.o $(NOMAIN_OBJS) $(LIBS)

vim: 
	vim Cmd_str_to_struct.cpp
exec: $(EXEC) 
	./$(EXEC)
log:
	 vim Cmd_str_to_struct.log
gdb: 
	gdb ./Cmd_str_to_struct
.PRECIOUS:%.cpp %.c %.C
.SUFFIXES:
.SUFFIXES:  .c .o .cpp .ecpp .pc .ec .C

.cpp.o:
	$(CPP) -c -o $*.o $(CFLAGS) $(INCLUDEDIR)  $*.cpp
	$(CPP) -S   $(CFLAGS) $(INCLUDEDIR)  $*.cpp

.c.o:
	$(CC) -c -o $*.o $(CFLAGS) $(INCLUDEDIR) $*.c
	$(CC) -S   $(CFLAGS) $(INCLUDEDIR) $*.c

.C.o:
	$(CC) -c -o $*.o $(CFLAGS) $(INCLUDEDIR) $*.C	
	$(CC) -S   $(CFLAGS) $(INCLUDEDIR) $*.C	

.ecpp.C:
	$(ESQL) -e $(ESQL_OPTION) $(INCLUDEDIR) $*.ecpp 
	
.ec.c:
	$(ESQL) -e $(ESQL_OPTION) $(INCLUDEDIR) $*.ec
	
.pc.cpp:
	$(PROC)  CPP_SUFFIX=cpp $(PROC_OPTION)  $*.pc
	

clean:
	-rm -f $(EXEC) *.o *.s *.log *.obj
