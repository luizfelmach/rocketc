rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))


IMPORTS += core/self core/type
IMPORTS += collections/vector collections/list



BUILD = .build
BUILD_L = $(BUILD)/lib
BUILD_I = $(BUILD)/include
BUILD_O = $(BUILD)/objs
BUILD_T = $(BUILD)/tests



FILES_C = $(foreach IMPORT, $(IMPORTS), $(foreach S, $(call rwildcard, $(IMPORT), *.c), $(if $(findstring /tests/, $S), ,$S)))
HEADERS_H = $(foreach IMPORT, $(IMPORTS), $(foreach S, $(call rwildcard, $(IMPORT), *.h), $(if $(findstring /tests/, $S), ,$S)))
TESTS_C = $(foreach IMPORT, $(IMPORTS), $(foreach S, $(call rwildcard, $(IMPORT), *.c), $(if $(findstring /tests/, $S), $S)))


CC = gcc
AR = ar
OBJECTS = $(addprefix $(BUILD_O)/, $(subst .c,.o, $(FILES_C)))
TESTS = $(addprefix $(BUILD_T)/, $(subst .c,, $(TESTS_C)))
INCLUDES = $(addprefix -I, $(IMPORTS))
HEADERS = $(notdir $(HEADERS_H))

all: $(BUILD_L)/librocketc.a $(BUILD_I)/rocketc/rocketc.h

$(BUILD_L)/librocketc.a: $(OBJECTS)
	@mkdir -p $(BUILD_L)
	@$(AR) -crs $(BUILD_L)/librocketc.a $^
	@echo "finished librocketc.a"

$(BUILD_O)/%.o: %.c %.h
	$(eval FOLDER = $(addprefix $(BUILD_O)/, $(dir $<)))
	$(eval OUT = $(addprefix $(BUILD_O)/, $(subst .c,.o,$<)))
	@mkdir -p $(FOLDER)
	@echo "building $(OUT)"
	@$(CC) -c -o $(OUT) $< $(INCLUDES)

$(BUILD_O)/%.o: %.c
	$(eval FOLDER = $(addprefix $(BUILD_O)/, $(dir $<)))
	$(eval OUT = $(addprefix $(BUILD_O)/, $(subst .c,.o,$<)))
	@mkdir -p $(FOLDER)
	@echo "building $(OUT)"
	@$(CC) -c -o $(OUT) $< $(INCLUDES)

$(BUILD_I)/rocketc/rocketc.h: $(HEADERS_H)
	@mkdir -p $(BUILD_I)/rocketc 
	@rm -rf $(BUILD_I)/rocketc/rocketc.h
	@touch $(BUILD_I)/rocketc/rocketc.h
	@for header_h in $(HEADERS_H) ; do \
		cp $${header_h} $(BUILD_I)/rocketc; \
	done
	@for header in $(HEADERS) ; do \
        echo "#include <$${header}>" >> $(BUILD_I)/rocketc/rocketc.h; \
    done
	@echo "finished rocketc.h"

tests: $(TESTS)
	@echo "finished tests"

$(BUILD_T)/%: %.c $(BUILD_L)/librocketc.a $(BUILD_I)/rocketc/rocketc.h
	$(eval FOLDER = $(addprefix $(BUILD_T)/, $(dir $<)))
	$(eval OUT = $(addprefix $(BUILD_T)/, $(subst .c,,$<)))
	@mkdir -p $(FOLDER)
	@echo "building $(OUT)"
	@$(CC) -o $(OUT) $< -I$(BUILD_I)/rocketc -L$(BUILD_L) -lrocketc


clean:
	rm -rf $(BUILD)