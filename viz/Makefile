include ../make.inc

VIZ_SRC = ./src/viz_main.cpp ./src/viz.cpp
VIZ_EXE = $(INDDGO_BIN)/td_viz

INC_DIR=  -I./inc -I$(GRAPH)/inc -I$(TREE)/inc $(METIS_INCLUDES) $(AMD_INCDIR) $(UTHASH_INCDIR) $(GMP_INCDIR) $(MADNESS_INCDIR) $(PARMETIS_INCDIR)

LIBS = -lm -lgraphd -ltreed $(METIS_LIB) $(AMD_LIB) $(ARPACK_LIB) $(GMP_LIB) 

LIB_DIR = -L$(INDDGO_LIB) -L$(METIS_LIB_DIR) $(AMD_LIBDIR) $(ARPACK_LIBDIR) $(GMP_LIBDIR)  

VIZ_OBJ=$(VIZ_SRC:.cpp=.o)

all: $(VIZ_EXE)

.cpp.o:
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $(INC_DIR)  $< -o $@

$(VIZ_EXE): $(VIZ_OBJ)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ $(INC_DIR) $(LIB_DIR) $(LIBS) -o $(VIZ_EXE)

clean: 
	-rm -rf $(VIZ_OBJ)
	-rm -rf $(VIZ_EXE)

