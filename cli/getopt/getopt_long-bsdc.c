/* 
by David P. Discher - 2015
Public domain. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
     
void usage(char* p) {

	printf ("%s [-hf] [-s string] [-i interger] [-d float]\n", p);
	printf ("   -h --help              print help/usage \n");
	printf ("   -f --flag              set the flag\n");
	printf ("   -s --string string     pass string to the s-flag\n");
	printf ("   -i --int int           passing the interger to the i-flag\n");
	printf ("   -d --float float       passing floating point number to the d-flag (d for double)\n");

}

int main(int argc, char**argv)
{
	int ch;
/*
	-h [ 'help|h', "help, print usage", ],
	-s [ 'str|s=s', "string", {required => 1},   ], 
	-f [ 'flag', "boolean flag",   ], 
	-i [ 'int|i=i', "interger option", { default => 1 }  ],
	-d [ 'float|f=f', "interger option", { default => 0.1 }  ],

	struct option {
		char *name;
		int has_arg;
		int *flag;
		int val;
	};
*/

	static struct option longopts[] = {
		{	"str",
			required_argument,
			NULL,
			's'
		},
		{	"int",
			required_argument,
			NULL,
			'i'
		},
		{	"float",
			required_argument,
			NULL,
			'd'
		},

		{	"flag",
			no_argument,
			NULL,
			'f'
		},
		{	"help",
			no_argument,
			NULL,
			'h'
		},

		/*  remember a zero line, else 
			getopt_long segfaults with unknown options */
	    {NULL, 
	    0, 
	    0, 
	    0}, 
			
	};


	while ((ch = getopt_long(argc, argv, "hs:fi:d:", longopts, NULL)) != -1) {
		switch (ch) {
			case 's':
				printf ( "Arg -s : Value : %s \n", optarg );
			break;

			case 'i':
				printf ( "Arg -i : Value : %s \n", optarg );
			break;

			case 'd':
				printf ( "Arg -d : Value : %s \n", optarg );
			break;

			case 'f':
				printf ( "Arg -f : Value : boolean/set \n");
			break;

			case '?':
			case 'h':
			default:
				usage(argv[0]);
			break;
		}
	}
	argc -= optind;
	argv += optind;
	
}
