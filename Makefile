include make.inc

DIRS	=	class02																\
			class04																\
			class05																\
			class06
#			class06																\
#			class07																\
#			class08																\
#			class09																\
#			class10																\
#			class11																\
#			class12																\
#			class13																\
#			class14																\
#			class15																\
#			class16																\
#			class17																\
#			class18																\
#			class19																\
#			class20																\
#			class21																\
#			class22

.PHONY	:	clean all $(DIRS)

all	:	$(BUILD_DIR) $(DIRS)

clean	:
	$(ECHO) Currently in $(CURDIR)
	$(foreach dir,$(DIRS),cd $(dir) && $(MAKE) clean && cd ../;)

$(DIRS)	:
	$(ECHO) Currently in $(CURDIR)
	$(MAKE) -C $@

$(BUILD_DIR)	:
	$(ECHO) Setting up build directory $(BUILD_DIR)...
	$(call setup_build_directory)
	$(ECHO) Build directory setup complete
