include ../make.inc

HTML			=
PDF				=
XARINGAN		=	$(BUILD_DIR)/class14_slides.html
BEAMER_PDFLATEX	=

all : $(ALL_FILES)
	$(call make_all)

clean :
	$(call cleanup)

$(PDF)	:	$(PDF_EXT) | $(BUILD_DIR)
	$(call rmarkdown_render,$(PDF_OUTPUT))

$(HTML)	:	$(HTML_EXT) | $(BUILD_DIR)
	$(call rmarkdown_render,$(HTML_OUTPUT))

$(BEAMER_PDFLATEX)	:	$(BEAMER_PDFLATEX_EXT) | $(BUILD_DIR)
	$(call pdflatex)

$(XARINGAN)	:	$(XARINGAN_EXT) | $(BUILD_DIR)
	$(call rmarkdown_render,$(XARINGAN_OUTPUT))
