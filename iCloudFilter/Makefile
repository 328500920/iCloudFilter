include $(HOME)/src/shell/common.mk

ORALIBPATH32 = -L$(ORACLE_HOME)/lib32 -L$(ORACLE_HOME)/rdbms/lib32
ORALDLIB32 = -locci -lclntsh `cat $(ORACLE_HOME)/lib32/sysliblist`
ORALIBPATH64 = -L$(ORACLE_HOME)/lib -L$(ORACLE_HOME)/rdbms/lib
ORALDLIB64 = -locci -lclntsh `cat $(ORACLE_HOME)/lib/sysliblist`
ORALIBPATH = $(ORALIBPATH32)
ORALDLIB = $(ORALDLIB32)
OCCI_INCLUDE = -I$(ORACLE_HOME)/rdbms/demo -I$(ORACLE_HOME)/rdbms/public -I$(ORACLE_HOME)/plsql/public -I$(ORACLE_HOME)/network/public
OCCI_LIBRARY = $(ORALIBPATH$(OBJECT_MODE))
OCCI_LD_LIBS = $(ORALDLIB$(OBJECT_MODE))

INCLUDE = -I$(OCCI_INCLUDE) \
	-I$(HOME)/src/shell/include \
          -I$(HOME)/src/shell/include/public \
          -I$(HOME)/src/shell/include/business \
          -I$(HOME)/src/shell/include/public/Log \
          -I$(HOME)/src/shell/include/business/PricingPlan \
          -I$(HOME)/src/shell/include/business/accumulator \
          -I$(HOME)/src/shell/include/public/formula \
          -I$(HOME)/src/shell/include/public/CComplex \
          -I$(HOME)/src/shell/libsrc/business/PricingPlan \
					-I$(HOME)/src/shell/include/public/InfoData  \
					-I$(HOME)/src/shell/include/business/psomc \
					-I$(HOME)/src/shell \
			-I$(HOME)/redis-4.0.6/deps

LIBRARY = -L$(HOME)/lib/shared -L$(HOME)/redis-4.0.6/deps/hiredis
LD_LIBS = -lpublic -lbusiness -lccomplex -luocci -ldebug -linfodata -lpthread libhiredis.a
DEBUG_FLAG=-D_DEBUG=true
		

SRCS=FilterInterface main
OBJS=$(SRCS:=.o)
EXE=demo

TARGET:$(EXE)

$(EXE):$(OBJS)
	$(LINK) -o $@ $(OBJS) $(LINK_PARAM) $(LIBRARY) $(LD_LIBS) 
	-cp $(EXE) $(HOME)/bin

	
.PHONY:clean
clean:
	-rm -f $(OBJS) $(EXE)




