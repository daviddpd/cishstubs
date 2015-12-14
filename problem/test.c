/* 
Copyright (c) 2015, David P. Discher
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

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

#include <stdlib.h>
#define _GLOBAL_DEBUG 1

#define CHATFABRIC_DEBUG_FMT2(d, func, line, fmt, ...) if (d) printf("[DEBUG][%s:%s:%d] " fmt "\n", __FILE__, func, line, __VA_ARGS__ );
#define CHATFABRIC_DEBUG_B2H(d, label, x, len) if (d) util_debug_bin2hex(label, x,len, __FILE__, __FUNCTION__, __LINE__ );

void  util_debug_bin2hex(char* label, unsigned char * x, int len, char* file, const char* func, int line ){

	int i;
	int z=0;
    int l = (len/4) + len*2;
    if (len % 4 > 0) { ++l; }

	char *_utilbuffer = (char *)malloc( (l+1) * sizeof(char) );
    bzero(_utilbuffer, l+1);
    
    
	for (i=0; i<len; i++) {
		sprintf(_utilbuffer+z, "%02x", x[i]);
		z+=2;

		if ( (i>0) && ( (i+1)%4 == 0 ) ) {
			sprintf (_utilbuffer+z, " " );
			z++;
		}

	}

	CHATFABRIC_DEBUG_FMT2(_GLOBAL_DEBUG, func, line, "%20s: %s",  label, _utilbuffer );
    free(_utilbuffer);
}

void createStr ( unsigned char * str, int len ) {

	str = (unsigned char *)calloc(len,sizeof(unsigned char));
	for (int i=0; i<len; i++) {
		str[i] = i+1;
	}

}

int main(int argc, char**argv)
{

	unsigned char * str = NULL;
	createStr ( str, 64 );
	CHATFABRIC_DEBUG_B2H(1, "STR", str, 64 );
	return 0;	

}
