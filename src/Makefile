###############################################################################
# Project:  COCKTAIL training
# Descr:    A simple pocket computer (scanner, parser, evaluator)
# Kind:     Makefile
# Author:   Prof. Dr. Juergen Vollmer <vollmer@dwbw-karlsruhe.de>
# $Id: Makefile,v 1.8 2010/06/19 16:13:16 vollmer Exp $
###############################################################################

# The executable to produce:
MAIN		= cssParser

# Source files
SRC_C		= main.c
SRC		= css.scan	\
		  css.pars	\
		  css.ast 	\

# Generated files
GEN_C		= css_scan.c css_scanSource.c css_pars.c Tree.c
GEN_H		= css_scan.h css_scanSource.h css_pars.h Tree.h yyTree.h
GEN		= css.rex css_scan.rpp css_pars.lrk      Tree.TS

###############################################################################

include config.mk

###############################################################################

# Create your parser
all: $(MAIN)

# Run the test suite
test:
	for f in test*; 	\
	do			\
	  echo "$$f ...";	\
	  ./$(MAIN) $$f; echo;	\
	done

###############################################################################

# Create the Parser
css_pars.lrk css_scan.rpp: css.pars
	lpp -cxzj  css.pars

LARK_OPTS = -cdi -Dw -5  # -5 ==> create the graphic LR-browser
LARK_OPTS = -cdi -Dw     #    ==> see ../config.mk
css_pars.c css_pars.h: css_pars.lrk
	lark $(LARK_OPTS) css_pars.lrk

# Create the Scanner
css.rex: css.scan css_scan.rpp
	rpp < css.scan css_scan.rpp > css.rex

css_scan.c css_scan.h css_scanSource.c css_scanSource.h: css.rex
	rex -cdis -y css.rex
	rm -f css_scanDrv.c

# Create the Abstract Syntax Tree module
# AST options
# -a generate all except -ceh (default)
# -4 generate tree/graph description in file TREE.TS
# -c generate C    source code
# -d generate header file or definition module
# -i generate implementation part or module
# -w generate text graph writer    WriteTREE
# -R generate list reverser        ReverseTREE, ForallTREE
# -t generate top down  traversal  TraverseTREETD
# -b generate bottom up traversal  TraverseTREEBU
# -k generate graph type checker   CheckTREE
# -q generate text  graph browser  QueryTREE
# -e generate graphic browser      procedure DrawTREE
Tree.TS Tree.c Tree.h yyTree.h: css.ast
	ast -cdi -4wemRk css.ast

###############################################################################

include common.mk

###############################################################################
## Internal stuff !!!!
###############################################################################
css.scan:
	cp -f ../css/css.scan .

###############################################################################
