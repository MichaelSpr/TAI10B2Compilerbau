# makefile für Testtat im compilerbau kurs bei prof. dr. vollmer an der dhbw karlsruhe
# css scanner/parser

# the executable
MAIN		= css-ast

# source files
SRC_C		= main.c
SRC		= css.scan
		  css$(SOLUTION).pars
		  css$(SOLUTION).ast

# generated files
GEN_C		= css_scan.c css_scanSource.c css_pars.c Tree.c
GEN_H		= css_scan.h css_scanSource.h css_pars.h Tree.h yyTree.h
GEN		= css.rex css_scan.rpp css_pars.lrk Tree.TS



include ../config.mk



# create parser
all: $(MAIN)

css_pars.lrk css_scan.rpp: css$(SOLUTION).pars
	lpp -cxzj css$(SOLUTION).pars

LARK_OPTS = -cdi -Dw -5
LARK_OPTS = -cdi -Dw
css_pars.c css_pars.h: css_pars.lrk
	lark $(LARK_OPTS) expr_pars.lrk

css.rex: css.scan css_scan.rpp
	rpp < css.scan css_scan.rpp > css.rex

css_scan.c css_scan.h css_scanSource.c css_scanSource.h: scan.rex
	rex -cdis -y css.rex
	rm -f css_scanDrv.c

Tree.TS Tree.c Tree.h yyTree.h: expr$(SOLUTION).ast
	ast -cdi -4wemRk expr$(SOLUTION).ast



include ../common.mk



css.scan:
	cp -f ../css/css.scan .



