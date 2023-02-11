#  ===================
#  auxiliary functions
#  ===================

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

#  ================
#  files to compile
#  ================

FILES += $(filter-out %.test.c, $(call rwildcard,core,*.c *.h))
FILES += $(filter-out %.test.c, $(call rwildcard,collections,*.c *.h))

TESTS_C += $(filter %.test.c,$(call rwildcard,core,*.c))
TESTS_C += $(filter %.test.c,$(call rwildcard,collections,*.c))

#  =================
#  file build folder
#  =================

BUILD = .build
BUILD_L = $(BUILD)/lib
BUILD_I = $(BUILD)/include
BUILD_O = $(BUILD)/objs
BUILD_T = $(BUILD)/temp
BUILD_TE = $(BUILD)/tests

#  ========================
#  c/c++ compilation config
#  ========================

CC = gcc
AR = ar
OBJECTS = $(addprefix $(BUILD_O)/,$(notdir $(subst .c,.o,$(filter %.c,$(FILES)))))
TESTS = $(addprefix $(BUILD_TE)/,$(notdir $(subst .c,,$(filter %.c,$(TESTS_C)))))
INCLUDES = $(addprefix -I, $(dir $(filter %.c,$(FILES))))
HEADERS = $(notdir $(filter %.h,$(FILES)))

#  =================
#  compiling rocketc
#  =================

all: $(BUILD_L)/librocketc.a $(BUILD_I)/rocketc.h $(TESTS)


$(BUILD_L)/librocketc.a: $(OBJECTS)
	@mkdir -p $(BUILD_L)
	@$(AR) -crs $(BUILD_L)/librocketc.a $^
	@echo "finished librocketc.a"


$(BUILD_O)/%.o: */*/%.c */*/%.h
	$(eval BASENAME = $(basename $(notdir $<)))
	$(eval OUT = $(addsuffix .o, $(addprefix $(LIBRARIES_BUILD), $(BASENAME))))
	@mkdir -p $(BUILD_O)
	@$(CC) -c -o $(BUILD_O)/$(OUT) $< $(INCLUDES)

$(BUILD_I)/rocketc.h: $(BUILD_T)/rocketc.temp.h
	@mkdir -p $(BUILD_I)
	@touch $(BUILD_I)/rocketc.h
	@$(CC) -E $(INCLUDES) $(BUILD_T)/rocketc.temp.h >> $(BUILD_I)/rocketc.h
	@echo "finished rocketc.h"

$(BUILD_T)/rocketc.temp.h:
	@mkdir -p $(BUILD_T)
	@touch $(BUILD_T)/rocketc.temp.h
	@for header in $(HEADERS) ; do \
        echo "#include<$${header}>" >> $(BUILD_T)/rocketc.temp.h; \
    done

$(BUILD_TE)/%.test: */*/%.test.c $(BUILD_L)/librocketc.a $(BUILD_I)/rocketc.h
	@mkdir -p $(BUILD_TE)
	@$(CC) $(INCLUDES) -o $@ $< -L$(BUILD_L) -I$(BUILD_I) -lrocketc

clean:
	rm -rf $(BUILD)
