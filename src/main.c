
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "Position.h"
# include "Errors.h"
# include "css_scan.h"
# include "css_pars.h"
# include "Tree.h"


int main (int argc, char *argv[])
{
	int errors = 0;
	if (argc == 2){
		if(strcmp (argv[1], "-h") == 0) {
			fprintf (stderr,
				 "usage: %s [-h] [file]\n"
				 "  expression LR based parser, reads 'file' or stdin\n"
				 "  -h: Help\n", argv[0]);
			exit (0);
		}

		css_scan_Attribute.Position.FileName = MakeIdent1 (argv[1]);
 		/*css_scan_beginFile (argv[1]);*/
	}

	BeginTree ();

	errors = css_pars ();
	printf ("parser returned: %d number of errors: %d\n",
		errors,GetCount (xxError));

	if (!CheckTree (TreeRoot)) {
		fprintf (stderr, "Der Baum ist falsch aufgebaut\n");
		exit(1);
	}

	SetDepthTree (20);
	SetBoxTree   (100, 20);
	DrawTree     (TreeRoot);

	return 0;

}
