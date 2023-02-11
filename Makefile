rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))


FILES += $(call rwildcard,core,*.c *.h)
FILES += $(call rwildcard,collections,*.c *.h)


CC = gcc
AR = ar

BUILD = .build
BUILD_L = $(BUILD)/lib
BUILD_I = $(BUILD)/include
BUILD_O = $(BUILD)/objs
BUILD_T = $(BUILD)/temp


OBJECTS = $(addprefix $(BUILD_O)/,$(notdir $(subst .c,.o,$(filter %.c,$(FILES)))))
INCLUDES = $(addprefix -I, $(dir $(filter %.c,$(FILES))))
HEADERS = $(notdir $(filter %.h,$(FILES)))



all: $(BUILD_L)/librocketc.a $(BUILD_I)/rocketc.h


 $(BUILD_L)/librocketc.a: $(OBJECTS)
	@mkdir -p $(BUILD_L)
	@$(AR) -crs $(BUILD_L)/librocketc.a $^


$(BUILD_O)/%.o: */*/%.c */*/%.h
	$(eval BASENAME = $(basename $(notdir $<)))
	$(eval OUT = $(addsuffix .o, $(addprefix $(LIBRARIES_BUILD), $(BASENAME))))
	@mkdir -p $(BUILD_O)
	@$(CC) -c -o $(BUILD_O)/$(OUT) $< $(INCLUDES)

$(BUILD_I)/rocketc.h: $(BUILD_T)/rocketc.temp.h
	@mkdir -p $(BUILD_I)
	@touch $(BUILD_I)/rocketc.h
	@$(CC) -E $(INCLUDES) $(BUILD_T)/rocketc.temp.h >> $(BUILD_I)/rocketc.h

$(BUILD_T)/rocketc.temp.h:
	@mkdir -p $(BUILD_T)
	@touch $(BUILD_T)/rocketc.temp.h
	@for header in $(HEADERS) ; do \
        echo "#include<$${header}>" >> $(BUILD_T)/rocketc.temp.h; \
    done


clean:
	rm -rf $(BUILD)