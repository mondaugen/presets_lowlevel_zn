PL_SRCS = src/presets_lowlevel_std.c
PL_OBJS = $(PL_SRCS:src/%.c=objs/%.o)
PL_INC_PATH = inc
INC		= $(PL_INC_PATH)
CFLAGS	= $(foreach inc,$(INC),-I$(inc))

CFLAGS += -ggdb3 -gdwarf-4 -Wall -ffunction-sections -fdata-sections
CFLAGS += -dD
CFLAGS += -Wno-unused-function

ARFLAGS   = rcs

OBJSDIR = objs

LIBDIR  = lib

CC = gcc
AR = ar

BIN = $(LIBDIR)/libpresets_lowlevel_std.a


all: $(LIBDIR) $(OBJSDIR) $(BIN) 

$(LIBDIR):
	if [ ! -d "$(LIBDIR)" ]; then mkdir $(LIBDIR); fi

$(OBJSDIR):
	if [ ! -d "$(OBJSDIR)" ]; then mkdir $(OBJSDIR); fi

# compile mmdsp 
$(PL_OBJS): $(OBJSDIR)/%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@ 

$(BIN): $(PL_OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -r $(LIBDIR) $(OBJSDIR)
