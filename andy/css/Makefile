###############################################################################
# Project:  COCKTAIL training
# Descr:    A simple pocket computer (scanner, parser, evaluator)
# Kind:     Makefile
# Author:   Prof. Dr. Juergen Vollmer <vollmer@dwbw-karlsruhe.de>
# $Id: Makefile,v 1.8 2010/06/19 16:13:16 vollmer Exp $
###############################################################################

# The executable to produce:
MAIN		= expr-ast

# Source files
SRC_C		= main.c
SRC		= expr.scan 	        \
		  expr.pars	\
		  expr.ast 	\

# Generated files
GEN_C		= expr_scan.c expr_scanSource.c expr_pars.c Tree.c
GEN_H		= expr_scan.h expr_scanSource.h expr_pars.h Tree.h yyTree.h
GEN		= expr.rex expr_scan.rpp expr_pars.lrk      Tree.TS

###############################################################################

include ../config.mk

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
expr_pars.lrk expr_scan.rpp: expr.pars
	lpp -cxzj  expr.pars

LARK_OPTS = -cdi -Dw -5  # -5 ==> create the graphic LR-browser
LARK_OPTS = -cdi -Dw     #    ==> see ../config.mk
expr_pars.c expr_pars.h: expr_pars.lrk
	lark $(LARK_OPTS) expr_pars.lrk

# Create the Scanner
expr.rex: expr.scan expr_scan.rpp
	rpp < expr.scan expr_scan.rpp > expr.rex

expr_scan.c expr_scan.h expr_scanSource.c expr_scanSource.h: expr.rex
	rex -cdis -y expr.rex
	rm -f expr_scanDrv.c

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
Tree.TS Tree.c Tree.h yyTree.h: expr.ast
	ast -cdi -4wemRk expr.ast

###############################################################################

include ../common.mk

###############################################################################
## Internal stuff !!!!
###############################################################################
expr.scan:
	cp -f ../expr/expr.scan .

###############################################################################
