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

void usage(void) {

	printf ("Usage\n");

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
*/

	while ((ch = getopt(argc, argv, "hs:fi:d:")) != -1) {
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
				usage();
			break;
		}
	}
	argc -= optind;
	argv += optind;
	
}
