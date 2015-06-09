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

#include <stdio.h>  // printf
#include <uuid.h>   // uuid
#include <stdlib.h> // free
#include <unistd.h> // sleep

#include <sys/uuid.h>  // UUIDGEN(2)

int main(int argc, char**argv)
{

	uuid_t uuid;
	struct uuid store;
	uint32_t status;
	char *str;

// Standard C Library (libc, -lc)

	uuid_create(&uuid,  &status);		
	uuid_to_string(&uuid, &str, &status);		
	printf ( "UUID-LIBC: %s\n", str );	
	free(str);

// system call

	uuidgen(&store, 1);
	printf ( "UUID--SYS: %08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x\n", 
		store.time_low, 
		store.time_mid,
		store.time_hi_and_version,
		store.clock_seq_hi_and_reserved,
		store.clock_seq_low,
		store.node[0],
		store.node[1],
		store.node[2],
		store.node[3],
		store.node[4],
		store.node[5]
	);

}

