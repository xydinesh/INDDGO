#
# This file is part of INDDGO.
#
# Copyright (C) 2012, Oak Ridge National Laboratory 
#
# This product includes software produced by UT-Battelle, LLC 
# under Contract No.  DE-AC05-00OR22725 with the Department of Energy. 
#
# This program is free software; you can redistribute it and/or modify it 
# under the terms of the New BSD 3-clause software license (see LICENSE file). 
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
# LICENSE for more details.
#
#  For more information please contact the INDDGO developers at: 
#  inddgo-info@googlegroups.com
#
include ../../make.inc
#-----Macros---------------------------------
# set up compiler and options
#CC = g++
#-----------------------------------------------------------------------------
# To build the test library

LIBGTEST=libgtest.a

#-----------------------------------------------------------------------------
INC_DIR= -I./inc -I$(WIS)/inc -I$(TREE)/inc -I$(GRAPH)/inc  $(METIS_INCLUDES) $(AMD_INCDIR) $(UTHASH_INCDIR) $(MADNESS_INCDIR) $(GMP_INCDIR) -I$(GTEST_DIR)/include -I$(GTEST_DIR) 

LIBS = -lm -lgraphd -ltreed $(METIS_LIB) $(AMD_LIB) $(ARPACK_LIB) $(MPILIBS) $(MADNESS_LIB) $(GMP_LIB) -lgtest -lpthread

LIB_DIR = -L./lib -L$(TREE)/lib -L$(GRAPH)/lib/ $(METIS_LIB_DIR) $(AMD_LIBDIR) $(ARPACK_LIBDIR) -L$(GRAPH)/lib $(MADNESS_LIBDIR) $(GMP_LIBDIR) 

#----changes are below this line----------------------------------------------

EXECUTABLES = $(LIBGTEST) testTDTree

SRC=TDTreeTest.cpp $(WIS)/src/weighted_ind_set.cpp

all : ${EXECUTABLES}

%.o : $(WIS)/src/%.cpp 
	$(CC) $(INC_DIR) $(CFLAGS) -c $<

.cpp.o:
	$(CC) $(INC_DIR) $(CFLAGS) -c $<

testTDTree: TDTreeTest.o $(WIS)/src/weighted_ind_set.o
	${CC} ${LFLAGS} -o bin/$@ $^ ${INC_DIR} $(LIBS) $(LIB_DIR)

#---- no change below this line--------------------------------------------------
CXXFLAGS = $(INC_DIR) -O3
gtest-all.o: ${GTEST_DIR}/src/gtest-all.cc
	$(CC) -c $< $(CXXFLAGS)	

gtest_main.o: ${GTEST_DIR}/src/gtest_main.cc
	$(CC) -c $< $(CXXFLAGS)	

$(LIBGTEST): gtest-all.o gtest_main.o
	ar -rv ./lib/$(LIBGTEST) $^
clean:
	rm -f *.o \#* PI* ${EXECUTABLES} core *~ bin/*

test:
	sh run_test.sh
