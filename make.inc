# Credit for ROOTDIR implementation:
# kenorb (https://stackoverflow.com/users/55075/kenorb),
# How to get current relative directory of your Makefile?,
# URL (version: 2017-05-23): https://stackoverflow.com/a/35698978
ROOTDIR	=	$(abspath $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST))))))

SHELL					=	/bin/sh

RM						=	rm
ECHO					=	echo
COPY					=	cp
LN						=	ln

LATEXMK					=	latexmk
LATEXMKOPTS_PDFLATEX	=	-pdf -dvi- -ps- -bibtex-cond

R						=	R
RSCRIPT					=	Rscript
ROPTS					=	--slave

HTML					=
PDF						=
MD						=
BEAMER_PDFLATEX			=
XARINGAN				=

BUILD_DIR				=	$(ROOTDIR)/build

HTML_OUTPUT				=	bookdown::html_document2
PDF_OUTPUT				=	bookdown::pdf_document2
MD_OUTPUT				=	github_document
XARINGAN_OUTPUT			=	xaringan::moon_reader
PDFLATEX_OUTPUT			=	pdflatex --shell-escape --interaction nonstopmode	\
							--synctex=1 %O %S

HTML_EXT				=	$(BUILD_DIR)/%.html	:	%.Rmd
PDF_EXT					=	$(BUILD_DIR)/%.pdf	:	%.Rmd
MD_EXT				    =	$(BUILD_DIR)/%.md	:	%.Rmd
BEAMER_PDFLATEX_EXT		=	$(BUILD_DIR)/%.pdf	:	%.tex
XARINGAN_EXT			=	$(BUILD_DIR)/%.html	:	%.Rmd

ALL_FILES				=	$(HTML)												\
							$(PDF)												\
							$(MD)												\
							$(BEAMER_PDFLATEX)									\
							$(XARINGAN)

CLEAN_FILES				=	*_files/											\
							*_cache/											\
							$(PDF:.pdf=.synctex.gz)								\
							$(PDF:.pdf=.tex)									\
							$(BEAMER_PDFLATEX:.pdf=.synctex.gz)					\
							$(BEAMER_PDFLATEX:.pdf=.snm)						\
							$(BEAMER_PDFLATEX:.pdf=.nav)

.SILENT	:
.PHONY	:	all clean

define make_all
	$(ECHO) All builds in $(CURDIR) complete!
endef

define setup_build_directory
	mkdir -p "$@"
endef

define cleanup
	$(ECHO) cleaning up in $(CURDIR)
	-$(RM) -rf $(CLEAN_FILES)
	-$(RM) -f $(ALL_FILES)
	-$(RM) -rf $(BUILD_DIR)
	$(if $(BEAMER_PDFLATEX), $(LATEXMK) -C, )
endef

define pdflatex
	$(LATEXMK) $(LATEXMKOPTS_PDFLATEX) -pdflatex="${PDFLATEX_OUTPUT}" 			\
	-outdir='$@' $<
endef

define rmarkdown_render
	$(R) $(ROPTS) -e "rmarkdown::render(input='$<', output_file='$@',		\
	output_format='$(1)')"
endef
