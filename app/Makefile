TARGET_MAIN = programa-principal
TARGET_TEST = programa-testes
TARGET_INTERATIVO = programa-interativo


CC = gcc

INCLUDE_DIRS := $(shell find include -type d)
CFLAGS = -Wall -Wextra -std=c99 -Werror=ignored-qualifiers -g -O2 -O3 $(addprefix -I,$(INCLUDE_DIRS))
CFLAGS += $(shell pkg-config --cflags glib-2.0)
LDFLAGS = $(shell pkg-config --libs glib-2.0) -lm


SRCS := $(shell find src -type f -name '*.c')


OBJS := $(patsubst src/%.c,obj/%.o,$(SRCS))


COMMON_OBJS := $(filter-out obj/programa-principal/main.o obj/programa-interativo/interativo.o obj/tests/programa-testes.o, $(OBJS))


all: $(TARGET_MAIN) $(TARGET_INTERATIVO) $(TARGET_TEST) 


$(TARGET_MAIN): $(COMMON_OBJS) obj/programa-principal/main.o

	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


$(TARGET_INTERATIVO): $(COMMON_OBJS) obj/programa-interativo/interativo.o
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


$(TARGET_TEST): $(COMMON_OBJS) obj/tests/programa-testes.o
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf obj $(TARGET_MAIN) $(TARGET_INTERATIVO) $(TARGET_TEST)


